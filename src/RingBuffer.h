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

