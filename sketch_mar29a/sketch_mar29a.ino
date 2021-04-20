#include <splash.h>

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// OLED display TWI address
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();

  // display a pixel in each corner of the screen
  display.drawPixel(0, 0, WHITE); // Top left
  display.drawPixel(127, 0, WHITE); // Top right
  display.drawPixel(0, 63, WHITE); // Bottom left
  display.drawPixel(127, 63, WHITE); // Bottom right

  // display a line of text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print("Data Glasses Booting ...");
  
  // update display with all of the above graphics
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}
