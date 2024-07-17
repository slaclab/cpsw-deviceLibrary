//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef _DAC38J84_H
#define _DAC38J84_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//Dac38J84
class   IDac38J84B;
typedef shared_ptr<IDac38J84B> Dac38J84B;


class IDac38J84B : public virtual IMMIODev {
public:
    static Dac38J84B create(const char *name);
};

class IDac38J84;
typedef shared_ptr<IDac38J84> Dac38J84;

class IDac38J84 : public virtual IEntry {
public:
    static Dac38J84 create(Path p);
public:
/* Commands */
    virtual void ClearDACAlarms() = 0;
    virtual void InitDAC_JESD() = 0;
};

#endif

