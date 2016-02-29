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

