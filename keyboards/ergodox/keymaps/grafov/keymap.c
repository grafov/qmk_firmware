// Keymacs + Control layer + QWERTY + Emacs macros + misc experiments
#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// #include "keymap_german.h"
// #include "keymap_nordic.h"

// Just for aesthetics
#define _____ KC_TRANSPARENT
#define XXXXX KC_NO
#define SCLK register_code(KC_SCROLLLOCK);unregister_code(KC_SCROLLLOCK);
#define RU(kc) SCLK register_code(kc);unregister_code(kc); SCLK


#define LTRU 0x7100

// Layer names
enum {
  LAYER_KEYMACS = 0,
  LAYER_RUSSIAN,
  LAYER_AUXCHARS,
  LAYER_MOUSE,
  LAYER_QWERTY,
  LAYER_NUMPAD,
  LAYER_CONTROL,
  LAYER_FN,
  LAYER_MEDIA,
  LAYER_SYMBOLS,
  LAYER_WM
};

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here  
  EPRM,
  VRSN,

  LTRU_AUX_LEFT,
  LTRU_AUX_RIGHT,
  LTRU_NUM_LEFT,
  LTRU_NUM_RIGHT,

  RGB_SLD,
  RGB_FF0000,  
  RGB_0000FF,
  RGB_008000,
  RGB_FFA500,
  RGB_800080,
  
  XKB,
};

// Macros IDs
enum {
  M_VRSN = 0,
  M_EMACS_SELECT,

  M_LAYER_IS_KEYMACS,
  M_LAYER_IS_AUXCHARS,
  M_LAYER_IS_RUSSIAN,
  M_LAYER_IS_CONTROL,
  M_LAYER_IS_MOUSE,
  M_LAYER_IS_QWERTY,
  M_LAYER_IS_NUMPAD,
  M_LAYER_IS_FN,
  M_LAYER_IS_MEDIA,
  M_LAYER_IS_SYMBOLS,
  M_LAYER_IS_WM,

  M_LAT,
  M_RUS,

  RU_IO,
  RU_SHORTI,
  RU_TSE, 
  RU_U, 
  RU_KA, 
  RU_IE, 
  RU_EN,
  RU_GHE,
  RU_SHA, 
  RU_SHCHA, 
  RU_ZE,
  RU_HA,
  RU_HARDSIGN,
                    
  RU_EF, 
  RU_YERU, 
  RU_VE, 
  RU_A, 
  RU_PE, 
  RU_ER,
  RU_O, 
  RU_EL, 
  RU_DE, 
  RU_ZHE, 
  RU_E,  
                    
  RU_YA, 
  RU_CHE,
  RU_ES,  
  RU_EM,  
  RU_I, 
  RU_TE, 
  RU_SOFTSIGN,
  RU_BE,  
  RU_YU,
  
};

//Tap Dance Declarations
enum {
  TD_QU = 0,
  TD_EYO,
  TD_SHSIG,
  TD_ASSIGN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Default layer based on Keymacs layout
  // -------------------------------------
  // This is the adaptation of the layout for common keyboards for Ergodox EZ
  // https://github.com/keyboard-ergonomics/keymacs
  [LAYER_KEYMACS] = KEYMAP( // left fingers
						   KC_ESCAPE,KC_GRAVE,KC_QUES,KC_MINUS,TD(TD_ASSIGN),KC_PLUS,KC_CAPSLOCK, //TG(LAYER_NUMPAD),
						   KC_LALT,TD(TD_QU),KC_B,KC_P,KC_F,ALGR_T(KC_G),OSL(LAYER_FN),
						   KC_LCTL,LT(LAYER_AUXCHARS,KC_R),KC_A,KC_E,KC_N,RCTL_T(KC_S),
						   KC_LSHIFT,LT(LAYER_NUMPAD,KC_Z),KC_COMMA,KC_U,KC_K,SFT_T(KC_J),M(M_EMACS_SELECT),
						   TG(LAYER_KEYMACS),MO(LAYER_WM),_____,KC_UNDS,MO(LAYER_MOUSE),
						   // left thumb
						   LCTL(KC_G),KC_WWW_BACK,KC_PLUS,
						   LT(LAYER_CONTROL,KC_SPACE),GUI_T(KC_BSPACE),KC_MINUS,
						   // right fingers 
						   M(M_LAYER_IS_KEYMACS),KC_ASTR,KC_SCOLON,KC_DQUO,KC_EXLM,KC_EQUAL,KC_BSPACE,
						   OSL(LAYER_FN),ALT_T(KC_DOT),KC_W,KC_D,KC_Y,KC_QUOTE,KC_RALT,
						   CTL_T(KC_L),KC_O,KC_T,KC_I,LT(LAYER_AUXCHARS,KC_H),KC_RCTL,
						   _____,SFT_T(KC_M),KC_C,KC_X,KC_V,LT(LAYER_NUMPAD,KC_SLASH),KC_RSHIFT,
						   MO(LAYER_MOUSE),KC_UNDS,TT(LAYER_SYMBOLS),MO(LAYER_WM),TT(LAYER_RUSSIAN),
						   // right thumb
						   KC_WWW_FORWARD,RCTL(KC_W),KC_WWW_REFRESH,
						   ALT_T(KC_APPLICATION),GUI_T(KC_TAB),LT(LAYER_CONTROL,KC_ENTER)),

