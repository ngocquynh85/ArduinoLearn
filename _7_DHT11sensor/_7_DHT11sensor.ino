#include <DHT.h>
#define DHTPIN 3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup(){
  Serial.begin(9600);
  dht.begin();
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
  
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C \t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.println(" *C ");
  
  delay(2000);
  
}
