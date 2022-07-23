#include<SoftwareSerial.h>
int x = 0;
int emergency = 3;
int pir = 2;
int e,p,v;
int relay = 4;
int vib = 5;
int led = 6;
int count=0;
void setup() { 
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  pinMode(emergency,INPUT);
  pinMode(pir,INPUT);
  digitalWrite(relay,LOW);
}
void loop() {
  e = digitalRead(emergency);
  if(e==LOW){
    digitalWrite(relay,HIGH);
  }
  else{
    digitalWrite(relay,LOW);
  }
  p = digitalRead(pir);
  if(p==HIGH){
    count = count + 1;
    Serial.print("Movement count=");
    Serial.println(count);
    delay(1000);
  }
  v = digitalRead(vib);
  if(v==HIGH){
    digitalWrite(led,HIGH);
    Serial.print("Vibration detected");
    Serial.println();
    delay(1000);
  }
  else{
    digitalWrite(led,LOW);
  }
}
