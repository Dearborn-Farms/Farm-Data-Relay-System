//  FARM DATA RELAY SYSTEM
//
//  Basic Sensor Example
//
//  Developed by Timm Bogner (bogner1@gmail.com) for Sola Gratia Farm in Urbana, Illinois, USA.
//  An example of how to send data using "fdrs_sensor.h".
//

#include "fdrs_sensor.h"

float data1 = 42.069;
float data2 = 21.0345;

void setup() {

  beginFDRS();
}
void loop() {
  loadFDRS(data1, 101);
  loadFDRS(data2, 102);
  sendFDRS();
  delay(30000);
}
