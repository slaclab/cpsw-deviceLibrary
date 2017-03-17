#ifndef _TENGIGETHREG_H
#define _TENGIGETHREG_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//TenGigEthReg
class   ITenGigEthRegB;
typedef shared_ptr<ITenGigEthRegB> TenGigEthRegB;


class ITenGigEthRegB : public virtual IMMIODev {
public:
    static TenGigEthRegB create(const char *name);
};

class ITenGigEthReg;
typedef shared_ptr<ITenGigEthReg> TenGigEthReg;

class ITenGigEthReg : public virtual IEntry {
public:
    static TenGigEthReg create(Path p);
public:
};

#endif

