#include <Arduino.h>

// ===================== PIN SETUP =====================
const int potPin = A0;   
const int ledPin = 9;   

// ===================== VARIABEL =====================
int nilaiADC = 0;  
int pwm = 0;       

void setup() {

  // ===================== OUTPUT SETUP =====================
  pinMode(ledPin, OUTPUT);

  // ===================== SERIAL MONITOR =====================
  Serial.begin(9600);
}

void loop() {

  // ===================== PEMBACAAN SENSOR =====================
  nilaiADC = analogRead(potPin);

  // ===================== PEMROSESAN DATA =====================
  pwm = map(nilaiADC,
            0,     // min ADC
            1023,  // max ADC
            0,     // min PWM
            255);  // max PWM

  // ===================== OUTPUT PWM =====================
  analogWrite(ledPin, pwm);

  // ===================== MONITORING =====================
  Serial.print("ADC: ");
  Serial.print(nilaiADC);

  Serial.print(" | PWM: ");
  Serial.println(pwm);

  // ===================== STABILISASI =====================
  delay(50);
}