  // QWERTY for Russian Typewriter layout adapted for Ergodox
  // --------------------------------------------------------
  // Х moved to top for right index finger
  // Э moved to down for right pinky
  // Tap dance:
  // - double-tap for Ь produces Ъ
  // - unresovled because RCTL_T: double-tap for Е should produce Ё but not yet
  //
  // It has used shift-shift switcher (https://github.com/grafov/shift-shift).
  // Top row chars: [хз] [?] [-] [,] [хз]    [хз] [.] [х] [!] [хз]
  [LAYER_RUSSIAN] = KEYMAP(// left fingers
			  KC_ESCAPE,_____,KC_9,KC_2,KC_6,_____,_____,
			  KC_LALT,M(RU_SHORTI),M(RU_TSE),M(RU_U),M(RU_KA),RALT_T(M(RU_IE)),_____,
			  KC_LCTL,LTRU_AUX_LEFT,M(RU_YERU),M(RU_VE),M(RU_A),RCTL_T(M(RU_PE)),
			  KC_LSHIFT,LTRU_NUM_LEFT,M(RU_CHE),M(RU_ES),M(RU_EM),SFT_T(M(RU_I)),_____,
			  TO(LAYER_KEYMACS),_____,_____,_____,_____,
			  // left thumb
			  _____,_____,_____,
			  _____,_____,_____,
			  // right fingers
			  M(M_LAYER_IS_RUSSIAN),_____,M(KC_7),M(KC_LBRACKET),M(KC_MINUS),_____,_____,
			  _____,LALT_T(M(RU_EN)),M(RU_GHE),M(RU_SHA),M(RU_SHCHA),M(RU_ZE),KC_RALT,
			  LCTL_T(M(RU_ER)),M(RU_O),M(RU_EL),M(RU_DE),LTRU_AUX_RIGHT,KC_RCTL,
			  _____,SFT_T(M(RU_TE)),TD(TD_SHSIG),M(RU_BE),M(RU_YU),LTRU_NUM_RIGHT,KC_RSHIFT,
			  _____,_____,_____,_____,_____,
			  // right thumb
			  _____,_____,_____,
			  _____,_____,_____),

/* Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   `  |   ?  |   -  |   :  |   +  |      |           |      |   *  |   ;  |   "  |   !  |   =  |   BSP  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |   ^  |   #  |   [  |      |      |           |      |      |   ]  |   $  |   %  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   &  |   {  |   (  |      |------|           |------|      |   )  |   }  |   _  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   <  |   ~  |   @  |      |      |           |      |      |   =  |   \  |   |  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |TOG   |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |VAI   |VAD   |HUI   |       |SAI   |      |MOD   |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |HUD   |       |SAD   |      |      |
 *                                 `--------------------'       `--------------------'
 */  
  [LAYER_AUXCHARS] = KEYMAP(// left fingers
			  M(M_VRSN),KC_GRAVE,KC_QUES,KC_MINUS,TD(TD_ASSIGN),KC_PLUS,_____,
			  KC_LALT,_____,KC_CIRC,KC_HASH,KC_LBRACKET,_____,_____,
			  KC_LCTL,_____,KC_AMPR,KC_LCBR,KC_LPRN,_____,
			  KC_LSHIFT,_____,KC_LABK,KC_TILD,KC_AT,_____,_____,
			  _____,_____,_____,_____,_____,
			  // left thumb
			  _____,_____,_____,
			  LT(LAYER_CONTROL,KC_SPACE),_____,_____,
			  // right fingers
			  M(M_LAYER_IS_AUXCHARS),KC_ASTR,KC_SCOLON,KC_DQUO,KC_EXLM,KC_EQUAL,_____,
			  _____,KC_RABK,KC_RBRACKET,KC_DLR,KC_PERC,_____,KC_RALT,
			  _____,KC_RPRN,KC_RCBR,KC_UNDS,_____,KC_RCTRL,
			  _____,KC_ENTER,KC_EQUAL,KC_BSLASH,KC_PIPE,_____,KC_RSHIFT,
			  _____,_____,_____,_____,_____,
			  // right thumb
			  _____,_____,_____,
			  _____,_____,LT(LAYER_CONTROL,KC_SPACE)),

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

