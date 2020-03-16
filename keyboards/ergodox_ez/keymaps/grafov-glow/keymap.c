/*
 * This is the keymap for the keyboard
 * Keymacs + Control layer + QWERTY + Emacs macros + misc experiments
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
//		 #include "ergodox_ez.h"
// #include "debug.h"
// #include "action_layer.h"
// #include "version.h"
// #include "process_keycode/process_tap_dance.h"

// Just for aesthetics
#define _____     KC_TRANSPARENT
#define XXXXX     KC_NO

// Switchers
#define RUS       KC_SCROLLLOCK
#define LAT       KC_SCROLLLOCK
#define MRUS      SCROLLLOCK
#define MLAT      SCROLLLOCK
#define XLAT      X_SCROLLLOCK
#define XRUS      X_SCROLLLOCK
#define LV3       KC_CAPSLOCK
#define MLV3      CAPSLOCK
// #define XKBSTR    "setxkbmap -layout \"us,ru(typewriter)\" -option grp:sclk_toggle -option lv3:caps_switch -option misc:typo"
#define TAP(kc)    register_code(kc); unregister_code(kc)

// Layer names
enum
{
   LAYER_KEYMACS = 0,
   LAYER_AUXCHARS,
   LAYER_RUSSIAN,
   LAYER_AUXCHARS_RU,
   LAYER_MOUSE,
   LAYER_QWERTY,
   LAYER_NUMPAD,
   LAYER_CONTROL,
   LAYER_FN,
   LAYER_GAME,
   LAYER_WM,
};

enum custom_keycodes
{
   PLACEHOLDER = SAFE_RANGE,      // can always be here
   RU_ASTR,
   EMACS_SELECT,
   EMACS_BLOCK_SELECT,
   M_RUASTR,
   ACCENT,
   RU_NOSIGN,
};

//Tap Dance Declarations
enum
{
   TD_DASH = 0,
   TD_GRAVEACCENT,
   TD_SHSIG,
   TD_LELKILAPKI,
   TD_RELKILAPKI,
   TD_TSE,
   TD_HE,
   TD_SCHCOLON,
   TD_YO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
   /* Default layer based on Keymacs layout
	* This is the adaptation of the layout for common keyboards for Ergodox EZ
	* https://github.com/keyboard-ergonomics/keymacs
	*
	* ,--------------------------------------------------.           ,--------------------------------------------------.
	* |   Esc  |   `  |   :  |   -  |   !  |   +  | Ctl-G|           | NumLk|   *  |   ?  |   "  |   ;  |   =  |   BSP  |
	* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	* |   Alt  |   q  |   b  |   p  |   f  |   g  | LGUI |           | LGUI |   v  |   w  |   l  |   y  |   '  |   Alt  |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |   Ctl  |   r  |   a  |   e  |.  n  |   s  |------|           |------|   d  |.  o  |   t  |   i  |   h  |   Ctl  |
	* |--------+------+------+------+------+------| Emacs|           |  Fn  |------+------+------+------+------+--------|
	* |  Shift |   z  |   ,  |   u  |   k  |   j  |  Sel |           |      |   m  |   c  |   x  |   .  |   /  |  Shift |
	* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	*   | LAT  |QWERTY| LGUI | APP  | S/Tab|                                       |M/Tab | APP  | RGUI |  CAPS|  RUS |
	*   `----------------------------------'                                       `----------------------------------'
	*                                        ,-------------.       ,-------------.
	*                                        | CtlG | Back |       | Frwd | CtlW |
	*                                 ,------|------|------|       |------+------+------.
	*                                 |      |      | CtlV |       | Rfrsh|      |      |
	*                                 |  SPC |  Tab |------|       |------| Ret  | SPC  |
	*                                 |/Shift|      | Ins  |       | Del  |      | /Ctl |
	*                                 `--------------------'       `--------------------'
	*/
   [LAYER_KEYMACS] = LAYOUT_ergodox(      // left fingers
	  KC_ESCAPE,                                                          KC_GRAVE,             KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,              LCTL(KC_G),
	  KC_LALT,                                                            LT(LAYER_NUMPAD,      KC_Q),            KC_B,             KC_P,                   KC_F,                 ALT_T(KC_G),              OSL(LAYER_WM),
	  KC_LCTL,                                                            LT(LAYER_AUXCHARS,    KC_R),            KC_A,             KC_E,                   KC_N,                 RCTL_T(KC_S),
	  KC_LSHIFT,                                                          LSFT_T(KC_Z),         KC_COMMA,         KC_U,             KC_K,                   LT(LAYER_CONTROL,KC_J),                   EMACS_SELECT,
	  TG(LAYER_KEYMACS),                                                  TG(LAYER_GAME),       KC_LGUI,          KC_UNDS,          LSFT_T(KC_TAB),
	  // left thumb
	  EMACS_BLOCK_SELECT,                                            KC_WWW_BACK,          LCTL(KC_V),
	  LT(LAYER_CONTROL,                                                   KC_SPACE),            LT(LAYER_MOUSE,   KC_TAB),          KC_INS,
	  // right finger
	  TG(LAYER_NUMPAD),                                                   KC_ASTR,              KC_QUES,          KC_DQUO,          KC_SCOLON,              KC_EQUAL,             KC_BSPACE,
	  OSL(LAYER_WM),                                                      ALT_T(KC_V),          KC_W,             KC_L,             KC_Y,                   LT(LAYER_NUMPAD,      KC_QUOTE),                KC_RALT,
	  LCTL_T(KC_D),                                                       KC_O,                 KC_T,             KC_I,             LT(LAYER_AUXCHARS,      KC_H),                KC_RCTL,
	  OSL(LAYER_FN),                                                      LT(LAYER_NUMPAD,      KC_M),            KC_C,             KC_X,                   KC_DOT,               RSFT_T(KC_SLASH),         KC_RSHIFT,
	  LT(LAYER_MOUSE,                                                     KC_TAB),              KC_EQUAL,         KC_RGUI,          KC_CAPSLOCK,            TO(LAYER_RUSSIAN),
	  // right thumb
	  KC_WWW_FORWARD,                                                     RCTL(KC_W),           KC_WWW_REFRESH,   // RCTL(KC_R),
	  KC_DELETE,                                                          LT(LAYER_MOUSE,       KC_ENTER),        LT(LAYER_CONTROL, KC_SPACE)),

   /* Symbol Layer
	*
	* ,--------------------------------------------------.           ,--------------------------------------------------.
	* |        |   `  |   :  |   -  |   !  |   +  |      |           |Numpad|   *  |   ?  |   "  |   ;  |   =  |   BSP  |
	* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	* |        |   ́  |   %  |   [  |   ]  |      |      |           |      |   |  |   ^  |   $  |   &  |   '  |        |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |        |      |   _  |   (  |.  )  |      |------|           |------|   №  |.  {  |   }  |   #  |      |        |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |        |      |   <  |   @  |   ~  |      |      |           |      |      |   =  |   \  |   >  |   /  |        |
	* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	*   |      |      |      |      |      |                                       |      |      |      |      |      |
	*   `----------------------------------'                                       `----------------------------------'
	*                                        ,-------------.       ,-------------.
	*                                        |      |      |       |      |      |
	*                                 ,------|------|------|       |------+------+------.
	*                                 |      |      |      |       |      |      |      |
	*                                 |      |      |------|       |------|      |      |
	*                                 |      |      |      |       |      |      |      |
	*                                 `--------------------'       `--------------------'
	*/
   [LAYER_AUXCHARS] = LAYOUT_ergodox(
	  // left fingers
	  _____,                                                               TD(TD_GRAVEACCENT),   KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,              _____,
	  KC_LALT,                                                            ACCENT,            KC_PERC,          KC_LBRACKET,      KC_RBRACKET,            XXXXX,                _____,
	  KC_LCTL,                                                            RU_NOSIGN,         KC_UNDS,          KC_LPRN,          KC_RPRN,                XXXXX,
	  KC_LSHIFT,                                                          XXXXX,                KC_LABK,          KC_AT,            KC_TILD,                KC_ENTER,             _____,
	  _____,                                                              _____,                _____,            _____,            KC_TAB,
	  // left thumb
	  _____,                                                              _____,                _____,
	  LT(LAYER_CONTROL,                                                   KC_SPACE),            _____,            _____,
	  // right fingers
	  _____,                                                              KC_ASTR,              KC_QUES,          KC_DQUO,          KC_SCOLON,              KC_EQUAL,             _____,
	  _____,                                                              KC_PIPE,              KC_CIRC,          KC_DLR,           KC_AMPR,                KC_QUOTE,             KC_RALT,
	  KC_NO,                                                              KC_LCBR,              KC_RCBR,          KC_HASH,          XXXXX,                  KC_RCTRL,
	  _____,                                                              KC_ENTER,             KC_EQUAL,         KC_BSLASH,        KC_RABK,                XXXXX,                KC_RSHIFT,
	  KC_TAB,                                                             _____,                _____,            _____,            _____,
	  // right thumb
	  _____,                                                              _____,                _____,
	  _____,                                                              _____,                LT(LAYER_CONTROL, KC_SPACE)),

   /* Russian layout slightly opimized for home row and adapted for EZ with Keymacs punctuatitons
	* for frequency optimization see https://ru.wikipedia.org/wiki/Частотность
	*
	* ,--------------------------------------------------.           ,--------------------------------------------------.
	* |        |  «/„ |  ч/: |   -  |   !  |  ё/+ |CapsLk|           |      |   *  |   ?  |  х/" |  щ/; |  »/“ |   BSP  |
	* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	* |        |   й  |   ц  |   у  |   к  |   ы  |      |           |      |   н  |   г  |   ш  |   ю  |   з  |        |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |        |   ф  |   а  |   е  |.  в  |   п  |------|           |------|   р  |.  о  |   л  |   д  |   ж  |        |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |        |   я  |   ,  |   с  |   м  |   и  |      |           |      |   т  |  ь/ъ |   б  |   .  |   э  |        |
	* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	*   | LAT  | LAT  |      |   _  |      |                                       |      |      |      | CAPS |      |
	*   `----------------------------------'                                       `----------------------------------'
	*                                        ,-------------.       ,-------------.
	*                                        |      |      |       |      |      |
	*                                 ,------|------|------|       |------+------+------.
	*                                 |      |      |      |       |      |      |      |
	*                                 |      |      |------|       |------|      |      |
	*                                 |      |      |      |       |      |      |      |
	*                                 `--------------------'       `--------------------'
	*/
   /* QWERTY for Russian Typewriter layout adapted for Ergodox */
   /* -------------------------------------------------------- */
   /* Х moved to top for right index finger */
   /* Э moved to down for right pinky */
   /* Tap dance: */
   /* - double-tap for Ь produces Ъ */
   /* - unresovled because RCTL_T: double-tap for Е should produce Ё but not yet */
   /* It has used shift-shift switcher (https://github.com/grafov/shift-shift). */
   [LAYER_RUSSIAN] = LAYOUT_ergodox(
	  // left fingers
	  KC_ESCAPE,                                                          TD(TD_LELKILAPKI),    TD(TD_TSE),       TD(TD_DASH),      KC_MINUS,               TD(TD_YO),            KC_CAPSLOCK,
	  KC_LALT,                                                            LT(LAYER_NUMPAD,      KC_Q),            KC_W,             KC_E,                   KC_R,                 ALT_T(KC_S),              _____,
	  KC_LCTL,                                                            LT(LAYER_AUXCHARS_RU, KC_A),            KC_F,             KC_T,                   KC_D,                 RCTL_T(KC_G),
	  KC_LSHIFT,                                                          LSFT_T(KC_Z),         KC_6,             KC_C,             KC_V,                   LT(LAYER_AUXCHARS_RU, KC_B),                    _____,
	  TO(LAYER_KEYMACS),                                                  TO(LAYER_KEYMACS),    _____,            KC_UNDS,          _____,
	  // left thumb=======
	  EMACS_BLOCK_SELECT,                                            KC_WWW_BACK,          KC_PLUS,
	  LT(LAYER_CONTROL,                                                   KC_SPACE),            LT(LAYER_MOUSE,   KC_TAB),          KC_INS,
	  // right fingers
	  _____,                                                              RU_ASTR,              KC_9,             TD(TD_HE),        TD(TD_SCHCOLON),        TD(TD_RELKILAPKI),    _____,
	  _____,                                                              ALT_T(KC_Y),          KC_U,             KC_I,             KC_DOT,                 LT(LAYER_NUMPAD,      KC_P),                    KC_RALT,
	  LCTL_T(KC_H),                                                       KC_J,                 KC_K,             KC_L,             LT(LAYER_AUXCHARS_RU,   KC_SCOLON),           KC_RCTL,
	  OSL(LAYER_FN),                                                      LT(LAYER_NUMPAD,      KC_N),            TD(TD_SHSIG),     KC_COMMA,               KC_7,                 RSFT_T(KC_QUOTE),         KC_RSHIFT,
	  _____,                                                              _____,                _____,            KC_CAPSLOCK,      _____,
	  // right thumb
	  KC_WWW_FORWARD,                                                     RCTL(KC_W),           KC_WWW_REFRESH,   // RCTL(KC_R),
	  KC_DELETE,                                                          LT(LAYER_MOUSE,       KC_ENTER),        LT(LAYER_CONTROL, KC_SPACE)),

   /* Symbol Layer for Russian layout
	*
	* ,--------------------------------------------------.           ,--------------------------------------------------.
	* |        |   `  |   :  |   -  |   !  |   +  |      |           |      |   *  |   ?  |   "  |   ;  |   =  |   BSP  |
	* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	* |        |   ́  |   %  |   [  |   ]  |      |      |           |      |   |  |   ^  |   $  |   &  |   '  |        |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |        |      |   _  |   (  |.  )  |      |------|           |------|   №  |.  {  |   }  |   #  |      |        |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |        |      |   <  |   @  |   ~  |      |      |           |      |      |   =  |   \  |   >  |   /  |        |
	* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	*   |      |      |      |   _  |      |                                       |      |      |      |      |      |
	*   `----------------------------------'                                       `----------------------------------'
	*                                        ,-------------.       ,-------------.
	*                                        |      |      |       |      |      |
	*                                 ,------|------|------|       |------+------+------.
	*                                 |      |      |      |       |      |      |      |
	*                                 |      |      |------|       |------|      |      |
	*                                 |      |      |      |       |      |      |      |
	*                                 `--------------------'       `--------------------'
	*/
   [LAYER_AUXCHARS_RU] = LAYOUT_ergodox(     // left fingers
	  _____,                                                            TD(TD_GRAVEACCENT),   KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,              _____,
	  KC_LALT,                                                            ACCENT,            KC_PERC,          KC_LBRACKET,      KC_RBRACKET,            _____,                _____,
	  KC_LCTL,                                                            XXXXX,                KC_UNDS,          KC_LPRN,          KC_RPRN,                KC_NO,
	  KC_LSHIFT,                                                          XXXXX,                KC_LABK,          KC_AT,            KC_TILD,                KC_ENTER,             _____,
	  _____,                                                              _____,                _____,            SFT_T(KC_9),      KC_TAB,
	  // left thumb
	  _____,                                                              _____,                _____,
	  LT(LAYER_CONTROL,                                                   KC_SPACE),            _____,            _____,
	  // right fingers
	  _____,                                                              KC_ASTR,              KC_QUES,          KC_LBRACKET,      KC_SCOLON,              KC_EQUAL,             _____,
	  _____,                                                              KC_PIPE,              KC_CIRC,          KC_DLR,           KC_AMPR,                KC_QUOTE,             KC_RALT,
	  RU_NOSIGN,                                                       KC_LCBR,              KC_RCBR,          KC_HASH,          KC_NO,                  KC_RCTRL,
	  OSL(LAYER_FN),                                                      KC_ENTER,             KC_EQUAL,         KC_BSLASH,        KC_RABK,                KC_SLASH,             KC_RSHIFT,
	  KC_TAB,                                                             _____,                _____,            _____,            _____,
	  // right thumb
	  _____,                                                              _____,                _____,
	  _____,                                                              _____,                LT(LAYER_CONTROL, KC_ENTER)),

   // Mouse control
   [LAYER_MOUSE] = LAYOUT_ergodox(     // left fingers
	  _____,                                                              _____,                _____,            _____,            _____,                  _____,                KC_MUTE,
	  _____,                                                              _____,                KC_MS_BTN3,       _____,            LGUI(RCTL(RALT(KC_F))), _____,                KC_VOLU,
	  _____,                                                              _____,                KC_MS_BTN1,       KC_MS_UP,         KC_MS_DOWN,             _____,
	  _____,                                                              _____,                KC_MS_BTN2,       KC_MS_WH_UP,      KC_MS_WH_DOWN,          _____,                KC_VOLD,
	  _____,                                                              TO(LAYER_KEYMACS),    KC_MS_BTN2,       KC_MS_BTN3,       KC_MS_BTN1,
	  // left thumb
	  _____,                                                              _____,                _____,            _____,            _____,                  _____,
	  // right fingers
	  KC_MS_ACCEL0,                                                       _____,                _____,            _____,            _____,                  _____,                _____,
	  KC_MS_ACCEL2,                                                       _____,                KC_MS_BTN1,       KC_MS_BTN2,       KC_MS_BTN3,             _____,                _____,
	  _____,                                                              KC_MS_LEFT,           KC_MS_RIGHT,      KC_MS_BTN1,       _____,                  _____,
	  KC_MS_ACCEL1,                                                       KC_ENTER,             KC_MS_WH_LEFT,    KC_MS_WH_RIGHT,   KC_MS_BTN2,             _____,                _____,
	  _____,                                                              KC_MS_BTN1,           KC_MS_BTN3,       KC_MS_BTN2,       _____,
	  // right thumb
	  _____,                                                              _____,                _____,            _____,            _____,                  _____),

   /* Numpad for the right hand (left hand the same as for Symbols layer)
	*
	* ,--------------------------------------------------.           ,--------------------------------------------------.
	* |        |   `  |   :  |   -  |   !  |   +  |      |           |      |   *  |   7  |   8  |   9  |   =  |   BSP  |
	* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	* |        |   ́  |   %  |   [  |   ]  |      |      |           |      |   |  |   4  |   5  |   6  |   '  |        |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |        |      |   _  |   (  |.  )  |      |------|           |------|   №  |.  1  |   2  |   3  |   -  |        |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |        |      |   ,  |   @  |   ~  |      |      |           |      |      |   =  |   0  |   .  |   /  |        |
	* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	*   |      |      |      |   _  |      |                                       |      |      |      |      |      |
	*   `----------------------------------'                                       `----------------------------------'
	*                                        ,-------------.       ,-------------.
	*                                        |      |      |       |      |      |
	*                                 ,------|------|------|       |------+------+------.
	*                                 |      |      |      |       |      |      |      |
	*                                 |      |      |------|       |------|      |      |
	*                                 |      |      |      |       |      |      |      |
	*                                 `--------------------'       `--------------------'
	*/
   [LAYER_NUMPAD] = LAYOUT_ergodox(     // left fingers
	  KC_NUMLOCK,                                                         TD(TD_GRAVEACCENT),   KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,              _____,
	  KC_LALT,                                                            ACCENT,            KC_PERC,          KC_LBRACKET,      KC_RBRACKET,            XXXXX,                _____,
	  KC_LCTL,                                                            XXXXX,                KC_UNDS,          KC_LPRN,          KC_RPRN,                XXXXX,
	  KC_LSHIFT,                                                          XXXXX,                KC_LABK,          KC_AT,            KC_TILD,                KC_TAB,               _____,
	  _____,                                                              _____,                _____,            _____,            _____,
	  // left thumb
	  _____,                                                              _____,                _____,
	  LT(LAYER_CONTROL,                                                   KC_SPACE),            LT(LAYER_WM,      KC_TAB),          _____,
	  // right fingers
	  _____,                                                              KC_KP_ASTERISK,       KC_7,             KC_8,             KC_9,                   KC_EQUAL,             KC_BSPACE,
	  KC_NUMLOCK,                                                         KC_PIPE,              KC_4,             KC_5,             KC_6,                   KC_QUOTE,             KC_RALT,
	  RU_NOSIGN,                                                       KC_1,                 KC_2,             KC_3,             KC_KP_MINUS,            KC_RCTRL,
	  KC_KP_SLASH,                                                        KC_KP_ENTER,          KC_KP_EQUAL,      KC_0,             KC_KP_DOT,              _____,                KC_RSHIFT,
	  _____,                                                              _____,                _____,            _____,            _____,
	  // right thumb
	  _____,                                                              _____,                _____
	  ,                                                                   _____,                LT(LAYER_WM,      KC_ENTER),        LT(LAYER_CONTROL,       KC_SPACE)),

   /* Control layer for line and page navigation
	* based on https://github.com/keyboard-ergonomics/control-layer.
	* Copypaste keys for Emacs (Alt+W,Ctl+W,Ctl+Y) and WordStar-like (Ctl+C,Ctl+X,Ctl+V) bindinds.
	* Copypaste keys for right hand because I'm using trackball by left hand.
	*
	* ,--------------------------------------------------.           ,--------------------------------------------------.
	* |  Esc   |      |      |      |      |      |      |           |      |      |      |      |      |      |   BSP  |
	* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	* |  Alt   |      |      |      |      | Esc  |      |           |      | CtlV | AltW | CtlW | CtlY |      | Alt    |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |  Ctrl  | CtlR | Home |  Up  |. Down| End  |------|           |------|  Del |. Left| Right|  BSP |  Tab | Ctrl   |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* | Shift  |      |SftTab| PgUp | PgDn | Tab  |      |           |      | Enter| CtlC | CtlX | CtlV | Ctl/ | Shift  |
	* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	*   |      |      |      |      |      |                                       |      |      |      |      |      |
	*   `----------------------------------'                                       `----------------------------------'
	*                                        ,-------------.       ,-------------.
	*                                        |      | Back |       | Fwd  |      |
	*                                 ,------|------|------|       |------+------+------.
	*                                 |      |      |      |       |Reload|      |      |
	*                                 | SPC  | Enter|------|       |------| Enter| SPC  |
	*                                 |      |      |      |       |      |      |      |
	*                                 `--------------------'       `--------------------'
	*/
   [LAYER_CONTROL] = LAYOUT_ergodox(     // left fingers
	  _____,                                                    XXXXX,                XXXXX,            XXXXX,            _____,                  _____,                KC_CAPSLOCK,
	  _____,                                                              XXXXX,                KC_LEFT,          KC_UP,            KC_RIGHT,               KC_ESCAPE,            KC_LGUI,
	  _____,                                                              RCTL(KC_R),           KC_HOME,          KC_UP,            KC_DOWN,                KC_END,
	  _____,                                                              RCTL(KC_Z),           RSFT(KC_ENTER),   KC_PGUP,          KC_PGDOWN,              KC_ENTER,             LCTL(KC_QUES),
	  TO(LAYER_KEYMACS),                                                  XXXXX,                XXXXX,            XXXXX,            KC_TAB,
	  // left thumb
	  KC_SPACE,                                                           KC_TAB,               _____,            _____,            _____,                  _____,
	  // right fingers
	  _____,                                                              RGUI(KC_F6),          RGUI(KC_F12),     XXXXX,            XXXXX,                  XXXXX,                _____,
	  KC_LGUI,                                                            LCTL(KC_V),           LALT(KC_W),       LCTL(KC_W),       LCTL(KC_Y),             XXXXX,                _____,
	  KC_DELETE,                                                          KC_LEFT,              KC_RIGHT,         KC_BSPACE,        KC_TAB,                 _____,
	  XXXXX,                                                              KC_ENTER,             LCTL(KC_C),       LCTL(KC_X),       LCTL(KC_V),             LCTL(KC_SLASH),       _____,
	  KC_TAB,                                                             XXXXX,                XXXXX,            XXXXX,            XXXXX,
	  // right thumb
	  _____,                                                              _____,                _____,            _____,            KC_ENTER,               KC_SPACE),

   /* Fn keys for the right hand (left hand the same as for Symbols layer)
	*
	* ,--------------------------------------------------.           ,--------------------------------------------------.
	* |        |   `  |   :  |   -  |   !  |   +  |      |           |      |   *  |   F7 |   F8 |   F9 |   =  |   BSP  |
	* |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
	* |        |   ́  |   %  |   [  |   ]  |      |      |           |      | Alt  |   F4 |   F5 |   F6 |   +  |        |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |        |      |   _  |   (  |.  )  |      |------|           |------| Ctrl |.  F1 |   F2 |   F3 |   -  |        |
	* |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
	* |        |      |   ,  |   @  |   ~  |      |      |           |      | Shift|      |  F10 |      |   /  |        |
	* `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
	*   |      |      |      |   _  |      |                                       |      |      |      |      |      |
	*   `----------------------------------'                                       `----------------------------------'
	*                                        ,-------------.       ,-------------.
	*                                        |      |      |       |      |      |
	*                                 ,------|------|------|       |------+------+------.
	*                                 |      |      |      |       |      |      |      |
	*                                 |      |      |------|       |------|      |      |
	*                                 |      |      |      |       |      |      |      |
	*                                 `--------------------'       `--------------------'
	*/
   [LAYER_FN] = LAYOUT_ergodox(     // left fingers
	  KC_NUMLOCK,                                                         TD(TD_GRAVEACCENT),   KC_COLON,         TD(TD_DASH),      KC_EXLM,                KC_PLUS,              _____,
	  KC_LALT,                                                            ACCENT,            KC_PERC,          KC_LBRACKET,      KC_RBRACKET,            KC_NO,                _____,
	  KC_LCTL,                                                            KC_NO,                KC_UNDS,          KC_LPRN,          KC_RPRN,                KC_NO,
	  KC_LSHIFT,                                                          KC_NO,                KC_LABK,          KC_AT,            KC_TILD,                KC_TAB,               _____,
	  TO(LAYER_KEYMACS),                                                  _____,                _____,            _____,            _____,
	  // left thumb
	  _____,                                                              _____,                _____,
	  LT(LAYER_CONTROL,                                                   KC_SPACE),            LT(LAYER_WM,      KC_TAB),          _____,
	  // right fingers
	  _____,                                                              KC_KP_ASTERISK,       KC_F7,            KC_F8,            KC_F9,                  KC_EQUAL,             KC_BSPACE,
	  KC_RALT,                                                            KC_PIPE,              KC_F4,            KC_F5,            KC_F6,                  KC_KP_PLUS,           KC_RALT,
	  KC_RCTL,                                                            KC_F1,                KC_F2,            KC_F3,            KC_KP_MINUS,            KC_RCTRL,
	  KC_RSHIFT,                                                          _____,                KC_F11,           KC_F10,           KC_F12,                 _____,                KC_RSHIFT,
	  _____,                                                              _____,                _____,            _____,            TO(LAYER_RUSSIAN),
	  // right thumb
	  _____,                                                              _____,                _____,
	  _____,                                                              LT(LAYER_WM,          KC_ENTER),        LT(LAYER_CONTROL, KC_SPACE)),

   // Gaming mode mostly for action games
   [LAYER_GAME] = LAYOUT_ergodox(     // left fingers
	  KC_ESCAPE,                                                          KC_1,                 KC_2,             KC_3,             KC_4,                   KC_5,                 KC_6,
	  KC_TAB,                                                             KC_LALT,              KC_Q,             KC_W,             KC_E,                   KC_T,                 KC_0,
	  KC_M,                                                               KC_LCTL,              KC_A,             KC_S,             KC_D,                   KC_F,
	  KC_RSHIFT,                                                          KC_LSHIFT,            KC_Z,             KC_X,             KC_C,                   KC_V,                 KC_G,
	  KC_J,                                                               KC_L,                 KC_TILD,          KC_LGUI,          KC_R,
	  // left thumb
	  KC_B,                                                               KC_9,                 _____,
	  KC_SPACE,                                                           KC_MS_BTN3,           KC_MS_BTN1,
	  // right fingers
	  KC_7,                                                               KC_8,                 KC_F7,            KC_F8,            KC_F9,                  KC_0,                 KC_Y,
	  KC_I,                                                               KC_Y,                 KC_F4,            KC_F5,            KC_F6,                  KC_P,                 KC_U,
	  KC_H,                                                               KC_H,                 KC_F1,            KC_F2,            KC_F3,                  KC_I,
	  _____,                                                              KC_N,                 KC_F11,           KC_F10,           KC_F12,                 KC_SLASH,             KC_RSHIFT,
	  _____,                                                              KC_LEFT,              KC_UP,            TO(LAYER_QWERTY), TO(LAYER_KEYMACS),
	  // right thumb
	  _____,                                                              _____,                _____,
	  _____,                                                              KC_ENTER,             KC_SPACE),

   // QWERTY for reference and for guests
   [LAYER_QWERTY] = LAYOUT_ergodox(     // left fingers
	  KC_ESCAPE,                                                          KC_1,                 KC_2,             KC_3,             KC_4,                   KC_5,                KC_6,
	  KC_LALT,                                                            KC_Q,                 KC_W,             KC_E,             KC_R,                   KC_T,                 KC_TAB,
	  KC_LCTL,                                                            KC_A,                 KC_S,             KC_D,             KC_F,                   KC_G,
	  KC_LSHIFT,                                                          KC_Z,                 KC_X,             KC_C,             KC_V,                   KC_B,                 _____,
	  TO(LAYER_KEYMACS),                                                  _____,                _____,            KC_LGUI,          KC_LALT,
	  // left thumb
	  _____,                                                              _____,                _____,
	  KC_SPACE,                                                           KC_ENTER,             _____,
	  // right fingers
	  TO(LAYER_KEYMACS),                                                  KC_6,                 KC_7,             KC_8,             KC_9,                   KC_0,                 KC_BSPACE,
	  KC_TAB,                                                             KC_Y,                 KC_U,             KC_I,             KC_O,                   KC_P,                 KC_LALT,
	  KC_H,                                                               KC_J,                 KC_K,             KC_L,             KC_QUES,                KC_LCTL,
	  _____,                                                              KC_N,                 KC_M,             KC_COMMA,         KC_DOT,                 KC_SLASH,             KC_RSHIFT,
	  _____,                                                              KC_LEFT,              KC_UP,            KC_DOWN,          KC_RIGHT,
	  // right thumb
	  _____,                                                              _____,                _____,
	  _____,                                                              KC_ENTER,             KC_SPACE),

   // Window manager control (currently for Spectr WM)
   [LAYER_WM] = LAYOUT_ergodox(     // left fingers
	  TO(LAYER_KEYMACS),                                                  KC_GRAVE,             KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,              _____,
	  ALT_T(KC_TAB),                                                      KC_Q,                 KC_B,             KC_P,             KC_F,                   ALGR_T(KC_G),         LCTL(KC_ENTER),
	  KC_LCTL,                                                            LT(LAYER_NUMPAD,      KC_R),            KC_A,             KC_E,                   KC_N,                 KC_S,
	  KC_LSHIFT,                                                          KC_Z,                 KC_COMMA,         KC_U,             KC_K,                   SFT_T(KC_J),          LSFT(KC_TAB),
	  TO(LAYER_KEYMACS),                                                  _____,                _____,            KC_UNDS,          KC_TAB,
	  // left thumb
	  LCTL(KC_G),                                                         KC_WWW_BACK,          LCTL(KC_V),
	  KC_SPACE,                                                           _____,                KC_INS,
	  // right fingers
	  _____,                                                              KC_ASTR,              KC_7,             KC_8,             KC_9,                   KC_EQUAL,             KC_BSPACE,
	  RCTL(KC_ENTER),                                                     ALT_T(KC_V),          KC_4,             KC_5,             KC_6,                   KC_QUOTE,             KC_RALT,
	  CTL_T(KC_D),                                                        KC_1,                 KC_2,             KC_3,             LT(LAYER_NUMPAD,        KC_H),                KC_RCTL,
	  KC_TAB,                                                             SFT_T(KC_M),          KC_C,             KC_0,             KC_DOT,                 KC_SLASH,             KC_RSHIFT,
	  KC_TAB,                                                             KC_UNDS,              _____,            _____,            TO(LAYER_RUSSIAN),
	  // right thumb
	  KC_WWW_FORWARD,                                                     RCTL(KC_W),           KC_WWW_REFRESH,
	  KC_DELETE,                                                          _____,                KC_SPACE),
};

