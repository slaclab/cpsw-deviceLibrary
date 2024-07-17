//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
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

