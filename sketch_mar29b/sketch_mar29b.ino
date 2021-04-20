#include <Countimer.h>

#include <splash.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

//#define LOGO16_GLCD_HEIGHT 16
//#define LOGO16_GLCD_WIDTH 16
//static const unsigned char PROGMEM logo16_glcd_bmp[] =
//{ B00000000, B11000000,
// B00000001, B11000000,
// B00000001, B11000000,
// B00000011, B11100000,
// B11110011, B11100000,
// B11111110, B11111000,
// B01111110, B11111111,
// B00110011, B10011111,
// B00011111, B11111100,
// B00001101, B01110000,
// B00011011, B10100000,
// B00111111, B11100000,
// B00111111, B11110000,
// B01111100, B11110000,
// B01110000, B01110000,
// B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 64)
#error(“Height incorrect, please fix Adafruit_SSD1306.h!”);
#endif

Countimer tDown;

const int switchPin1 = 8;
const int switchPin2 = 9;

int ledPin = 13;
int ledState = LOW;

int counter1 = 0;
int currentState1 = 0;
int previousState1 = LOW;

int counter2 = 0;
int currentState2 = 0;
int previousState2 = LOW;

void setup()
{
Serial.begin(9600);

display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
display.display();
delay(500);
display.clearDisplay();

pinMode(switchPin1, INPUT);
pinMode(switchPin2, INPUT);

// Count-down timer with 21s
tDown.setCounter(0, 0, 20, tDown.COUNT_DOWN, tDownComplete);
// Call print_time2() method every 1s.
tDown.setInterval(print_time2, 1000);
//tNone.setInterval(print_none, 2000);

scrolltext1();
delay(1000);
display.clearDisplay();
display.display();
//Serial.println(“Press Start to activate the Countdown Timer”);
}

void loop()
{
tDown.run();
//tNone.run();

display.clearDisplay();
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(35,10);
display.print(“R2M8N”);
display.setCursor(20,30);
display.print(tDown.getCurrentTime());
display.display();
//delay(100);

currentState1 = digitalRead(switchPin1);
currentState2 = digitalRead(switchPin2);
// read input value
if(currentState1 != previousState1){
if(currentState1 == HIGH){
counter1 = counter1 +1;
}
}
else if (currentState1 == LOW){
counter1 = 0;
}

// read input value
if(currentState2 != previousState2){
if(currentState2 == HIGH){
counter2 = counter2 +1;
}
}
else if (currentState2 == LOW){
counter2 = 0;
}

switch (counter1)
{
case 1:
if (counter1 == 0) {
return;

case 2:
if (counter1 > 1) {
tDown.start();
break;
return;
}
}
}

switch (counter2)
{
case 1:
if (counter2 == 0) {
return;

case 2:
if (counter2 > 1) {
tDown.pause();
break;
return;
}
}
}
}
// //MtUp.stop();
// tDown.stop();

// //MtUp.restart();
// tDown.restart();

// //MtUp.start();
// tDown.start();

// //MtUp.pause();
// tDown.pause();

void print_time2()
{
//Serial.print(“tDown: “);
//Serial.println(tDown.getCurrentTime());
}
void tDownComplete()
{
display.clearDisplay();
scrolltext2();
delay(1000);
display.clearDisplay();
display.display();
//display.setTextSize(2);
//display.setTextColor(WHITE);
//display.setCursor(0,0);
//display.println(“TIME OUT!”);
//display.display();
delay(4000);
//Serial.println(“TIME OUT!!!”);
digitalWrite(13, LOW);
}
void scrolltext1(void) {
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(42,0);
display.clearDisplay();
display.println(“PRESS”);
display.setCursor(40,20);
display.println(“START”);
display.display();

display.startscrollright(0x00, 0x0F);
delay(1000);
display.stopscroll();
delay(1000);
display.startscrollleft(0x00, 0x0F);
delay(1000);
display.stopscroll();
//delay(500);
//display.startscrolldiagright(0x00, 0x07);
//delay(2000);
//display.startscrolldiagleft(0x00, 0x07);
//delay(2000);
//display.stopscroll();
}
void scrolltext2(void) {
display.setTextSize(2);
display.setTextColor(WHITE);
display.setCursor(47,0);
display.clearDisplay();
display.println(“TIME”);
display.setCursor(47,20);
display.println(“OCT”);
display.display();

display.startscrollright(0x00, 0x0F);
delay(1000);
display.stopscroll();
delay(1000);
display.startscrollleft(0x00, 0x0F);
delay(1000);
display.stopscroll();
delay(3000);
//display.startscrolldiagright(0x00, 0x07);
//delay(2000);
///display.startscrolldiagleft(0x00, 0x07);
//delay(2000);
//display.stopscroll();
scrolltext1();
//delay(1000);
display.display();
display.clearDisplay();

}
