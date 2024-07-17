//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#include "JesdRx.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CJesdRxImpl;
typedef shared_ptr<CJesdRxImpl> JesdRxImpl;

class CJesdRxImpl : public CMMIODevImpl, public virtual IJesdRxB {
public:
    CJesdRxImpl(Key &key, const char* name);
};

JesdRxB IJesdRxB::create(const char *name)
{
JesdRxImpl v = CShObj::create<JesdRxImpl>(name);
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
    f = bldr->build( "SysrefDelay" );
    v->CMMIODevImpl::addAtAddress( f , 0x01*addrSize);

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
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "ClearErrors" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "InvertSync" );
    v->CMMIODevImpl::addAtAddress( f , 0x04*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "L1_Test_thr" );
    v->CMMIODevImpl::addAtAddress( f , 0x30*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "L1_Threshold_Low" );
    v->CMMIODevImpl::addAtAddress( f , 0x30*addrSize);

    bldr->reset();
    bldr->lsBit( 16 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "L1_Threshold_High" );
    v->CMMIODevImpl::addAtAddress( f , 0x30*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "L2_Test_thr" );
    v->CMMIODevImpl::addAtAddress( f , 0x31*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "L2_Threshold_Low" );
    v->CMMIODevImpl::addAtAddress( f , 0x31*addrSize);

    bldr->reset();
    bldr->lsBit( 16 );
    bldr->sizeBits( 16 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "L2_Threshold_High" );
    v->CMMIODevImpl::addAtAddress( f , 0x31*addrSize);

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
    f = bldr->build( "L1_AlignErr" );
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
    f = bldr->build( "L1_RxBuffUfl" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_RxBuffOfl" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 6 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_PositionErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 7 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_RxEnabled" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_SysRefDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 9 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_CommaDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 10 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_DisparityErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 14 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_DecErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x10*addrSize);

    bldr->reset();
    bldr->lsBit( 18 );
    bldr->sizeBits( 8 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L1_ElBuffLatency" );
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
    f = bldr->build( "L2_AlignErr" );
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
    f = bldr->build( "L2_RxBuffUfl" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_RxBuffOfl" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 6 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_PositionErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 7 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_RxEnabled" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_SysRefDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 9 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_CommaDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 10 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_DisparityErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 14 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L2_DecErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x11*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3_Status" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3_GTXRdy" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3_DataValid" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3_AlignErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3_nSync" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3_RxBuffUfl" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3_RxBuffOfl" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 6 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3_PositionErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 7 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3_RxEnabled" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3_SysRefDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 9 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3_CommaDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 10 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3_DisparityErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 14 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L3_DecErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x12*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4_Status" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4_GTXRdy" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4_DataValid" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4_AlignErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4_nSync" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4_RxBuffUfl" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4_RxBuffOfl" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 6 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4_PositionErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 7 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4_RxEnabled" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4_SysRefDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 9 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4_CommaDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 10 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4_DisparityErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 14 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L4_DecErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x13*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5_Status" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5_GTXRdy" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5_DataValid" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5_AlignErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5_nSync" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5_RxBuffUfl" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5_RxBuffOfl" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 6 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5_PositionErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 7 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5_RxEnabled" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5_SysRefDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 9 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5_CommaDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 10 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5_DisparityErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 14 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L5_DecErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x14*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6_Status" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6_GTXRdy" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    bldr->reset();
    bldr->lsBit( 1 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6_DataValid" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    bldr->reset();
    bldr->lsBit( 2 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6_AlignErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    bldr->reset();
    bldr->lsBit( 3 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6_nSync" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6_RxBuffUfl" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    bldr->reset();
    bldr->lsBit( 5 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6_RxBuffOfl" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    bldr->reset();
    bldr->lsBit( 6 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6_PositionErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    bldr->reset();
    bldr->lsBit( 7 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6_RxEnabled" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    bldr->reset();
    bldr->lsBit( 8 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6_SysRefDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    bldr->reset();
    bldr->lsBit( 9 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6_CommaDetected" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    bldr->reset();
    bldr->lsBit( 10 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6_DisparityErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    bldr->reset();
    bldr->lsBit( 14 );
    bldr->sizeBits( 4 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "L6_DecErr" );
    v->CMMIODevImpl::addAtAddress( f , 0x15*addrSize);

    return v;
}

CJesdRxImpl::CJesdRxImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CJesdRxAdapt;
typedef shared_ptr<CJesdRxAdapt> JesdRxAdapt;

class CJesdRxAdapt : public IJesdRx, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CJesdRxAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */
/* Commands */
    virtual void ClearErrors();
    virtual void RestartGTs();

};

CJesdRxAdapt::CJesdRxAdapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}


/* Commands */
void CJesdRxAdapt::ClearErrors()
{
    throw InternalError("CJesdRxAdapt::ClearErrors not implemented\n");
}
void CJesdRxAdapt::RestartGTs()
{
    throw InternalError("CJesdRxAdapt::RestartGTs not implemented\n");
}

JesdRx IJesdRx::create(Path p)
{
    JesdRxAdapt rval = IEntryAdapt::check_interface<JesdRxAdapt, JesdRxImpl>(p);
    return rval;
}