static bool ingame = false;     // for GAME LAYER

// implements user hook on the each key press/release
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
   static uint8_t old_layer = 0xff;
   static bool    backrus;
   static uint8_t layer = 0xff;
   static bool    shift_pressed;

   old_layer = layer;
   layer     = biton32(layer_state);

   if(old_layer != layer){
	  // when layer switched
	  //
	  if(old_layer == LAYER_WM){
		 unregister_code(KC_LGUI);
		 }

	  switch(layer){
		  case LAYER_CONTROL:
		  case LAYER_KEYMACS:
		  case LAYER_NUMPAD:
		  case LAYER_AUXCHARS_RU:
			 if(old_layer == LAYER_RUSSIAN){
				// switch to English
				TAP(LAT);
				}
			 break;

		  case LAYER_RUSSIAN:
			 if(old_layer != LAYER_MOUSE){
				// switch to Russian
				TAP(RUS);
				}
			 break;

		  case LAYER_FN:
			 if(old_layer == LAYER_RUSSIAN){
				// switch to English
				TAP(LAT);
				}
			 break;

		  case LAYER_WM:
			 if(old_layer == LAYER_RUSSIAN){
				// switch to English
				TAP(LAT);
				}
			 register_code(KC_LGUI);
			 break;
			 }
	  }
   else{
	   // when layer didn't switch
	   //
	   switch(old_layer){
		   case LAYER_GAME:
			  if(keycode == KC_I || keycode == KC_Y || keycode == KC_U){
				 ingame = true;
				 register_code(keycode);
				 unregister_code(keycode);
				 layer_off(LAYER_GAME);
				 layer_on(LAYER_KEYMACS);
				 return(true);
				 }
			  break;

		   case LAYER_KEYMACS:
			  if(ingame && (keycode == KC_ENTER || keycode == KC_ESC)){
				 ingame = false;
				 unregister_code(KC_ESC);
				 register_code(KC_ENTER);
				 unregister_code(KC_ENTER);
				 layer_off(LAYER_KEYMACS);
				 layer_on(LAYER_GAME);
				 return(false);
				 }
			  break;
			  }
	   }

   switch(keycode){
	   case KC_LSHIFT:
	   case KC_RSHIFT:
		  ergodox_right_led_3_on();
		  if(record->event.pressed){
			 shift_pressed = true;
			 }
		  else{
		   ergodox_right_led_3_off();
		  shift_pressed = false;
			  }
		  return(true);

  // when Alt or Ctl pressed in Russian layout temporary switch back to Latin layout
   case KC_LCTL:																																													case KC_RCTL:
	  ergodox_right_led_2_on();
	   case KC_LALT:
	   case KC_RALT:
		  if (keycode==KC_LALT||keycode==KC_RALT) ergodox_right_led_1_on();
	   if(!record->event.pressed) {
		ergodox_right_led_1_off();
		   ergodox_right_led_2_off();
	   }
	   case KC_APP:
		  if(backrus){
			 if(!record->event.pressed){
				layer_off(LAYER_KEYMACS);
				layer_on(LAYER_RUSSIAN);
				backrus = false;
				}
			 }
		  else{
			  if(layer == LAYER_RUSSIAN){
				 layer_off(LAYER_RUSSIAN);
				 layer_on(LAYER_KEYMACS);
				 backrus = true;
				 }
			  }
		  return(true);

	   case RU_ASTR:
		  if(record->event.pressed){
			 SEND_STRING(SS_TAP(XLAT) "*" SS_TAP(XRUS));
			 }
		  return(false);

	   case KC_MINUS:
		  if(shift_pressed && record->event.pressed){
			 unregister_code(KC_LSHIFT);
			 unregister_code(KC_RSHIFT);
			 register_code(LV3);
			 }
		  if(record->event.pressed){
			 TAP(KC_MINUS);
			 }
		  if(shift_pressed && !record->event.pressed){
			 unregister_code(LV3);
			 }
		  return(false);

	  case ACCENT:
			 SEND_STRING(SS_DOWN(X_CAPSLOCK) "a" SS_UP(X_CAPSLOCK));
			 return(false);

	  // case RU_NOSIGN:
	  //		 SEND_STRING(SS_TAP(X_SCROLLLOCK), "3", SS_TAP(X_SCROLLLOCK));
	  //		 return(false);

	  case EMACS_SELECT:              // Emacs: reset the selection and activate a new one
			 SEND_STRING(SS_LCTL("g "));
			 return(false);

	  case EMACS_BLOCK_SELECT:
			 SEND_STRING(SS_LCTL("gx") " ");
			 return(false);
   }

   return(true);
}

