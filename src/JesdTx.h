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

