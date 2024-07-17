//////////////////////////////////////////////////////////////////////////////
// This file is part of 'deviceLibrary'.
// It is subject to the license terms in the LICENSE.txt file found in the 
// top-level directory of this distribution and at: 
//    https://confluence.slac.stanford.edu/display/ppareg/LICENSE.html. 
// No part of 'deviceLibrary', including this file, 
// may be copied, modified, propagated, or distributed except according to 
// the terms contained in the LICENSE.txt file.
//////////////////////////////////////////////////////////////////////////////
#ifndef PROM_FILE_READER_H
#define PROM_FILE_READER_H

#include <stdint.h>

// For definition of shared_ptr 
#include <cpsw_api_user.h>

// PROM File reader interface
class IFileDescriptor;
typedef shared_ptr<IFileDescriptor> FileDescriptor;

class IFileReader;
typedef shared_ptr<IFileReader> FileReader;

class IFileDescriptor {
public:
	//  'getAddress()' returns the current write pointer
	//                 (prom address).
	virtual uint32_t   getAddr()          = 0;
	//  'getSize()'    returns the size of the payload
	//                 data in the file
	virtual uint32_t   getSize()          = 0;
	//  'operator++()' reads and returns the next
	//                 byte in the file. It also updates
	//                 the address pointer (which can
	//                 be retrieved via 'getAddr()'.
	//                 THROWS: ReadError if an error occurs
	//                         EndOfFile when the EOF is reached
	virtual uint8_t    operator++()       = 0;

	class EndOfFile {};
	class ReadError {};
};

class IFileReader {
public:
	// open the file associated with this reader;
	// returns a 'FileDescriptor' on success.
	//
	// If the file cannot be opened a NIL pointer
	// is returned;
	//
	// The implementation must close the file from
	// its destructor;
	//
	// The reader implementation also must initialize
	// the descriptor state so that 'getAddr()' and 'getSize()'
	// return valid values.
	virtual FileDescriptor open() = 0;

	class InvalidPathError {};
};

#endif