uint32_t layer_state_set_user(uint32_t state)
{
   uint8_t layer = biton32(state);

   switch(layer){
	   case LAYER_KEYMACS:
		  rgblight_mode(0);
		  break;

	   case LAYER_CONTROL:
		  rgblight_mode(1);
		  rgblight_sethsv(HSV_RED);
		  break;

	   case LAYER_AUXCHARS:
		  rgblight_mode(1);
		  rgblight_sethsv(HSV_AZURE);
		  break;

	   case LAYER_RUSSIAN:
		  rgblight_mode(1);
		  rgblight_sethsv(HSV_BLUE);
		  break;

	   case LAYER_AUXCHARS_RU:
		  rgblight_mode(1);
		  rgblight_sethsv(HSV_MAGENTA);
		  break;

	   case LAYER_MOUSE:
		  rgblight_mode(1);
		  rgblight_sethsv(HSV_GOLD);
		  break;

	  case LAYER_NUMPAD:
		  rgblight_mode(1);
		  rgblight_sethsv(HSV_GREEN);
		  break;

	   case LAYER_FN:
		  rgblight_mode(1);
		  rgblight_sethsv(HSV_PURPLE);
		  break;

	   case LAYER_WM:
		  rgblight_mode(1);
		  rgblight_sethsv(HSV_ORANGE);
		  break;
	  }
   return(state);
};

