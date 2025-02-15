#include QMK_KEYBOARD_H

#define XXXX KC_NO

// Switchers
// #define RUS      KC_SCROLLLOCK
// #define LAT      KC_SCROLLLOCK
// return to shift-shift utility for layout switching
// #define RUS      KC_RSFT
// #define LAT      KC_LSFT

// Linux kernel (evdev) uses https://raw.githubusercontent.com/torvalds/linux/v6.12/include/uapi/linux/input-event-codes.h
// foreign as KC_KATAKANA code 90 in kernel
// I use it for Latin (English)
#define LAT KC_LNG3
#define XLAT X_LNG3
// native as KC_HIRAGANA code 91 in kernel
// I use it for Russian
#define RUS KC_LNG4
#define XRUS X_LNG4
// Zenkaku/Hankaku code 92 in kernel
// I use it for Esperanto ("epo" symbols in xkb)
#define EPO KC_LNG5
#define XEPO X_LNG5

void switch_russian_layer(bool back);
