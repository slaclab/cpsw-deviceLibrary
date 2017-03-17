//-----------------------------------------------------------------------------
// File          : AxiMicronN25Q.h
// Author        : Larry Ruckman  <ruckman@slac.stanford.edu>
// Created       : 03/19/2014
// Project       :  
//-----------------------------------------------------------------------------
// Description :
//    Micron N25Q and Micron MT25Q PROM C++ Class
//-----------------------------------------------------------------------------
// This file is part of 'SLAC Generic DAQ Software'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'SLAC Generic DAQ Software', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
// Proprietary and confidential to SLAC.
//-----------------------------------------------------------------------------
// Modification history :
// 03/19/2014: created
// 02/08/2016: cpsw port
//-----------------------------------------------------------------------------

#ifndef __AXI_MICRON_N25Q_H__
#define __AXI_MICRON_N25Q_H__

#include <stdint.h>

#include <cpsw_api_user.h>
#include <cpsw_api_builder.h>


// builder interface for axi micron N25Q eeprom
class IAxiMicronN25Q;
typedef shared_ptr<IAxiMicronN25Q> AxiMicronN25Q;

class IAxiMicronN25Q : public virtual IField {
public:

	virtual ~IAxiMicronN25Q() {}

	static AxiMicronN25Q create(const char *name);
};

#endif