// XXX I have stopped using it
// Grave vs accent sign
void dance_graveaccent(qk_tap_dance_state_t *state, void *user_data)
{
   switch(state->count){
	   case 1:
		  TAP(KC_GRAVE);
		  break;

	   case 2:
		  register_code(LV3);
		  TAP(KC_A);
		  unregister_code(LV3);
		  break;

	   default:
		  reset_tap_dance(state);
		  }
}

// -/— minus or emdash
void dance_dash(qk_tap_dance_state_t *state, void *user_data)
{
   uint8_t layer = biton32(layer_state);       // get the current layer

   switch(state->count){
	   case 1:
		  if(layer == LAYER_RUSSIAN){
			 TAP(LAT);
			 }
		  TAP(KC_MINUS);
		  if(layer == LAYER_RUSSIAN){
			 TAP(RUS);
			 }
		  break;

	   case 2:
		  register_code(LV3);
		  TAP(KC_MINUS);
		  unregister_code(LV3);
		  break;

	   default:
		  reset_tap_dance(state);
		  }
}

// «/„ для русской раскладки
void dance_elkilapki_left(qk_tap_dance_state_t *state, void *user_data)
{
   switch(state->count){
	   case 1:
		  register_code(LV3);
		  TAP(KC_COMMA);
		  unregister_code(LV3);
		  break;

	   case 2:
		  register_code(LV3);
		  TAP(KC_J);
		  unregister_code(LV3);
		  break;

	   default:
		  reset_tap_dance(state);
		  }
}

