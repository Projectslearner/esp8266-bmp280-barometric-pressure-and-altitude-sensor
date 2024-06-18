/*
    Project name : ESP8266 BMP280 Barometric Pressure and Altitude Sensor
    Modified Date: 18-06-2024
    Code by : Projectslearner
    Website : 
*/

#include <Wire.h>https://projectslearner.com/learn/esp8266-bmp280-barometric-pressure-and-altitude-sensor
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

// Create an instance of the BMP280 sensor
Adafruit_BMP280 bmp; // I2C

void setup() {
  Serial.begin(9600);
  
  // Initialize the sensor
  if (!bmp.begin(0x76)) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  // Read temperature, pressure, and altitude
  float temperature = bmp.readTemperature();
  float pressure = bmp.readPressure() / 100.0F; // Convert Pa to hPa
  float altitude = bmp.readAltitude(1013.25); // Sea level pressure in hPa

  // Print the values to the Serial Monitor
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" *C");

  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.print("Approx. Altitude = ");
  Serial.print(altitude);
  Serial.println(" m");

  delay(2000); // Delay before the next reading
}
