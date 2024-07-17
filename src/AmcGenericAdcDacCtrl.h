//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef _AMCGENERICADCDACCTRL_H
#define _AMCGENERICADCDACCTRL_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//AmcGenericAdcDacCtrl
class   IAmcGenericAdcDacCtrlB;
typedef shared_ptr<IAmcGenericAdcDacCtrlB> AmcGenericAdcDacCtrlB;


class IAmcGenericAdcDacCtrlB : public virtual IMMIODev {
public:
    static AmcGenericAdcDacCtrlB create(const char *name);
};

class IAmcGenericAdcDacCtrl;
typedef shared_ptr<IAmcGenericAdcDacCtrl> AmcGenericAdcDacCtrl;

class IAmcGenericAdcDacCtrl : public virtual IEntry {
public:
    static AmcGenericAdcDacCtrl create(Path p);
public:
};

#endif

