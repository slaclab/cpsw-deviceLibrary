//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
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
