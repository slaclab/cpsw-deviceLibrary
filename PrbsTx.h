#ifndef _PRBSTX_H
#define _PRBSTX_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//PrbsTx
class   IPrbsTxB;
typedef shared_ptr<IPrbsTxB> PrbsTxB;


class IPrbsTxB : public virtual IMMIODev {
public:
    static PrbsTxB create(const char *name);
};

class IPrbsTx;
typedef shared_ptr<IPrbsTx> PrbsTx;

class IPrbsTx : public virtual IEntry {
public:
    static PrbsTx create(Path p);
public:
/* Commands */
    virtual void OneShot() = 0;
};

#endif

