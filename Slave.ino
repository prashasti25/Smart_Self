#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,10,11,12,13);
#include<SoftwareSerial.h>
SoftwareSerial gps(4,3);
int x = 0;
int b;
int BUZZ = 7;
int button = 5;
void initModule(String cmd, char *res, int t)
{
  while(1)
  {
    Serial.println(cmd);
    delay(100);
    while(Serial.available()>0)
    {
      if(Serial.find(res))
      {
        Serial.println(res);
        delay(t);
        return;
      }
      else
      {
        Serial.println("Error");
      }
    } 
    delay(t);
  }
}
void setup()
{
  lcd.begin(16,2);
  Serial.begin(9600);
  gps.begin(9600);
  pinMode(BUZZ, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(BUZZ, LOW);
  lcd.clear();
//  lcd.setCursor(0,0); lcd.print("VIT BHOPAL");
//  lcd.setCursor(0,1); lcd.print("SMART SELF"); delay(1000);lcd.clear();
//  lcd.setCursor(0,0); lcd.print("DEFENSE DEVICE");
//  lcd.setCursor(0,1); lcd.print("EPICS PROJECT"); delay(1000); lcd.clear();
//
//  lcd.setCursor(0,0); lcd.print("Waiting for GPS");
//  lcd.setCursor(0,0); lcd.print("Signal    "); delay(1000);
//  lcd.clear();
//  lcd.setCursor(0,0);
//  lcd.print("Lat: 17.475889");
//  lcd.setCursor(0,1);  
//  lcd.print("Log: 78.2564126");
//  delay(1000);
//  lcd.clear();
//
//  lcd.setCursor(0,0);lcd.print("GPS is OK"); delay(1000); lcd.clear();

  lcd.setCursor(0,0); lcd.print("Initializing");
  lcd.setCursor(0,1);lcd.print("GSM Modem"); delay(1000);
  initModule("AT","OK",1000);
  initModule("AT+CMGF=1", "OK",1000);

  lcd.setCursor(0,0); lcd.print("Initialized");
  lcd.setCursor(0,1); lcd.print("Successfully"); delay(1000);lcd.clear();
}
void loop(){
  b = digitalRead(button);
    if (b == LOW) { 
      digitalWrite(BUZZ,HIGH);
      lcd.setCursor(0,0); lcd.print("Emergency");
      tone(BUZZ,1000); 
      delay(1000);
    }
    if(b==HIGH)
      {
        digitalWrite(BUZZ,LOW);
        lcd.clear();
        noTone(BUZZ); 
      }
}
