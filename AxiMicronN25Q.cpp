//-----------------------------------------------------------------------------
// File          : CMicronN25QEEProm.cpp
// Author        : Larry Ruckman  <ruckman@slac.stanford.edu>
// Created       : 03/19/2014
// Project       :  
//-----------------------------------------------------------------------------
// Description :
//    Micron N25Q and Micron MT25Q PROM C++ Class
//-----------------------------------------------------------------------------
// This file is part of 'SLAC Generic DAQ Software'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'SLAC Generic DAQ Software', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
// Proprietary and confidential to SLAC.
//-----------------------------------------------------------------------------
// Modification history :
// 03/19/2014: created
//-----------------------------------------------------------------------------
#include <fcntl.h>
#include <sstream>
#include <string>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <signal.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#include "AxiMicronN25Q_cpsw.h"
#include <cpsw_entry_adapt.h>
#include "McsRead.h"

using namespace std;

#define CMD_OFFSET 16

#define WRITE_3BYTE_CMD    (0x02 << CMD_OFFSET)
#define WRITE_4BYTE_CMD    (0x12 << CMD_OFFSET)

#define READ_3BYTE_CMD     (0x03 << CMD_OFFSET)
#define READ_4BYTE_CMD     (0x13 << CMD_OFFSET)
   
#define FLAG_STATUS_REG    (0x70 << CMD_OFFSET)
#define FLAG_STATUS_RDY    (0x80)
   
#define WRITE_ENABLE_CMD   (0x06 << CMD_OFFSET)
#define WRITE_DISABLE_CMD  (0x04 << CMD_OFFSET)

#define ADDR_ENTER_CMD     (0xB7 << CMD_OFFSET)
#define ADDR_EXIT_CMD      (0xE9 << CMD_OFFSET)

#define ENABLE_RESET_CMD   (0x66 << CMD_OFFSET)
#define RESET_CMD          (0x99 << CMD_OFFSET)
   
#define ERASE_CMD          (0xD8 << CMD_OFFSET)
#define ERASE_SIZE         (0x10000)

#define STATUS_REG_WR_CMD  (0x01 << CMD_OFFSET)
#define STATUS_REG_RD_CMD  (0x05 << CMD_OFFSET)

#define DEV_ID_RD_CMD      (0x9F << CMD_OFFSET)

#define WRITE_NONVOLATILE_CONFIG (0xB1 << CMD_OFFSET)
#define WRITE_VOLATILE_CONFIG    (0x81 << CMD_OFFSET)
#define READ_NONVOLATILE_CONFIG  (0xB5 << CMD_OFFSET)
#define READ_VOLATILE_CONFIG     (0x85 << CMD_OFFSET)

// Default Configuration:
// Number of dummy clock cycles = 0xF
// XIP mode at power-on reset = 0x7
// Output driver strength = x7
// Double transfer rate protocol = 0x1 ( = Disabled and only used in MT25Q only)
// Reset/hold = 0x0 (disabled to be MT25Q pin compatible with N25Q)
// Quad I/O protocol = 0x1
// Dual I/O protocol = 0x1
// 128Mb segment select = 0x1
#define DEFAULT_3BYTE_CONFIG     0xFFEF
#define DEFAULT_4BYTE_CONFIG     0xFFEE

#define READ_MASK   0x00000000 
#define WRITE_MASK  0x80000000 
#define VERIFY_MASK 0x40000000 

class IFileReader;
class FileReader;

class IFileReader {
public:
	virtual bool       open(string)       = 0;
	virtual void       close()            = 0;
	virtual uint32_t   startAddr()        = 0;
	virtual uint32_t   addrSize()         = 0;
	virtual uint32_t   read(McsReadData*) = 0;
};

// for exception safety
class FileReader : public IFileReader {
	IFileReader *h;
public:
	virtual bool       open(string path)      { return h->open(path);  }
	virtual void       close()                { h->close();            }
	virtual uint32_t   startAddr()            { return h->startAddr(); }
	virtual uint32_t   addrSize()             { return h->addrSize();  }
	virtual uint32_t   read(McsReadData *arg) { return h->read(arg);   }

	virtual ~FileReader() 
	{
		h->close();
	}
	FileReader(IFileReader *i):h(i) {}
};

