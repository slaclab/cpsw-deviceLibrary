#ifndef _AXIMICRONN25Q_H
#define _AXIMICRONN25Q_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiMicronN25Q
class   IAxiMicronN25QB;
typedef shared_ptr<IAxiMicronN25QB> AxiMicronN25QB;


class IAxiMicronN25QB : public virtual IMMIODev {
public:
    static AxiMicronN25QB create(const char *name);
};

class IAxiMicronN25Q;
typedef shared_ptr<IAxiMicronN25Q> AxiMicronN25Q;

class IAxiMicronN25Q : public virtual IEntry {
public:
    static AxiMicronN25Q create(Path p);
public:
};

#endif

=======
//-----------------------------------------------------------------------------
// File          : AxiMicronN25Q.h
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
// 02/08/2016: cpsw port
//-----------------------------------------------------------------------------

#ifndef __AXI_MICRON_N25Q_H__
#define __AXI_MICRON_N25Q_H__

#include <stdint.h>
#include <string.h>

#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

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

// builder interface for axi micron N25Q eeprom
class IAxiMicronN25Q;
typedef shared_ptr<IAxiMicronN25Q> AxiMicronN25Q;

class IAxiMicronN25Q : public virtual IField {
public:

	virtual ~IAxiMicronN25Q() {}

	static AxiMicronN25Q create(const char *name);
};

#include <cpsw_mmio_dev.h>

class CAxiMicronN25QImpl : public IAxiMicronN25Q, public CMMIODevImpl {
public:
	CAxiMicronN25QImpl(Key &k, const char *name)
	: CMMIODevImpl(k, name, 0xC0 << 2, LE)
	{
	}
protected:
	CAxiMicronN25QImpl(CAxiMicronN25QImpl &orig, Key &k)
	: CMMIODevImpl(orig, k)
	{
	}

	virtual CAxiMicronN25QImpl *clone(Key &k) { return new CAxiMicronN25QImpl( *this, k ); }
};

typedef shared_ptr<CAxiMicronN25QImpl> AxiMicronN25QImpl;

#endif
