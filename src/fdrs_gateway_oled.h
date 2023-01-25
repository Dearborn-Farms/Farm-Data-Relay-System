
#ifdef USE_OLED
#include <SSD1306Wire.h>

String debug_buffer[5] = {"", "", "", "", ""};
SSD1306Wire display(0x3c, OLED_SDA, OLED_SCL); // ADDRESS, SDA, SCL

void draw_OLED_header()
{
    display.setFont(ArialMT_Plain_10);
    display.clear();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString(0, 0, String(UNIT_MAC, HEX));
    display.setTextAlignment(TEXT_ALIGN_CENTER);
    display.drawString(63, 0, OLED_HEADER);
    display.setTextAlignment(TEXT_ALIGN_RIGHT);
    display.drawString(127, 0, "TBD");
    display.display();
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.setFont(ArialMT_Plain_10);
}
void debug_OLED(String debug_text)
{
    draw_OLED_header();
    display.drawHorizontalLine(0, 15, 128);
    display.drawHorizontalLine(0, 16, 128);

    for (uint8_t i = 4; i > 0; i--)
    {

        debug_buffer[i] = debug_buffer[i - 1];
    }
    debug_buffer[0] = String(millis() / 1000) + " " + debug_text;
    uint8_t lineNumber = 0;
    for (uint8_t i = 0; i < 5; i++)
    {
        uint8_t ret = display.drawStringMaxWidth(0, 17 + (lineNumber * 9), 127, debug_buffer[i]);
        lineNumber = ret + lineNumber;
        if (lineNumber > 5)
            break;
    }
    display.display();
}
#endif
