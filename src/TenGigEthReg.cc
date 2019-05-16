#include "TenGigEthReg.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CTenGigEthRegImpl;
typedef shared_ptr<CTenGigEthRegImpl> TenGigEthRegImpl;

class CTenGigEthRegImpl : public CMMIODevImpl, public virtual ITenGigEthRegB {
public:
    CTenGigEthRegImpl(Key &key, const char* name);
};

TenGigEthRegB ITenGigEthRegB::create(const char *name)
{
TenGigEthRegImpl v = CShObj::create<TenGigEthRegImpl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "PhyReadyCnt" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxPauseCnt" );
    v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxPauseCnt" );
    v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxCountEnCnt" );
    v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxOverFlowCnt" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxCrcErrorCnt" );
    v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxCountEnCnt" );
    v->CMMIODevImpl::addAtAddress( f , 0x06*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxUnderRunCnt" );
    v->CMMIODevImpl::addAtAddress( f , 0x07*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxNotReadyCnt" );
    v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxDisable" );
    v->CMMIODevImpl::addAtAddress( f , 0x09*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "SigDet" );
    v->CMMIODevImpl::addAtAddress( f , 0x0A*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxFault" );
    v->CMMIODevImpl::addAtAddress( f , 0x0B*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "GtTxRst" );
    v->CMMIODevImpl::addAtAddress( f , 0x0C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "GtRxRst" );
    v->CMMIODevImpl::addAtAddress( f , 0x0D*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RstCntDone" );
    v->CMMIODevImpl::addAtAddress( f , 0x0E*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Qplllock" );
    v->CMMIODevImpl::addAtAddress( f , 0x0F*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxRstdone" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxRstdone" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxUsrRdy" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Status" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_PhyReady" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_RxPause" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_TxPause" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_RxCountEn" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_RxOverFlow" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_RxCrcError" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 6 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_TxCountEn" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 7 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_TxUnderRun" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_TxNotReady" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 9 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_TxDisable" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 10 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_SigDet" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 11 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_TxFault" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 12 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_GtTxRst" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 13 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_GtRxRst" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 14 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_RstCntDone" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 15 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_Qplllock" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 16 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_TxRstdone" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 17 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_RxRstdone" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    bldr->reset();
    bldr->lsBit( 18 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "FLAG_TxUsrRdy" );
    v->CMMIODevImpl::addAtAddress( f , 0x40*addrSize);

    return v;
}

CTenGigEthRegImpl::CTenGigEthRegImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CTenGigEthRegAdapt;
typedef shared_ptr<CTenGigEthRegAdapt> TenGigEthRegAdapt;

class CTenGigEthRegAdapt : public ITenGigEthReg, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CTenGigEthRegAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */

};

CTenGigEthRegAdapt::CTenGigEthRegAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}



TenGigEthReg ITenGigEthReg::create(Path p)
{
    TenGigEthRegAdapt rval = IEntryAdapt::check_interface<TenGigEthRegAdapt, TenGigEthRegImpl>(p);
    return rval;
}

