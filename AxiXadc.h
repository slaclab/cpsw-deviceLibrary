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

