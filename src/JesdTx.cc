#include "JesdTx.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CJesdTxImpl;
typedef shared_ptr<CJesdTxImpl> JesdTxImpl;

class CJesdTxImpl : public CMMIODevImpl, public virtual IJesdTxB {
public:
    CJesdTxImpl(Key &key, const char* name);
};

JesdTxB IJesdTxB::create(const char *name)
{
JesdTxImpl v = CShObj::create<JesdTxImpl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "Enable" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "CommonControl" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "SubClass" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "ReplaceEnable" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "ResetGTs" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "InvertSync" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "EnableTestSig" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "PeriodRampStep" );
    v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "RampStep" );
    v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);

    bldr->reset();
    bldr->lsBit( 16 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "SquarePeriod" );
    v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LowAmplitudeVal" );
    v->CMMIODevImpl::addAtAddress( f , 0x06*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "HighAmplitudeVal" );
    v->CMMIODevImpl::addAtAddress( f , 0x07*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_Status" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_GTXReady" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_DataValid" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_IlasActive" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_nSync" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_TxEnabled" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_SysRefDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_Status" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_GTXRdy" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_DataValid" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_IlasActive" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_nSync" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_TxEnabled" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_SysRefDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "L1_SignalSelect" );
    v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "L1_data_out_mux" );
    v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "L1_test_out_mux" );
    v->CMMIODevImpl::addAtAddress( f , 0x20*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "L2_SignalSelect" );
    v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "L2_data_out_mux" );
    v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "L2_test_out_mux" );
    v->CMMIODevImpl::addAtAddress( f , 0x21*addrSize);

    return v;
}

CJesdTxImpl::CJesdTxImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CJesdTxAdapt;
typedef shared_ptr<CJesdTxAdapt> JesdTxAdapt;

class CJesdTxAdapt : public IJesdTx, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CJesdTxAdapt(Key &k, Path p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */

};

CJesdTxAdapt::CJesdTxAdapt(Key &k, Path p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}



JesdTx IJesdTx::create(Path p)
{
    JesdTxAdapt rval = IEntryAdapt::check_interface<JesdTxAdapt, JesdTxImpl>(p);
    return rval;
}