class McsReadAdapt : public McsRead, public IFileReader {
public:
	virtual bool       open(string path)      { return McsRead::open(path);  }
	virtual void       close()                { McsRead::close();            }
	virtual uint32_t   startAddr()            { return McsRead::startAddr(); }
	virtual uint32_t   addrSize()             { return McsRead::addrSize();  }
	virtual uint32_t   read(McsReadData *arg) { return McsRead::read(arg);   }
};


class CEEPromImpl : public IEEProm {
private:
	// Local Variables -- for supporting the public interface
	string       filePath_;
	uint32_t     promSize_;
	uint32_t     promStartAddr_;
	IFileReader *reader_;

protected:
	bool     addr32BitMode_;

public:
	CEEPromImpl()
	: promSize_(0),
	  promStartAddr_(0),
	  addr32BitMode_(false),
	  reader_( new McsReadAdapt() )
	{
	}

	CEEPromImpl(IFileReader *reader)
	: promSize_(0),
	  promStartAddr_(0),
	  addr32BitMode_(false),
	  reader_( reader )
	{
	}

	virtual ~CEEPromImpl()
	{
		delete reader_;
	}
	virtual void setPromSize (uint32_t promSize);
	virtual uint32_t getPromSize (string pathToFile); 
	virtual void setFilePath (string pathToFile);
	virtual bool fileExist ( );      
	virtual void setAddr32BitMode (bool addr32BitMode);
	virtual void eraseProm ( );    
	// pure virtual methods to implemented for particular EEPROM
	virtual void    setPromStatusReg(uint8_t value) = 0;
	virtual uint8_t getPromStatusReg()              = 0;
	virtual uint8_t getManufacturerId()             = 0;
	virtual uint8_t getManufacturerType()           = 0;
	virtual uint8_t getManufacturerCapacity()       = 0;
	virtual bool    writeProm ( ); 
	virtual bool    verifyProm ( ); 
	virtual void rebootReminder ( bool pwrCycleReq );      
	virtual void readProm (uint32_t address, uint32_t *data);      

// variable and method members that are visible only to the implementation
protected:

    uint32_t data_[64];

    //! Enter 4-BYTE ADDRESS MODE Command
    virtual void enter32BitMode()               = 0;

    //! Exit 4-BYTE ADDRESS MODE Command
	virtual void exit32BitMode()                = 0;

	virtual void eraseCommand(uint32_t address) = 0;
	virtual void writeCommand(uint32_t address) = 0; 
	virtual void readCommand(uint32_t address)  = 0;
	virtual void resetFlash ( )                 = 0;
	virtual void writeEnable ( )                = 0;
	virtual void writeDisable ( )               = 0;
};

//! Class to support SPI EEPROM regardless of a particular driver.
//  Such a driver must implement the low-level functions left as
//  pure-virtual by this class.
class CMicronN25QEEProm : public CEEPromImpl {
   public:

	//! Destructor
	virtual ~CMicronN25QEEProm ( ) {};

	virtual void    setPromStatusReg(uint8_t value);
	virtual uint8_t getPromStatusReg();
	virtual uint8_t getManufacturerId();
	virtual uint8_t getManufacturerType();
	virtual uint8_t getManufacturerCapacity();

   protected:
	//! Enter 4-BYTE ADDRESS MODE Command
	virtual void enter32BitMode();

	//! Exit 4-BYTE ADDRESS MODE Command
	virtual void exit32BitMode();


	virtual void eraseCommand(uint32_t address);
	virtual void writeCommand(uint32_t address);
	virtual void readCommand(uint32_t address);
	virtual void resetFlash ( );
	virtual void writeEnable ( );
	virtual void writeDisable ( );
      
    //! Reset the FLASH memory Command

    //! Wait for the FLASH memory to not be busy
	virtual void waitForFlashReady ( );

    //! Pull the status register
	virtual uint32_t statusReg ( );


	virtual void set32BitModeReg()        = 0;
      
    //! Set the address register
    virtual void setAddr (uint32_t value) = 0;


    //! Set the command register
	virtual void setCmd (uint32_t value, bool writeEnable = true) = 0;

	virtual uint32_t getCmd() = 0;
      
    //! Send the data register
	virtual void setData ()   = 0;

    //! Get the data register
	virtual void getData ()   = 0;
};

