#include <config.h>
#include <ds3231.h>

#include <DHT.h>
#define DHTPIN 3
#define DHTTYPE DHT11
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

DHT dht(DHTPIN, DHTTYPE);

void setup(){
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Quynh phot phet");
  lcd.setCursor(0,1);
  lcd.print("T:");
  lcd.setCursor(9,1);
  lcd.print("H: ");
  lcd.cursor();
  lcd.blink();
  
}

void loop(){
  float h   = dht.readHumidity();
  float t   = dht.readTemperature();
  float f   = dht.readTemperature(true);
  
  if( isnan(h) || isnan(t) || isnan(f) ){
     Serial.println("Failed to read from DHT sensor");
     delay(2000);
     return;
  }
  
  float hic  = dht.computeHeatIndex(t,h,false);
  
  lcd.setCursor(2,1);
  lcd.print(t);
  lcd.setCursor(6,1);
  lcd.print("c ");

  lcd.setCursor(11,1);
  lcd.print(h);
    lcd.setCursor(15,1);
  lcd.print("%");
  
  lcd.setCursor(15,0);
  int r = random(3);
  if (r==0) lcd.print("\\");
  if (r==1) lcd.print("-");
  if (r==2) lcd.print("/");
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C \t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.println(" *C ");
  
  
  
  delay(1000);
  
}
