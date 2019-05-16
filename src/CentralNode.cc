#include "CentralNode.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CCentralNodeImpl;
typedef shared_ptr<CCentralNodeImpl> CentralNodeImpl;

class CCentralNodeImpl : public CMMIODevImpl, public virtual ICentralNodeB {
public:
    CCentralNodeImpl(Key &key, const char* name);
};

CentralNodeB ICentralNodeB::create(const char *name)
{
CentralNodeImpl v = CShObj::create<CentralNodeImpl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "CounterReset" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "MsgErrCounter" );
    v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "MsgOverflowCounter" );
    v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DigitalInputMask0" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DigitalInputMask1" );
    v->CMMIODevImpl::addAtAddress( f , 0x41*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DigitalInputMask2" );
    v->CMMIODevImpl::addAtAddress( f , 0x42*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "ForceMitMsgEn" );
    v->CMMIODevImpl::addAtAddress( f , 0x44*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 8 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "ForceMitMsgVal" );
    v->CMMIODevImpl::addAtAddress( f , 0x45*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "DigitalInputState0" );
    v->CMMIODevImpl::addAtAddress( f , 0x80*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "DigitalInputState1" );
    v->CMMIODevImpl::addAtAddress( f , 0x81*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "DigitalInputState2" );
    v->CMMIODevImpl::addAtAddress( f , 0x82*addrSize);

    return v;
}

CCentralNodeImpl::CCentralNodeImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CCentralNodeAdapt;
typedef shared_ptr<CCentralNodeAdapt> CentralNodeAdapt;

class CCentralNodeAdapt : public ICentralNode, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CCentralNodeAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */
/* Commands */
    virtual void CounterReset();

};

CCentralNodeAdapt::CCentralNodeAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}


/* Commands */
void CCentralNodeAdapt::CounterReset()
{
    throw InternalError("CCentralNodeAdapt::CounterReset not implemented\n");
}

CentralNode ICentralNode::create(Path p)
{
    CentralNodeAdapt rval = IEntryAdapt::check_interface<CentralNodeAdapt, CentralNodeImpl>(p);
    return rval;
}

