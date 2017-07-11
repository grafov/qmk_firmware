// Keymacs + QWERTY + Emacs macros + misc experiments
#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// #include "keymap_german.h"
// #include "keymap_nordic.h"

// Just for aesthetics
#define _____ KC_TRANSPARENT

// Layer names
enum {
  LAYER_KEYMACS = 0,
  LAYER_PROGER,
  LAYER_RUSSIAN,
  LAYER_CONTROL,
  LAYER_MOUSE,
  LAYER_QWERTY,
  LAYER_NUMPAD,
  LAYER_FN,
  LAYER_MEDIA,
  LAYER_SYMBOLS
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here  
  EPRM,
  VRSN,
  RGB_SLD,
  RGB_0000FF,
  RGB_008000,
  RGB_FFA500,
  RGB_800080,
  RGB_FF0000
};

// Macros IDs
enum {
  M_VRSN = 0,
  M_EMACS_SELECT,
  M_LAYER_IS_KEYMACS,
  M_LAYER_IS_PROGER,
  M_LAYER_IS_RUSSIAN,
  M_LAYER_IS_CONTROL,
  M_LAYER_IS_MOUSE,
  M_LAYER_IS_QWERTY,
  M_LAYER_IS_NUMPAD,
  M_LAYER_IS_FN,
  M_LAYER_IS_MEDIA,
  M_LAYER_IS_SYMBOLS,
  M_RUS,
  M_LAT
};

//Tap Dance Declarations
enum {
  TD_QU = 0
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Default layer
  // This is the adaptation of Keymacs layout for common keyboards for Ergodox EZ
  // https://github.com/keyboard-ergonomics/keymacs
  [LAYER_KEYMACS] = KEYMAP( // left fingers
			   KC_ESCAPE,KC_GRAVE,KC_EXLM,KC_QUES,KC_COLN,KC_PLUS,TG(LAYER_NUMPAD),
			   KC_LALT,TD(TD_QU),KC_B,KC_P,KC_F,ALGR_T(KC_G),OSL(LAYER_FN),
			   KC_LCTL,LT(LAYER_PROGER,KC_R),KC_A,KC_E,KC_N,RCTL_T(KC_S),
			   KC_LSHIFT,LT(LAYER_NUMPAD,KC_Z),KC_COMMA,KC_U,KC_K,SFT_T(KC_J),M(M_EMACS_SELECT),
			   OSL(LAYER_FN),TG(LAYER_MEDIA),TG(LAYER_SYMBOLS),_____,MO(LAYER_MOUSE),
			   // left thumb
			   LCTL(KC_G),KC_WWW_BACK,KC_PLUS,
			   LT(LAYER_CONTROL,KC_SPACE),GUI_T(KC_BSPACE),KC_MINUS,
			   // right fingers 
			   M(M_LAYER_IS_KEYMACS),KC_ASTR,KC_SCOLON,KC_MINUS,KC_DQUO,KC_EQUAL,KC_BSPACE,
			   OSL(LAYER_FN),ALT_T(KC_DOT),KC_W,KC_D,KC_Y,KC_QUOTE,KC_RALT,
			   CTL_T(KC_L),KC_O,KC_T,KC_I,LT(LAYER_PROGER,KC_H),KC_RCTRL,
			   _____,SFT_T(KC_M),KC_C,KC_X,KC_V,LT(LAYER_NUMPAD,KC_SLASH),SFT_T(M_RUS),
			   MO(LAYER_MOUSE),KC_UNDS,TG(LAYER_RUSSIAN),TG(LAYER_QWERTY),OSL(LAYER_FN),
			   // right thumb
			   KC_WWW_FORWARD,RCTL(KC_W),KC_WWW_REFRESH,
			   ALT_T(KC_APPLICATION),GUI_T(KC_TAB),LT(LAYER_CONTROL,KC_ENTER)),

  // Programmer layer (various shifted characters) [yellow]
  [LAYER_PROGER] = KEYMAP(// left fingers
			  M(M_VRSN),KC_GRAVE,KC_EXLM,KC_QUES,KC_COLN,KC_PLUS,_____,
			  KC_LALT,_____,KC_CIRC,KC_HASH,KC_LBRACKET,_____,_____,
			  KC_LCTL,_____,KC_AMPR,KC_LCBR,KC_LPRN,_____,
			  KC_LSHIFT,_____,KC_LABK,KC_TILD,KC_AT,_____,_____,
			  _____,_____,_____,_____,_____,
			  // left thumb
			  _____,_____,_____,KC_SPACE,_____,_____,
			  // right fingers
			  M(M_LAYER_IS_PROGER),KC_ASTR,KC_SCOLON,KC_MINUS,KC_DQUO,KC_EQUAL,_____,
			  _____,KC_RABK,KC_RBRACKET,KC_DLR,KC_PERC,_____,KC_RALT,
			  _____,KC_RPRN,KC_RCBR,KC_UNDS,_____,KC_RCTRL,
			  _____,KC_ENTER,KC_EQUAL,KC_BSLASH,KC_PIPE,_____,KC_RSHIFT,
			  _____,_____,_____,_____,_____,
			  // right thumb
			  _____,_____,_____,_____,_____,KC_SPACE),

