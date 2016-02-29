#ifndef _AXI_COMMON_H
#define _AXI_COMMON_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

class   IAXICommon;
typedef shared_ptr<IAXICommon> AXICommon;

class CAXICommonImpl;
typedef shared_ptr<CAXICommonImpl> AXICommonImpl;


class IAXICommon : public virtual IMMIODev {
public:
        static AXICommon create(const char *name);
};

class CAXICommonImpl : public CMMIODevImpl, public virtual IAXICommon {
public:
        CAXICommonImpl(Key &key, const char *name);
};
#endif
