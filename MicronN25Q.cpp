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

#include "MicronN25Q.h"

//! Enter 4-BYTE ADDRESS MODE Command
void CMicronN25QEEProm::enter32BitMode( ) {   
   // Send the enter command
   setCmd(OP_WRITE, ADDR_ENTER_CMD, 0);     
   set32BitModeReg();
}

//! Exit 4-BYTE ADDRESS MODE Command
void CMicronN25QEEProm::exit32BitMode( ) {   
   // Send the exit command
   setCmd(OP_WRITE, ADDR_EXIT_CMD, 0);      
   set32BitModeReg();
}

//! Set the non-volatile status register 
void CMicronN25QEEProm::setPromStatusReg(uint8_t value) {   
   if(addr32BitMode_){
      setAddr(((uint32_t)value)<<24); 
      setCmd(OP_WRITE, STATUS_REG_WR_CMD, 0x1);     
   } else {
      setAddr(((uint32_t)value)<<16); 
      setCmd(OP_WRITE, STATUS_REG_WR_CMD, 0x1);          
   }
   waitForFlashReady();    
}

uint8_t CMicronN25QEEProm::getPromStatusReg(){  
   waitForFlashReady();
   setCmd(OP_READ, STATUS_REG_RD_CMD, 0x1); 
   return (uint8_t)(getCmd() & 0xFF);
}

uint8_t CMicronN25QEEProm::getManufacturerId(){  
   waitForFlashReady();
   setCmd(OP_READ, DEV_ID_RD_CMD, 0x1); 
   return (uint8_t)(getCmd()&0xFF);       
}

uint8_t CMicronN25QEEProm::getManufacturerType(){  
   waitForFlashReady();
   setCmd(OP_READ, DEV_ID_RD_CMD, 0x2); 
   return (uint8_t)(getCmd()&0xFF);      
}        

uint8_t CMicronN25QEEProm::getManufacturerCapacity(){  
   waitForFlashReady();
   setCmd(OP_READ, DEV_ID_RD_CMD, 0x3); 
   return (uint8_t)(getCmd()&0xFF);      
}    


//! Erase Command
void CMicronN25QEEProm::eraseCommand(uint32_t address) {    
   // Set the address
   setAddr(address); 
   // Send the erase command      
   if(addr32BitMode_){   
      setCmd(OP_WRITE, ERASE_CMD, 0x4);     
   }else{
      setCmd(OP_WRITE, ERASE_CMD, 0x3);  
   }           
}

//! Write Command
void CMicronN25QEEProm::writeCommand(uint32_t address) {   
   setData();
   // Set the address
   setAddr(address); 
   // Send the write command      
   if(addr32BitMode_){   
      setCmd(OP_WRITE, WRITE_4BYTE_CMD, 0x104);     
   }else{
      setCmd(OP_WRITE, WRITE_3BYTE_CMD, 0x103);  
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
      setCmd(OP_READ, READ_4BYTE_CMD, 0x104);     
   }else{
      setCmd(OP_READ, READ_3BYTE_CMD, 0x103);  
   }          
   getData();
}

//! Reset the FLASH memory Command
void CMicronN25QEEProm::resetFlash ( ) {

   // Send the enable reset command
   setCmd(OP_WRITE, ENABLE_RESET_CMD, 0, false); 
   
   // Send the reset command
   setCmd(OP_WRITE, RESET_CMD, 0, false); 
   
   // Check the address mode
   if(addr32BitMode_){
      enter32BitMode();
      setAddr(DEFAULT_4BYTE_CONFIG<<16); 
      setCmd(OP_WRITE, WRITE_NONVOLATILE_CONFIG_CMD, 0x2);
      waitForFlashReady();      
      setCmd(OP_WRITE, WRITE_VOLATILE_CONFIG_CMD, 0x2);         
   } else {
      exit32BitMode();
      setAddr(DEFAULT_3BYTE_CONFIG<<8); 
      setCmd(OP_WRITE, WRITE_NONVOLATILE_CONFIG_CMD, 0x2);         
      waitForFlashReady();
      setCmd(OP_WRITE, WRITE_VOLATILE_CONFIG_CMD, 0x2);         
   }
}

//! Enable Write commands
void CMicronN25QEEProm::writeEnable ( ) {
   //Wait while the Flash is busy.
   waitForFlashReady();   
   
   // Enable Writes
   setCmd(OP_WRITE, WRITE_ENABLE_CMD, 0, false);
}

//! Disable Write commands
void CMicronN25QEEProm::writeDisable ( ) {
   //Wait while the Flash is busy.
   waitForFlashReady();   
   
   // Disable Writes
   setCmd(OP_WRITE, WRITE_DISABLE_CMD, 0, false); 
}

//! Wait for the FLASH memory to not be busy
void CMicronN25QEEProm::waitForFlashReady ( ) { 
	while((statusReg() & FLAG_STATUS_RDY) == 0);
}

//! Pull the status register
uint32_t CMicronN25QEEProm::statusReg ( ) {  
   setCmd(OP_READ, FLAG_STATUS_REG, 0x1); 
   return getCmd();
}
