// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// PCA9536_R11
// This code is designed to work with the PCA9536_I2CR_R11 I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/products

#include<Wire.h>

// PCA9536_R11 I2C address is 0x41(65)
#define Addr 0x41

void setup()
{
  // Initialise I2C communication
  Wire.begin();
  // Initialise Serial Communication, set baud rate = 9600
  Serial.begin(9600);
  
  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select configuration register
  Wire.write(0x03);
  // Set all pins as OUTPUT
  Wire.write(0x00);
  // Stop I2C transmission
  Wire.endTransmission();
  delay(300);
}

void loop()
{

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select output port register
  Wire.write(0x01);
  Wire.write(0x01);
  // Stop I2C transmission
  Wire.endTransmission();
  Serial.println("Pin-1 state is : HIGH");
  delay(1000);
  
  Wire.beginTransmission(Addr);
  // Select output port register
  Wire.write(0x01);
  Wire.write(0x00);
  // Stop I2C transmission
  Wire.endTransmission();
  Serial.println("Pin-1 state is : LOW");
  delay(1000);
}
