#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

char Resourses[][16] = {
  "Yandex",
  "Google",
  "Steam"
};

char Passwords[][16] = {
  "Yandex123",
  "Google123",
  "Steam12123"
};


int iUP_DWN = 0;


void setup()

{
 
lcd.begin(16, 2);

pinMode(13, INPUT);
pinMode(12, INPUT);
pinMode(11, INPUT);



}

void loop() {

 
int ButUp = digitalRead(13);
int ButDwn = digitalRead(12);
int ButClck = digitalRead(11);

delay(5);

if (ButUp == HIGH){
iUP_DWN ++;
  lcd.clear();
  if (iUP_DWN > 2){
    iUP_DWN = 0;
  }
}

delay(5);

if (ButDwn == HIGH){
iUP_DWN --;
  lcd.clear();
  if (iUP_DWN < 0){
    iUP_DWN = 2;
  }
}

delay(5);

 
lcd.setCursor(0, 0);
lcd.print(Resourses[iUP_DWN]);
lcd.setCursor(0, 1);
lcd.print(Passwords[iUP_DWN]);

delay(5);

}