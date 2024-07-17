//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef _MITIGATIONNODE_H
#define _MITIGATIONNODE_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//MitigationNode
class   IMitigationNodeB;
typedef shared_ptr<IMitigationNodeB> MitigationNodeB;


class IMitigationNodeB : public virtual IMMIODev {
public:
    static MitigationNodeB create(const char *name);
};

class IMitigationNode;
typedef shared_ptr<IMitigationNode> MitigationNode;

class IMitigationNode : public virtual IEntry {
public:
    static MitigationNode create(Path p);
public:
/* Commands */
    virtual void CounterReset() = 0;
};

#endif