  // QWERTY for reference and for guests 
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
			  KC_NUMLOCK,KC_ASTR,KC_KP_7,KC_KP_8,KC_KP_9,_____,_____,
			  KC_LALT,KC_PLUS,KC_KP_4,KC_KP_5,KC_KP_6,_____,KC_TAB,
			  KC_LCTL,KC_MINUS,KC_KP_1,KC_KP_2,KC_KP_3,_____,
			  KC_LSHIFT,_____,KC_KP_DOT,KC_KP_0,KC_EQUAL,KC_ENTER,_____,
			  TO(LAYER_KEYMACS),_____,_____,_____,_____,
			  // left thumb
			  _____,_____,_____,
			  LT(LAYER_CONTROL,KC_SPACE),KC_LGUI,_____,
			  // right fingers
			  M(M_LAYER_IS_NUMPAD),KC_KP_ASTERISK,KC_KP_7,KC_KP_8,KC_KP_9,KC_KP_ASTERISK,KC_BSPACE,
			  KC_TAB,KC_KP_PLUS,KC_KP_4,KC_KP_5,KC_KP_6,KC_KP_PLUS,KC_RALT,
			  KC_KP_MINUS,KC_KP_1,KC_KP_2,KC_KP_3,KC_KP_MINUS,KC_RCTRL,
			  KC_KP_SLASH,KC_KP_ENTER,KC_EQUAL,KC_KP_0,KC_KP_DOT,_____,KC_RSHIFT,
			  _____,_____,_____,_____,_____,
			  // right thumb
			  _____,_____,_____
			  ,_____,KC_RGUI,LT(LAYER_CONTROL,KC_SPACE)),

  // Control layer for line and page navigation
  // TODO maybe combine it with WM control layer?
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

  // Media controls and Colors
  // TODO adapt more for mpv
  [LAYER_MEDIA] = KEYMAP(// left fingers
			 _____,_____,_____,_____,_____,_____,_____,
			 _____,_____,_____,_____,_____,_____,_____,
			 _____,_____,_____,_____,_____,_____,
			 _____,_____,_____,_____,_____,_____,_____,
			 TO(LAYER_KEYMACS),_____,_____,_____,_____,
			 // left thumb
			 RGB_MOD,_____,_____,
			 RGB_VAD,RGB_VAI,_____,
			 // right fingers
			 M(M_LAYER_IS_MEDIA),RGB_0000FF,RGB_008000,RGB_FFA500,RGB_800080,RGB_FF0000,_____,
			 _____,_____,_____,_____,_____,_____,_____,
			 _____,_____,_____,_____,_____,_____,
			 _____,_____,_____,_____,_____,_____,_____,
			 _____,_____,_____,_____,_____,
			 // right thumb
			 RGB_TOG,RGB_SLD,_____,
			 _____,RGB_HUD,RGB_HUI),

  // XXX Symbols layer for Unicode input 
  [LAYER_SYMBOLS] = KEYMAP(// left fingers
	 		   UC_LNX,UC(0x03a8),UC(0x0152),UC_A,_____,_____,_____,
			   _____,UC(0x00E4), UC(0x00E5), UC(0x00E9), UC(0x00AE), UC(0x00FE), _____,			   
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

  // Window manager control (i3 currently)
  [LAYER_WM] = KEYMAP(// left fingers
		      _____,LSFT(LGUI(KC_9)),LSFT(LGUI(KC_7)),LSFT(LGUI(KC_1)),LSFT(LGUI(KC_3)),LSFT(LGUI(KC_5)),_____,
		      _____,LGUI(KC_9),LGUI(KC_7),LGUI(KC_1),LGUI(KC_3),LGUI(KC_5),_____,
		      _____,LGUI(KC_R),_____,LGUI(KC_UP),LGUI(KC_DOWN),LGUI(KC_F10),
		      _____,LGUI(KC_Z),_____,_____,_____,LGUI(KC_J),LGUI(KC_F11),
		      TO(LAYER_KEYMACS),_____,_____,_____,_____,
		      // left thumb
		      _____,_____,_____,
		      LGUI(KC_SPACE),KC_ENTER,_____,
		      // right fingers
		      M(M_LAYER_IS_SYMBOLS),LSFT(RGUI(KC_6)),LSFT(RGUI(KC_2)),LSFT(RGUI(KC_0)),LSFT(RGUI(KC_4)),LSFT(RGUI(KC_8)),LGUI(KC_F9),
		      _____,RGUI(KC_6),RGUI(KC_2),RGUI(KC_0),RGUI(KC_4),RGUI(KC_8),LGUI(KC_F7),
		      LGUI(KC_F12),RGUI(KC_LEFT),RGUI(KC_RIGHT),_____,_____,LGUI(KC_F6),
		      LGUI(KC_F11),_____,_____,RGUI(KC_X),_____,_____,LGUI(KC_F5),
		      _____,_____,_____,_____,_____,
		      // right thumb
		      _____,_____,_____,
		      _____,KC_ENTER,RGUI(KC_SPACE)),

};

