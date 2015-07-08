int P_Led = 13;

int S_Input = 0; 

char str_in[10] = {};
int curr_pos = 0;

void setup() {

  pinMode(P_Led, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
  //phan header tab
  Serial.println("Start monitor serial port ");
  Serial.print("Decimal");
  Serial.print("\t");
  Serial.println("Char");
  
  curr_pos = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available()>0 ){
    S_Input  = Serial.read();

    str_in[curr_pos] = S_Input;
    curr_pos +=1;
    
    Serial.print(S_Input); 
    Serial.print("\t");
    Serial.print(char(S_Input));

    if (S_Input == '1'){
      Serial.print("  LED ON ");
      digitalWrite(P_Led,HIGH);
    }
    if (S_Input =='0'){
      Serial.print("  LED OFF ");
      digitalWrite(P_Led,LOW );
    }

    //if (S_Input == '9'){
      Serial.print( "\t string: ");
      Serial.print(str_in); 
    //}
    
  
    Serial.println();
  }
  
}
