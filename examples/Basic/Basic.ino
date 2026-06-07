#include <SoftI2C_VPORT.h>
#include "TinySSD1306.h"

SoftI2C_VPORT i2c(1, 2);   // SDA=PA1, SCL=PA2
TinySSD1306 oled(i2c);

int counter = 0;
int temp = 25;

void setup()
{
i2c.begin();
oled.begin();

oled.setCursor(0,0);
oled.print("TinySSD1306");

oled.setCursor(0,2);
oled.print("Temp=");
oled.print(temp);
oled.print("C");

oled.setCursor(0,4);
oled.print("Count;");

}

void loop()
{
oled.setCursor(6,4);

// 前回表示を消去
oled.print("    ");

oled.setCursor(6,4);
oled.print(counter);

counter++;

if(counter > 99)
{
    counter = 0;
}

delay(1000);

}
