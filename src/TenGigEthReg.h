//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef _TENGIGETHREG_H
#define _TENGIGETHREG_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//TenGigEthReg
class   ITenGigEthRegB;
typedef shared_ptr<ITenGigEthRegB> TenGigEthRegB;


class ITenGigEthRegB : public virtual IMMIODev {
public:
    static TenGigEthRegB create(const char *name);
};

class ITenGigEthReg;
typedef shared_ptr<ITenGigEthReg> TenGigEthReg;

class ITenGigEthReg : public virtual IEntry {
public:
    static TenGigEthReg create(Path p);
public:
};

#endif

