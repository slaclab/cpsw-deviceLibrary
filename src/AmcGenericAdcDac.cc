#include <cpsw_mmio_dev.h>
#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

#include "AmcGenericAdcDac.h"
#include "JesdRx.h"
#include "JesdTx.h"
#include "Lmk04828.h"
#include "Adc16Dx370.h"
#include "Dac38J84.h"
#include "AmcGenericAdcDacCtrl.h"
#include "RingBuffer.h"

#define JESDRX_BASE_ADDR_C                ( 0x00000000 )
#define JESDTX_BASE_ADDR_C                ( 0x00100000 )
#define LMK04828_BASE_ADDR_C              ( 0x00200000 )
#define ADC16DX370_0_BASE_ADDR_C          ( 0x00300000 )
#define ADC16DX370_1_BASE_ADDR_C          ( 0x00400000 )
#define DAC38J84_BASE_ADDR_C              ( 0x00500000 )
#define AMCGENERICADCDACCTRL_BASE_ADDR_C  ( 0x00600000 ) 
#define ADC0_DEBUG_BASE_ADDR_C            ( 0x00610000 ) 
#define ADC1_DEBUG_BASE_ADDR_C            ( 0x00620000 ) 
#define ADC2_DEBUG_BASE_ADDR_C            ( 0x00630000 ) 
#define ADC3_DEBUG_BASE_ADDR_C            ( 0x00640000 ) 
#define DAC0_DEBUG_BASE_ADDR_C            ( 0x00650000 )
#define DAC1_DEBUG_BASE_ADDR_C            ( 0x00660000 )

AmcGenericAdcDac IAmcGenericAdcDac::create(const char *name)
{
AmcGenericAdcDacImpl v = CShObj::create<AmcGenericAdcDacImpl>(name);

        JesdRxB p1 = IJesdRxB::create("JesdRx");
        v->CMMIODevImpl::addAtAddress( p1, JESDRX_BASE_ADDR_C );

        JesdTxB p2 = IJesdTxB::create("JesdTx");
        v->CMMIODevImpl::addAtAddress( p2, JESDTX_BASE_ADDR_C );

        Lmk04828B p3 = ILmk04828B::create("Lmk04828");
        v->CMMIODevImpl::addAtAddress( p3, LMK04828_BASE_ADDR_C );

        Adc16Dx370B p4 = IAdc16Dx370B::create("Adc16Dx370");
        v->CMMIODevImpl::addAtAddress( p4, ADC16DX370_0_BASE_ADDR_C, 2, 0x100000 );

        Dac38J84B p6 = IDac38J84B::create("Dac38J84");
        v->CMMIODevImpl::addAtAddress( p6, DAC38J84_BASE_ADDR_C );

        AmcGenericAdcDacCtrlB p7 = IAmcGenericAdcDacCtrlB::create("AmcGenericAdcDacCtrl");
        v->CMMIODevImpl::addAtAddress( p7, AMCGENERICADCDACCTRL_BASE_ADDR_C );

        RingBufferB  p8 = IRingBufferB::create("AdcDebug");
        v->CMMIODevImpl::addAtAddress( p8, ADC0_DEBUG_BASE_ADDR_C, 4 );

        RingBufferB  p9 = IRingBufferB::create("DacDebug");
        v->CMMIODevImpl::addAtAddress( p9, DAC0_DEBUG_BASE_ADDR_C, 2 );

        return v;
}

CAmcGenericAdcDacImpl::CAmcGenericAdcDacImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00800000, LE)
{
}
