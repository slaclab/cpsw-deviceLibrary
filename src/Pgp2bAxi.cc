//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#include "Pgp2bAxi.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CPgp2bAxiImpl;
typedef shared_ptr<CPgp2bAxiImpl> Pgp2bAxiImpl;

class CPgp2bAxiImpl : public CMMIODevImpl, public virtual IPgp2bAxiB {
public:
    CPgp2bAxiImpl(Key &key, const char* name);
};

Pgp2bAxiB IPgp2bAxiB::create(const char *name)
{
Pgp2bAxiImpl v = CShObj::create<Pgp2bAxiImpl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "CountReset" );
    v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "ResetRx" );
    v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "Flush" );
    v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "Loopback" );
    f->setDescription( "Controls the GT loopback mode" );
    v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 8 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LocData" );
    f->setDescription( "Sideband data to transmit" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LocDataEn" );
    f->setDescription( "Enable Sideband data to transmit" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "AutoStatus" );
    f->setDescription( "Auto Status Send Enable (PPI)" );
    v->CMMIODevImpl::addAtAddress( f , 0x05*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Status" );
    v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxPhyReady" );
    f->setDescription( "RX Phy Is ready" );
    v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxPhyReady" );
    f->setDescription( "TX Phy Is ready" );
    v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxLocalLinkReady" );
    f->setDescription( "RX Local Link Ready" );
    v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxRemLinkReady" );
    f->setDescription( "RX Remote Link Ready" );
    v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxLinkReady" );
    f->setDescription( "Tx Link Ready" );
    v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 2 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxLinkPolarity" );
    f->setDescription( "Rx Link Polarity" );
    v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);

    bldr->reset();
    bldr->lsBit( 12 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxRemPause" );
    f->setDescription( "Rx Remote Pause Is Asserted" );
    v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);

    bldr->reset();
    bldr->lsBit( 16 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxLocPause" );
    f->setDescription( "Tx Local Pause Is Asserted" );
    v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);

    bldr->reset();
    bldr->lsBit( 20 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxRemOverflow" );
    f->setDescription( "Rx remote overflow flag" );
    v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);

    bldr->reset();
    bldr->lsBit( 24 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxLocOverflow" );
    f->setDescription( "Transmit local overflow flag" );
    v->CMMIODevImpl::addAtAddress( f , 0x08*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxRemLinkData" );
    f->setDescription( "Link data received from remote link" );
    v->CMMIODevImpl::addAtAddress( f , 0x09*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxCellErrorCount" );
    f->setDescription( "Receive Cell Error Count" );
    v->CMMIODevImpl::addAtAddress( f , 0x0A*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxLinkDownCount" );
    f->setDescription( "Receive Link Down Count" );
    v->CMMIODevImpl::addAtAddress( f , 0x0B*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxLinkErrorCount" );
    f->setDescription( "Receive Link Error Count" );
    v->CMMIODevImpl::addAtAddress( f , 0x0C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxRemOverflow0Count" );
    f->setDescription( "Receive Remote Overflow VC 0 Counter" );
    v->CMMIODevImpl::addAtAddress( f , 0x0D*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxRemOverflow1Count" );
    f->setDescription( "Receive Remote Overflow VC 1 Counter" );
    v->CMMIODevImpl::addAtAddress( f , 0x0E*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxRemOverflow2Count" );
    f->setDescription( "Receive Remote Overflow VC 2 Counter" );
    v->CMMIODevImpl::addAtAddress( f , 0x0F*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxRemOverflow3Count" );
    f->setDescription( "Receive Remote Overflow VC 3 Counter" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxFrameErrorCount" );
    f->setDescription( "Receive Frame Error Counter" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxFrameCount" );
    f->setDescription( "Receive Frame Counter" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxLocOverflow0Count" );
    f->setDescription( "Local Overflow VC 0 Counter" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxLocOverflow1Count" );
    f->setDescription( "Local Overflow VC 1 Counter" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxLocOverflow2Count" );
    f->setDescription( "Local Overflow VC 2 Counter" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxLocOverflow3Count" );
    f->setDescription( "Local Overflow VC 3 Counter" );
    v->CMMIODevImpl::addAtAddress( f , 0x16*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxFrameErrorCount" );
    f->setDescription( "Transmit frame error counter" );
    v->CMMIODevImpl::addAtAddress( f , 0x17*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxFrameCount" );
    f->setDescription( "Transmit frame counter" );
    v->CMMIODevImpl::addAtAddress( f , 0x18*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxClkFreq" );
    f->setDescription( "Receive clock frequency" );
    v->CMMIODevImpl::addAtAddress( f , 0x19*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxClkFreq" );
    f->setDescription( "Transmit clock frequency" );
    v->CMMIODevImpl::addAtAddress( f , 0x1A*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxOpCodeStatus" );
    v->CMMIODevImpl::addAtAddress( f , 0x1C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 8 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "LastTxOpCode" );
    v->CMMIODevImpl::addAtAddress( f , 0x1C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxOpCodeStatus" );
    v->CMMIODevImpl::addAtAddress( f , 0x1D*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 8 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "LastRxOpCode" );
    v->CMMIODevImpl::addAtAddress( f , 0x1D*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TxOpCodeCount" );
    v->CMMIODevImpl::addAtAddress( f , 0x1E*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "RxOpCodeCount" );
    v->CMMIODevImpl::addAtAddress( f , 0x1F*addrSize);

    return v;
}

CPgp2bAxiImpl::CPgp2bAxiImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CPgp2bAxiAdapt;
typedef shared_ptr<CPgp2bAxiAdapt> Pgp2bAxiAdapt;

class CPgp2bAxiAdapt : public IPgp2bAxi, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CPgp2bAxiAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */
/* Commands */
    virtual void ResetRx();
    virtual void Flush();

};

CPgp2bAxiAdapt::CPgp2bAxiAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}


/* Commands */
void CPgp2bAxiAdapt::ResetRx()
{
    throw InternalError("CPgp2bAxiAdapt::ResetRx not implemented\n");
}
void CPgp2bAxiAdapt::Flush()
{
    throw InternalError("CPgp2bAxiAdapt::Flush not implemented\n");
}

Pgp2bAxi IPgp2bAxi::create(Path p)
{
    Pgp2bAxiAdapt rval = IEntryAdapt::check_interface<Pgp2bAxiAdapt, Pgp2bAxiImpl>(p);
    return rval;
}

