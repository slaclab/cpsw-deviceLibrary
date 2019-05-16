#include "RingBuffer.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CRingBufferImpl;
typedef shared_ptr<CRingBufferImpl> RingBufferImpl;

class CRingBufferImpl : public CMMIODevImpl, public virtual IRingBufferB {
public:
    CRingBufferImpl(Key &key, const char* name);
};

RingBufferB IRingBufferB::create(const char *name)
{
RingBufferImpl v = CShObj::create<RingBufferImpl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "WaveformSize" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 20 );
    bldr->sizeBits( 8 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RAM_ADDR_WIDTH_G" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 28 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ExtdataLogClr" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 29 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ExtDataLogEn" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 30 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "IntdataLogClr" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 31 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "IntDataLogEn" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Reg0x0000" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RingBuffer" );
    v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize, 2046);

    return v;
}

CRingBufferImpl::CRingBufferImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CRingBufferAdapt;
typedef shared_ptr<CRingBufferAdapt> RingBufferAdapt;

class CRingBufferAdapt : public IRingBuffer, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CRingBufferAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */

};

CRingBufferAdapt::CRingBufferAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}



RingBuffer IRingBuffer::create(Path p)
{
    RingBufferAdapt rval = IEntryAdapt::check_interface<RingBufferAdapt, RingBufferImpl>(p);
    return rval;
}