#if 0
:
      Device(linkConfig, baseAddress, "CMicronN25QEEProm", index, parent)
{
   // Declare the registers
   addRegisterLink(new RegisterLink("Test", baseAddress + 0x0*addrSize, Variable::Configuration));   
   addr32BitReg_ = new Register("addr32BitMode",baseAddress + (0x01 * addrSize)); 
   addrReg_      = new Register("ADDR",         baseAddress + (0x02 * addrSize)); 
   cmdReg_       = new Register("CMD",          baseAddress + (0x03 * addrSize));
   dataReg_      = new Register("DATA",         baseAddress + (0x80 * addrSize),64);
}
#endif

void CEEPromImpl::setPromSize (uint32_t promSize) {
   promSize_ = promSize;
}

uint32_t CEEPromImpl::getPromSize (string pathToFile) {
   FileReader mcsReader(reader_);
   uint32_t retVar;
   mcsReader.open(pathToFile);
   printf("Calculating PROM file (.mcs) Memory Address size ...");    
   retVar = mcsReader.addrSize();
   printf("PROM Size = 0x%08x\n", retVar); 
   return retVar; 
}

void CEEPromImpl::setFilePath (string pathToFile) {
   filePath_ = pathToFile;
   FileReader mcsReader(reader_);   
   mcsReader.open(filePath_);
   promStartAddr_ = mcsReader.startAddr();
   resetFlash();     
}

//! Set the address mode
void CEEPromImpl::setAddr32BitMode (bool addr32BitMode) {
   addr32BitMode_ = addr32BitMode;
   if(addr32BitMode_){
      enter32BitMode();
   } else {
      exit32BitMode();
   }
}

//! Enter 4-BYTE ADDRESS MODE Command
void CMicronN25QEEProm::enter32BitMode( ) {   
   // Send the enter command
   setCmd(WRITE_MASK|ADDR_ENTER_CMD);     
   set32BitModeReg();
}

//! Exit 4-BYTE ADDRESS MODE Command
void CMicronN25QEEProm::exit32BitMode( ) {   
   // Send the exit command
   setCmd(WRITE_MASK|ADDR_EXIT_CMD);      
   set32BitModeReg();
}

//! Set the non-volatile status register 
void CMicronN25QEEProm::setPromStatusReg(uint8_t value) {   
   if(addr32BitMode_){
      setAddr(((uint32_t)value)<<24); 
      setCmd(WRITE_MASK|STATUS_REG_WR_CMD|0x1);     
   } else {
      setAddr(((uint32_t)value)<<16); 
      setCmd(WRITE_MASK|STATUS_REG_WR_CMD|0x1);          
   }
   waitForFlashReady();    
}

uint8_t CMicronN25QEEProm::getPromStatusReg(){  
   waitForFlashReady();
   setCmd(READ_MASK|STATUS_REG_RD_CMD|0x1); 
   return (uint8_t)(getCmd() & 0xFF);
}

uint8_t CMicronN25QEEProm::getManufacturerId(){  
   waitForFlashReady();
   setCmd(READ_MASK|DEV_ID_RD_CMD|0x1); 
   return (uint8_t)(getCmd()&0xFF);       
}

uint8_t CMicronN25QEEProm::getManufacturerType(){  
   waitForFlashReady();
   setCmd(READ_MASK|DEV_ID_RD_CMD|0x2); 
   return (uint8_t)(getCmd()&0xFF);      
}        

uint8_t CMicronN25QEEProm::getManufacturerCapacity(){  
   waitForFlashReady();
   setCmd(READ_MASK|DEV_ID_RD_CMD|0x3); 
   return (uint8_t)(getCmd()&0xFF);      
}    

//! Check if file exist (true=exists)
bool CEEPromImpl::fileExist ( ) {
  ifstream ifile(filePath_.c_str());
  return ifile;
}

//! Print Power Cycle Reminder
void CEEPromImpl::rebootReminder ( bool pwrCycleReq ) {
   cout << "\n\n\n\n\n";
   cout << "***************************************" << endl;
   cout << "***************************************" << endl;
   cout << "The new data written in the PROM has "   << endl;
   cout << "has been loaded into the FPGA. "         << endl;
   if(pwrCycleReq){
      cout << endl;
      cout << "A reboot or power cycle is required " << endl;
   }
   cout << "***************************************" << endl;
   cout << "***************************************" << endl;
   cout << "\n\n\n\n\n";
}

