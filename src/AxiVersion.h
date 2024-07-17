//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef _AXIVERSION_H
#define _AXIVERSION_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiVersion
class   IAxiVersionB;
typedef shared_ptr<IAxiVersionB> AxiVersionB;


class IAxiVersionB : public virtual IMMIODev {
public:
    static AxiVersionB create(const char *name);
};

class IAxiVersion;
typedef shared_ptr<IAxiVersion> AxiVersion;

class IAxiVersion : public virtual IEntry {
public:
    static AxiVersion create(Path p);
public:
/* Commands */
    virtual void MasterReset() = 0;
    virtual void FpgaReload() = 0;
    virtual void CounterReset() = 0;
};

#endif

