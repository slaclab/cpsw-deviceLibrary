//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef AMCCARRIER_DRIVER_H
#define AMCCARRIER_DRIVER_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>


class   IAmcCarrier;
typedef shared_ptr<IAmcCarrier> AmcCarrier;

class CAmcCarrierImpl;
typedef shared_ptr<CAmcCarrierImpl> AmcCarrierImpl;


class IAmcCarrier : public virtual IMMIODev {
public:
        static AmcCarrier create(const char *name);
};

class CAmcCarrierImpl : public CMMIODevImpl, public virtual IAmcCarrier {
public:
        CAmcCarrierImpl(Key &key, const char *name);
};
#endif

