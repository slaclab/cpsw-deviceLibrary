//-----------------------------------------------------------------------------
// File          : EEPromApiUser.h
// Author        : Till Straumann <strauman@slac.stanford.edu>
// Created       : 02/20/2016
// Project       :  
//-----------------------------------------------------------------------------
// Description :
//    Generic EEPROM Programmer Interface
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
// 02/08/2016: cpsw port
//-----------------------------------------------------------------------------

#ifndef PROM_API_USER_H
#define PROM_API_USER_H

#include <stdint.h>

#include <cpsw_api_user.h>

#include <PromFileReader.h>

// public user interface

class IEEProm;
typedef shared_ptr<IEEProm> EEProm;

class IEEProm : public virtual IEntry {
   public:
      virtual void setFileReader(FileReader)             = 0;
      
      virtual void setAddr32BitMode (bool addr32BitMode) = 0;
      
      virtual void setPromStatusReg(uint8_t value)       = 0;  
      
      virtual uint8_t getPromStatusReg()                 = 0;    
      
      virtual uint8_t getManufacturerId()                = 0;      
      
      virtual uint8_t getManufacturerType()              = 0;        
      
      virtual uint8_t getManufacturerCapacity()          = 0;        

	  virtual unsigned getEraseBlockSize()               = 0;
      
      //! Erase the PROM

	  virtual void eraseProm ()                          = 0;

      //! Write the .mcs file to the PROM
      virtual bool writeProm ( )                         = 0; 
      
      //! Compare the .mcs file with the PROM
      virtual bool verifyProm ( )                        = 0; 
      
      //! Print Reminder
      virtual void rebootReminder ( bool pwrCycleReq )   = 0;
   
      //! Block Read of PROM (independent of .MCS file)
      virtual void readProm (uint32_t address, uint32_t *data) = 0;      
   
      virtual ~IEEProm ( ) {};


      static EEProm create(Path p);

      class InvalidFileReader {};
};

#endif
