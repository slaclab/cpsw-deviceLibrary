CPSW_DIR=/home/till/lcls/lcls2/cpsw/api/sw

include $(CPSW_DIR)/defs.mak

STATIC_LIBRARIES += deviceLib

deviceLib_SRCS += Adc16Dx370.cc
deviceLib_SRCS += AmcCarrier.cc
deviceLib_SRCS += AmcGenericAdcDac.cc
deviceLib_SRCS += AmcGenericAdcDacCtrl.cc
deviceLib_SRCS += AxiAd5780.cc
deviceLib_SRCS += AxiCommon.cc
deviceLib_SRCS += AxiLtc2270.cc
deviceLib_SRCS += AxiMicronN25Q.cc
deviceLib_SRCS += AxiMicronP30.cc
deviceLib_SRCS += AxiVersion.cc
deviceLib_SRCS += AxiXadc.cc
deviceLib_SRCS += CentralNode.cc
deviceLib_SRCS += Dac38J84.cc
deviceLib_SRCS += JesdRx.cc
deviceLib_SRCS += JesdRxDaq.cc
deviceLib_SRCS += JesdTx.cc
deviceLib_SRCS += Lmk04828.cc
deviceLib_SRCS += MicronN25Q.cc
deviceLib_SRCS += MitigationNode.cc
deviceLib_SRCS += Pgp2bAxi.cc
deviceLib_SRCS += PrbsTx.cc
deviceLib_SRCS += PromApiImpl.cc
deviceLib_SRCS += RingBuffer.cc
deviceLib_SRCS += TenGigEthReg.cc

include $(CPSW_DIR)/rules.mak
