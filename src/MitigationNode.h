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