//! Erase the PROM
void CEEPromImpl::eraseProm (uint32_t startAddr, uint32_t eraseSize) {

   uint32_t address = startAddr;
   double size = double(eraseSize);
   double percentage;
   double skim = 5.0; 

   if ( (startAddr % ERASE_SIZE) != 0 ) {
      throw InvalidArgError("eraseProm: startAddr must be multiple of ERASE_SIZE");
   }
   if ( (eraseSize % ERASE_SIZE) != 0 ) {
      throw InvalidArgError("eraseProm: eraseSize must be multiple of ERASE_SIZE");
   }

   cout << "*******************************************************************" << endl;   
   cout << "Starting Erasing ..." << endl; 
   while(address < (startAddr+eraseSize)) {        
      /*
      // Print the status to screen
      cout << hex << "Erasing PROM from 0x" << address << " to 0x" << (address+ERASE_SIZE-1);
      cout << setprecision(3) << " ( " << ((double(address))/size)*100 << " percent done )" << endl;      
      */
      
      // execute the erase command
      eraseCommand(address);
      
      //increment the address pointer
      address += ERASE_SIZE;
      
      percentage = (((double)address-startAddr)/size)*100;
      if( (percentage>=skim) && (percentage<100.0) ) {
         skim += 5.0;
         cout << "Erasing the PROM: " << floor(percentage) << " percent done" << endl;
      }               
   }   
   cout << "Erasing completed" << endl;
}

//! Write the .mcs file to the PROM
bool CEEPromImpl::writeProm ( ) {
   cout << "*******************************************************************" << endl;
   cout << "Starting Writing ..." << endl; 
   FileReader mcsReader(reader_);
   McsReadData mem;
   
   uint32_t fileData;
   double size = double(promSize_);
   double percentage;
   double skim = 1.0;    
   uint32_t byteCnt = 0;    
   uint32_t wordCnt = 0;    
   uint32_t baseAddr = 0;
   uint32_t cnt     = 0;     

   //check for valid file path
   if ( !mcsReader.open(filePath_) ) {
      cout << "mcsReader.open() = file path error" << endl;
      return false;
   }  
   
   if(promSize_ == 0x0){
      cout << "Invalid promSize_: 0x0" << endl;
      return false;      
   }
   
   //reset the flags
   mem.endOfFile = false;      
   
   //read the entire mcs file
   while(cnt < promSize_) {
   
      //read a line of the mcs file
      if (mcsReader.read(&mem)<0){
         cout << "mcsReader.read() = line read error" << endl;
         return false;
      }
      if ( mem.endOfFile ){
         break;
      }
      
      if( (byteCnt==0) && (wordCnt==0) ) {
         baseAddr = mem.address;
      }
      if( byteCnt==0 ){
         fileData = ((uint32_t)(mem.data&0xFF)) << (8*(3-byteCnt));
      }else{
         fileData |= ((uint32_t)(mem.data&0xFF)) << (8*(3-byteCnt));
      }
      
      cnt++;
      byteCnt++;
      if(byteCnt==4){
         byteCnt = 0;
         data_[wordCnt] = fileData;
         wordCnt++;
         if(wordCnt==64){
            wordCnt = 0;
            writeCommand(baseAddr);
         }                 
      }
      
      percentage = (((double)(mem.address-promStartAddr_))/size)*100;
      if( (percentage>=skim) && (percentage<100.0) ) {
         skim += 5.0;
         cout << "Writing the PROM: " << dec << round(percentage)-1 << " percent done" << endl;
      }       
   }
   
   // Check for the end of the buffer
   if( (byteCnt!=0) || (wordCnt!=0) ){
      while( (byteCnt!=0) || (wordCnt!=0) ){
         // Pad with ones
         if( byteCnt==0 ){
            fileData = 0xFF << (8*(3-byteCnt));
         }else{
            fileData |= 0xFF << (8*(3-byteCnt));
         }         
         byteCnt++;
         if(byteCnt==4){
            byteCnt = 0;
            data_[wordCnt] = fileData;
            wordCnt++;            
            if(wordCnt==64){
               wordCnt = 0;
               writeCommand(baseAddr);
            }                 
         }         
      }
   }

   cout << "Writing completed" << endl;   
   return true;
}

