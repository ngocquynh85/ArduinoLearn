int PLed = 13;

String str = "";
int chr = 0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
      chr = Serial.read();
      str += char(chr);

      Serial.println(str);
  }

  
}
