#include "display.h"

SSD1306Wire display(0x3C, SDA, SCL);

void initDisplay() {
    Wire.begin();
    display.init();
}

void clearDisplay() {
    display.clear();
    // display.display();
}

void renderText(int x, int y, const char* text) {
    display.drawString(x, y, text);
    // display.display();
}

void renderCircle(int x, int y, int r, bool filled) {
    if (filled) {
        display.fillCircle(x, y, r);
    } else {
        display.drawCircle(x, y, r);
    }
    
    // display.display();
}

void renderRect(int x, int y, int w, int h, bool filled) {
    if (filled) {
        display.fillRect(x, y, w, h);
    } else {
        display.drawRect(x, y, w, h);
    }

    // display.display();
}

void renderTriangle(int x0, int y0, int x1, int y1, int x2, int y2, bool filled) {
    if (filled) {
        display.fillTriangle(x0, y0, x1, y1, x2, y2);
    } else {
        display.drawTriangle(x0, y0, x1, y1, x2, y2);
    }
}

void renderLine(int x0, int y0, int x1, int y1) {
    display.drawLine(x0, y0, x1, y1);
    // display.display();
}

void renderPixel(int x, int y) {
    display.setPixel(x, y);
    // display.display();
}

void renderDisplay() {
    display.display();
}