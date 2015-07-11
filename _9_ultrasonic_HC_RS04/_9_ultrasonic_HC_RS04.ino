#include <Ultrasonic.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20,4);

Ultrasonic ultrasonic(5,6, 100000); //trig, Echo pin , timeout ms. 1000 micro S = 1 ms = 17cm

void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("cm");
  lcd.setCursor(5,1);
  lcd.print("ms");
  
}

void loop(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   ");  
  lcd.setCursor(0,0);  
  lcd.print(ultrasonic.Ranging(CM));
  
  lcd.setCursor(0,1);
  lcd.print("     ");  
  lcd.setCursor(0,1);  
  lcd.print(ultrasonic.Timing());
  
  lcd.setCursor(5,0);
  lcd.print("cm");
  lcd.setCursor(7,1);
  lcd.print("ms");

  Serial.print(ultrasonic.Ranging(CM));  
  Serial.println("cm");
  delay(100);
}

