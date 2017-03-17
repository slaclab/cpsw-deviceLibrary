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

