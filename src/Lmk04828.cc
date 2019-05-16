#include "Lmk04828.h"
#include <cpsw_sval.h>
#include <cpsw_entry_adapt.h>

#define addrSize 4

class CLmk04828Impl;
typedef shared_ptr<CLmk04828Impl> Lmk04828Impl;

class CLmk04828Impl : public CMMIODevImpl, public virtual ILmk04828B {
public:
    CLmk04828Impl(Key &key, const char* name);
};

Lmk04828B ILmk04828B::create(const char *name)
{
Lmk04828Impl v = CShObj::create<Lmk04828Impl>(name);
Field f;
IIntField::Builder bldr = IIntField::IBuilder::create();

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ID_DEVICE_TYPE" );
    v->CMMIODevImpl::addAtAddress( f , 0x003*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ID_PROD_UPPER" );
    v->CMMIODevImpl::addAtAddress( f , 0x004*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ID_PROD_LOWER" );
    v->CMMIODevImpl::addAtAddress( f , 0x005*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ID_MASKREV" );
    v->CMMIODevImpl::addAtAddress( f , 0x006*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ID_VNDR_UPPER" );
    v->CMMIODevImpl::addAtAddress( f , 0x00C*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RO );
    f = bldr->build( "ID_VNDR_LOWER" );
    v->CMMIODevImpl::addAtAddress( f , 0x00D*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 2 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "SYS_REF_MUX" );
    v->CMMIODevImpl::addAtAddress( f , 0x139*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 2 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "SYNC_MODE" );
    v->CMMIODevImpl::addAtAddress( f , 0x143*addrSize);

    bldr->reset();
    bldr->lsBit( 4 );
    bldr->sizeBits( 1 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "SYNC_EN" );
    v->CMMIODevImpl::addAtAddress( f , 0x143*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 8 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "SYNC_DIS" );
    v->CMMIODevImpl::addAtAddress( f , 0x144*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0100" );
    v->CMMIODevImpl::addAtAddress( f , 0x0100*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0101" );
    v->CMMIODevImpl::addAtAddress( f , 0x0101*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0103" );
    v->CMMIODevImpl::addAtAddress( f , 0x0103*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0104" );
    v->CMMIODevImpl::addAtAddress( f , 0x0104*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0105" );
    v->CMMIODevImpl::addAtAddress( f , 0x0105*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0106" );
    v->CMMIODevImpl::addAtAddress( f , 0x0106*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0107" );
    v->CMMIODevImpl::addAtAddress( f , 0x0107*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0108" );
    v->CMMIODevImpl::addAtAddress( f , 0x0108*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0109" );
    v->CMMIODevImpl::addAtAddress( f , 0x0109*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x010b" );
    v->CMMIODevImpl::addAtAddress( f , 0x010b*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x010c" );
    v->CMMIODevImpl::addAtAddress( f , 0x010c*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x010d" );
    v->CMMIODevImpl::addAtAddress( f , 0x010d*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x010e" );
    v->CMMIODevImpl::addAtAddress( f , 0x010e*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x010f" );
    v->CMMIODevImpl::addAtAddress( f , 0x010f*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0110" );
    v->CMMIODevImpl::addAtAddress( f , 0x0110*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0111" );
    v->CMMIODevImpl::addAtAddress( f , 0x0111*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0113" );
    v->CMMIODevImpl::addAtAddress( f , 0x0113*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0114" );
    v->CMMIODevImpl::addAtAddress( f , 0x0114*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0115" );
    v->CMMIODevImpl::addAtAddress( f , 0x0115*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0116" );
    v->CMMIODevImpl::addAtAddress( f , 0x0116*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0117" );
    v->CMMIODevImpl::addAtAddress( f , 0x0117*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0118" );
    v->CMMIODevImpl::addAtAddress( f , 0x0118*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0119" );
    v->CMMIODevImpl::addAtAddress( f , 0x0119*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x011a" );
    v->CMMIODevImpl::addAtAddress( f , 0x011a*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x011b" );
    v->CMMIODevImpl::addAtAddress( f , 0x011b*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x011c" );
    v->CMMIODevImpl::addAtAddress( f , 0x011c*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x011d" );
    v->CMMIODevImpl::addAtAddress( f , 0x011d*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x011e" );
    v->CMMIODevImpl::addAtAddress( f , 0x011e*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x011f" );
    v->CMMIODevImpl::addAtAddress( f , 0x011f*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0120" );
    v->CMMIODevImpl::addAtAddress( f , 0x0120*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0121" );
    v->CMMIODevImpl::addAtAddress( f , 0x0121*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0123" );
    v->CMMIODevImpl::addAtAddress( f , 0x0123*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0124" );
    v->CMMIODevImpl::addAtAddress( f , 0x0124*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0125" );
    v->CMMIODevImpl::addAtAddress( f , 0x0125*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0126" );
    v->CMMIODevImpl::addAtAddress( f , 0x0126*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0127" );
    v->CMMIODevImpl::addAtAddress( f , 0x0127*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0128" );
    v->CMMIODevImpl::addAtAddress( f , 0x0128*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0129" );
    v->CMMIODevImpl::addAtAddress( f , 0x0129*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x012b" );
    v->CMMIODevImpl::addAtAddress( f , 0x012b*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x012c" );
    v->CMMIODevImpl::addAtAddress( f , 0x012c*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x012d" );
    v->CMMIODevImpl::addAtAddress( f , 0x012d*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x012e" );
    v->CMMIODevImpl::addAtAddress( f , 0x012e*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x012f" );
    v->CMMIODevImpl::addAtAddress( f , 0x012f*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0130" );
    v->CMMIODevImpl::addAtAddress( f , 0x0130*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0131" );
    v->CMMIODevImpl::addAtAddress( f , 0x0131*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0133" );
    v->CMMIODevImpl::addAtAddress( f , 0x0133*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0134" );
    v->CMMIODevImpl::addAtAddress( f , 0x0134*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0135" );
    v->CMMIODevImpl::addAtAddress( f , 0x0135*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0136" );
    v->CMMIODevImpl::addAtAddress( f , 0x0136*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0137" );
    v->CMMIODevImpl::addAtAddress( f , 0x0137*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0138" );
    v->CMMIODevImpl::addAtAddress( f , 0x0138*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0139" );
    v->CMMIODevImpl::addAtAddress( f , 0x0139*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x013a" );
    v->CMMIODevImpl::addAtAddress( f , 0x013a*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x013b" );
    v->CMMIODevImpl::addAtAddress( f , 0x013b*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x013c" );
    v->CMMIODevImpl::addAtAddress( f , 0x013c*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x013d" );
    v->CMMIODevImpl::addAtAddress( f , 0x013d*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x013e" );
    v->CMMIODevImpl::addAtAddress( f , 0x013e*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x013f" );
    v->CMMIODevImpl::addAtAddress( f , 0x013f*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0140" );
    v->CMMIODevImpl::addAtAddress( f , 0x0140*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0141" );
    v->CMMIODevImpl::addAtAddress( f , 0x0141*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0142" );
    v->CMMIODevImpl::addAtAddress( f , 0x0142*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0143" );
    v->CMMIODevImpl::addAtAddress( f , 0x0143*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0144" );
    v->CMMIODevImpl::addAtAddress( f , 0x0144*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0145" );
    v->CMMIODevImpl::addAtAddress( f , 0x0145*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0146" );
    v->CMMIODevImpl::addAtAddress( f , 0x0146*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0147" );
    v->CMMIODevImpl::addAtAddress( f , 0x0147*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0148" );
    v->CMMIODevImpl::addAtAddress( f , 0x0148*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0149" );
    v->CMMIODevImpl::addAtAddress( f , 0x0149*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x014a" );
    v->CMMIODevImpl::addAtAddress( f , 0x014a*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x014b" );
    v->CMMIODevImpl::addAtAddress( f , 0x014b*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x014c" );
    v->CMMIODevImpl::addAtAddress( f , 0x014c*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x014d" );
    v->CMMIODevImpl::addAtAddress( f , 0x014d*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x014e" );
    v->CMMIODevImpl::addAtAddress( f , 0x014e*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x014f" );
    v->CMMIODevImpl::addAtAddress( f , 0x014f*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0150" );
    v->CMMIODevImpl::addAtAddress( f , 0x0150*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0151" );
    v->CMMIODevImpl::addAtAddress( f , 0x0151*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0152" );
    v->CMMIODevImpl::addAtAddress( f , 0x0152*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0153" );
    v->CMMIODevImpl::addAtAddress( f , 0x0153*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0154" );
    v->CMMIODevImpl::addAtAddress( f , 0x0154*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0155" );
    v->CMMIODevImpl::addAtAddress( f , 0x0155*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0156" );
    v->CMMIODevImpl::addAtAddress( f , 0x0156*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0157" );
    v->CMMIODevImpl::addAtAddress( f , 0x0157*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0158" );
    v->CMMIODevImpl::addAtAddress( f , 0x0158*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0159" );
    v->CMMIODevImpl::addAtAddress( f , 0x0159*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x015a" );
    v->CMMIODevImpl::addAtAddress( f , 0x015a*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x015b" );
    v->CMMIODevImpl::addAtAddress( f , 0x015b*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x015c" );
    v->CMMIODevImpl::addAtAddress( f , 0x015c*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x015d" );
    v->CMMIODevImpl::addAtAddress( f , 0x015d*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x015e" );
    v->CMMIODevImpl::addAtAddress( f , 0x015e*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x015f" );
    v->CMMIODevImpl::addAtAddress( f , 0x015f*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0160" );
    v->CMMIODevImpl::addAtAddress( f , 0x0160*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0161" );
    v->CMMIODevImpl::addAtAddress( f , 0x0161*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0162" );
    v->CMMIODevImpl::addAtAddress( f , 0x0162*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0163" );
    v->CMMIODevImpl::addAtAddress( f , 0x0163*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0164" );
    v->CMMIODevImpl::addAtAddress( f , 0x0164*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0165" );
    v->CMMIODevImpl::addAtAddress( f , 0x0165*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0166" );
    v->CMMIODevImpl::addAtAddress( f , 0x0166*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0167" );
    v->CMMIODevImpl::addAtAddress( f , 0x0167*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0168" );
    v->CMMIODevImpl::addAtAddress( f , 0x0168*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0169" );
    v->CMMIODevImpl::addAtAddress( f , 0x0169*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x016a" );
    v->CMMIODevImpl::addAtAddress( f , 0x016a*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x016b" );
    v->CMMIODevImpl::addAtAddress( f , 0x016b*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x016c" );
    v->CMMIODevImpl::addAtAddress( f , 0x016c*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x016d" );
    v->CMMIODevImpl::addAtAddress( f , 0x016d*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x016e" );
    v->CMMIODevImpl::addAtAddress( f , 0x016e*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0173" );
    v->CMMIODevImpl::addAtAddress( f , 0x0173*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x0174" );
    v->CMMIODevImpl::addAtAddress( f , 0x0174*addrSize);

    bldr->reset();
    bldr->lsBit( 0 );
    bldr->sizeBits( 32 );
    bldr->mode( IIntField::RW );
    f = bldr->build( "LmkReg0x017c" );
    v->CMMIODevImpl::addAtAddress( f , 0x017c*addrSize);

    return v;
}

CLmk04828Impl::CLmk04828Impl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000, LE)
{
}


class CLmk04828Adapt;
typedef shared_ptr<CLmk04828Adapt> Lmk04828Adapt;

class CLmk04828Adapt : public ILmk04828, public IEntryAdapt {
protected:
/* put ScalVals, etc. here */
public:
    CLmk04828Adapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie);

public:
/* Functions that we will implement */
/* Commands */
    virtual void SyncClks();
    virtual void writeConfig();

};

CLmk04828Adapt::CLmk04828Adapt(Key &k, ConstPath p, shared_ptr<const CEntryImpl> ie) : IEntryAdapt(k, p, ie)
{

}


/* Commands */
void CLmk04828Adapt::SyncClks()
{
    throw InternalError("CLmk04828Adapt::SyncClks not implemented\n");
}
void CLmk04828Adapt::writeConfig()
{
    throw InternalError("CLmk04828Adapt::writeConfig not implemented\n");
}

Lmk04828 ILmk04828::create(Path p)
{
    Lmk04828Adapt rval = IEntryAdapt::check_interface<Lmk04828Adapt, Lmk04828Impl>(p);
    return rval;
}

