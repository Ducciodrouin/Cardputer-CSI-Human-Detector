#include <Arduino.h>
#include <TFT_eSPI.h>

TFT_eSPI display = TFT_eSPI();

void setup() {
    Serial.begin(115200);
    delay(500);

    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

    display.init();
    display.setRotation(1);
    display.fillScreen(TFT_BLACK);

    display.setTextColor(TFT_GREEN, TFT_BLACK);
    display.setTextDatum(MC_DATUM);
    display.drawString(
        "ESP32 CSI TEST",
        display.width() / 2,
        display.height() / 2 - 15,
        4
    );

    display.setTextColor(TFT_CYAN, TFT_BLACK);
    display.drawString(
        "Ecran OK",
        display.width() / 2,
        display.height() / 2 + 25,
        2
    );

    Serial.println("Display initialization complete.");
}

void loop() {
    static uint32_t lastUpdate = 0;
    static uint32_t counter = 0;

    if (millis() - lastUpdate >= 1000) {
        lastUpdate = millis();
        counter++;

        display.fillRect(90, 190, 140, 25, TFT_BLACK);
        display.setTextColor(TFT_YELLOW, TFT_BLACK);
        display.setTextDatum(MC_DATUM);

        String message = "Secondes: " + String(counter);
        display.drawString(message, display.width() / 2, 202, 2);

        Serial.println(message);
    }
}