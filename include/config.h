


#ifdef ARDUINO_ARCH_AVR
#define PIN_SW_ON 3
#define PIN_BTN_PANIC 4
#define PIN_LEDS1 9
#define PIN_LEDS2 10
#define PIN_LEDS3 11
#elif defined ARDUINO_ARCH_SAMD
#define PIN_SW_ON 0
#define PIN_BTN_PANIC 3
#define PIN_LEDS1 4
#define PIN_LEDS2 5
#define PIN_LEDS3 6
#endif

#define MAX_BRIGHTNESS 60          // 0 to 255
#define MAX_BRIGHTNESS_PANIC 255    // 0 to 255
#define PANIC_HZ 30            // 30
#define PANIC_INTERVALL 5000        // length of panic in ms