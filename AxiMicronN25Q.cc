#include "AxiMicronN25Q.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CAxiMicronN25QImpl;
typedef shared_ptr<CAxiMicronN25QImpl> AxiMicronN25QImpl;

class CAxiMicronN25QImpl : public CMMIODevImpl, public virtual IAxiMicronN25QB {
public:
    CAxiMicronN25QImpl(Key &key, const char* name);
};

AxiMicronN25QB IAxiMicronN25QB::create(const char *name)
{
AxiMicronN25QImpl v = CShObj::create<AxiMicronN25QImpl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "Test" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "addr32BitMode" );
    v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "ADDR" );
    v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "CMD" );
    v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DATA" );
    v->CMMIODevImpl::addAtAddress( f , 0x80*addrSize, 64);

    return v;
}

CAxiMicronN25QImpl::CAxiMicronN25QImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CAxiMicronN25QAdapt;
typedef shared_ptr<CAxiMicronN25QAdapt> AxiMicronN25QAdapt;

class CAxiMicronN25QAdapt : public IAxiMicronN25Q, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CAxiMicronN25QAdapt(Key &k, Path p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */

};

CAxiMicronN25QAdapt::CAxiMicronN25QAdapt(Key &k, Path p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}



AxiMicronN25Q IAxiMicronN25Q::create(Path p)
{
    AxiMicronN25QAdapt rval = IEntryAdapt::check_interface<AxiMicronN25QAdapt, AxiMicronN25QImpl>(p);
    return rval;
}

