#ifndef _AXIMICRONN25Q_H
#define _AXIMICRONN25Q_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiMicronN25Q
class   IAxiMicronN25QB;
typedef shared_ptr<IAxiMicronN25QB> AxiMicronN25QB;


class IAxiMicronN25QB : public virtual IMMIODev {
public:
    static AxiMicronN25QB create(const char *name);
};

class IAxiMicronN25Q;
typedef shared_ptr<IAxiMicronN25Q> AxiMicronN25Q;

class IAxiMicronN25Q : public virtual IEntry {
public:
    static AxiMicronN25Q create(Path p);
public:
};

#endif

