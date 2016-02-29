#include "MitigationNode.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CMitigationNodeImpl;
typedef shared_ptr<CMitigationNodeImpl> MitigationNodeImpl;

class CMitigationNodeImpl : public CMMIODevImpl, public virtual IMitigationNodeB {
public:
    CMitigationNodeImpl(Key &key, const char* name);
};

MitigationNodeB IMitigationNodeB::create(const char *name)
{
MitigationNodeImpl v = CShObj::create<MitigationNodeImpl>(name);
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
    bldr->sizeBits( 8 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "MitigationMsgRcvd" );
    v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);

    return v;
}

CMitigationNodeImpl::CMitigationNodeImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CMitigationNodeAdapt;
typedef shared_ptr<CMitigationNodeAdapt> MitigationNodeAdapt;

class CMitigationNodeAdapt : public IMitigationNode, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CMitigationNodeAdapt(Key &k, Path p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */
/* Commands */
    virtual void CounterReset();

};

CMitigationNodeAdapt::CMitigationNodeAdapt(Key &k, Path p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}


/* Commands */
void CMitigationNodeAdapt::CounterReset()
{
    throw InternalError("CMitigationNodeAdapt::CounterReset not implemented\n");
}

MitigationNode IMitigationNode::create(Path p)
{
    MitigationNodeAdapt rval = IEntryAdapt::check_interface<MitigationNodeAdapt, MitigationNodeImpl>(p);
    return rval;
}

