#ifndef _PGP2BAXI_H
#define _PGP2BAXI_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//Pgp2bAxi
class   IPgp2bAxiB;
typedef shared_ptr<IPgp2bAxiB> Pgp2bAxiB;


class IPgp2bAxiB : public virtual IMMIODev {
public:
    static Pgp2bAxiB create(const char *name);
};

class IPgp2bAxi;
typedef shared_ptr<IPgp2bAxi> Pgp2bAxi;

class IPgp2bAxi : public virtual IEntry {
public:
    static Pgp2bAxi create(Path p);
public:
/* Commands */
    virtual void ResetRx() = 0;
    virtual void Flush() = 0;
};

#endif

