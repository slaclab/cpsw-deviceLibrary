//-----------------------------------------------------------------------------
// File          : CMicronN25QEEProm.cpp
// Author        : Larry Ruckman  <ruckman@slac.stanford.edu>
// Created       : 03/19/2014
// Project       :  
//-----------------------------------------------------------------------------
// Description :
//    Axi Micron N25Q and Micron MT25Q PROM C++ Class
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
#include "AxiMicronN25Q.h"
#include <cpsw_entry_adapt.h>

using namespace std;

#define CMD_OFFSET 16

#define READ_MASK   0x00000000 
#define WRITE_MASK  0x80000000 
#define VERIFY_MASK 0x40000000 

#include <cpsw_mmio_dev.h>

class CAxiMicronN25QImpl;
typedef shared_ptr<CAxiMicronN25QImpl> AxiMicronN25QImpl;

class CAxiMicronN25QEEProm;
typedef shared_ptr<CAxiMicronN25QEEProm> AxiMicronN25QAdapt;

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

public:

	CAxiMicronN25QImpl(Key &k, YamlState &ypath)
	: CMMIODevImpl( k, ypath )
	{
	}

	virtual void dumpYamlPart(YAML::Node &node) const
	{
		CMMIODevImpl::dumpYamlPart( node );
	}

	static const char *_getClassName() { return "AxiMicronN25Q"; }

	virtual const char *getClassName() const { return _getClassName(); }

};


// Micron N25Q driven by slac axi firmware.
// This class implements SPI operations via access to firmware
// registers. The registers are manipulated via CPSW.

class CAxiMicronN25QEEProm:  public CMicronN25QEEProm, public IEntryAdapt {
protected:
	ScalVal amodeReg_;
	ScalVal addrReg_;
	ScalVal cmdReg_;
	ScalVal dataReg_;

public:
	CAxiMicronN25QEEProm(Key &k, Path p, shared_ptr<const CAxiMicronN25QImpl> ie)
	: IEntryAdapt(k, p, ie),
      amodeReg_( IScalVal::create( p->findByName("Addr32BitMode") ) ),
      addrReg_ ( IScalVal::create( p->findByName("Addr") ) ),
      cmdReg_  ( IScalVal::create( p->findByName("Cmd") ) ),
      dataReg_ ( IScalVal::create( p->findByName("Data") ) )
	{
	}

protected:
	virtual void set32BitModeReg();
      
    //! Set the address register
    virtual void setAddr (uint32_t value);


    //! Set the command register
	virtual void setCmd (OP op, uint8_t cmd, uint16_t extra, bool writeEnable = true);

	virtual uint32_t getCmd();
      
    //! Send the data register
	virtual void setData ();

    //! Get the data register
	virtual void getData ();

	class CreatorRegistrar : protected CEEPromImpl::CreatorRegistrar {
	public:
		virtual EEProm creator(Path);
	};

	// This object registers our implementation with the interface
	static CreatorRegistrar axiMicronN25QEEPromDriver;
};

void CAxiMicronN25QEEProm::set32BitModeReg()
{
   amodeReg_->setVal(addr32BitMode_ ? 1 : 0);
}

uint32_t CAxiMicronN25QEEProm::getCmd() {
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
void CAxiMicronN25QEEProm::setCmd (OP op, uint8_t cmd, uint16_t extra, bool doWriteEnable) {

uint32_t value = OP_WRITE == op ? WRITE_MASK : READ_MASK;

	value |= (cmd << CMD_OFFSET) | extra;

   // Check for write command and not write disable command
   if ( doWriteEnable && OP_WRITE == op ){
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

EEProm CAxiMicronN25QEEProm::CreatorRegistrar::creator(Path p)
{
  // check if the object referred to by 'p' actually supports
  // the desired interface:
  EEProm rval = IEntryAdapt::check_interface<AxiMicronN25QAdapt, AxiMicronN25QImpl>( p );

  return rval;
}

// Builder factory method
AxiMicronN25Q IAxiMicronN25Q::create(const char *name)
{
AxiMicronN25QImpl v = CShObj::create<AxiMicronN25QImpl>(name);
Field f;
	f = IIntField::create("Addr32BitMode", 32);
	v->addAtAddress( f,  0x04 );
	f = IIntField::create("Addr",          32);
	v->addAtAddress( f,  0x08 );
	f = IIntField::create("Cmd",           32);
	v->addAtAddress( f,  0x0C );
	f = IIntField::create("Data",          32);
	v->addAtAddress( f, 0x200, 64 );
	return v;
}

// Instantiation of this object registers this implementation
CAxiMicronN25QEEProm::CreatorRegistrar CAxiMicronN25QEEProm::axiMicronN25QEEPromDriver;
