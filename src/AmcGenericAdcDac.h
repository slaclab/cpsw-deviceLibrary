//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef AMC_GENERIC_ADC_DAC_DRIVER_H
#define AMC_GENERIC_ADC_DAC_DRIVER_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

class   IAmcGenericAdcDac;
typedef shared_ptr<IAmcGenericAdcDac> AmcGenericAdcDac;

class CAmcGenericAdcDacImpl;
typedef shared_ptr<CAmcGenericAdcDacImpl> AmcGenericAdcDacImpl;


class IAmcGenericAdcDac : public virtual IMMIODev {
public:
        static AmcGenericAdcDac create(const char *name);
};

class CAmcGenericAdcDacImpl : public CMMIODevImpl, public virtual IAmcGenericAdcDac {
public:
        CAmcGenericAdcDacImpl(Key &key, const char *name);
};
#endif

