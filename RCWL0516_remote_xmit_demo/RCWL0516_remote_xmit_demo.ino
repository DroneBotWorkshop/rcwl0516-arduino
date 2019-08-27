/*
  RCWL-0516 Remote Transmit Demo
  RCWL0516_remote_xmit_demo.ino
  Demonstrates remote using RCWL-0516 Microwave Sensor
  Use with RCWL-0516 Remote Receive Demo

  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Include libraries for transmitter
#include <RH_ASK.h> // Include RadioHead Amplitude Shift Keying Library
#include <SPI.h>  // Include dependant SPI Library 

// Define Input and Output
int Sensor = 2;     // RCWL-0516 Input Pin
int LED = 13;       // Output LED

// Define variables
int sensorval = 0;  // RCWL-0516 Sensor Value
String str_out;   // Output String

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

void setup() {

  rf_driver.init(); // Initialize ASK Object
  pinMode (Sensor, INPUT);  //RCWL-0516 as input
  pinMode (LED, OUTPUT);    //LED as OUTPUT
  digitalWrite(LED, LOW);  // Turn LED Off

}

void loop()
{

  sensorval = digitalRead(Sensor);  //Read Sensor value

  if (sensorval == HIGH) {
    str_out = "1";
    digitalWrite(LED, HIGH);  // Turn LED On
  } else {
    str_out = "0";
    digitalWrite(LED, LOW);  // Turn LED Off
  }

  // Compose output character
  static char *msg = str_out.c_str();

  rf_driver.send((uint8_t *)msg, strlen(msg));
  rf_driver.waitPacketSent();

}
