#include "AxiVersion.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CAxiVersionImpl;
typedef shared_ptr<CAxiVersionImpl> AxiVersionImpl;

class CAxiVersionImpl : public CMMIODevImpl, public virtual IAxiVersionB {
public:
    CAxiVersionImpl(Key &key, const char* name);
};

AxiVersionB IAxiVersionB::create(const char *name)
{
AxiVersionImpl v = CShObj::create<AxiVersionImpl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FpgaVersion" );
    f->setDescription( "FPGA Firmware Version Number" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "ScratchPad" );
    f->setDescription( "Register to test reads and writes" );
    v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "DeviceDnaHigh" );
    f->setDescription( "Xilinx Device DNA value burned into FPGA" );
    v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "DeviceDnaLow" );
    f->setDescription( "Xilinx Device DNA value burned into FPGA" );
    v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FdSerialHigh" );
    f->setDescription( "Board ID value read from DS2411 chip" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FdSerialLow" );
    f->setDescription( "Board ID value read from DS2411 chip" );
    v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "MasterReset" );
    f->setDescription( "" );
    v->CMMIODevImpl::addAtAddress( f , 0x06*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "FpgaReload" );
    f->setDescription( "" );
    v->CMMIODevImpl::addAtAddress( f , 0x07*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "FpgaReloadAddress" );
    f->setDescription( "" );
    v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Counter" );
    f->setDescription( "" );
    v->CMMIODevImpl::addAtAddress( f , 0x09*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "FpgaReloadHalt" );
    f->setDescription( "" );
    v->CMMIODevImpl::addAtAddress( f , 0x0A*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "UserConstants" );
    f->setDescription( "" );
    v->CMMIODevImpl::addAtAddress( f , 0x100*addrSize, 64);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 8 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "BuildStamp" );
    f->setDescription( "Firmware Build String" );
    v->CMMIODevImpl::addAtAddress( f , 0x200*addrSize, 64);

    return v;
}

CAxiVersionImpl::CAxiVersionImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CAxiVersionAdapt;
typedef shared_ptr<CAxiVersionAdapt> AxiVersionAdapt;

class CAxiVersionAdapt : public IAxiVersion, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CAxiVersionAdapt(Key &k, Path p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */
/* Commands */
    virtual void MasterReset();
    virtual void FpgaReload();
    virtual void CounterReset();

};

CAxiVersionAdapt::CAxiVersionAdapt(Key &k, Path p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}


/* Commands */
void CAxiVersionAdapt::MasterReset()
{
    throw InternalError("CAxiVersionAdapt::MasterReset not implemented\n");
}
void CAxiVersionAdapt::FpgaReload()
{
    throw InternalError("CAxiVersionAdapt::FpgaReload not implemented\n");
}
void CAxiVersionAdapt::CounterReset()
{
    throw InternalError("CAxiVersionAdapt::CounterReset not implemented\n");
}

AxiVersion IAxiVersion::create(Path p)
{
    AxiVersionAdapt rval = IEntryAdapt::check_interface<AxiVersionAdapt, AxiVersionImpl>(p);
    return rval;
}

