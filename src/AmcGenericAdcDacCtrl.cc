//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#include "AmcGenericAdcDacCtrl.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CAmcGenericAdcDacCtrlImpl;
typedef shared_ptr<CAmcGenericAdcDacCtrlImpl> AmcGenericAdcDacCtrlImpl;

class CAmcGenericAdcDacCtrlImpl : public CMMIODevImpl, public virtual IAmcGenericAdcDacCtrlB {
public:
    CAmcGenericAdcDacCtrlImpl(Key &key, const char* name);
};

AmcGenericAdcDacCtrlB IAmcGenericAdcDacCtrlB::create(const char *name)
{
AmcGenericAdcDacCtrlImpl v = CShObj::create<AmcGenericAdcDacCtrlImpl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcValidCnt0" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcValidCnt1" );
    v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcValidCnt2" );
    v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcValidCnt3" );
    v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "DebugTrigCnt" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "StatusReg" );
    v->CMMIODevImpl::addAtAddress( f , 0x3F*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcValid0" );
    v->CMMIODevImpl::addAtAddress( f , 0x3F*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcValid1" );
    v->CMMIODevImpl::addAtAddress( f , 0x3F*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcValid2" );
    v->CMMIODevImpl::addAtAddress( f , 0x3F*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcValid3" );
    v->CMMIODevImpl::addAtAddress( f , 0x3F*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "DebugTrig" );
    v->CMMIODevImpl::addAtAddress( f , 0x3F*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcValue0" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcValue1" );
    v->CMMIODevImpl::addAtAddress( f , 0x41*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcValue2" );
    v->CMMIODevImpl::addAtAddress( f , 0x42*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcValue3" );
    v->CMMIODevImpl::addAtAddress( f , 0x43*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "DacValue0" );
    v->CMMIODevImpl::addAtAddress( f , 0x44*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "DacValue1" );
    v->CMMIODevImpl::addAtAddress( f , 0x45*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "DacVco" );
    v->CMMIODevImpl::addAtAddress( f , 0x7E*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AmcClkFreq" );
    v->CMMIODevImpl::addAtAddress( f , 0x7F*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 2 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkClkSel" );
    v->CMMIODevImpl::addAtAddress( f , 0x80*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkRst" );
    v->CMMIODevImpl::addAtAddress( f , 0x81*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkSync" );
    v->CMMIODevImpl::addAtAddress( f , 0x82*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 2 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "LmkStatus" );
    v->CMMIODevImpl::addAtAddress( f , 0x83*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "loopback" );
    v->CMMIODevImpl::addAtAddress( f , 0x84*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "CounterReset" );
    v->CMMIODevImpl::addAtAddress( f , 0xFF*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkMuxSel" );
    v->CMMIODevImpl::addAtAddress( f , 0x85*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "SoftTrig" );
    v->CMMIODevImpl::addAtAddress( f , 0x86*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "SoftClear" );
    v->CMMIODevImpl::addAtAddress( f , 0x87*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DacVcoSckConfig" );
    v->CMMIODevImpl::addAtAddress( f , 0x88*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DacVcoEnable" );
    v->CMMIODevImpl::addAtAddress( f , 0x89*addrSize);

    return v;
}

CAmcGenericAdcDacCtrlImpl::CAmcGenericAdcDacCtrlImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CAmcGenericAdcDacCtrlAdapt;
typedef shared_ptr<CAmcGenericAdcDacCtrlAdapt> AmcGenericAdcDacCtrlAdapt;

class CAmcGenericAdcDacCtrlAdapt : public IAmcGenericAdcDacCtrl, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CAmcGenericAdcDacCtrlAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */

};

CAmcGenericAdcDacCtrlAdapt::CAmcGenericAdcDacCtrlAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}



AmcGenericAdcDacCtrl IAmcGenericAdcDacCtrl::create(Path p)
{
    AmcGenericAdcDacCtrlAdapt rval = IEntryAdapt::check_interface<AmcGenericAdcDacCtrlAdapt, AmcGenericAdcDacCtrlImpl>(p);
    return rval;
}