//! Compare the .mcs file with the PROM (true=matches)
bool CEEPromImpl::verifyProm ( ) {
   cout << "*******************************************************************" << endl;
   cout << "Starting Verification ..." << endl; 
   FileReader  mcsReader(reader_);
   McsReadData mem;
   
   uint8_t promData,fileData;
   double size = double(promSize_);
   double percentage;
   double skim = 5.0; 
   uint32_t byteCnt = 0;    
   uint32_t wordCnt = 0;  
   uint32_t cnt     = 0;  

   //check for valid file path
   if ( !mcsReader.open(filePath_) ) {
      cout << "mcsReader.open() = file path error" << endl;
      return(1);
   }

   if(promSize_ == 0x0){
      cout << "Invalid promSize_: 0x0" << endl;
      return false;      
   }   
   
   //reset the flags
   mem.endOfFile = false;   

   //read the entire mcs file
   while(cnt < promSize_) {
   
      //read a line of the mcs file
      if (mcsReader.read(&mem)<0){
         cout << "mcsReader.read() = line read error" << endl;
         return false;
      }
      if ( mem.endOfFile ){
         break;
      }
      
      fileData = (uint8_t)(mem.data & 0xFF);
      if( (byteCnt==0) && (wordCnt==0) ){ 
         readCommand(mem.address);
      }
      promData = (uint8_t)( (data_[wordCnt] >> 8*(3-byteCnt)) & 0xFF);
      cnt++;
      if(fileData != promData) {
         cout << "verifyProm error = ";
         cout << "invalid read back" <<  endl;
         cout << hex << "\taddress: 0x"  << mem.address << endl;
         cout << hex << "\tfileData: 0x" << (uint32_t)fileData << endl;
         cout << hex << "\tpromData: 0x" << (uint32_t)promData << endl;
         return false;
      }      
      
      byteCnt++;
      if(byteCnt==4){
         byteCnt = 0;
         wordCnt++;
         if(wordCnt==64){
            wordCnt = 0;
         }                 
      }      
      
      percentage = (((double)(mem.address-promStartAddr_))/size)*100;
      if( (percentage>=skim) && (percentage<100.0) ) {
         skim += 5.0;
         cout << "Verifying the PROM: " << dec << uint16_t(percentage) << " percent done" << endl;
      }       
   }
   
   cout << "Verification completed" << endl;
   cout << "*******************************************************************" << endl;   
   return true;
}

//! Block Read of PROM (independent of .MCS file)
void CEEPromImpl::readProm (uint32_t address, uint32_t *data){
   uint32_t i;
   readCommand(address);
   for(i=0;i<64;i++){
      data[i] = data_[i];
   }
}

//! Erase Command
void CMicronN25QEEProm::eraseCommand(uint32_t address) {    
   // Set the address
   setAddr(address); 
   // Send the erase command      
   if(addr32BitMode_){   
      setCmd(WRITE_MASK|ERASE_CMD|0x4);     
   }else{
      setCmd(WRITE_MASK|ERASE_CMD|0x3);  
   }           
}


//! Write Command
void CMicronN25QEEProm::writeCommand(uint32_t address) {   
   setData();
   // Set the address
   setAddr(address); 
   // Send the write command      
   if(addr32BitMode_){   
      setCmd(WRITE_MASK|WRITE_4BYTE_CMD|0x104);     
   }else{
      setCmd(WRITE_MASK|WRITE_3BYTE_CMD|0x103);  
   }    
}

//! Read Command
void CMicronN25QEEProm::readCommand(uint32_t address) {  
   //Wait while the Flash is busy.
   waitForFlashReady();   
   
   // Set the address
   setAddr(address); 
   
   // Send the read command      
   if(addr32BitMode_){   
      setCmd(READ_MASK|READ_4BYTE_CMD|0x104);     
   }else{
      setCmd(READ_MASK|READ_3BYTE_CMD|0x103);  
   }          
   getData();
}

