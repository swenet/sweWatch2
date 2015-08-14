
/*
 * sweWatch 2 source code
 * edited on August 8th
 * edit it as you want
 */
#include "U8glib.h"
#include "RTClib.h"
#include <Wire.h>

RTC_DS1307 RTC;
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);
//int ReadSerial = 0;

void setup() {
  Wire.begin();
    RTC.begin();
  clear_Display();
    //RTC.adjust(DateTime(__DATE__, __TIME__));
    pinMode(3,INPUT);
      //RTC.adjust(DateTime(__DATE__, __TIME__));  
  
}


void loop() {
  
  if(digitalRead(3) == HIGH){
  u8g.firstPage();  
   do {
  drawDate();
   }while(u8g.nextPage());
    delay(3000);
    if(digitalRead(3) == HIGH){
      drawAbout();
      delay(5000);
    }else{
      
      delay(2000);
    }
    
  clear_Display();  
}
   delay(150);
}





void clear_Display(){
  u8g.firstPage();  
  do {
    u8g.setPrintPos(0,0);
    u8g.print("");
  }while(u8g.nextPage());
}




void drawDate(){

  DateTime now = RTC.now();
 u8g.setFont(u8g_font_6x10);
  u8g.setPrintPos(0,10);


  u8g.print((int)(now.year()));
    u8g.print("/");
    
  u8g.print((int)(now.month()));
    u8g.print("/");
    
  u8g.print((int)(now.day()));
  u8g.setPrintPos(107, 10);
  u8g.print("SWE");
  
   u8g.setFont(u8g_font_freedoomr25n);
    u8g.setPrintPos(15,64);
    
  u8g.print((int)(now.hour()));
    u8g.print(":");
    if ((int)(now.minute()) < 10) {
      u8g.print("0");
  u8g.print((int)(now.minute()));
    }else{
    u8g.print((int)(now.minute()));
  }
   // u8g.print(":");
    
  //u8g.print((int)(now.second()));
}

void drawAbout(){
   u8g.setFont(u8g_font_6x10);
  
u8g.firstPage();
do
{
  u8g.setPrintPos(0,10);
  u8g.print("About");
  u8g.setPrintPos(0,20);
  u8g.print("Code by SWE");
  u8g.setPrintPos(0,30);
  u8g.print("Web:http://iswe.cc");
  u8g.setPrintPos(0,40);
  u8g.print("Code is free");
}while(u8g.nextPage());
}
