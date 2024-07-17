//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#include "Adc16Dx370.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CAdc16Dx370Impl;
typedef shared_ptr<CAdc16Dx370Impl> Adc16Dx370Impl;

class CAdc16Dx370Impl : public CMMIODevImpl, public virtual IAdc16Dx370B {
public:
    CAdc16Dx370Impl(Key &key, const char* name);
};

Adc16Dx370B IAdc16Dx370B::create(const char *name)
{
Adc16Dx370Impl v = CShObj::create<Adc16Dx370Impl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ID_DEVICE_TYPE" );
    v->CMMIODevImpl::addAtAddress( f , 0x003*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 2 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "PD_MODE" );
    v->CMMIODevImpl::addAtAddress( f , 0x002*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ID_PROD_UPPER" );
    v->CMMIODevImpl::addAtAddress( f , 0x004*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ID_PROD_LOWER" );
    v->CMMIODevImpl::addAtAddress( f , 0x005*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ID_MASKREV" );
    v->CMMIODevImpl::addAtAddress( f , 0x006*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ID_VNDR_UPPER" );
    v->CMMIODevImpl::addAtAddress( f , 0x00C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ID_VNDR_LOWER" );
    v->CMMIODevImpl::addAtAddress( f , 0x00D*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ADC_Status" );
    v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Clock_ready" );
    v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Calibration_done" );
    v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "PLL_lock" );
    v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Aligned_to_sysref" );
    v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Realigned_to_sysref" );
    v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Sync_form_FPGA" );
    v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);

    bldr->reset();
    bldr->lsBit( 6 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Link_active" );
    v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "SYS_EN" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0000" );
    v->CMMIODevImpl::addAtAddress( f , 0x0000*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0002" );
    v->CMMIODevImpl::addAtAddress( f , 0x0002*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0003" );
    v->CMMIODevImpl::addAtAddress( f , 0x0003*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0004" );
    v->CMMIODevImpl::addAtAddress( f , 0x0004*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0005" );
    v->CMMIODevImpl::addAtAddress( f , 0x0005*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0006" );
    v->CMMIODevImpl::addAtAddress( f , 0x0006*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x000c" );
    v->CMMIODevImpl::addAtAddress( f , 0x000c*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x000d" );
    v->CMMIODevImpl::addAtAddress( f , 0x000d*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0010" );
    v->CMMIODevImpl::addAtAddress( f , 0x0010*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0012" );
    v->CMMIODevImpl::addAtAddress( f , 0x0012*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0013" );
    v->CMMIODevImpl::addAtAddress( f , 0x0013*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0014" );
    v->CMMIODevImpl::addAtAddress( f , 0x0014*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0015" );
    v->CMMIODevImpl::addAtAddress( f , 0x0015*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0019" );
    v->CMMIODevImpl::addAtAddress( f , 0x0019*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x003b" );
    v->CMMIODevImpl::addAtAddress( f , 0x003b*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x003c" );
    v->CMMIODevImpl::addAtAddress( f , 0x003c*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x003d" );
    v->CMMIODevImpl::addAtAddress( f , 0x003d*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0047" );
    v->CMMIODevImpl::addAtAddress( f , 0x0047*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0060" );
    v->CMMIODevImpl::addAtAddress( f , 0x0060*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0061" );
    v->CMMIODevImpl::addAtAddress( f , 0x0061*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0062" );
    v->CMMIODevImpl::addAtAddress( f , 0x0062*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0063" );
    v->CMMIODevImpl::addAtAddress( f , 0x0063*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AdcReg0x0070" );
    v->CMMIODevImpl::addAtAddress( f , 0x0070*addrSize);

    return v;
}

CAdc16Dx370Impl::CAdc16Dx370Impl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CAdc16Dx370Adapt;
typedef shared_ptr<CAdc16Dx370Adapt> Adc16Dx370Adapt;

class CAdc16Dx370Adapt : public IAdc16Dx370, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CAdc16Dx370Adapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */
/* Commands */
    virtual void CalibrateADC();

};

CAdc16Dx370Adapt::CAdc16Dx370Adapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}


/* Commands */
void CAdc16Dx370Adapt::CalibrateADC()
{
    throw InternalError("CAdc16Dx370Adapt::CalibrateADC not implemented\n");
}

Adc16Dx370 IAdc16Dx370::create(Path p)
{
    Adc16Dx370Adapt rval = IEntryAdapt::check_interface<Adc16Dx370Adapt, Adc16Dx370Impl>(p);
    return rval;
}

