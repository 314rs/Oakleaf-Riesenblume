#include <Arduino.h>
#include <config.h>
#include <Button.h>


Button panikBtn(PIN_BTN_PANIC);
Button onSw(PIN_SW_ON);
unsigned long panicTimestamp = 0;

void setup() {
    panikBtn.begin();
    onSw.begin();
    pinMode(PIN_LEDS1, OUTPUT);
    pinMode(PIN_LEDS2, OUTPUT);
    pinMode(PIN_LEDS3, OUTPUT);
}

void loop() {
    if (panikBtn.pressed()) {
        panicTimestamp = millis();
        while ( millis() - panicTimestamp < PANIC_INTERVALL) {
            // Panic
            if ((millis()*PANIC_HZ/500)%2) {
                analogWrite(PIN_LEDS1, MAX_BRIGHTNESS_PANIC*random(2));
            }
            if ((millis()*PANIC_HZ/500)%2) {
                analogWrite(PIN_LEDS2, MAX_BRIGHTNESS_PANIC*random(2));
            }
            if ((millis()*PANIC_HZ/500)%2) {
                analogWrite(PIN_LEDS3, MAX_BRIGHTNESS_PANIC*random(2));
            }
        }
        analogWrite(PIN_LEDS1, 0);
        analogWrite(PIN_LEDS2, 0);
        analogWrite(PIN_LEDS3, 0);
    } else {
        if (onSw.read() == Button::PRESSED) {
            analogWrite(PIN_LEDS1, MAX_BRIGHTNESS);
            analogWrite(PIN_LEDS2, MAX_BRIGHTNESS);
            analogWrite(PIN_LEDS3, MAX_BRIGHTNESS);
        } else {
            analogWrite(PIN_LEDS1, 0);
            analogWrite(PIN_LEDS2, 0);
            analogWrite(PIN_LEDS3, 0);
        }
    }


}