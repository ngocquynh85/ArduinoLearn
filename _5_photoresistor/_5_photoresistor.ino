/*
- use photoresistor.
 - Dùng 2 mạch cầu phân áp.  1 cái đo ánh sáng, 1 cái xác định mứcđộ
 */

int P_led = 2;
int P_photo = A0; 
int P_poten = A1;

void setup(){
  Serial.begin(9600);
  pinMode(P_led, OUTPUT);
  
}


void loop(){
   float v_photo = analogRead(P_photo);
   float v_poten =analogRead(P_poten);
   float v_photo_volt = v_photo*5.0/1023.0;
   float v_poten_volt = v_poten*5.0/1023.0;
   
   
   
   Serial.print(v_photo);
   Serial.print("\t");
   Serial.print(v_photo_volt);
   Serial.print("\t");
   Serial.print(v_poten);
   Serial.print("\t");
   Serial.print(v_poten_volt);
   
   if (v_photo_volt < v_poten_volt){
      digitalWrite(P_led,HIGH);
      Serial.print(" LED ON");
   } else {
      digitalWrite(P_led,LOW);

   }
   
   Serial.println();
   
   delay(1000);
}


