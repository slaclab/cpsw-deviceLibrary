// Adapter classes to implement FileDescriptor/FileReader with McsRead

#include <McsFileReader.h>
#include <McsRead.h>

class McsFileDescriptor : public McsRead, public IFileDescriptor {
private:

	McsReadData        pos_;
	bool               haveSize_;
	uint32_t           size_;

public:
	virtual uint32_t   getAddr() { return pos_.address; }

	virtual uint32_t   getSize();

	virtual uint8_t    operator++();

	virtual ~McsFileDescriptor();

protected:
	McsFileDescriptor(string path);

	friend class McsFileReader;
};


uint32_t McsFileDescriptor::getSize()
{
	if ( ! haveSize_ ) {
		size_     = McsRead::addrSize();
		haveSize_ = true;
	}
	return size_;
}

uint8_t  McsFileDescriptor::operator++()
{
	if ( McsRead::read( &pos_ ) < 0 )
		throw ReadError();
	if ( pos_.endOfFile )
		throw EndOfFile();
	return pos_.data & 0xff;
}

McsFileDescriptor::~McsFileDescriptor()
{
	McsRead::close();
}

McsFileDescriptor::McsFileDescriptor(string path)
: haveSize_(false)
{
	pos_.endOfFile = true;
	if ( ! open( path ) ) {
		throw IFileReader::InvalidPathError();
	}
	pos_.endOfFile = false;
	pos_.address   = McsRead::startAddr();
}

McsFileReader::McsFileReader(string path)
:path_(path)
{
}

FileDescriptor McsFileReader::open()
{
McsFileDescriptor *ptr = new McsFileDescriptor(path_);
	return FileDescriptor(ptr);
}

FileReader McsFileReader::create(string path)
{
	McsFileReader *ptr = new McsFileReader( path );
	return FileReader(ptr);
}
