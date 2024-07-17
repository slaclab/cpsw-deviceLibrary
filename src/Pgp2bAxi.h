//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
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

