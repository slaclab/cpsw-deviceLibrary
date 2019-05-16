#include "JesdRxDaq.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CJesdRxDaqImpl;
typedef shared_ptr<CJesdRxDaqImpl> JesdRxDaqImpl;

class CJesdRxDaqImpl : public CMMIODevImpl, public virtual IJesdRxDaqB {
public:
    CJesdRxDaqImpl(Key &key, const char* name);
};

JesdRxDaqB IJesdRxDaqB::create(const char *name)
{
JesdRxDaqImpl v = CShObj::create<JesdRxDaqImpl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "SwDaqTrigger" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 0 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "SwDaqTrigger0" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "SampleDecimation" );
    v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DaqBufferSize" );
    v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "S1ChannelSelect" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "S2ChannelSelect" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "StatusStream0" );
    v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Pause0" );
    v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Idle0" );
    v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Overflow0" );
    v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Error0" );
    v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "JESDValid0" );
    v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Enable0" );
    v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);

    bldr->reset();
    bldr->lsBit( 16 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "PacketCnt0" );
    v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "StatusStream1" );
    v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Pause1" );
    v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Idle1" );
    v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Overflow1" );
    v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Error1" );
    v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "JESDValid1" );
    v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Enable1" );
    v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);

    bldr->reset();
    bldr->lsBit( 16 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "PacketCnt1" );
    v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);

    return v;
}

CJesdRxDaqImpl::CJesdRxDaqImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CJesdRxDaqAdapt;
typedef shared_ptr<CJesdRxDaqAdapt> JesdRxDaqAdapt;

class CJesdRxDaqAdapt : public IJesdRxDaq, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CJesdRxDaqAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */
/* Commands */
    virtual void TriggerDAQ();

};

CJesdRxDaqAdapt::CJesdRxDaqAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}


/* Commands */
void CJesdRxDaqAdapt::TriggerDAQ()
{
    throw InternalError("CJesdRxDaqAdapt::TriggerDAQ not implemented\n");
}

JesdRxDaq IJesdRxDaq::create(Path p)
{
    JesdRxDaqAdapt rval = IEntryAdapt::check_interface<JesdRxDaqAdapt, JesdRxDaqImpl>(p);
    return rval;
}

