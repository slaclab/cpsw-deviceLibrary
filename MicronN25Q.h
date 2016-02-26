#ifndef MICRON_N25Q_EEPROM_H
#define MICRON_N25Q_EEPROM_H

#include <PromApiImpl.h>

//  Class to support SPI EEPROM regardless of a particular driver.
//  Such a driver must implement the low-level functions left as
//  pure-virtual by this class.

//  IEEProm                --  user interface 
//  CEEPromImpl            --  class implementing IEEProm 
//                             using abstract primitives like
//                             'eraseCommand', 'writeCommand' etc.
//  CMicronN25QEEProm      --  implements these primitives for
//                             a SPI EEPROM. Requires lower-level
//                             accessors to issue SPI operations
//  CAxiMicronN25QEEProm   --  implements SPI operations via 
//                             CPSW/AXI for the controller in SLAC
//                             firmware
//                             

class CMicronN25QEEProm : public CEEPromImpl {
   public:

	//! Destructor
	virtual ~CMicronN25QEEProm ( ) {};

	virtual void    setPromStatusReg(uint8_t value);
	virtual uint8_t getPromStatusReg();
	virtual uint8_t getManufacturerId();
	virtual uint8_t getManufacturerType();
	virtual uint8_t getManufacturerCapacity();

   protected:

	static const uint8_t WRITE_3BYTE_CMD    = 0x02;
	static const uint8_t WRITE_4BYTE_CMD    = 0x12;

	static const uint8_t READ_3BYTE_CMD     = 0x03;
	static const uint8_t READ_4BYTE_CMD     = 0x13;
   
	static const uint8_t FLAG_STATUS_REG    = 0x70;
	static const uint8_t FLAG_STATUS_RDY    = 0x80;
   
	static const uint8_t WRITE_ENABLE_CMD   = 0x06;
	static const uint8_t WRITE_DISABLE_CMD  = 0x04;

	static const uint8_t ADDR_ENTER_CMD     = 0xB7;
	static const uint8_t ADDR_EXIT_CMD      = 0xE9;

	static const uint8_t ENABLE_RESET_CMD   = 0x66;
	static const uint8_t RESET_CMD          = 0x99;
   
	static const uint8_t ERASE_CMD          = 0xD8;
	static const uint32_t ERASE_SIZE        = 0x10000;

	static const uint8_t STATUS_REG_WR_CMD  = 0x01;
	static const uint8_t STATUS_REG_RD_CMD  = 0x05;

	static const uint8_t DEV_ID_RD_CMD      = 0x9F;

	static const uint8_t WRITE_NONVOLATILE_CONFIG_CMD = 0xB1;
	static const uint8_t WRITE_VOLATILE_CONFIG_CMD    = 0x81;
	static const uint8_t READ_NONVOLATILE_CONFIG_CMD  = 0xB5;
	static const uint8_t READ_VOLATILE_CONFIG_CMD     = 0x85;

// Default Configuration:
// Number of dummy clock cycles = 0xF
// XIP mode at power-on reset = 0x7
// Output driver strength = x7
// Double transfer rate protocol = 0x1 ( = Disabled and only used in MT25Q only)
// Reset/hold = 0x0 (disabled to be MT25Q pin compatible with N25Q)
// Quad I/O protocol = 0x1
// Dual I/O protocol = 0x1
// 128Mb segment select = 0x1

	static const uint16_t DEFAULT_3BYTE_CONFIG = 0xFFEF;
	static const uint16_t DEFAULT_4BYTE_CONFIG = 0xFFEE;

	//! Enter 4-BYTE ADDRESS MODE Command
	virtual void enter32BitMode();

	//! Exit 4-BYTE ADDRESS MODE Command
	virtual void exit32BitMode();


	virtual void eraseCommand(uint32_t address);
	virtual void writeCommand(uint32_t address);
	virtual void readCommand(uint32_t address);
	virtual void resetFlash ( );
	virtual void writeEnable ( );
	virtual void writeDisable ( );

	virtual unsigned getEraseBlockSize() { return ERASE_SIZE; }
      
    //! Reset the FLASH memory Command

    //! Wait for the FLASH memory to not be busy
	virtual void waitForFlashReady ( );

    //! Pull the status register
	virtual uint32_t statusReg ( );


	virtual void set32BitModeReg()        = 0;
      
    //! Send address
    virtual void setAddr (uint32_t value) = 0;

	enum OP { OP_READ = 0, OP_WRITE = 1 };

    //! Send command
	virtual void setCmd (OP op, uint8_t cmd, uint16_t xtra, bool sendWriteEnable = true) = 0;

	virtual uint32_t getCmd() = 0;
      
    //! Send the data register
	virtual void setData ()   = 0;

    //! Get the data register
	virtual void getData ()   = 0;
};

#endif
