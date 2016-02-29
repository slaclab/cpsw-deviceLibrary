CPSW_DIR=/home/till/lcls/lcls2/cpsw/api/sw

include $(CPSW_DIR)/defs.mak

promLib_SRCS+=AxiMicronN25Q.cpp
promLib_SRCS+=MicronN25Q.cpp
promLib_SRCS+=McsFileReader.cpp
promLib_SRCS+=PromApiImpl.cpp
promLib_SRCS+=McsRead.cpp

STATIC_LIBRARIES+=promLib

include $(CPSW_DIR)/rules.mak
