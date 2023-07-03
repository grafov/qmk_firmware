#include QMK_KEYBOARD_H

#define TAP(kc)    register_code(kc); unregister_code(kc)
#define XXXX KC_NO

// Switchers
//#define RUS      KC_SCROLLLOCK
//#define LAT      KC_SCROLLLOCK
// return to shift-shift utility for layout switching
#define RUS      KC_RSFT
#define LAT      KC_LSFT


void switch_russian_layer(bool back);
