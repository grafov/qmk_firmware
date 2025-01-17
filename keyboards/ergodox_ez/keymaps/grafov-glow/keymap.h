#include QMK_KEYBOARD_H

#define XXXX KC_NO

// Switchers
// #define RUS      KC_SCROLLLOCK
// #define LAT      KC_SCROLLLOCK
// return to shift-shift utility for layout switching
// #define RUS      KC_RSFT
// #define LAT      KC_LSFT

// evdev uses https://raw.githubusercontent.com/torvalds/linux/v6.12/include/uapi/linux/input-event-codes.h
// foreign as KC_KATAKANA code 90
#define LAT KC_LNG3

// native as KC_HIRAGANA code 91
#define RUS KC_LNG4

void switch_russian_layer(bool back);
