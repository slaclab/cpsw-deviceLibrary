#ifndef _AXI_LTC_2270_H
#define _AXI_LTC_2270_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

class   IAXILtc2270;
typedef shared_ptr<IAXILtc2270> AXILtc2270;

class CAXILtc2270Impl;
typedef shared_ptr<CAXILtc2270Impl> AXILtc2270Impl;


class IAXILtc2270 : public virtual IMMIODev {
public:
        static AXILtc2270 create(const char *name);
};

class CAXILtc2270Impl : public CMMIODevImpl, public virtual IAXILtc2270 {
public:
        CAXILtc2270Impl(Key &key, const char *name);
};
#endif
