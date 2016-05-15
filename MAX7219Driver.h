/**
 * Arduino - MAX7219 driver
 *
 * MAX7219Driver.h
 *
 * 10MHz Serial Interface
 * Individual LED Segment Control
 * Decode/No-Decode Digit Selection
 * 150μA Low-Power Shutdown (Data Retained)
 * Digital and Analog Brightness Control
 * Display Blanked on Power-Up
 * Drive Common-Cathode LED Display
 * Slew-Rate Limited Segment Drivers for Lower EMI (MAX7221)
 * SPI, QSPI, MICROWIRE Serial Interface (MAX7221)
 * 24-Pin DIP and SO Packages
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_MAX7219_H__
#define __ARDUINO_DRIVER_MAX7219_H__ 1

#define MAX7219_WIDTH 8
#define MAX7219_HEIGHT 8

#define MAX7219_DIGIR_ORDER LSBFIRST

class MAX7219Driver {

    unsigned char dataPin;
    unsigned char clockPin;
    unsigned char loadPin;

public:

    enum Registers {
        NOOP = 0x00,
        DIGIT0 = 0x01,
        DIGIT1 = 0x02,
        DIGIT2 = 0x03,
        DIGIT3 = 0x04,
        DIGIT4 = 0x05,
        DIGIT5 = 0x06,
        DIGIT6 = 0x07,
        DIGIT7 = 0x08,
        DECODE_MODE = 0x09,
        INTENSITY = 0x0a,
        SCAN_LIMIT = 0x0b,
        SHUTDOWN = 0x0c,
        DISPLAY_TEST = 0x0f
    };

    enum ScanLimit {
        DIGIT_UPTO_0 = 0x00,
        DIGIT_UPTO_1 = 0x01,
        DIGIT_UPTO_2 = 0x02,
        DIGIT_UPTO_3 = 0x03,
        DIGIT_UPTO_4 = 0x04,
        DIGIT_UPTO_5 = 0x05,
        DIGIT_UPTO_6 = 0x06,
        DIGIT_UPTO_7 = 0x07
    };

    enum ShutdownMode {
        SHUTDOWN_MODE = 0x00, NORMAL_MODE = 0x01
    };

    enum DecodeMode {
        NO_DECODE = 0x00,
        DECODE_0 = 0x01,
        DECODE_0_TO_3 = 0x0f,
        DECODE_0_TO_7 = 0xff
    };

    enum TestMode {
        TEST_MODE_OFF = 0x00, TEST_MODE_ON = 0x01
    };

    MAX7219Driver(unsigned char dataPin, unsigned char clockPin,
            unsigned char loadPin);

    void setShutdown(unsigned char value);

    void setDecodeMode(unsigned char mode);

    void setDisplayIntensity(unsigned char intensity);

    void setScanLimit(unsigned char limit);

    void setTestMode(unsigned char mode);

    void fill(unsigned char patern);

    void writeRegister(unsigned char reg, unsigned char value);

    void sendPackage(unsigned int package);

    unsigned int createPackage(unsigned char reg, unsigned char payload);
};

#endif /* __ARDUINO_DRIVER_MAX7219_H__ */
