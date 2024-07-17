//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef _JESDRXDAQ_H
#define _JESDRXDAQ_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//JesdRxDaq
class   IJesdRxDaqB;
typedef shared_ptr<IJesdRxDaqB> JesdRxDaqB;


class IJesdRxDaqB : public virtual IMMIODev {
public:
    static JesdRxDaqB create(const char *name);
};

class IJesdRxDaq;
typedef shared_ptr<IJesdRxDaq> JesdRxDaq;

class IJesdRxDaq : public virtual IEntry {
public:
    static JesdRxDaq create(Path p);
public:
/* Commands */
    virtual void TriggerDAQ() = 0;
};

#endif

