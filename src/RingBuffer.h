//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef _RINGBUFFER_H
#define _RINGBUFFER_H

#include <cpsw_api_builder.h>
#include <cpsw_mmio_dev.h>

//RingBuffer
class   IRingBufferB;
typedef shared_ptr<IRingBufferB> RingBufferB;


class IRingBufferB : public virtual IMMIODev {
public:
    static RingBufferB create(const char *name);
};

class IRingBuffer;
typedef shared_ptr<IRingBuffer> RingBuffer;

class IRingBuffer : public virtual IEntry {
public:
    static RingBuffer create(Path p);
public:
};

#endif

