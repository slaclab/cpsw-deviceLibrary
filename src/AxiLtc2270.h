//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
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
