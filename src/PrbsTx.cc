//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#include "PrbsTx.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CPrbsTxImpl;
typedef shared_ptr<CPrbsTxImpl> PrbsTxImpl;

class CPrbsTxImpl : public CMMIODevImpl, public virtual IPrbsTxB {
public:
    CPrbsTxImpl(Key &key, const char* name);
};

PrbsTxB IPrbsTxB::create(const char *name)
{
PrbsTxImpl v = CShObj::create<PrbsTxImpl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "ConfigStatus" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AxiEn" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "TxEn" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Busy" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Overflow" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "PacketLength" );
    v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AxiStreamCfg" );
    v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 8 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "tDest" );
    v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 8 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "tId" );
    v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "DataCount" );
    v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "EventCount" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RandomData" );
    v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);

    return v;
}

CPrbsTxImpl::CPrbsTxImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CPrbsTxAdapt;
typedef shared_ptr<CPrbsTxAdapt> PrbsTxAdapt;

class CPrbsTxAdapt : public IPrbsTx, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CPrbsTxAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */
/* Commands */
    virtual void OneShot();

};

CPrbsTxAdapt::CPrbsTxAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}


/* Commands */
void CPrbsTxAdapt::OneShot()
{
    throw InternalError("CPrbsTxAdapt::OneShot not implemented\n");
}

PrbsTx IPrbsTx::create(Path p)
{
    PrbsTxAdapt rval = IEntryAdapt::check_interface<PrbsTxAdapt, PrbsTxImpl>(p);
    return rval;
}

