//library
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>

Adafruit_LiquidCrystal lcd(0);
Servo myservo;

//PIN
#define PIR 2 //PIR
#define buzzer 5// Buzzer

//var
int statusPIR = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  pinMode(buzzer, OUTPUT);
  myservo.attach(4);//servo
  myservo.write(0);
  
  // start lcd
  lcd.begin(16, 2); 
  lcd.setCursor(5,0);
  lcd.print("Selamat");
  lcd.setCursor(5,1);
  lcd.print("Datang");
  delay(3000);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0,0);
  myservo.write(0);
  
  statusPIR = digitalRead(PIR);
  Serial.println(statusPIR);
  
  if (statusPIR > 0){
   tone(5, 500);
   Serial.println("Terdeteksi Pergerakan");
   myservo.write(90);
   lcd.setCursor(5,0);
   lcd.print("Silahkan");
   lcd.setCursor(5,1);
   lcd.print("Masuk");
   delay(5000);
  }
  else {
   noTone(5);
   Serial.println("Tidak ada Pergerakan");
   lcd.setCursor(5,0);
   lcd.print("Selamat");
   lcd.setCursor(5,1);
   lcd.print("Datang");
  }
  delay(4000);
  Serial.println();
}