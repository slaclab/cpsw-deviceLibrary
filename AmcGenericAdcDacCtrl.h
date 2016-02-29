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

