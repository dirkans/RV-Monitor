#include <LiquidCrystal_I2C.h> //lib
#include <Wire.h>
#include <DHT.h>


  float hpa=1013;
  float co2=1150;
  float x=-2.3;
  float y=0.5;
  float delaymenu=2000;

#define DHTPIN 2;
#define DHTTYPE DHT11;
DHT dhtin(2, DHT11);
DHT dhtext(3, DHT11);



   byte grados[8] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
 };

 byte happy[8] = {
B00000,
B10001,
B00000,
B00000,
B10001,
B01110,
B00000
};

  int buttonup = 7;
  int buttondown = 3;
  int val = 0;
  int selection = 0;
  int ledPin = 13;
  
  

LiquidCrystal_I2C lcd (0x27,20,4);

void setup() {
  pinMode(7, INPUT);
  pinMode(3, INPUT);
  pinMode(13, OUTPUT);

Serial.begin(9600);
  dhtin.begin();
  dhtext.begin();

  
  lcd.createChar (0,grados);
  lcd.createChar (1,happy);
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   DIRKANS RV");
  lcd.setCursor(0, 1);
  lcd.print("    MONITOR");
  lcd.setCursor(0,2);
  lcd.print("by Pablo Ambrosio");
  delay(2000);
  //lcd.setCursor(0,3);
  //lcd.print("Please Wait - 3");
  //delay(1000);
  //lcd.setCursor(0,3);
  //lcd.print("Please Wait - 2");
  //delay(1000);
  //lcd.setCursor(0,3);
  //lcd.print("Please Wait - 1");
  //delay(1000);
  lcd.clear();


}

///////// MENU 1//////////////
void m1()
{
    float inthum = dhtin.readHumidity();
    float inttemp = dhtin.readTemperature();
    float exthum = dhtext.readHumidity();
    float exttemp = dhtext.readTemperature();
    
lcd.print("IN Temp: " +String(inttemp,1));
lcd.write(byte (0));
lcd.setCursor(0,1);
lcd.print("IN Hum: " +String(inthum,0)+"%");
lcd.setCursor(0,2);
lcd.print("Ext Temp: " +String(exttemp,1));
lcd.write(byte (0));
lcd.setCursor(0,3);
lcd.print("Ext Hum: " +String(exthum,0)+"%");
delay(2000);

}


///////// MENU 1//////////////////


////////////////// MENU 2------------------
void m2()
{
  
  lcd.print("Atmospheric Pressure");
  lcd.setCursor(0,1);
  lcd.print(String(hpa,0)+" hPa");
  lcd.setCursor(0,2);
  lcd.print("Feeling: ");
  lcd.write(byte (1));
  delay(500);
  }

///////////////// MENU 2------------------


///////////////MENU 3 ------------------
void m3()
{
lcd.print("CO2 Level");
lcd.setCursor(0,1);
lcd.print(String(co2,0)+" ppm");
lcd.setCursor(0,2);
if(co2 > 1000){
lcd.print("OPEN WINDOWS SOON!!!");
} else {lcd.print("Levels ok");

}
delay(2000);
}

///////////////MENU 3 ------------------


///////////////MENU 4 ------------------
void m4()
{
 lcd.print("RV LEVELING");
  lcd.setCursor(0,1);
  lcd.print("X Axis: ");
  lcd.print(String(x,1));
  lcd.setCursor(0,3);
  lcd.print("Y Axis: ");
  lcd.print(String(y,1));
 delay(2000);
}

///////////////MENU 4 ------------------

void loop() {


   ///////////////////// BEGIN OF CODE
lcd.clear();
m1();
delay(2000);
lcd.clear();
m2();
delay(2000);
lcd.clear();
m3();
delay(2000);
lcd.clear();
m4();
delay(2000);
}











  
// val = digitalRead(buttonup);

 //if (digitalRead(buttonup) == HIGH) {
   // selection += 1;
    //delay(750);
  //}
  //if (digitalRead(buttondown) == HIGH) {
//    selection -= 1;
    //delay(750);
  //}
//    if (selection > 3) {
      //selection = 0;
    //}
    //if (selection < 0) {
//      selection = 4;
    //}

  //switch (selection) {

//    case 0:                            
      //lcd.clear();
      //m1();
      //break;
//
    //case 1:
//      lcd.clear();
      //m2();
      //break;

    //case 2:
//      lcd.clear();
      //m3();
      //break;

    //case 3:
//      lcd.clear();
      //m4();
      //break;
  //}
///////////////////////////////////////////////////////////////////TEST ZONE
  
