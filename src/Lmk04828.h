//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef _LMK04828_H
#define _LMK04828_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//Lmk04828
class   ILmk04828B;
typedef shared_ptr<ILmk04828B> Lmk04828B;


class ILmk04828B : public virtual IMMIODev {
public:
    static Lmk04828B create(const char *name);
};

class ILmk04828;
typedef shared_ptr<ILmk04828> Lmk04828;

class ILmk04828 : public virtual IEntry {
public:
    static Lmk04828 create(Path p);
public:
/* Commands */
    virtual void SyncClks() = 0;
    virtual void writeConfig() = 0;
};

#endif

