#include <Arduino.h>

Servo myservo; //deklarasi objek

//deklarasi pin
const int btnUp = 6; 
const int pinLed = 7;
const int servoPin = 9;

//inisialisasi variabel
int valOff = 0; //insiaslisasi variabel untuk servo saat button tidak ditekan
int valOn = 90; //inisialisasi variabel untuk servo saat button ditekan
bool lastUpState = HIGH;


void setup() {
  pinMode(pinLED, OUTPUT); //led = output
  pinMode(btnUp, INPUT_PULLUP) //button = input pullup
  myservo.attach(servoPin); //menghubungkan servo ke pin digital arduino
  Serial.begin(9600);//mengaktifkan serial komunikasi
}

void loop() {
  bool upState = digitalRead(btnUp);
  if(lastUpState == HIGH){ //kondisi saat button tidak ditekan
    digitalWrite(pinLed, LOW); //led = off
    myservo.write(valOff); //servo = 0 derajat
    Serial.print("DRC: Closed"); 
  } else{ //kondisi saat button ditekan dan ditahan 
    digitalWrite(pinLed, HIGH); //led = on
    myservo.write(valOn); //servo = 90 derajat
    Serial.print("DRC: Active");
  }
  delay(100)
}
