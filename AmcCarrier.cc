#include <cpsw_mmio_dev.h>
#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>

#include "AmcCarrier.h"
#include "AxiVersion.h"
#include "AmcGenericAdcDac.h"
#include "Pgp2bAxi.h"
#include "JesdRxDaq.h"

#define BAY0_BASE_ADDR_C   (0x80000000) 
#define BAY1_BASE_ADDR_C   (0x80800000)

#define AXIVERSION_BASE_ADDR_C  ( 0x00000000 )
#define PGP2BAXI_BASE_ADDR_C    ( 0x0A000000 )
#define JESDRXDAQ_BASE_ADDR_C   ( 0x81000000  )


AmcCarrier IAmcCarrier::create(const char *name)
{
AmcCarrierImpl v = CShObj::create<AmcCarrierImpl>(name);

        AxiVersionB p1 = IAxiVersionB::create("AxiVersion");
        v->CMMIODevImpl::addAtAddress( p1, AXIVERSION_BASE_ADDR_C );

        Pgp2bAxiB p2 = IPgp2bAxiB::create("Pgp2bAxi");
        v->CMMIODevImpl::addAtAddress( p2, PGP2BAXI_BASE_ADDR_C );

        JesdRxDaqB p10 = IJesdRxDaqB::create("JesdRxDaq");
        v->CMMIODevImpl::addAtAddress( p10, JESDRXDAQ_BASE_ADDR_C );

        return v;
}

CAmcCarrierImpl::CAmcCarrierImpl(Key &key, const char *name) : CMMIODevImpl(key, name, 0x90000000 , LE)
{
}