/* const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE */
/* ( */
/*  UCIS_SYM("poop", 0x1f4a9), */
/*  UCIS_SYM("rofl", 0x1f923), */
/*  UCIS_SYM("kiss", 0x1f619), */
/*  UCIS_SYM("snowman", 0x2603), */
/*  UCIS_SYM("coffee", 0x2615), */
/*  UCIS_SYM("heart", 0x2764), */
/*  UCIS_SYM("bolt", 0x26a1), */
/*  UCIS_SYM("pi", 0x03c0), */
/*  UCIS_SYM("mouse", 0x1f401), */
/*  UCIS_SYM("micro", 0x00b5), */
/*  UCIS_SYM("tm", 0x2122) */
/* ); */ 

const uint16_t PROGMEM fn_actions[] = {
  //  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};


// Runs just one time when the keyboard initializes.
/* void matrix_init_user(void) { */
/*   set_unicode_input_mode(UC_LNX); */
/* } */

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  
  if (record->event.pressed) {
  switch(id) {
	
  case RU_SHORTI: // Й
	return MACRO (T(SCROLLLOCK),T(Q),T(SCROLLLOCK), END);
  case RU_TSE: // Ц
	return MACRO (T(SCROLLLOCK),T(W),T(SCROLLLOCK), END);
  case RU_U: // У
	return MACRO (T(SCROLLLOCK),T(E),T(SCROLLLOCK), END);
  case RU_KA: // К
	return MACRO (T(SCROLLLOCK),T(R),T(SCROLLLOCK), END);
  case RU_IE: // 
	return MACRO (T(SCROLLLOCK),T(T),T(SCROLLLOCK), END);
  case RU_EN: // 
	return MACRO (T(SCROLLLOCK),T(Y),T(SCROLLLOCK), END);
  case RU_GHE: // 
	return MACRO (T(SCROLLLOCK),T(U),T(SCROLLLOCK), END);
  case RU_SHCHA: // 
	return MACRO (T(SCROLLLOCK),T(I),T(SCROLLLOCK), END);
  case RU_HA: // 
	return MACRO (T(SCROLLLOCK),T(O),T(SCROLLLOCK), END);
	//  case RU_HARDSIGN: //
	//	return MACRO (T(SCROLLLOCK),T(),T(SCROLLLOCK), END);
	//break;
   
  case RU_YERU: // 
	return MACRO (T(SCROLLLOCK),T(S),T(SCROLLLOCK), END);
  case RU_VE: // 
	return MACRO (T(SCROLLLOCK),T(D),T(SCROLLLOCK), END);
  case RU_A: // 
	return MACRO (T(SCROLLLOCK),T(F),T(SCROLLLOCK), END);
  case RU_PE: // 
	return MACRO (T(SCROLLLOCK),T(G),T(SCROLLLOCK), END);
  case RU_ER: // 
	return MACRO (T(SCROLLLOCK),T(H),T(SCROLLLOCK), END);
  case RU_O: // 
	return MACRO (T(SCROLLLOCK),T(J),T(SCROLLLOCK), END);
  case RU_EL: // 
	return MACRO (T(SCROLLLOCK),T(K),T(SCROLLLOCK), END);
  case RU_DE: // 
	return MACRO (T(SCROLLLOCK),T(L),T(SCROLLLOCK), END);
	//  case RU_ZHE: // 
	//	return MACRO (T(SCROLLLOCK),T(SCOLON),T(SCROLLLOCK), END);
  case RU_E: // 
	return MACRO (T(SCROLLLOCK),T(QUOTE),T(SCROLLLOCK), END);

	
  case RU_YA: // 
	return MACRO (T(SCROLLLOCK),T(Z),T(SCROLLLOCK), END);
  case RU_CHE: // 
	return MACRO (T(SCROLLLOCK),T(X),T(SCROLLLOCK), END);
  case RU_ES: // 
	return MACRO (T(SCROLLLOCK),T(C),T(SCROLLLOCK), END);
  case RU_EM: // 
	return MACRO (T(SCROLLLOCK),T(V),T(SCROLLLOCK), END);
  case RU_I: // 
	return MACRO (T(SCROLLLOCK),T(B),T(SCROLLLOCK), END);
  case RU_TE: // 
	return MACRO (T(SCROLLLOCK),T(N),T(SCROLLLOCK), END);
  case RU_SOFTSIGN: // 
	return MACRO (T(SCROLLLOCK),T(M),T(SCROLLLOCK), END);
  case RU_BE: // 
	 return MACRO (T(SCROLLLOCK),T(COMMA),T(SCROLLLOCK), END);
  case RU_YU: // 
	return MACRO (T(SCROLLLOCK),T(DOT),T(SCROLLLOCK), END);

	
  case M_EMACS_SELECT: // Emacs: reset the selection and activate a new one
    return MACRO(D(LCTL),T(G),T(SPC),U(LCTL),END);
  case M_VRSN:
    SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION "-Keymacs");
    break;
  case M_LAYER_IS_KEYMACS:
    SEND_STRING ("Layer is Keymacs [0]");
    break;
  case M_LAYER_IS_RUSSIAN:
    SEND_STRING ("Layer is Russian [1]");
    break;
  case M_LAYER_IS_AUXCHARS:
    SEND_STRING ("Layer is Aux Chars [2]");
    break;
  case M_LAYER_IS_MOUSE:
    SEND_STRING ("Layer is Mouse [3]");
    break;
  case M_LAYER_IS_QWERTY:
    SEND_STRING ("Layer is QWERTY [4]");
    break;
  case M_LAYER_IS_NUMPAD:
    SEND_STRING ("Layer is Numpad [5]");
    break;
  case M_LAYER_IS_CONTROL:
    SEND_STRING ("Layer is Control [6]");
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
  case M_LAYER_IS_WM:
    SEND_STRING ("Layer is WM [A]");
    break;
  }}
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static bool layer_interrupted = false;
  
  switch (keycode) {	  
  case LTRU_AUX_LEFT: // for Russian layer
	if (record->event.pressed) {
	  layer_interrupted = false;
	  layer_on(LAYER_AUXCHARS);
	} else {
	  if (!layer_interrupted) {
		RU(KC_A); // ф
	  }
	  layer_off(LAYER_AUXCHARS);
	}
	return false;
	break;
  case LTRU_AUX_RIGHT: // for Russian layer
	if (record->event.pressed) {
	  layer_interrupted = false;
	  layer_on(LAYER_AUXCHARS);
	} else {
	  if (!layer_interrupted) {
		RU(KC_SCOLON); // ж
	  }
	  layer_off(LAYER_AUXCHARS);
	}
	return false;
	break;
  case LTRU_NUM_LEFT: // for Russian layer 
	if (record->event.pressed) {
	  layer_interrupted = false;
	  layer_on(LAYER_NUMPAD);
	} else {
	  if (!layer_interrupted) {
		RU(KC_Z); // я
	  }
	  layer_off(LAYER_NUMPAD);
	}
	return false;
	break;
  case LTRU_NUM_RIGHT: // for Russian layer
	if (record->event.pressed) {
	  layer_interrupted = false;
	  layer_on(LAYER_NUMPAD);
	} else {
	  if (!layer_interrupted) {
		RU(KC_QUOTE); // э
	  }
	  layer_off(LAYER_NUMPAD);
	}
	return false;
	break;
	
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
	
  case XKB:
	if (record->event.pressed) {
	  SEND_STRING ("setxkbmap -layout 'us,ru(typewriter)' -option grp:sclk_toggle -option lv3:caps_switch -option misc:typo");
	}
	return false;
	break;

    default: {
      layer_interrupted = true;
      break;
    }
	
  }
  
  return true;
}

