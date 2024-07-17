//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef _CENTRALNODE_H
#define _CENTRALNODE_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//CentralNode
class   ICentralNodeB;
typedef shared_ptr<ICentralNodeB> CentralNodeB;


class ICentralNodeB : public virtual IMMIODev {
public:
    static CentralNodeB create(const char *name);
};

class ICentralNode;
typedef shared_ptr<ICentralNode> CentralNode;

class ICentralNode : public virtual IEntry {
public:
    static CentralNode create(Path p);
public:
/* Commands */
    virtual void CounterReset() = 0;
};

#endif