//! Reset the FLASH memory Command
void CMicronN25QEEProm::resetFlash ( ) {

   // Send the enable reset command
   setCmd(WRITE_MASK|ENABLE_RESET_CMD, false); 
   
   // Send the reset command
   setCmd(WRITE_MASK|RESET_CMD, false); 
   
   // Check the address mode
   if(addr32BitMode_){
      enter32BitMode();
      setAddr(DEFAULT_4BYTE_CONFIG<<16); 
      setCmd(WRITE_MASK|WRITE_NONVOLATILE_CONFIG|0x2);
      waitForFlashReady();      
      setCmd(WRITE_MASK|WRITE_VOLATILE_CONFIG|0x2);         
   } else {
      exit32BitMode();
      setAddr(DEFAULT_3BYTE_CONFIG<<8); 
      setCmd(WRITE_MASK|WRITE_NONVOLATILE_CONFIG|0x2);         
      waitForFlashReady();
      setCmd(WRITE_MASK|WRITE_VOLATILE_CONFIG|0x2);         
   }
}

//! Enable Write commands
void CMicronN25QEEProm::writeEnable ( ) {
   //Wait while the Flash is busy.
   waitForFlashReady();   
   
   // Enable Writes
   setCmd(WRITE_MASK|WRITE_ENABLE_CMD, false);
}

//! Disable Write commands
void CMicronN25QEEProm::writeDisable ( ) {
   //Wait while the Flash is busy.
   waitForFlashReady();   
   
   // Disable Writes
   setCmd(WRITE_MASK|WRITE_DISABLE_CMD, false); 
}

//! Wait for the FLASH memory to not be busy
void CMicronN25QEEProm::waitForFlashReady ( ) { 
	while((statusReg() & FLAG_STATUS_RDY) == 0);
}

//! Pull the status register
uint32_t CMicronN25QEEProm::statusReg ( ) {  
   setCmd(READ_MASK|FLAG_STATUS_REG|0x1); 
   return getCmd();
}

// Micron N25Q driven by slac axi firmware
class CAxiMicronN25QEEProm:  public CMicronN25QEEProm, public IEntryAdapt {
protected:
	ScalVal amodeReg_;
	ScalVal addrReg_;
	ScalVal cmdReg_;
	ScalVal dataReg_;

public:
	CAxiMicronN25QEEProm(Key &k, Path p, shared_ptr<const CAxiMicronN25QImpl> ie)
	: IEntryAdapt(k, p, ie),
      amodeReg_( IScalVal::create( p->findByName("addr32BitMode") ) ),
      addrReg_ ( IScalVal::create( p->findByName("ADDR") ) ),
      cmdReg_  ( IScalVal::create( p->findByName("CMD") ) ),
      dataReg_ ( IScalVal::create( p->findByName("DATA") ) )
	{
	}

protected:
	virtual void set32BitModeReg();
      
    //! Set the address register
    virtual void setAddr (uint32_t value);


    //! Set the command register
	virtual void setCmd (uint32_t value, bool writeEnable = true);

	virtual uint32_t getCmd();
      
    //! Send the data register
	virtual void setData ();

    //! Get the data register
	virtual void getData ();
};

void CAxiMicronN25QEEProm::set32BitModeReg()
{
   amodeReg_->setVal(addr32BitMode_ ? 1 : 0);
}


uint32_t CAxiMicronN25QEEProm::getCmd()
{
uint32_t v;
   cmdReg_->getVal( &v );
   return v;
}


//! Set the address register
void CAxiMicronN25QEEProm::setAddr (uint32_t value)
{
   addrReg_->setVal(value);
}

//! Set the command register
void CAxiMicronN25QEEProm::setCmd (uint32_t value, bool doWriteEnable) {
   // Check for write command and not write disable command
   if ( doWriteEnable && (value & WRITE_MASK) ){
      writeEnable(); 
   }
   // Send the command
   cmdReg_->setVal(value);
}

//! Set the data register
void CAxiMicronN25QEEProm::setData ()
{
   dataReg_->setVal(data_, sizeof(data_)/sizeof(data_[0]));
}

//! Get the data register
void CAxiMicronN25QEEProm::getData ()
{
   dataReg_->getVal(data_, sizeof(data_)/sizeof(data_[0]));
}

typedef shared_ptr<CAxiMicronN25QEEProm> AxiMicronN25QAdapt;

EEProm IEEProm::create(Path p)
{
EEProm rval;

  // check if the object referred to by 'p' actually supports
  // the desired interface:
  rval = IEntryAdapt::check_interface<AxiMicronN25QAdapt, AxiMicronN25QImpl>( p );

  return rval;
}