void matrix_scan_user(void) {
    static uint8_t old_layer = 0xff;
  
    uint8_t layer = biton32(layer_state);

	// do action once on a layer switch
	if (layer == old_layer) return;
	
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
    case LAYER_KEYMACS:
	  //      rgblight_task();
	  /* if (old_layer == LAYER_RUSSIAN) { */
	  /* 	register_code(KC_LALT); // switch to English */
	  /* 	unregister_code(KC_LALT); // switch to English */
	  /* } */
	  rgblight_show_solid_color(0,0,0);
      break;      
    case LAYER_RUSSIAN:
	  /* register_code(KC_RALT); // switch to Russian */
	  /* unregister_code(KC_RALT); // switch to Russian */
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
#ifdef RGBLIGHT_ENABLE
      rgblight_show_solid_color(0xff,0x00,0xff);
#endif
      break;
    case LAYER_AUXCHARS:
      ergodox_right_led_2_on();
#ifdef RGBLIGHT_ENABLE
      rgblight_show_solid_color(0x00,0xff,0x00);
#endif	  
      break;
    case LAYER_MOUSE:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
#ifdef RGBLIGHT_ENABLE
	  rgblight_effect_christmas();
#endif	  
      break;
    case LAYER_NUMPAD:
      ergodox_right_led_3_on();
#ifdef RGBLIGHT_ENABLE	  
      rgblight_show_solid_color(0x00,0x00,0xff);
#endif	  
      break;
    case LAYER_CONTROL:
      ergodox_right_led_1_on();
#ifdef RGBLIGHT_ENABLE
      rgblight_show_solid_color(0xff,0x00,0x00);
#endif
      break;
    case LAYER_FN:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
#ifdef RGBLIGHT_ENABLE
      rgblight_show_solid_color(0x00,0xff,0xff);
#endif	  
      break;
    case LAYER_WM:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
#ifdef RGBLIGHT_ENABLE
	  // rgblight_effect_christmas();
      rgblight_show_solid_color(0x11,0xff,0x33);
#endif	  
      break;
    default:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();	    
      ergodox_right_led_3_on();
#ifdef RGBLIGHT_ENABLE
      rgblight_show_solid_color(0x20,0x20,0x10);
#endif
     }
	old_layer = layer;
};

