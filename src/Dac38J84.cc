#include "Dac38J84.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CDac38J84Impl;
typedef shared_ptr<CDac38J84Impl> Dac38J84Impl;

class CDac38J84Impl : public CMMIODevImpl, public virtual IDac38J84B {
public:
    CDac38J84Impl(Key &key, const char* name);
};

Dac38J84B IDac38J84B::create(const char *name)
{
Dac38J84Impl v = CShObj::create<Dac38J84Impl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "IntStatus" );
    v->CMMIODevImpl::addAtAddress( f , 0x07*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 5 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "LaneBufferDelay" );
    v->CMMIODevImpl::addAtAddress( f , 0x07*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 8 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Temperature" );
    v->CMMIODevImpl::addAtAddress( f , 0x07*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1ErrCnt" );
    v->CMMIODevImpl::addAtAddress( f , 0x41*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2ErrCnt" );
    v->CMMIODevImpl::addAtAddress( f , 0x42*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1SERDES_alarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1ReadFifoEmpty" );
    v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1ReadFifoUnderflow" );
    v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1ReadFifoFull" );
    v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1ReadFifoOverflow" );
    v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1DispErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);

    bldr->reset();
    bldr->lsBit( 9 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1NotitableErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);

    bldr->reset();
    bldr->lsBit( 10 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1CodeSyncErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);

    bldr->reset();
    bldr->lsBit( 11 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1FirstDataMatchErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);

    bldr->reset();
    bldr->lsBit( 12 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1ElasticBuffOverflow" );
    v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);

    bldr->reset();
    bldr->lsBit( 13 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1LinkConfigErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);

    bldr->reset();
    bldr->lsBit( 14 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1FrameAlignErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);

    bldr->reset();
    bldr->lsBit( 15 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1MultiFrameAlignErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x64*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2SERDES_alarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2ReadFifoEmpty" );
    v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2ReadFifoUnderflow" );
    v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2ReadFifoFull" );
    v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2ReadFifoOverflow" );
    v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2DispErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);

    bldr->reset();
    bldr->lsBit( 9 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2NotitableErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);

    bldr->reset();
    bldr->lsBit( 10 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2CodeSyncErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);

    bldr->reset();
    bldr->lsBit( 11 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2FirstDataMatchErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);

    bldr->reset();
    bldr->lsBit( 12 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2ElasticBuffOverflow" );
    v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);

    bldr->reset();
    bldr->lsBit( 13 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2LinkConfigErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);

    bldr->reset();
    bldr->lsBit( 14 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2FrameAlignErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);

    bldr->reset();
    bldr->lsBit( 15 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2MultiFrameAlignErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x65*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3SERDES_alarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x66*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4SERDES_alarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x67*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5SERDES_alarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x68*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6SERDES_alarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x69*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L7SERDES_alarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x6A*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L8SERDES_alarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x6B*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Sysref_alarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Serdes1pllAlarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Serdes0pllAlarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);

    bldr->reset();
    bldr->lsBit( 12 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "SysRefAlarms" );
    v->CMMIODevImpl::addAtAddress( f , 0x6C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Lane_alarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x6D*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Lane1Loss" );
    v->CMMIODevImpl::addAtAddress( f , 0x6D*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Lane2Loss" );
    v->CMMIODevImpl::addAtAddress( f , 0x6D*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Lane1Alarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x6D*addrSize);

    bldr->reset();
    bldr->lsBit( 9 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Lane2Alarm" );
    v->CMMIODevImpl::addAtAddress( f , 0x6D*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "IDs" );
    v->CMMIODevImpl::addAtAddress( f , 0x7F*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DacReg0x0000" );
    v->CMMIODevImpl::addAtAddress( f , 0x0000*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DacReg0x0001" );
    v->CMMIODevImpl::addAtAddress( f , 0x0001*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DacReg0x0002" );
    v->CMMIODevImpl::addAtAddress( f , 0x0002*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DacReg0x0003" );
    v->CMMIODevImpl::addAtAddress( f , 0x0003*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DacReg0x0004" );
    v->CMMIODevImpl::addAtAddress( f , 0x0004*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DacReg0x0005" );
    v->CMMIODevImpl::addAtAddress( f , 0x0005*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "DacReg0x0006" );
    v->CMMIODevImpl::addAtAddress( f , 0x0006*addrSize);

    return v;
}

CDac38J84Impl::CDac38J84Impl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CDac38J84Adapt;
typedef shared_ptr<CDac38J84Adapt> Dac38J84Adapt;

class CDac38J84Adapt : public IDac38J84, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CDac38J84Adapt(Key &k, Path p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */
/* Commands */
    virtual void ClearDACAlarms();
    virtual void InitDAC_JESD();

};

CDac38J84Adapt::CDac38J84Adapt(Key &k, Path p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}


/* Commands */
void CDac38J84Adapt::ClearDACAlarms()
{
    throw InternalError("CDac38J84Adapt::ClearDACAlarms not implemented\n");
}
void CDac38J84Adapt::InitDAC_JESD()
{
    throw InternalError("CDac38J84Adapt::InitDAC_JESD not implemented\n");
}

Dac38J84 IDac38J84::create(Path p)
{
    Dac38J84Adapt rval = IEntryAdapt::check_interface<Dac38J84Adapt, Dac38J84Impl>(p);
    return rval;
}

