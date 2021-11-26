#include <BnrOneA.h>   // Bot'n Roll ONE A library
#include <EEPROM.h>    // EEPROM reading and writing
#include <SPI.h>       // SPI communication library required by BnrOne.cpp
BnrOneA one;           // declaration of object variable to control the Bot'n Roll ONE A
#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7); // RX | TX

//constants definition
#define SSPIN  2       // Slave Select (SS) pin for SPI communication

void setup() {
  // put your setup code here, to run once:


  Serial.begin(9600);     // set baud rate to 9600bps for printing values at serial monitor.
  mySerial.begin(9600);
  one.spiConnect(SSPIN);   // start SPI communication module
  one.stop();              // stop motors
  one.minBat(10.5);        // define de minimum battery voltage. Robot stops if voltage is below the specified value!

}

void loop() {
  // put your main code here, to run repeatedly:

  float battery = one.readBattery(); // read battery voltage

  if (mySerial.available()) {
    char opcao = mySerial.read();

    Serial.write(opcao);
    switch (opcao) {
      case 'F':
        one.lcd2("    Forward "); // print data on LCD line 2
        one.move(50, 50);         // Forward
        break;
      case 'S':
        one.lcd2("Battery V: ", battery); // print data on LCD line 2
        //one.lcd2("     Stop   ");
        one.stop();               // Stop Motors
        break;
      case 'B':
        one.lcd2("   Backwards ");
        one.move(-50, -50);       // Backwards
        break;
      case 'R':
        one.lcd2("  Rotate Right ");
        one.move(50, -50);        // Rotate Right
        break;
      case 'L':
        one.lcd2("  Rotate Left ");
        one.move(-50, 50);        //Rotate Left
        break;
    }
  }



}