  // Qwerty for Russian layout
  [LAYER_RUSSIAN] = KEYMAP(// left fingers
			  KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,_____,
			  _____,KC_Q,KC_W,KC_E,KC_R,KC_T,_____,
			  _____,KC_A,KC_S,KC_D,KC_F,KC_G,
			  KC_LSPO,KC_Z,KC_X,KC_C,KC_V,KC_B,_____,
			  TO(LAYER_KEYMACS),_____,_____,_____,_____,
			  // left thumb
			  _____,_____,_____,_____,_____,_____,
			  // right fingers
			  M(M_LAYER_IS_RUSSIAN),KC_6,KC_7,KC_8,KC_9,KC_0,_____,
			  _____,KC_Y,KC_U,KC_I,KC_O,KC_P,_____,
			  KC_H,KC_J,KC_K,KC_I,KC_QUOTE,_____,
			  _____,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,_____,
			  _____,_____,_____,_____,_____,
			  // right thumb
			  _____,_____,_____,_____,_____,_____),

  // Control layer
  [LAYER_CONTROL] = KEYMAP(// left fingers
			   _____,_____,_____,_____,LGUI(KC_F10),LGUI(KC_F11),LGUI(KC_F5),
			   _____,_____,KC_LEFT,KC_UP,KC_RIGHT,KC_ESCAPE,_____,
			   _____,LSFT(KC_TAB),KC_HOME,KC_UP,KC_DOWN,KC_END,
			   _____,_____,RCTL(RSFT(KC_COMMA)),KC_PGUP,KC_PGDOWN,LGUI(KC_J),_____,
			   TO(LAYER_KEYMACS),_____,_____,_____,_____,
			   // left thumb
			   _____,_____,_____,_____,_____,_____,
			   // right fingers
			   M(M_LAYER_IS_CONTROL),RGUI(KC_F6),RGUI(KC_F12),_____,_____,_____,_____,
			   _____,LCTL(LSFT(KC_DOT)),LALT(KC_W),KC_DELETE,LCTL(KC_Y),_____,_____,
			   _____,KC_LEFT,KC_RIGHT,KC_BSPACE,KC_TAB,_____,
			   _____,KC_ENTER,LCTL(KC_C),LCTL(KC_X),LCTL(KC_V),LCTL(KC_SLASH),_____,
			   _____,_____,_____,_____,_____,
			   // right thumb
			   _____,_____,_____,_____,_____,_____),

  // Mouse control
  [LAYER_MOUSE] = KEYMAP(// left fingers
			 _____,_____,_____,_____,_____,_____,KC_MS_ACCEL2,
			 _____,_____,KC_MS_BTN3,_____,_____,_____,KC_MS_ACCEL1,
			 _____,_____,KC_MS_BTN1,KC_MS_UP,KC_MS_DOWN,_____,
			 _____,_____,KC_MS_BTN2,KC_MS_WH_UP,KC_MS_WH_DOWN,_____,KC_MS_ACCEL0,
			 _____,TO(LAYER_KEYMACS),KC_MS_BTN2,KC_MS_BTN3,KC_MS_BTN1,
			 // left thumb
			 _____,_____,_____,_____,_____,_____,
			 // right fingers
			 M(M_LAYER_IS_MOUSE),_____,_____,_____,_____,_____,_____,
			 _____,_____,_____,_____,KC_MS_BTN3,_____,_____,
			 _____,KC_MS_LEFT,KC_MS_RIGHT,KC_MS_BTN1,_____,_____,
			 _____,_____,KC_MS_WH_LEFT,KC_MS_WH_RIGHT,KC_MS_BTN2,_____,_____,
			 _____,KC_MS_BTN1,KC_MS_BTN3,KC_MS_BTN2,_____,
			 // right thumb
			 _____,_____,_____,_____,_____,_____),

