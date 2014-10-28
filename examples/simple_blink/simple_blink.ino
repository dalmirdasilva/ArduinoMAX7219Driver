#include <MAX7219Driver.h>

void setup() {

    Serial.begin(9600);
    Serial.println("Ready.");

    MAX7219Driver driver(12, 11, 10);
    driver.setTestMode(MAX7219Driver::TEST_MODE_OFF);
    driver.setScanLimit(MAX7219Driver::DIGIT_UPTO_7);
    driver.setDisplayIntensity(0x0f);
    driver.setDecodeMode(MAX7219Driver::NO_DECODE);
    //driver.setShutdown(MAX7219Driver::NORMAL_MODE);
    
    unsigned char i = 0;
    unsigned int package;

    while (true) {
        
        i++; 
        package = driver.createPackage(i, MAX7219Driver::DIGIT0);
        driver.sendPackage(package);
        package = driver.createPackage(i, MAX7219Driver::DIGIT1);
        driver.sendPackage(package);
        package = driver.createPackage(i, MAX7219Driver::DIGIT2);
        driver.sendPackage(package);
        package = driver.createPackage(i, MAX7219Driver::DIGIT3);
        driver.sendPackage(package);
        package = driver.createPackage(i, MAX7219Driver::DIGIT4);
        driver.sendPackage(package);
        package = driver.createPackage(i, MAX7219Driver::DIGIT5);
        driver.sendPackage(package);
        package = driver.createPackage(i, MAX7219Driver::DIGIT6);
        driver.sendPackage(package);
        package = driver.createPackage(i, MAX7219Driver::DIGIT7);
        driver.sendPackage(package);
        Serial.print('.');
        delay(1000);
    }
}

void loop() {
}