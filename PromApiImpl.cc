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

#include <stdio.h>
#include <math.h>

#include <iostream>

#include "PromApiImpl.h"

using namespace std;

void CEEPromImpl::setFileReader(FileReader reader)
{
	reader_             = reader;
	FileDescriptor desc = reader_->open();
	progStartAddr_      = desc->getAddr();
    printf("Calculating PROM file (.mcs) Memory Address size ...");    
	progSize_           = desc->getSize();
    printf("PROM Size = 0x%08x\n", progSize_); 
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

void CEEPromImpl::eraseProm() {
uint32_t align_mask = ~(getEraseBlockSize() - 1);
uint32_t start_addr = progStartAddr_ & align_mask; // down-align to block addr
uint32_t end_addr   = (progStartAddr_ + progSize_ + getEraseBlockSize() - 1) & align_mask ; // up-align to block addr
	eraseProm( start_addr, end_addr - start_addr );
}

//! Erase the PROM
void CEEPromImpl::eraseProm (uint32_t startAddr, uint32_t eraseSize) {

   uint32_t address = startAddr;
   double size = double(eraseSize);
   double percentage;
   double skim = 5.0; 

   if ( (startAddr % getEraseBlockSize()) != 0 ) {
      throw InvalidArgError("eraseProm: startAddr must be multiple of erase block size");
   }
   if ( (eraseSize % getEraseBlockSize()) != 0 ) {
      throw InvalidArgError("eraseProm: eraseSize must be multiple of erase block size");
   }

   cout << "*******************************************************************" << endl;   
   cout << "Starting Erasing ..." << endl; 
   while(address < (startAddr+eraseSize)) {        
      /*
      // Print the status to screen
      cout << hex << "Erasing PROM from 0x" << address << " to 0x" << (address+getEraseBlockSize()-1);
      cout << setprecision(3) << " ( " << ((double(address))/size)*100 << " percent done )" << endl;      
      */
      
      // execute the erase command
      eraseCommand(address);
      
      //increment the address pointer
      address += getEraseBlockSize();
      
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

   FileDescriptor fileDesc;

   uint8_t data;
   
   uint32_t fileData;
   double size = double(progSize_);
   double percentage;
   double skim = 1.0;    
   uint32_t byteCnt = 0;    
   uint32_t wordCnt = 0;    
   uint32_t baseAddr = 0;
   uint32_t cnt     = 0;     

   //check for valid file path
   if ( ! reader_ ) {
      cout << "No FileReader set" << endl;
      return false;
   }
   try {
      fileDesc = reader_->open();
   } catch ( IFileReader::InvalidPathError ) {
      cout << "reader->open() = file path error" << endl;
      return false;
   }
   
   if(progSize_ == 0x0){
      cout << "Invalid progSize_: 0x0" << endl;
      return false;      
   }
   
   //read the entire mcs file
   while(cnt < progSize_) {
   
      //read a line of the mcs file
	  try {
		data = ++(*fileDesc);
	  } catch ( IFileDescriptor::ReadError ) {
         cout << "++(*fileDesc)(): = line read error" << endl;
         return false;
      } catch ( IFileDescriptor::EndOfFile ) {
         break;
      }
      
      if( (byteCnt==0) && (wordCnt==0) ) {
         baseAddr = fileDesc->getAddr();
      }
      if( byteCnt==0 ){
         fileData = ((uint32_t)(data&0xFF)) << (8*(3-byteCnt));
      }else{
         fileData |= ((uint32_t)(data&0xFF)) << (8*(3-byteCnt));
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
      
      percentage = (((double)(fileDesc->getAddr() - progStartAddr_))/size)*100;
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
   FileDescriptor fileDesc;

   uint8_t data;
   
   uint8_t promData,fileData;
   double size = double(progSize_);
   double percentage;
   double skim = 5.0; 
   uint32_t byteCnt = 0;    
   uint32_t wordCnt = 0;  
   uint32_t cnt     = 0;  

   //check for valid file path
   if ( ! reader_ ) {
      cout << "No FileReader set" << endl;
      return false;
   }
   try {
      fileDesc = reader_->open();
   } catch ( IFileReader::InvalidPathError ) {
      cout << "reader->open() = file path error" << endl;
      return false;
   }
 
   if(progSize_ == 0x0){
      cout << "Invalid progSize_: 0x0" << endl;
      return false;      
   }   
   
   //read the entire mcs file
   while(cnt < progSize_) {
   
      //read a line of the mcs file
      try {
         data = ++(*fileDesc);
      } catch ( IFileDescriptor::ReadError ) {
         cout << "++(*fileDesc)(): = line read error" << endl;
         return false;
      } catch ( IFileDescriptor::EndOfFile ) {
         break;
      }
      
      fileData = (uint8_t)(data & 0xFF);
      if( (byteCnt==0) && (wordCnt==0) ){ 
         readCommand(fileDesc->getAddr());
      }
      promData = (uint8_t)( (data_[wordCnt] >> 8*(3-byteCnt)) & 0xFF);
      cnt++;
      if(fileData != promData) {
         cout << "verifyProm error = ";
         cout << "invalid read back" <<  endl;
         cout << hex << "\taddress: 0x"  << fileDesc->getAddr() << endl;
         cout << hex << "\tfileData: 0x" << (uint32_t)fileData  << endl;
         cout << hex << "\tpromData: 0x" << (uint32_t)promData  << endl;
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
      
      percentage = (((double)(fileDesc->getAddr()-progStartAddr_))/size)*100;
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

CEEPromImpl::CreatorRegistrar::CreatorRegistrar()
:next_( getHead() )
{
	getHead() = this;
}

CEEPromImpl::CreatorRegistrar * &CEEPromImpl::CreatorRegistrar::getHead()
{
static CreatorRegistrar *theHead = 0;
	return theHead;
}

EEProm CEEPromImpl::CreatorRegistrar::create(Path p)
{
EEProm rval;
CreatorRegistrar *r = getHead();
	for ( r = getHead(); r; r = r->next_ ) {
		try {
			if ( (rval = r->creator( p )) )
				return rval;
		} catch ( InterfaceNotImplementedError ) {
		}
	}
	throw InterfaceNotImplementedError(p);
}

EEProm CEEPromImpl::create(Path p)
{
	return CEEPromImpl::CreatorRegistrar::create( p );
}

EEProm IEEProm::create(Path p)
{
	return CEEPromImpl::create( p );
}
