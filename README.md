# TinySSD1306

Ultra-lightweight SSD1306 OLED library for ATtiny202/402/404.

This library was designed for very small AVR microcontrollers where standard SSD1306 libraries require too much RAM.

## Features

* SSD1306 128x64 OLED support
* ATtiny202 / ATtiny402 / ATtiny404 compatible
* SoftI2C_VPORT compatible
* No frame buffer
* RAM usage approximately 16 bytes
* Flash size approximately 1.8 KB
* AQM1602-like API

## Supported Functions

```cpp
oled.begin();
oled.clear();
oled.home();
oled.setCursor(x, page);

oled.print("Hello");
oled.print(123);
```

## Supported Characters

* A-Z
* a-z
* 0-9
* Space
* * . :, ; ! ? + = / * ( ) % # & _

## Example

```cpp
#include <SoftI2C_VPORT.h>
#include "TinySSD1306.h"

SoftI2C_VPORT i2c(1,2);
TinySSD1306 oled(i2c);

void setup()
{
    i2c.begin();
    oled.begin();

    oled.print("Hello");
}

void loop()
{
}
```

## Memory Usage (ATtiny202)

* Flash: approximately 1800 bytes
* RAM: approximately 16 bytes

## License

MIT License
