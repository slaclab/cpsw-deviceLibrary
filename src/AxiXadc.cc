//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#include "AxiXadc.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CAxiXadcImpl;
typedef shared_ptr<CAxiXadcImpl> AxiXadcImpl;

class CAxiXadcImpl : public CMMIODevImpl, public virtual IAxiXadcB {
public:
    CAxiXadcImpl(Key &key, const char* name);
};

AxiXadcB IAxiXadcB::create(const char *name)
{
AxiXadcImpl v = CShObj::create<AxiXadcImpl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 24 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Temperature" );
    v->CMMIODevImpl::addAtAddress( f , 0x200*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 24 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccInt" );
    v->CMMIODevImpl::addAtAddress( f , 0x204*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 24 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccAux" );
    v->CMMIODevImpl::addAtAddress( f , 0x208*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VrefP" );
    v->CMMIODevImpl::addAtAddress( f , 0x210*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VrefN" );
    v->CMMIODevImpl::addAtAddress( f , 0x214*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccBram" );
    v->CMMIODevImpl::addAtAddress( f , 0x218*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "SupplyOffsetA" );
    v->CMMIODevImpl::addAtAddress( f , 0x220*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcOffsetA" );
    v->CMMIODevImpl::addAtAddress( f , 0x224*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "AdcGainA" );
    v->CMMIODevImpl::addAtAddress( f , 0x228*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccpInt" );
    v->CMMIODevImpl::addAtAddress( f , 0x234*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccpAux" );
    v->CMMIODevImpl::addAtAddress( f , 0x238*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccpDdr" );
    v->CMMIODevImpl::addAtAddress( f , 0x23C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux_0" );
    v->CMMIODevImpl::addAtAddress( f , 0x240*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux01" );
    v->CMMIODevImpl::addAtAddress( f , 0x244*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux02" );
    v->CMMIODevImpl::addAtAddress( f , 0x248*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux03" );
    v->CMMIODevImpl::addAtAddress( f , 0x24C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux04" );
    v->CMMIODevImpl::addAtAddress( f , 0x250*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux05" );
    v->CMMIODevImpl::addAtAddress( f , 0x254*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux06" );
    v->CMMIODevImpl::addAtAddress( f , 0x258*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux07" );
    v->CMMIODevImpl::addAtAddress( f , 0x25C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux08" );
    v->CMMIODevImpl::addAtAddress( f , 0x260*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux09" );
    v->CMMIODevImpl::addAtAddress( f , 0x264*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux10" );
    v->CMMIODevImpl::addAtAddress( f , 0x268*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux11" );
    v->CMMIODevImpl::addAtAddress( f , 0x26C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux12" );
    v->CMMIODevImpl::addAtAddress( f , 0x270*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux13" );
    v->CMMIODevImpl::addAtAddress( f , 0x274*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux14" );
    v->CMMIODevImpl::addAtAddress( f , 0x278*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VinAux15" );
    v->CMMIODevImpl::addAtAddress( f , 0x27C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TemperatureMax" );
    v->CMMIODevImpl::addAtAddress( f , 0x280*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccIntMax" );
    v->CMMIODevImpl::addAtAddress( f , 0x288*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccAuxMax" );
    v->CMMIODevImpl::addAtAddress( f , 0x284*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccBramMax" );
    v->CMMIODevImpl::addAtAddress( f , 0x28C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "TemperatureMin" );
    v->CMMIODevImpl::addAtAddress( f , 0x290*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccIntMin" );
    v->CMMIODevImpl::addAtAddress( f , 0x294*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccAuxMin" );
    v->CMMIODevImpl::addAtAddress( f , 0x298*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccBramMin" );
    v->CMMIODevImpl::addAtAddress( f , 0x29C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccpIntMax" );
    v->CMMIODevImpl::addAtAddress( f , 0x2A0*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccpAuxMax" );
    v->CMMIODevImpl::addAtAddress( f , 0x2A4*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccpDdrMax" );
    v->CMMIODevImpl::addAtAddress( f , 0x2A8*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccpIntMin" );
    v->CMMIODevImpl::addAtAddress( f , 0x2B0*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccpAuxMin" );
    v->CMMIODevImpl::addAtAddress( f , 0x2B4*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "VccpDdrMin" );
    v->CMMIODevImpl::addAtAddress( f , 0x2B8*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Flag" );
    v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);

    bldr->reset();
    bldr->lsBit( 11 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Flag_JTGD" );
    v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);

    bldr->reset();
    bldr->lsBit( 10 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Flag_JTGR" );
    v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);

    bldr->reset();
    bldr->lsBit( 9 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Flag_REF" );
    v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);

    bldr->reset();
    bldr->lsBit( 7 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Flag_VccpDdr" );
    v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);

    bldr->reset();
    bldr->lsBit( 6 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Flag_VccpAux" );
    v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Flag_VccpInt" );
    v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Flag_VccBram" );
    v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Flag_VccAux" );
    v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Flag_VccInt" );
    v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "Flag_Temperature" );
    v->CMMIODevImpl::addAtAddress( f , 0x2FC*addrSize);

    return v;
}

CAxiXadcImpl::CAxiXadcImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CAxiXadcAdapt;
typedef shared_ptr<CAxiXadcAdapt> AxiXadcAdapt;

class CAxiXadcAdapt : public IAxiXadc, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CAxiXadcAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */

};

CAxiXadcAdapt::CAxiXadcAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}



AxiXadc IAxiXadc::create(Path p)
{
    AxiXadcAdapt rval = IEntryAdapt::check_interface<AxiXadcAdapt, AxiXadcImpl>(p);
    return rval;
}

