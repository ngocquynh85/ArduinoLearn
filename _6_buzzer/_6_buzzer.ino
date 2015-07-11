/*
  test buzzer
 delay: 5: not den. 6: den cham doi. 7: tron. 8: tron cham doi. 9: trang.
 4: kep.  3: ..
 Note: c d e f g a b C D E F G A B
 Freq:  A = 440  
 end sheet: |
 blank: n
   sheet ="c5c5g5g5a5a5g7f5f5e5e5d5d5c7|";
 */



int P_buzzer = 11;
String sheet;

long tempo = 110; //per min 

void setup(){
  Serial.begin(9600);
  pinMode(P_buzzer,OUTPUT);
  sheet ="";
   tempo = 60000/tempo;
}

void loop(){
  
  if (Serial.available()>0 ){
    char tmp;
    tmp = Serial.read();
    
    if (tmp=='|'){
      Serial.println("Begin music");
      Serial.print(sheet);
      Serial.print("\t Length:");
      Serial.println(sheet.length());
      play_music();  
    } else {
      sheet += char(tmp);
    } 
  }

}
//-----
void play_music(){
  if(sheet.length()<2){
     sheet="";
     Serial.println("Sheet error");
     return;
  }
  for (int i=0; i<= sheet.length()-2; i+=2){
    
    int v_freq     = freq(sheet.charAt(i));
    int v_duration = duration(sheet.charAt(i+1));
    
    Serial.print(sheet.charAt(i));
    Serial.print("\t");    
    Serial.print(v_freq);
    Serial.print("\t");
    Serial.print(v_duration);
    Serial.println();
    
    tone(P_buzzer, v_freq, v_duration);
    delay(v_duration);
    noTone(P_buzzer);
  }
  
  sheet = "";
}

//------
int freq(char fc){
  int f;

  switch (fc){
    case 'c':    f= 262;      break;
    case 'd':    f=  294;     break;
    case 'e':    f=  330;     break;
    case 'f':    f=  349;     break;
    case 'g':    f=  392;     break;
    case 'a':    f=  440;     break;
    case 'b':    f=  494;     break;
    case 'C':    f=  523;     break;
    case 'n':    f=0;         break;
    default:     f= 800;      break;
  }
  return f;
}

//------
int duration(char dr){
  long dur;
  switch (dr){
    case '5': dur = tempo;      break;
    case '6': dur = tempo*1.5;  break;
    case '7': dur = tempo*2;    break;
    case '8': dur = tempo*3;    break;
    case '9': dur = tempo*4;    break;
    case '4': dur = tempo*0.75; break;
    case '3': dur = tempo*0.5;  break;
    default: dur = tempo;   break;  
  }
  if (dur <0){
    dur = 0;
  }
  return dur;
}