  // Qwerty
  [LAYER_QWERTY] = KEYMAP(// left fingers
			  KC_ESCAPE,KC_1,KC_2,KC_3,KC_4,KC_5,TO(LAYER_KEYMACS),
			   KC_LALT,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_TAB,
			   KC_LCTL,KC_A,KC_S,KC_D,KC_F,KC_G,
			   KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,_____,
			   _____,_____,_____,KC_LGUI,KC_LALT,
			   // left thumb
			   _____,_____,_____,
			   KC_SPACE,KC_ENTER,_____,
			   // right fingers
			   M(M_LAYER_IS_QWERTY),KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPACE,
			   KC_TAB,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LALT,
			   KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_LCTL,
			   _____,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,
			   _____,KC_LEFT,KC_UP,KC_DOWN,KC_RIGHT,
			   // right thumb
			   _____,_____,_____,
			   _____,KC_ENTER,KC_SPACE),

  // Numpad
  [LAYER_NUMPAD] = KEYMAP(// left fingers
			  KC_NUMLOCK,KC_ASTR,KC_7,KC_8,KC_9,_____,_____,
			  KC_LALT,KC_PLUS,KC_4,KC_5,KC_6,_____,KC_TAB,
			  KC_LCTL,KC_MINUS,KC_1,KC_2,KC_3,_____,
			  KC_LSHIFT,_____,KC_DOT,KC_0,KC_EQUAL,KC_ENTER,_____,
			  TO(LAYER_KEYMACS),_____,_____,_____,_____,
			  // left thumb
			  _____,_____,KC_SPACE,KC_LGUI,_____,_____,
			  // right fingers
			  M(M_LAYER_IS_NUMPAD),_____,KC_7,KC_8,KC_9,KC_KP_ASTERISK,KC_BSPACE,
			  KC_TAB,KC_DOT,KC_4,KC_5,KC_6,KC_KP_PLUS,KC_RALT,
			  _____,KC_1,KC_2,KC_3,KC_KP_MINUS,KC_RCTRL,
			  _____,KC_KP_ENTER,KC_DOT,KC_0,KC_EQUAL,_____,KC_RSHIFT,
			  _____,_____,_____,_____,_____,
			  // right thumb
			  _____,_____,_____,_____,KC_RGUI,KC_SPACE),

  // Fn keys
  [LAYER_FN] = KEYMAP(// left fingers
		      _____,KC_F13,KC_F14,KC_F15,KC_F16,_____,_____,
		      KC_LALT,KC_F9,KC_F10,KC_F11,KC_F12,KC_RALT,_____,
		      KC_LCTL,KC_F5,KC_F6,KC_F7,KC_F8,KC_RCTRL,
		      KC_LSHIFT,KC_F1,KC_F2,KC_F3,KC_F4,KC_RSHIFT,_____,
		      TO(LAYER_KEYMACS),_____,_____,_____,_____,
		      // left thumb
		      _____,_____,_____,_____,_____,_____,
		      // right fingers
		      M(M_LAYER_IS_FN),_____,KC_F13,KC_F14,KC_F15,KC_F16,_____,
		      _____,KC_LALT,KC_F9,KC_F10,KC_F11,KC_F12,KC_RALT,
		      KC_LCTL,KC_F5,KC_F6,KC_F7,KC_F8,KC_RCTRL,
		      _____,KC_LSHIFT,KC_F1,KC_F2,KC_F3,KC_F4,KC_RSHIFT,
		      _____,_____,_____,_____,_____,
		      // right thumb
		      _____,_____,_____,_____,_____,_____),

  // Color and Media controls 
  [LAYER_MEDIA] = KEYMAP(// left fingers
			 _____,_____,_____,_____,_____,_____,_____,
			 _____,_____,_____,_____,_____,_____,_____,
			 _____,_____,_____,_____,_____,_____,
			 _____,_____,_____,_____,_____,_____,_____,
			 TO(LAYER_KEYMACS),_____,_____,_____,_____,
			 // left thumb
			 RGB_MOD,_____,_____,RGB_VAD,RGB_VAI,_____,
			 // right fingers
			 M(M_LAYER_IS_MEDIA),RGB_0000FF,RGB_008000,RGB_FFA500,RGB_800080,RGB_FF0000,_____,
			 _____,_____,_____,_____,_____,_____,_____,
			 _____,_____,_____,_____,_____,_____,
			 _____,_____,_____,_____,_____,_____,_____,
			 _____,_____,_____,_____,_____,
			 // right thumb
			 RGB_TOG,RGB_SLD,_____,_____,RGB_HUD,RGB_HUI),

