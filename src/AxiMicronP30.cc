#include <cpsw_mmio_dev.h>
#include <string.h>
#include <stdio.h>
#include <inttypes.h>
#include <string>
#include <sstream>
#include <iomanip>

#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

#include "AxiMicronP30.h"

#define addrSize 4

AXIMicronP30 IAXIMicronP30::create(const char *name)
{
AXIMicronP30Impl v = CShObj::create<AXIMicronP30Impl>(name);
Field f;
        f = IIntField::create("Data", false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x00*addrSize );
        f = IIntField::create("Addr", 32, false,  0);
        v->CMMIODevImpl::addAtAddress( f,   0x01*addrSize  );
        f = IIntField::create("Read", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x02*addrSize  );
        f = IIntField::create("Test", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f , 0x03*addrSize  );
        f = IIntField::create("FastAddr", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x04*addrSize  );
        f = IIntField::create("FastProg", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x05*addrSize  );
        f = IIntField::create("BurstAddr", 32, false, 0);
        v->CMMIODevImpl::addAtAddress( f, 0x06*addrSize  );

        return v;
}

CAXIMicronP30Impl::CAXIMicronP30Impl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x00010000 >> 2, LE)
{
}
