#ifndef TINY_SSD1306_H
#define TINY_SSD1306_H

#include <avr/io.h>
#include <stdlib.h>
#include "SoftI2C_VPORT.h"

class TinySSD1306
{
public:
    TinySSD1306(SoftI2C_VPORT& i2c);

    void begin();
    void clear();

    void home();

    void setCursor(uint8_t col, uint8_t row);

    void print(const char* str);
    void print(int value);

    void println(const char* str);

private:
    SoftI2C_VPORT& _i2c;

    uint8_t cursorX;
    uint8_t cursorY;

    void command(uint8_t cmd);
    void data(uint8_t d);

    void drawChar(char c);
};

#endif
