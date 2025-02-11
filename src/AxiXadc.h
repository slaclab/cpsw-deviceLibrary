//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef _AXIXADC_H
#define _AXIXADC_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiXadc
class   IAxiXadcB;
typedef shared_ptr<IAxiXadcB> AxiXadcB;


class IAxiXadcB : public virtual IMMIODev {
public:
    static AxiXadcB create(const char *name);
};

class IAxiXadc;
typedef shared_ptr<IAxiXadc> AxiXadc;

class IAxiXadc : public virtual IEntry {
public:
    static AxiXadc create(Path p);
public:
};

#endif

