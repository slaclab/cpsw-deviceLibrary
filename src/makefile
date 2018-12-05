PACKAGE_TOP=/afs/slac/g/lcls/package/
CPSW_FRAMEWORK_VERSION=R3.6.6

CPSW_DIR=$(PACKAGE_TOP)/cpsw/framework/$(CPSW_FRAMEWORK_VERSION)/src

# may override CPSW_DIR from 'release.mak'
# must set SRCDIR (is redefined by recursive make)
SRCDIR=.

-include $(SRCDIR)/release.mak
include $(CPSW_DIR)/defs.mak

HEADERS += Adc16Dx370.h AmcCarrier.h AmcGenericAdcDacCtrl.h AmcGenericAdcDac.h
HEADERS += AxiAd5780.h AxiCommon.h AxiLtc2270.h AxiMicronN25Q.h AxiMicronP30.h
HEADERS += AxiVersion.h AxiXadc.h CentralNode.h Dac38J84.h JesdRxDaq.h JesdRx.h
HEADERS += JesdTx.h Lmk04828.h MicronN25Q.h MitigationNode.h Pgp2bAxi.h PrbsTx.h
HEADERS += PromApiImpl.h PromApiUser.h PromFileReader.h RingBuffer.h TenGigEthReg.h

STATIC_LIBRARIES_YES += deviceLib
SHARED_LIBRARIES_YES += deviceLib

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
