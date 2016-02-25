#ifndef MCS_FILE_READER_H
#define MCS_FILE_READER_H

// Adapter classes to implement FileDescriptor/FileReader with McsRead
#include <PromFileReader.h>
#include <string>

using std::string;

class McsFileReader;

class McsFileReader : public IFileReader {
private:
	string path_;
protected:
	McsFileReader(string path);

public:

	virtual FileDescriptor open();

	static FileReader create(string path);
};

#endif