  // Symbols layer for Unicode input
  [LAYER_SYMBOLS] = KEYMAP(// left fingers
	 		   UC_LNX,UC(0x03a8),UC(0x0152),UC_A,_____,_____,_____,
			   _____,_____,_____,_____,_____,_____,_____,
			   _____,_____,_____,_____,_____,_____,
			   _____,_____,_____,_____,_____,_____,_____,
			   TO(LAYER_KEYMACS),_____,_____,_____,_____,
			   // left thumb
			   RGB_MOD,_____,_____,RGB_VAD,RGB_VAI,_____,
			   // right fingers
			   M(M_LAYER_IS_SYMBOLS),RGB_0000FF,RGB_008000,RGB_FFA500,RGB_800080,RGB_FF0000,_____,
			   _____,_____,_____,_____,_____,_____,_____,
			   _____,_____,_____,_____,_____,_____,
			   _____,_____,_____,_____,_____,_____,_____,
			   _____,_____,_____,_____,_____,
			   // right thumb
			   RGB_TOG,RGB_SLD,_____,_____,RGB_HUD,RGB_HUI),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};


// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (record->event.pressed) {
  switch(id) {
  case M_EMACS_SELECT: // Emacs: reset the selection and activate a new one
    return MACRO(D(LCTL),T(G),T(SPC),U(LCTL),END);
  case M_VRSN:
    SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION "-Keymacs");
    break;
  case M_LAYER_IS_KEYMACS:
    SEND_STRING ("Layer is Keymacs [0]");
    break;
  case M_LAYER_IS_PROGER:
    SEND_STRING ("Layer is Programmer [1]");
    break;
  case M_LAYER_IS_RUSSIAN:
    SEND_STRING ("Layer is Russian [2]");
    break;
  case M_LAYER_IS_CONTROL:
    SEND_STRING ("Layer is Control [3]");
    break;
  case M_LAYER_IS_MOUSE:
    SEND_STRING ("Layer is Mouse [4]");
    break;
  case M_LAYER_IS_QWERTY:
    SEND_STRING ("Layer is QWERTY [5]");
    break;
  case M_LAYER_IS_NUMPAD:
    SEND_STRING ("Layer is Numpad [6]");
    break;
  case M_LAYER_IS_MEDIA:
    SEND_STRING ("Layer is Media and Color [7]");
    break;
  case M_LAYER_IS_FN:
    SEND_STRING ("Layer is Function keys [8]");
    break;
  case M_LAYER_IS_SYMBOLS:
    SEND_STRING ("Layer is Symbols [9]");
    break;
  }} else {
  switch(id) {
  case M_LAT:
        register_code(KC_LSHIFT);
        unregister_code(KC_LSHIFT);
    layer_on(LAYER_KEYMACS);
    break;
  case M_RUS:
        register_code(KC_RSHIFT);
        unregister_code(KC_RSHIFT);
    layer_on(LAYER_RUSSIAN);
    break;
  }}
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;    
    case RGB_0000FF:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_setrgb(0x00,0x00,0xff);
        #endif
      }
      return false;
      break;    
    case RGB_008000:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_setrgb(0x00,0x80,0x00);
        #endif
      }
      return false;
      break;
    
    case RGB_FFA500:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_setrgb(0xff,0xa5,0x00);
        #endif
      }
      return false;
      break;
    
    case RGB_800080:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_setrgb(0x80,0x00,0x80);
        #endif
      }
      return false;
      break;
    
    case RGB_FF0000:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_enable();
          rgblight_mode(1);
          rgblight_setrgb(0xff,0x00,0x00);
        #endif
      }
      return false;
      break;
    
  }
  return true;
}

void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
    case LAYER_KEYMACS:
      // rgblight_task();
      // rgblight_show_solid_color(0xaa,0xaa,0xaa);
      break;      
    case LAYER_PROGER:
      ergodox_right_led_2_on();
      // rgblight_show_solid_color(0x00,0xff,0x00);      
      break;
    case LAYER_RUSSIAN:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      // rgblight_show_solid_color(0xff,0x00,0xff);      
      break;
    case LAYER_CONTROL:
      ergodox_right_led_1_on();
      // rgblight_show_solid_color(0xff,0x00,0x00);
      break;
    case LAYER_MOUSE:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      // rgblight_show_solid_color(0xff,0xff,0x00);
      break;
    case LAYER_NUMPAD:
      ergodox_right_led_3_on();
      // rgblight_show_solid_color(0x00,0x00,0xff);      
      break;
    case LAYER_FN:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      //      rgblight_show_solid_color(0x00,0xff,0xff);
      break;
    default:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();	    
      ergodox_right_led_3_on();
      //      rgblight_show_solid_color(0xaa,0xaa,0xaa);      
     }
};

void dance_qu (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      register_code(KC_Q);
      unregister_code(KC_Q);
      break;
    case 2:
      register_code(KC_Q);
      unregister_code(KC_Q);      
      register_code(KC_U);
      unregister_code(KC_U);
      // XXX
      unicode_input_start();
      register_hex(0x03bb);
      unicode_input_finish();      
      break;
    default:
      reset_tap_dance(state);
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_QU]  = ACTION_TAP_DANCE_FN(dance_qu)
};
