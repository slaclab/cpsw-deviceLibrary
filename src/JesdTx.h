//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef _JESDTX_H
#define _JESDTX_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//JesdTx
class   IJesdTxB;
typedef shared_ptr<IJesdTxB> JesdTxB;


class IJesdTxB : public virtual IMMIODev {
public:
    static JesdTxB create(const char *name);
};

class IJesdTx;
typedef shared_ptr<IJesdTx> JesdTx;

class IJesdTx : public virtual IEntry {
public:
    static JesdTx create(Path p);
public:
};

#endif

