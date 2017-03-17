#ifndef _ADC16DX370_H
#define _ADC16DX370_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//Adc16Dx370
class   IAdc16Dx370B;
typedef shared_ptr<IAdc16Dx370B> Adc16Dx370B;


class IAdc16Dx370B : public virtual IMMIODev {
public:
    static Adc16Dx370B create(const char *name);
};

class IAdc16Dx370;
typedef shared_ptr<IAdc16Dx370> Adc16Dx370;

class IAdc16Dx370 : public virtual IEntry {
public:
    static Adc16Dx370 create(Path p);
public:
/* Commands */
    virtual void CalibrateADC() = 0;
};

#endif

