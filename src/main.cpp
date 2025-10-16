#include <Arduino.h>

// voltage input
#define VOLT_SENSOR 5

// fault inputs
#define F1_BUTTON 34
#define F2_BUTTON 4

// LEDS
#define BLUE_LED 26
#define YELLOW_LED 14
#define VOLTAGE_LED 18

// RADIO
#define RX 16
#define TX 17

void setup() {
  Serial.begin(115200);
  Serial.println("STARTING PROTOTYPE!");

  // set input for volt sensor
  pinMode(VOLT_SENSOR, INPUT);
  
  // set input for faults
  pinMode(F1_BUTTON, INPUT);
  pinMode(F2_BUTTON, INPUT);

  // set output for LEDS
  pinMode(BLUE_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(VOLTAGE_LED, OUTPUT);

  // RADIO
}

void loop() {
  // FAULTS & FAULTS LEDS
  if(digitalRead(F1_BUTTON) == HIGH)
  {
    digitalWrite(BLUE_LED, HIGH);
    Serial.println("Fault 1 Detected :(");
  }
  else
  {
    digitalWrite(BLUE_LED, LOW);
  }
  
  if(digitalRead(F2_BUTTON) == HIGH)
  {
    digitalWrite(YELLOW_LED, HIGH);
    Serial.println("Fault 2 Detected :(");
  }
  else
  {
    digitalWrite(YELLOW_LED, LOW);
  }

  // VOLTAGE SENSOR & VOLTAGE LED
  long voltage = analogRead(VOLT_SENSOR); //def gonna have to calibrate
  Serial.print("Voltage: ");
  Serial.print(voltage);

}

