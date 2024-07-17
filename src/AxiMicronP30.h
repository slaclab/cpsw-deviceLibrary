//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
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
