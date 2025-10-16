#include <Arduino.h>
#include <prototype.h>

void setup() 
{
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

void loop() 
{
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
  int  volt = analogRead(VOLT_SENSOR); //def gonna have to calibrate
  float voltage = (volt * 3.3)/4096.0;
  float voltage_real = voltage * 5; 
  Serial.print("Voltage: ");
  Serial.print(voltage_real);
  Serial.println("V");
  /*if (voltage > 3.3)
  {
    digitalWrite(VOLTAGE_LED, HIGH);
    Serial.println("Voltage TOO HIGH!!");
  }
  else
  {
    digitalWrite(VOLTAGE_LED, LOW);
  }*/
  delay(1000);

}