// »/“ для русской раскладки
void dance_elkilapki_right(qk_tap_dance_state_t *state, void *user_data)
{
   switch(state->count){
	   case 1:
		  register_code(LV3);
		  TAP(KC_DOT);
		  unregister_code(LV3);
		  break;

	   case 2:
		  register_code(LV3);
		  TAP(KC_K);
		  unregister_code(LV3);
		  break;

	   default:
		  reset_tap_dance(state);
		  }
}

// Ь/Ъ для русской раскладки
void dance_shsig(qk_tap_dance_state_t *state, void *user_data)
{
   switch(state->count){
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

// And finally the Dancings!
qk_tap_dance_action_t tap_dance_actions[] =
{
   [TD_DASH]        = ACTION_TAP_DANCE_FN(dance_dash),
   [TD_GRAVEACCENT] = ACTION_TAP_DANCE_FN(dance_graveaccent),
   [TD_SHSIG]       = ACTION_TAP_DANCE_FN(dance_shsig),
   [TD_LELKILAPKI]  = ACTION_TAP_DANCE_FN(dance_elkilapki_left),
   [TD_RELKILAPKI]  = ACTION_TAP_DANCE_FN(dance_elkilapki_right),
   [TD_TSE]         = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_5),              // ч/;
   [TD_HE]          = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_4),       // х/"
   [TD_SCHCOLON]    = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_EQUAL),          // щ/:
   [TD_YO]          = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_TILD),       // ч/;
};
