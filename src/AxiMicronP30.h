#ifndef _AXI_MICRON_P30_H
#define _AXI_MICRON_P30_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

class   IAXIMicronP30;
typedef shared_ptr<IAXIMicronP30> AXIMicronP30;

class CAXIMicronP30Impl;
typedef shared_ptr<CAXIMicronP30Impl> AXIMicronP30Impl;


class IAXIMicronP30 : public virtual IMMIODev {
public:
        static AXIMicronP30 create(const char *name);
};

class CAXIMicronP30Impl : public CMMIODevImpl, public virtual IAXIMicronP30 {
public:
        CAXIMicronP30Impl(Key &key, const char *name);
};
#endif