// Q or QU experiment
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
      break;
    default:
      reset_tap_dance(state);
  }
}

// Е/Ё для русской раскладки
void dance_eyo (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
	  // XXX
      break;
    case 2:
	  // XXX
      break;
    default:
      reset_tap_dance(state);
  }
}

// Ь/Ъ для русской раскладки
void dance_shsig (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      register_code(KC_M);
      unregister_code(KC_M);      
      break;
    case 2:
      register_code(KC_RBRACKET);
      unregister_code(KC_RBRACKET);      
      break;
    default:
      reset_tap_dance(state);
  }
}

// golang assign op
void dance_assign (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      SEND_STRING(":");
      break;
    case 2:
      SEND_STRING(" := ");
      break;
    default:
      reset_tap_dance(state);
  }
}

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_QU]  = ACTION_TAP_DANCE_FN(dance_qu),
  [TD_EYO] = ACTION_TAP_DANCE_FN(dance_eyo),
  [TD_SHSIG] = ACTION_TAP_DANCE_FN(dance_shsig),
  [TD_ASSIGN] = ACTION_TAP_DANCE_FN(dance_assign),
};

// https://github.com/qmk/qmk_firmware/issues/303
/* #define CTL_T_CUSTOM 0x7101 */

/* bool ctl_t_interrupted = false; */

/* bool process_record_user(uint16_t keycode, keyrecord_t *record) { */
/*     switch(keycode) { */
/*       case CTL_T_CUSTOM: { */
/*       if (record->event.pressed) { */
/*         ctl_t_interrupted = false; */
/*         register_code(KC_LCTL); */
/*       } else { */
/*         unregister_code(KC_LCTL); */
/*         if (!ctl_t_interrupted) { */
/*           register_code(KC_V); */
/*           unregister_code(KC_V); */
/*         } */
/*       } */
/*       return false; */
/*       break; */
/*     } */
/*     default: { */
/*       ctl_t_interrupted = true; */
/*       break; */
/*     } */
/* } */
	
