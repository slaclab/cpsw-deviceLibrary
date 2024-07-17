//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef _AXIAD5780_H
#define _AXIAD5780_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AxiAd5780
class   IAxiAd5780B;
typedef shared_ptr<IAxiAd5780B> AxiAd5780B;


class IAxiAd5780B : public virtual IMMIODev {
public:
    static AxiAd5780B create(const char *name);
};

class IAxiAd5780;
typedef shared_ptr<IAxiAd5780> AxiAd5780;

class IAxiAd5780 : public virtual IEntry {
public:
    static AxiAd5780 create(Path p);
public:
/* Commands */
    virtual void dacRst() = 0;
};

#endif

