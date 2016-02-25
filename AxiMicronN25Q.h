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

// public user interface

class IEEProm;
typedef shared_ptr<IEEProm> EEProm;

class IEEProm : public virtual IEntry {
   public:
      virtual void setPromSize (uint32_t promSize);
      
      virtual uint32_t getPromSize (string pathToFile); 
      
      virtual void setFilePath (string pathToFile);
      
      virtual void setAddr32BitMode (bool addr32BitMode);
      
      virtual void setPromStatusReg(uint8_t value);  
      
      virtual uint8_t getPromStatusReg();    
      
      virtual uint8_t getManufacturerId();      
      
      virtual uint8_t getManufacturerType();        
      
      virtual uint8_t getManufacturerCapacity();        
      
      //! Erase the PROM
      virtual void eraseProm (uint32_t startAddr, uint32_t endAddr);

      //! Write the .mcs file to the PROM
      virtual bool writeProm ( ); 
      
      //! Compare the .mcs file with the PROM
      virtual bool verifyProm ( ); 
      
      //! Print Reminder
      virtual void rebootReminder ( bool pwrCycleReq );      
   
      //! Block Read of PROM (independent of .MCS file)
      virtual void readProm (uint32_t address, uint32_t *data);      
   
      virtual ~IEEProm ( ) {};

      static EEProm create(Path p);
};

// builder interface for axi micron N25Q eeprom
class IAxiMicronN25Q;
typedef shared_ptr<IAxiMicronN25Q> AxiMicronN25Q;

class IAxiMicronN25Q : public virtual IEntry {
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

AxiMicronN25Q IAxiMicronN25Q::create(const char *name)
{
AxiMicronN25QImpl v = CShObj::create<AxiMicronN25QImpl>(name);
Field f;
	f = IIntField::create("addr32BitMode", 32);
	v->addAtAddress( f, 0x04 );
	f = IIntField::create("ADDR",          32);
	v->addAtAddress( f, 0x08 );
	f = IIntField::create("CMD",           32);
	v->addAtAddress( f, 0x0C );
	f = IIntField::create("DATA",          32);
	v->addAtAddress( f, 0x80, 64 );
	return v;
}

#endif
