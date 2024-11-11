#ifndef DISPLAY_H
    #define DISPLAY_H

    #include <Wire.h>
    #include "SSD1306Wire.h"

    #define SCREEN_WIDTH 128
    #define SCREEN_HEIGHT 64

    extern SSD1306Wire display;

    void initDisplay();
    void clearDisplay();
    void renderText(int x, int y, const char* text);
    void renderCircle(int x, int y, int r, bool filled);
    void renderRect(int x, int y, int w, int h, bool filled);
    void renderLine(int x0, int y0, int x1, int y1);
    void renderPixel(int x, int y);
#endif
