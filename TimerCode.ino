#include <Adafruit_GFX.h>
#include <Adafruit_GrayOLED.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>

#include <Adafruit_SSD1306.h>
#include <splash.h>

#define OLED_ADDR       0x3C
#define COUNTDOWN_TIME  121000ul

char
    szString[20];
byte
    mins, secs;
        
unsigned long
    timeTemp,
    timeNow,
    timeStart,
    timeElapsed,
    timeLeft;    

Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() 
{
    // initialize and clear display
    display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);

    Serial.begin(9600);
    timeStart = millis();
    mins = 1;
    secs = 1;
  
}//setup

void DoCountdown()
{
    static unsigned long
        lastTimeNow = 0;
    static byte
        lastsecs = 1;
        
    timeNow = millis();
    timeElapsed = timeNow - timeStart;
    
    if( mins == 0 && secs == 0 )
        return;
        
    timeLeft = COUNTDOWN_TIME - timeElapsed;

    mins = (byte)(timeLeft / 60000ul);
    timeTemp = timeLeft - (mins * 60000);
    secs = (byte)(timeTemp / 1000ul);
    timeTemp = timeTemp - (secs * 1000ul);

    if( mins == 0 && secs == 0 )
    {
        sprintf( szString, "**DONE**" );
        Serial.println( szString );
        display.setCursor( 44, 30 );
        display.print( szString );
        display.display();
         
    }//if
    else if( secs != lastsecs )
    {
        lastsecs = secs;
        sprintf( szString, "%02d:%02d", mins, secs );
        Serial.println( szString );
        //
        display.setCursor( 50, 30 );
        display.print( szString );
        display.display();
    
    }//if
    
}//DoCountdown

void loop() 
{
    DoCountdown();
            
}//loop
