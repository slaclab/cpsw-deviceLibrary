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

