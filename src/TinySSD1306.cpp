#include "TinySSD1306.h"
#include "font5x7.h"
#include <stdlib.h>

#define SSD1306_ADDR 0x3C

TinySSD1306::TinySSD1306(SoftI2C_VPORT& i2c)
    : _i2c(i2c)
{
    cursorX = 0;
    cursorY = 0;
}
void TinySSD1306::command(uint8_t cmd)
{
    _i2c.start();

    _i2c.write(SSD1306_ADDR << 1);
    _i2c.write(0x00);
    _i2c.write(cmd);

    _i2c.stop();
}
void TinySSD1306::data(uint8_t d)
{
    _i2c.start();

    _i2c.write(SSD1306_ADDR << 1);
    _i2c.write(0x40);
    _i2c.write(d);

    _i2c.stop();
}
void TinySSD1306::begin()
{  
    delay(100);
    command(0xAE);

    command(0x20);
    command(0x02);

    command(0xB0);

    command(0xC8);

    command(0x00);
    command(0x10);

    command(0x40);

    command(0x81);
    command(0x7F);

    command(0xA1);

    command(0xA6);

    command(0xA8);
    command(0x3F);

    command(0xD3);
    command(0x00);

    command(0xD5);
    command(0x80);

    command(0xD9);
    command(0xF1);

    command(0xDA);
    command(0x12);

    command(0xDB);
    command(0x40);

    command(0x8D);
    command(0x14);

    command(0xAF);

    clear();
   // setCursor(0,0);
}
void TinySSD1306::clear()
{
    for(uint8_t page=0; page<8; page++)
    {
        command(0xB0 + page);
        command(0x00);
        command(0x10);

        for(uint8_t i=0;i<128;i++)
        {
            data(0x00);
        }
    }

    setCursor(0,0);
}
void TinySSD1306::home()
{
    setCursor(0,0);
}
void TinySSD1306::setCursor(uint8_t col,
                            uint8_t row)
{
    cursorX = col;
    cursorY = row;

    uint8_t x = col * 6;

    command(0xB0 + row);

    command(0x00 + (x & 0x0F));
    command(0x10 + (x >> 4));
}
void TinySSD1306::drawChar(char c)
{
    uint8_t index;

    if(c==' ')
        index = 0;

    else if(c=='-')
        index = 1;

    else if(c=='.')
        index = 2;

    else if(c==':')
        index = 3;

    else if(c>='0' && c<='9')
        index = 4 + (c-'0');

    else if(c>='A' && c<='Z')
        index = 14 + (c-'A');

    else if(c>='a' && c<='z')
        index = 40 + (c-'a');

    else if(c==',')
        index = 66;

    else if(c==';')
        index = 67;

    else if(c=='!')
        index = 68;

    else if(c=='?')
        index = 69;

    else if(c=='+')
        index = 70;

    else if(c=='=')
        index = 71;

    else if(c=='/')
        index = 72;

    else if(c=='*')
        index = 73;

    else if(c=='(')
        index = 74;

    else if(c==')')
        index = 75;

    else if(c=='%')
        index = 76;

    else if(c=='#')
        index = 77;

    else if(c=='&')
        index = 78;

    else if(c=='_')
        index = 79;

    else
        return;

    for(uint8_t i=0;i<5;i++)
    {
        data(
            pgm_read_byte(
                &font5x7[index][i]
            )
        );
    }

    data(0x00);
}
void TinySSD1306::print(int value)
{
    char buf[8];

    itoa(value, buf, 10);

    print(buf);
}

void TinySSD1306::print(const char* str)
{
    
    while(*str)
    {
        drawChar(*str++);
    }
}
void TinySSD1306::println(const char* str)
{
    print(str);

    cursorY++;

    setCursor(0,cursorY);
}
