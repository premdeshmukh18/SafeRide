#include<LiquidCrystal.h>  //LCD Library
#define mq3_Pin 7   //mq3 out pin to pin7
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;  //LCD to arduino connection
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  //pins used passed as arguments in the instance 
int sensorval;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);       //defining no. of column and rows
  pinMode(6,OUTPUT);     //pin 6 as output connected to led
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorval = digitalRead(mq3_Pin);
  if(sensorval == 0)  //sensorval = 1 for absence of alcohol
  { 
    digitalWrite(6,HIGH);
    lcd.setCursor(0,1);            //cursor position column 0 row 1
    lcd.print("Alcohol Detected");
    lcd.display();
  }    
  else
  {
    digitalWrite(6,LOW);
    lcd.setCursor(0,1);
    lcd.print("No Alcohol Detected");
    lcd.display();    
  }
  delay(1000);
  lcd.clear();
}
