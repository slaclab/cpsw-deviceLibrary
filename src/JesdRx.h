#ifndef _JESDRX_H
#define _JESDRX_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//JesdRx
class   IJesdRxB;
typedef shared_ptr<IJesdRxB> JesdRxB;


class IJesdRxB : public virtual IMMIODev {
public:
    static JesdRxB create(const char *name);
};

class IJesdRx;
typedef shared_ptr<IJesdRx> JesdRx;

class IJesdRx : public virtual IEntry {
public:
    static JesdRx create(Path p);
public:
/* Commands */
    virtual void ClearErrors() = 0;
    virtual void RestartGTs() = 0;
};

#endif

