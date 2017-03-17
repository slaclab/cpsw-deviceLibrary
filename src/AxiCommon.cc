#include <cpsw_mmio_dev.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <sstream>
#include <iomanip>

#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

#include "AxiCommon.h"

#define addrSize 4

AXICommon IAXICommon::create(const char *name)
{
AXICommonImpl v = CShObj::create<AXICommonImpl>(name);
Field f;
std::stringstream tmp;
        f = IIntField::create("frontPanelDoutCnt0", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize );
        f = IIntField::create("frontPanelDoutCnt1", 32, false,  0);
        v->CMMIODevImpl::addAtAddress( f,   0x01*addrSize );
        f = IIntField::create("frontPanelDinCnt0", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize );
        f = IIntField::create("frontPanelDinCnt1", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize );
        f = IIntField::create("backPanelDoutCnt0", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x04*addrSize );
        f = IIntField::create("backPanelDoutCnt1", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x05*addrSize );
        f = IIntField::create("backPanelDinCnt0", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x06*addrSize );
        f = IIntField::create("backPanelDinCnt1", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x07*addrSize );
        f = IIntField::create("backPanelDinCnt2",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x08*addrSize );
        f = IIntField::create("backPanelDinCnt3",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x09*addrSize );
        f = IIntField::create("redCnt",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x0A*addrSize );
        f = IIntField::create("greenCnt",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x0B*addrSize );
        f = IIntField::create("blueCnt",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x0C*addrSize );
        f = IIntField::create("rxReadyCnt",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x0D*addrSize );
        f = IIntField::create("txReadyCnt",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x0E*addrSize );
        f = IIntField::create("packetSentCnt",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x0F*addrSize );
   
/*	addRegisterLink(rl = new RegisterLink("REG40", baseAddress_ + 0x40*addrSize, 1, 16,
                                         "frontPanelDout0", Variable::Status, 0,  0x1,  // 0
                                         "frontPanelDout1", Variable::Status, 1,  0x1,  // 1
                                         "frontPanelDin0",  Variable::Status, 2,  0x1,  // 2
                                         "frontPanelDin1",  Variable::Status, 3,  0x1,  // 3
                                         "backPanelDout0",  Variable::Status, 4,  0x1,  // 4
                                         "backPanelDout1",  Variable::Status, 5,  0x1,  // 5
                                         "backPanelDin0",   Variable::Status, 6,  0x1,  // 6
                                         "backPanelDin1",   Variable::Status, 7,  0x1,  // 7
                                         "backPanelDin2",   Variable::Status, 8,  0x1,  // 8
                                         "backPanelDin3",   Variable::Status, 9,  0x1,  // 9
                                         "red",             Variable::Status, 10, 0x1,  // 10
                                         "green",           Variable::Status, 11, 0x1,  // 11
                                         "blue",            Variable::Status, 12, 0x1,  // 12
                                         "rxReady",         Variable::Status, 13, 0x1,  // 13
                                         "txReady",         Variable::Status, 14, 0x1,  // 14
                                         "packetSent",      Variable::Status, 15, 0x1));// 15
*/
        f = IIntField::create("REG40",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x40*addrSize  );

        for ( int i = 0; i < 16; i++ ) {
	 tmp.str("");
	 tmp << "DspStatus_" << std::dec << std::setw(2) << std::setfill('0') << i;
	 f = IIntField::create((const char*) tmp.str().c_str(), 32, false, 0);
	 v->CMMIODevImpl::addAtAddress( f, ( 0x70 + 8*i )*addrSize  );
	 
	 tmp.str("");
	 tmp << "DspConfig_" << std::dec << std::setw(2) << std::setfill('0') << i;
	 f = IIntField::create((const char*) tmp.str().c_str(), 32, false, 0);
	 v->CMMIODevImpl::addAtAddress( f, ( 0x80 + 8*i )*addrSize  );
	}
	
	for (int i = 0; i < 1; i++ ) {
	 tmp.str("");
	 tmp << "DspCmd_" << std::dec << std::setw(2) << std::setfill('0') << i;
	 f = IIntField::create((const char*) tmp.str().c_str(), 32, false, 0);
	 v->CMMIODevImpl::addAtAddress( f, ( 0xA0 + 8*i )*addrSize  );
	}
	
        f = IIntField::create("BurstLength",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xF2*addrSize  );
	f = IIntField::create("SoftTrig",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xFB*addrSize  );
	f = IIntField::create("SaveDspConfig",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xFC*addrSize  );
	f = IIntField::create("CounterReset",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xFD*addrSize  );
	f = IIntField::create("SoftReset",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xFE*addrSize  );
	f = IIntField::create("HardReset",  32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0xFF*addrSize  );
        return v;
}

CAXICommonImpl::CAXICommonImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000 >> 2, LE)
{
}
