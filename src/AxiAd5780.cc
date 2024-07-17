//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#include "AxiAd5780.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CAxiAd5780Impl;
typedef shared_ptr<CAxiAd5780Impl> AxiAd5780Impl;

class CAxiAd5780Impl : public CMMIODevImpl, public virtual IAxiAd5780B {
public:
    CAxiAd5780Impl(Key &key, const char* name);
};

AxiAd5780B IAxiAd5780B::create(const char *name)
{
AxiAd5780Impl v = CShObj::create<AxiAd5780Impl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "dacRefreshRate" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "dacData" );
    v->CMMIODevImpl::addAtAddress( f , 0x30*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "debugMux" );
    v->CMMIODevImpl::addAtAddress( f , 0x80*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "debugData" );
    v->CMMIODevImpl::addAtAddress( f , 0x90*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "sdoDisable" );
    v->CMMIODevImpl::addAtAddress( f , 0xA0*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "binaryOffset" );
    v->CMMIODevImpl::addAtAddress( f , 0xA1*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "dacTriState" );
    v->CMMIODevImpl::addAtAddress( f , 0xA2*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "opGnd" );
    v->CMMIODevImpl::addAtAddress( f , 0xA3*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "rbuf" );
    v->CMMIODevImpl::addAtAddress( f , 0xA4*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "halfSckPeriod" );
    v->CMMIODevImpl::addAtAddress( f , 0xA5*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "dacRst" );
    v->CMMIODevImpl::addAtAddress( f , 0xFE*addrSize);

    return v;
}

CAxiAd5780Impl::CAxiAd5780Impl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CAxiAd5780Adapt;
typedef shared_ptr<CAxiAd5780Adapt> AxiAd5780Adapt;

class CAxiAd5780Adapt : public IAxiAd5780, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CAxiAd5780Adapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */
/* Commands */
    virtual void dacRst();

};

CAxiAd5780Adapt::CAxiAd5780Adapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}


/* Commands */
void CAxiAd5780Adapt::dacRst()
{
    throw InternalError("CAxiAd5780Adapt::dacRst not implemented\n");
}

AxiAd5780 IAxiAd5780::create(Path p)
{
    AxiAd5780Adapt rval = IEntryAdapt::check_interface<AxiAd5780Adapt, AxiAd5780Impl>(p);
    return rval;
}

