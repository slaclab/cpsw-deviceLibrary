#ifndef PROM_API_IMPL_H
#define PROM_API_IMPL_H

#include <PromApiUser.h>

// Implementation of the user interface - in-turn relies
// on derived classes implementing actual access methods

class CEEPromImpl : public IEEProm {
private:
	// Local Variables -- for supporting the public interface
	uint32_t     progSize_;
	uint32_t     progStartAddr_;
	FileReader   reader_;

protected:
	bool     addr32BitMode_;

public:
	CEEPromImpl()
	: progSize_(0),
	  progStartAddr_(0),
	  addr32BitMode_(false)
	{
	}

    virtual void setFileReader(FileReader reader);
	virtual void setAddr32BitMode (bool addr32BitMode);
    virtual void eraseProm (uint32_t startAddr, uint32_t endAddr);

	virtual void eraseProm();

	// pure virtual methods to implemented for particular EEPROM
	virtual void    setPromStatusReg(uint8_t value) = 0;
	virtual uint8_t getPromStatusReg()              = 0;
	virtual uint8_t getManufacturerId()             = 0;
	virtual uint8_t getManufacturerType()           = 0;
	virtual uint8_t getManufacturerCapacity()       = 0;
	virtual unsigned getEraseBlockSize()            = 0;
	virtual bool    writeProm ( ); 
	virtual bool    verifyProm ( ); 
	virtual void rebootReminder ( bool pwrCycleReq );      
	virtual void readProm (uint32_t address, uint32_t *data);      

// variable and method members that are visible only to the implementation
protected:

    uint32_t data_[64];

    //! Enter 4-BYTE ADDRESS MODE Command
    virtual void enter32BitMode()               = 0;

    //! Exit 4-BYTE ADDRESS MODE Command
	virtual void exit32BitMode()                = 0;

	virtual void eraseCommand(uint32_t address) = 0;
	virtual void writeCommand(uint32_t address) = 0; 
	virtual void readCommand(uint32_t address)  = 0;
	virtual void resetFlash ( )                 = 0;
	virtual void writeEnable ( )                = 0;
	virtual void writeDisable ( )               = 0;

	class CreatorRegistrar {
		private:
			CreatorRegistrar *next_;
		public:
			virtual EEProm creator(ConstPath) = 0;
		protected:
			CreatorRegistrar();
		private:
			static CreatorRegistrar *&getHead();
		public:
			static EEProm create(ConstPath);
	};

public:
	static EEProm create(ConstPath);
};

#endif
