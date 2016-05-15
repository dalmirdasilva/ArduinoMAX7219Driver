/**
 * Arduino - MAX7219 driver
 *
 * MAX7219Driver.cpp
 *
 * MAX7219 driver.
 *
 * @author Dalmir da Silva <dalmirdasilva@gmail.com>
 */

#ifndef __ARDUINO_DRIVER_MAX7219_CPP__
#define __ARDUINO_DRIVER_MAX7219_CPP__ 1

#include "MAX7219Driver.h"
#include <Arduino.h>

MAX7219Driver::MAX7219Driver(unsigned char dataPin, unsigned char clockPin,
        unsigned char loadPin) {
    this->dataPin = dataPin;
    this->clockPin = clockPin;
    this->loadPin = loadPin;
    pinMode(dataPin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(loadPin, OUTPUT);
}

void MAX7219Driver::setShutdown(unsigned char value) {
    writeRegister(SHUTDOWN, value);
}

void MAX7219Driver::setDecodeMode(unsigned char mode) {
    writeRegister(DECODE_MODE, mode);
}

void MAX7219Driver::setDisplayIntensity(unsigned char intensity) {
    writeRegister(INTENSITY, intensity);
}

void MAX7219Driver::setScanLimit(unsigned char limit) {
    writeRegister(SCAN_LIMIT, limit);
}

void MAX7219Driver::setTestMode(unsigned char mode) {
    writeRegister(DISPLAY_TEST, mode);
}

void MAX7219Driver::fill(unsigned char patern) {
    unsigned char digitMap[MAX7219_WIDTH] = {DIGIT0, DIGIT1, DIGIT2, DIGIT3,
            DIGIT4, DIGIT5, DIGIT6, DIGIT7};
    for (unsigned char i = 0; i < MAX7219_WIDTH; i++) {
        writeRegister(digitMap[i], patern);
    }
}

void MAX7219Driver::writeRegister(unsigned char reg, unsigned char value) {
    unsigned int package = createPackage(reg, value);
    sendPackage(package);
}

void MAX7219Driver::sendPackage(unsigned int package) {
    unsigned char reg = (unsigned char) ((package >> 8) & 0xff);
    unsigned char order = MSBFIRST;
    if (reg >= DIGIT0 && reg <= DIGIT7) {
        order = MAX7219_DIGIR_ORDER;
    }
    digitalWrite(loadPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, reg);
    shiftOut(dataPin, clockPin, order, (unsigned char) (package & 0xff));
    digitalWrite(loadPin, HIGH);
}

unsigned int MAX7219Driver::createPackage(unsigned char reg,
        unsigned char payload) {
    unsigned int package;
    package = (0x000f & reg);
    package <<= 8;
    package |= (0x00ff & payload);
    return package;
}

#endif /* __ARDUINO_DRIVER_MAX7219_CPP__ */
