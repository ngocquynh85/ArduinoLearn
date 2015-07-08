/*
 * Bài 1: tìm hiểu Led.
 * - setup pinmode
 * -bật tắt pin (cấp dòng tối đa 40mA). Chân output 3.3V được 50mA.
 * - Sử dụng Serial.write. (1 cách debug)
 */

int PLed = 13;
int inByte = 0; //serial incom 




  
void setup(){
  pinMode(PLed, OUTPUT);
  Serial.begin(9600);

}

void loop(){
  //checkSerial();
 
  //batden(PLed, 1000 );
  //log("Bat den");
  
  //digitalWrite(PLed, LOW );
  //log("Tat den ");
  //delay(100);  

  while (Serial.available() >0 ){
    //str_inByte = Serial.read();
    Serial.print("Du lieu la: ");
    Serial.println(Serial.read());
  }

}


//-------------
/*
void serialEvent(){
  char str_inByte[] = "" ;
  
  Serial.println( "Co tin hieu gui serial : ");
  Serial.println(Serial.available() );
  
  while (Serial.available()>0){
    inByte = Serial.read();
    Serial.println( inByte );
  }
}
*/

void checkSerial(){
  while(!Serial ){
    
  }
  log("Cong Serial ready !!!");
}

void batden(int PLed, int thoigian ){
  digitalWrite(PLed, HIGH);
  delay(thoigian); 
  
}

void log(char str_log[]){
  Serial.println(str_log);
} 


