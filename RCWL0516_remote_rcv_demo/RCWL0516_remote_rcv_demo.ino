/*
  RCWL-0516 Remote Receive Demo
  RCWL0516_remote_rcv_demo.ino
  Demonstrates remote using RCWL-0516 Microwave Sensor
  Use with RCWL-0516 Remote Transmit Demo

  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Include libraries for receiver
#include <RH_ASK.h> // Include RadioHead Amplitude Shift Keying Library
#include <SPI.h>  // Include dependant SPI Library 

// Define Output
int LED = 13;       // Output LED

// Define variable
String str_out;   // Output String

// Create Amplitude Shift Keying Object
RH_ASK rf_driver;

void setup() {

  rf_driver.init(); // Initialize ASK Object
  pinMode (LED, OUTPUT);    //LED as OUTPUT
  digitalWrite(LED, LOW);   // Turn LED Off

}

void loop()
{
  // Set buffer to size of expected message
  uint8_t buf[1];
  uint8_t buflen = sizeof(buf);
  // Check if received packet is correct size
  if (rf_driver.recv(buf, &buflen))
  {

    // Message received with valid checksum
    // Get values from string

    // Convert received data into string
    str_out = String((char*)buf);

    if (str_out == "1") {
      digitalWrite(LED, HIGH);  // Turn LED On
    } else {
      digitalWrite(LED, LOW);  // Turn LED Off
    }

  }
}
