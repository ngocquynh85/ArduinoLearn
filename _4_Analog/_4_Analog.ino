int P_in = 2;

void setup(){
  pinMode(P_in, INPUT);
  Serial.begin(9600);
}

void loop(){
  Serial.println(digitalRead(P_in));
  delay(1000);
}

