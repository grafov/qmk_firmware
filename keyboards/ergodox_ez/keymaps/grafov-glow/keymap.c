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
#define _____    KC_TRANSPARENT
#define XXXXX    KC_NO

// Switchers
//#define RUS      KC_SCROLLLOCK
//#define LAT      KC_SCROLLLOCK
// return to shift-shift utility for layout switching
#define RUS      KC_RSFT
#define LAT      KC_LSFT

#define MRUS     RSFT
#define MLAT     LSFT
#define XLAT     X_SCROLLLOCK
#define XRUS     X_SCROLLLOCK
#define LV3      KC_CAPSLOCK
#define MLV3     CAPSLOCK
// #define XKBSTR    "setxkbmap -layout \"us,ru(typewriter)\" -option grp:sclk_toggle -option lv3:caps_switch -option misc:typo"
#define TAP(kc)    register_code(kc); unregister_code(kc)

// Layer names
enum
{
   LAYER_KEYMACS = 0,
   LAYER_AUX,
   LAYER_RUSSIAN,
   LAYER_AUX_RU,
   LAYER_CONTROL,
   LAYER_PTR,
   LAYER_QWERTY,
   LAYER_NUMPAD,
   LAYER_FN,
   LAYER_GAME,
   LAYER_WM,
   MAX_LAYER,
};

enum custom_keycodes
{
   PLACEHOLDER = SAFE_RANGE,      // can always be here
   RU_ASTR,
   EMACS_TAB,
   EMACS_SELECT,
   EMACS_BLOCK_SELECT,
   EMACS_ALTX,
   EMACS_RESET,
   M_RUASTR,
   ASSIGN,
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
m   TD_SCHCOLON,
   TD_YO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{

   /* Default layer based on Keymacs layout
    * This is the adaptation of the layout for common keyboards for Ergodox EZ
    * https://github.com/keyboard-ergonomics/keymacs
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |   Esc  |   `  |   :  |   -  |   !  |   +  | Ctl-G|           | NumLk|   *  |   ?  |   "  |   ;  |  :=  |  Undo  |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |   Alt  |   q  |   b  |   p  |   f  |   g  |      |           | LGUI |   v  |   w  |   l  |   y  |   '  |   Alt  |
    * |--------+------+------+------+------+------| Find |           |      |------+------+------+------+------+--------|
    * |   Ctl  |   r  |   a  |   e  |.  n  |   s  |------|           |------|   d  |.  o  |   t  |   i  |   h  |   Ctl  |
    * |--------+------+------+------+------+------| Emacs|           | Emacs|------+------+------+------+------+--------|
    * |  Shift |   z  |   ,  |   u  |   k  |   j  |Select|           | CMD  |   m  |   c  |   x  |   .  |   /  |  Shift |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | LAT  |QWERTY| LGUI |   _  | Shift|                                       |Shift | APP  | RGUI |  CAPS|  RUS |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,--------------.     ,--------------.
    *                                        | Shift| LShift|     | RShift| Shift|
    *                                 ,------|------|-------|     |-------+------+------.
    *                                 |      |      | LCtl  |     | RCtl  |      |      |
    *                                 | BSpc |  Tab |-------|     |-------| Ret  | SPC  |
    *                                 | nav  | Ctrl |Del/Alt|     |Ins/Alt| Ctrl | nav  |
    *                                 `---------------------'     `---------------------'
    */
   [LAYER_KEYMACS] = LAYOUT_ergodox(      // left fingers
      KC_ESCAPE,                                                          KC_GRAVE,           KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,           EMACS_RESET,
      KC_LALT,                                                            LT(LAYER_NUMPAD,    KC_Q),            KC_B,             KC_P,                   KC_F,              ALT_T(KC_G),     KC_FIND,
      KC_LCTL,                                                            LT(LAYER_AUX,       KC_R),            KC_A,             KC_E,                   KC_N,              RCTL_T(KC_S),
      KC_LSHIFT,                                                          LSFT_T(KC_Z),       KC_COMMA,         KC_U,             KC_K,                   LT(LAYER_FN,  KC_J),           EMACS_SELECT,
      TG(LAYER_KEYMACS),                                                  XXXXX,              KC_LGUI,          KC_UNDS,          KC_LSHIFT,
      // left thumb
      KC_LSHIFT, KC_LSHIFT,  KC_LCTRL,
      LT(LAYER_CONTROL, KC_BSPACE), CTL_T(KC_TAB), ALT_T(KC_DEL),

      // right finger
      TG(LAYER_NUMPAD),                                                   KC_ASTR,            KC_QUES,          KC_DQUO,          KC_SCOLON,              ASSIGN,            KC_UNDO,
      OSL(LAYER_WM),                                                      ALT_T(KC_V),        KC_W,             KC_L,             KC_Y,                   LT(LAYER_NUMPAD,   KC_QUOTE),       KC_RALT,
      LCTL_T(KC_D),                                                       KC_O,               KC_T,             KC_I,             LT(LAYER_AUX,           KC_H),             KC_RCTL,
      EMACS_ALTX,                                                         LT(LAYER_NUMPAD,KC_M),            KC_C,             KC_X,                   KC_DOT,            RSFT_T(KC_SLASH),KC_RSHIFT,
      KC_LSHIFT,                                                LT(LAYER_FN,KC_APP),         KC_RGUI,       KC_CAPS,             TO(LAYER_RUSSIAN),
      // right thumb
      KC_LSHIFT, KC_LSHIFT, KC_RCTRL,
      ALT_T(KC_INS), CTL_T(KC_ENTER), LT(LAYER_CONTROL, KC_SPACE)),



   /* Symbol Layer
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |   `  |   :  |   -  |   !  |   +  |      |           |Numpad|   ×  |   ?  |   "  |   ;  |  :=  |   BSP  |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |        |    ́  |   %  |   [  |   ]  |      |      |           |      |   |  |   ^  |   $  |   &  |   '  |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      |   @  |   (  |.  )  |      |------|           |------|   №  |.  {  |   }  |   #  |   °  |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      |   <  |   _  |   ~  |      |      |           |      |      |   =  |   \  |   >  |   /  |        |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |      |      |  _   |      |                                       |      |      |      |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       |      |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |      |      |      |
    *                                 |      |      |------|       |------|      |      |
    *                                 |      |      |      |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
   [LAYER_AUX] = LAYOUT_ergodox(
      // left fingers
      _____,                                                              TD(TD_GRAVEACCENT), KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,           _____,
      KC_LALT,                                                            ACCENT,             KC_PERC,          KC_LBRACKET,      KC_RBRACKET,            XXXXX,             _____,
      KC_LCTL,                                                            RU_NOSIGN,          KC_AT,            KC_LPRN,          KC_RPRN,                XXXXX,
      KC_LSHIFT,                                                          XXXXX,              KC_LABK,          KC_UNDS,          KC_TILD,                KC_ENTER,          _____,
      _____,                                                              _____,              _____,            _____,            KC_TAB,
      // left thumb
      _____,                                                              _____,              _____,
      LT(LAYER_CONTROL,                                                   KC_BSPACE),          _____,            _____,
      // right fingers
      _____,                                                              KC_ASTR,            KC_QUES,          KC_DQUO,          KC_SCOLON,              ASSIGN,            _____,
      _____,                                                              KC_PIPE,            KC_CIRC,          KC_DLR,           KC_AMPR,                KC_QUOTE,          KC_RALT,
      KC_NO,                                                              KC_LCBR,            KC_RCBR,          KC_HASH,          XXXXX,                  KC_RCTRL,
      _____,                                                              KC_ENTER,           KC_EQUAL,         KC_BSLASH,        KC_RABK,                KC_SLASH,         KC_RSHIFT,
      LT(LAYER_PTR,KC_TAB),                                            LT(LAYER_FN,KC_APP),   XXXXX,            KC_CAPS,            _____,
      // right thumb
      _____,                                                              _____,              _____,
      _____,                                                              _____,              LT(LAYER_CONTROL, KC_SPACE)),

   /* Russian layout slightly opimized for home row and adapted for EZ with Keymacs punctuatitons
    * for frequency optimization see https://ru.wikipedia.org/wiki/Частотность
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |  « „ |  ч : |   -  |   !  |  ё + |Ctl+G |           |      |   *  |   ?  |  х " |  щ ; |  » “ |   BSP  |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |        |   й  |   ц  |   у  |   к  |   ы  |      |           |      |   н  |   г  |   ш  |   ю  |   з  |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |   ф  |   а  |   е  |.  в  |   п  |------|           |------|   р  |.  о  |   л  |   д  |   ж  |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |   я  |   ,  |   с  |   м  |   и  |      |           |      |   т  |  ь ъ |   б  |   .  |   э  |        |
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
      KC_ESCAPE,                                                          TD(TD_LELKILAPKI),  TD(TD_TSE),       KC_KP_MINUS,      KC_MINUS,               TD(TD_YO),         EMACS_RESET,
      KC_LALT,                                                            LT(LAYER_NUMPAD,    KC_Q),            KC_W,             KC_E,                   KC_R,              ALT_T(KC_S),     _____,
      KC_LCTL,                                                            LT(LAYER_AUX_RU,    KC_A),            KC_F,             KC_T,                   KC_D,              RCTL_T(KC_G),
      KC_LSHIFT,                                                          LSFT_T(KC_Z),       KC_6,             KC_C,             KC_V,                   LT(LAYER_AUX_RU,   KC_B),           _____,
      TO(LAYER_KEYMACS),                                                  KC_CAPSLOCK,         _____,            KC_UNDS,          _____,
      // left thumb=======
      _____,                                                              _____,              _____,
      LT(LAYER_CONTROL,                                                   KC_BSPACE),          _____,            _____,

      // right fingers
      _____,                                                              RU_ASTR,            KC_9,             TD(TD_HE),        TD(TD_SCHCOLON),        TD(TD_RELKILAPKI), _____,
      _____,                                                              ALT_T(KC_Y),        KC_U,             KC_I,             KC_DOT,                 LT(LAYER_NUMPAD,   KC_P),           KC_RALT,
      LCTL_T(KC_H),                                                       KC_J,               KC_K,             KC_L,             LT(LAYER_AUX_RU,        KC_SCOLON),        KC_RCTL,
      EMACS_ALTX,                                                      LT(LAYER_NUMPAD,    KC_N),            TD(TD_SHSIG),     KC_COMMA,               KC_7,              RSFT_T(KC_QUOTE),KC_RSHIFT,
      LT(LAYER_PTR,KC_TAB),                                            LT(LAYER_FN,KC_APP),   XXXXX,            KC_CAPS,            _____,
      // right thumb
      _____,                                                              _____,              _____,
      _____,                                                              _____,              LT(LAYER_CONTROL, KC_SPACE)),


   /* Symbol Layer (AUX) for Russian layout
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |   `  |   :  |   -  |   !  |   +  |      |           |      |   ×  |   ?  |   "  |   ;  |  :=  |   BSP  |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |        |    ́  |   %  |   [  |   ]  |      |      |           |      |   |  |   ^  |   $  |   &  |   '  |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      |   @  |   (  |.  )  |      |------|           |------|   №  |.  {  |   }  |   #  |   °  |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      |   <  |   _  |   ~  |      |      |           |      |      |   =  |   \  |   >  |   /  |        |
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
   [LAYER_AUX_RU] = LAYOUT_ergodox(     // left fingers
      _____,                                                              TD(TD_GRAVEACCENT), KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,           _____,
      KC_LALT,                                                            ACCENT,             KC_PERC,          KC_LBRACKET,      KC_RBRACKET,            _____,             _____,
      KC_LCTL,                                                            XXXXX,              KC_AT,            KC_LPRN,          KC_RPRN,                KC_NO,
      KC_LSHIFT,                                                          XXXXX,              KC_LABK,          KC_UNDS,          KC_TILD,                KC_ENTER,          _____,
      _____,                                                              _____,              _____,            SFT_T(KC_9),      KC_TAB,
      // left thumb
      _____,                                                              _____,              _____,
      LT(LAYER_CONTROL,                                                   KC_SPACE),          _____,            _____,
      // right fingers
      _____,                                                              KC_ASTR,            KC_QUES,          KC_LBRACKET,      KC_SCOLON,              ASSIGN,            _____,
      _____,                                                              KC_PIPE,            KC_CIRC,          KC_DLR,           KC_AMPR,                KC_QUOTE,          KC_RALT,
      RU_NOSIGN,                                                          KC_LCBR,            KC_RCBR,          KC_HASH,          KC_NO,                  KC_RCTRL,
      EMACS_ALTX,                                                      KC_ENTER,           KC_EQUAL,         KC_BSLASH,        KC_RABK,                KC_SLASH,          KC_RSHIFT,
      LT(LAYER_PTR,KC_TAB),                                            LT(LAYER_FN,KC_APP),   XXXXX,            XXXXX,            _____,
      // right thumb
      _____,                                                              _____,              _____,
      _____,                                                              _____,              LT(LAYER_CONTROL, KC_ENTER)),

   /* Control layer for pointer movement (mouse, trackball etc)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |  Esc   |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |  Alt   |      |      |      |      |      |      |           |      |      | WLft | WRght|      |      | Alt    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |  Ctrl  |      |      | WUp  |.WDwn |      |------|           |------|      |. LClk| RClk | MClk |      | Ctrl   |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Shift  |      |      |      |      |      |      |           |      | Enter| CtlC | CtlX | CtlV |      | Shift  |
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
   [LAYER_PTR] = LAYOUT_ergodox(     // left fingers
      _____,                                                              _____,              _____,            _____,            _____,                  _____,             KC_MUTE,
      _____,                                                              _____,              KC_MS_WH_UP,      KC_MS_WH_DOWN,    LGUI(RCTL(RALT(KC_F))), _____,             KC_VOLU,
      _____,                                                              _____,              _____,            KC_MS_UP,         KC_MS_DOWN,             _____,
      _____,                                                              _____,              _____,            _____,      _____,          _____,             KC_VOLD,
      _____,                                                              TO(LAYER_KEYMACS),  _____,       _____,       _____,
      // left thumb
      _____,                                                              _____,              _____,            _____,            _____,                  _____,
      // right fingers
      KC_MS_ACCEL0,                                                       _____,              _____,            _____,            _____,                  _____,             _____,
      KC_MS_ACCEL2,                                                       _____,              KC_MS_WH_LEFT,    KC_MS_WH_RIGHT,   _____,             _____,             _____,
      KC_DELETE,                                                          KC_MS_BTN1,         KC_MS_BTN2,       KC_MS_BTN3,       _____,                  _____,
      KC_MS_ACCEL1,                                                       KC_ENTER,           LCTL(KC_C),       LCTL(KC_X),       LCTL(KC_V),             _____,             _____,
      _____,                                                              XXXXX,              XXXXX,            XXXXX,            _____,
      // right thumb
      _____,                                                              _____,              _____,            _____,            _____,                  _____),

   /* Control layer for line and page navigation and common text operations
    * based on https://github.com/keyboard-ergonomics/control-layer.
    * Copypaste keys for Emacs (Alt+W,Ctl+W,Ctl+Y) and WordStar-like (Ctl+C,Ctl+X,Ctl+V) bindinds.
    * Copypaste keys for right hand because I'm using trackball by left hand.
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |  Esc   |      |      |      |      |      |      |           |      |      | MLClk| MRClk| MMClk|      | Undo   |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |  Alt   |      |      | PgUp |      | Esc  |      |           |      | CtlV | AltW | CtlW | CtlY |      | Alt    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |  Ctrl  | CtlR | Home |  Up  |. Down|      |------|           |------|  Del |. Left| Right|  End | Back | Fwd    |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * | Shift  |      |SftTab|      | PgDn | Tab  |      |           |      | Enter| CtlC | CtlX | CtlV | Ctl/ | Shift  |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   |      |      |      |      |      |                                       |      |      |      |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      | Back |       | Fwd  |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |Reload|      |      |
    *                                 |Bspace| Tab  |------|       |------| Enter| SPC  |
    *                                 |      |      |      |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
   [LAYER_CONTROL] = LAYOUT_ergodox(     // left fingers
      _____,                                                              XXXXX,              XXXXX,            XXXXX,            XXXXX,                  _____,             _____,
      _____,                                                              XXXXX,              KC_LEFT,          KC_PGUP,          KC_RIGHT,               KC_ESCAPE,         KC_LGUI,
      _____,                                                              RCTL(KC_R),         KC_HOME,          KC_UP,            KC_DOWN,                _____,
      _____,                                                              RCTL(KC_Z),         RSFT(KC_ENTER),   XXXXX,            KC_PGDOWN,              KC_ENTER,          LCTL(KC_QUES),
      TG(LAYER_KEYMACS),                                                  TO(LAYER_GAME),     TO(LAYER_QWERTY), XXXXX,            KC_TAB,
      // left thumb
      KC_SPACE,                                                           _____,              _____,            _____,            _____,                  _____,
      // right fingers
      _____,                                                              RGUI(KC_F6),        KC_MS_BTN1,       KC_MS_BTN2,       KC_MS_BTN3,             _____,             KC_UNDO,
      KC_LGUI,                                                            LCTL(KC_V),         LALT(KC_W),       LCTL(KC_W),       LCTL(KC_Y),             XXXXX,             _____,
      KC_DELETE,                                                          KC_LEFT,            KC_RIGHT,         KC_END,           KC_WWW_BACK,            KC_WWW_FORWARD,
      XXXXX,                                                              KC_ENTER,           LCTL(KC_C),       LCTL(KC_X),       LCTL(KC_V),             LCTL(KC_SLASH),    _____,
      KC_TAB,                                                             _____,              _____,            _____,            TG(LAYER_RUSSIAN),
      // right thumb
      _____,                                                              _____,              _____,            _____,            KC_ENTER,               KC_SPACE),


   /* Numpad for the right hand (left hand the same as for Symbols layer)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |   `  |   :  |   -  |   !  |   +  |      |           | Numlk|   *  |   7  |   8  |   9  |  :=  |   BSP  |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |        |    ́  |   %  |   [  |   ]  | Alt  |      |           |   +  |   |  |   4  |   5  |   6  |   '  |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      |   @  |   (  |.  )  | Ctrl |------|           |------|   №  |.  1  |   2  |   3  |   -  |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      |   ,  |   _  |   ~  | Shift|      |           |      | Enter|   =  |   0  |   .  |   /  |        |
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
      KC_NUMLOCK,                                                         TD(TD_GRAVEACCENT), KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,           _____,
      KC_LALT,                                                            ACCENT,             KC_PERC,          KC_LBRACKET,      KC_RBRACKET,            XXXXX,             _____,
      KC_LCTL,                                                            XXXXX,              KC_AT,            KC_LPRN,          KC_RPRN,                XXXXX,
      KC_LSHIFT,                                                          XXXXX,              KC_LABK,          KC_UNDS,          KC_TILD,                KC_TAB,            _____,
      _____,                                                              _____,              _____,            _____,            _____,
      // left thumb
      _____,                                                              _____,              _____,
      LT(LAYER_CONTROL,                                                   KC_SPACE),          LT(LAYER_WM,      KC_TAB),          _____,
      // right fingers
      KC_NUMLOCK,                                                         KC_KP_ASTERISK,     KC_7,             KC_8,             KC_9,                   KC_EQUAL,          KC_BSPACE,
      KC_KP_PLUS,                                                         KC_PIPE,            KC_4,             KC_5,             KC_6,                   KC_QUOTE,          KC_RALT,
      RU_NOSIGN,                                                          KC_1,               KC_2,             KC_3,             KC_KP_MINUS,            KC_RCTRL,
      KC_KP_SLASH,                                                        KC_KP_ENTER,        KC_KP_EQUAL,      KC_0,             KC_KP_DOT,              _____,             KC_RSHIFT,
      _____,                                                              _____,              _____,            _____,            _____,
      // right thumb
      _____,                                                              _____,              _____
      ,                                                                   _____,              LT(LAYER_WM,      KC_ENTER),        LT(LAYER_CONTROL,       KC_SPACE)),

   /* Fn keys for the right hand (left hand the same as for Symbols layer)
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |   `  |   :  |   -  |   !  |   +  |      |           |      |   *  |   F7 |   F8 |   F9 |   =  |   BSP  |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |        |    ́  |   %  |   [  |   ]  |      |      |           |      | LAlt |   F4 |   F5 |   F6 | RAlt |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      |   @  |   (  |.  )  |      |------|           |------| LCtrl|.  F1 |   F2 |   F3 | RCtrl|        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |      |   ,  |   _  |   ~  |      |      |           |      |LShift|  F11 |  F10 |  F12 |RShift|        |
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
      KC_NUMLOCK,                                                         TD(TD_GRAVEACCENT), KC_F7,            KC_F8,            KC_F9,                KC_PLUS,           _____,
      KC_LALT,                                                            ACCENT,             KC_F4,            KC_F5,            KC_F6,                KC_RALT,             _____,
      KC_LCTL,                                                            KC_NO,              KC_F1,            KC_F2,            KC_F3,                KC_RCTL,
      KC_LSHIFT,                                                          KC_NO,              KC_F11,           KC_F10,           KC_F12,                KC_RSHIFT,            _____,
      KC_LSHIFT,                                                  _____,              _____,            _____,            _____,
      // left thumb
      _____,                                                              _____,              _____,
      LT(LAYER_CONTROL,                                                   KC_SPACE),          LT(LAYER_WM,      KC_TAB),          _____,
      // right fingers
      _____,                                                              KC_KP_ASTERISK,     KC_F7,            KC_F8,            KC_F9,                  KC_EQUAL,          KC_BSPACE,
      _____,                                                              KC_LALT,            KC_F4,            KC_F5,            KC_F6,                  KC_RALT,        KC_RALT,
      KC_LCTL,                                                            KC_F1,              KC_F2,            KC_F3,            KC_KP_MINUS,            KC_RCTL,
      KC_LSHIFT,                                                          _____,              KC_F11,           KC_F10,           KC_F12,                 KC_RSHIFT,          KC_RSHIFT,
      _____,                                                              _____,              _____,            _____,            KC_RSHIFT,
      // right thumb
      _____,                                                              _____,              _____,
      _____,                                                              LT(LAYER_WM,        KC_ENTER),        LT(LAYER_CONTROL, KC_SPACE)),

   // Gaming mode mostly for action games
   [LAYER_GAME] = LAYOUT_ergodox(     // left fingers
      KC_ESCAPE,                                                          KC_1,               KC_2,             KC_3,             KC_4,                   KC_5,              KC_PLUS,
      KC_TAB,                                                             KC_LALT,            KC_Q,             KC_W,             KC_E,                   KC_T,              KC_H,
      KC_M,                                                               KC_LCTL,            KC_A,             KC_S,             KC_D,                   KC_F,
      KC_K,                                                               KC_LSHIFT,          KC_Z,             KC_X,             KC_C,                   KC_V,              KC_G,
      KC_L,                                                               LALT(KC_1),         LALT(KC_2),       LALT(KC_3),       KC_R,
      // left thumb
      KC_B,                                                               _____,              _____,
      KC_SPACE,                                                           KC_MS_BTN3,         KC_KP_DOT,
      // right fingers
      KC_EQUAL,                                                           KC_6,               KC_7,             KC_8,             KC_9,                   KC_0,              KC_BSPACE,
      KC_I,                                                               KC_O,               KC_F7,            KC_F8,            KC_F9,                  KC_W,              KC_RALT,
      KC_P,                                                               KC_F4,              KC_F5,            KC_F6,            KC_H,                   KC_RCTL,
      KC_J,                                                               KC_N,               KC_F1,            KC_F2,            KC_F3,                  KC_SLASH,          KC_RSHIFT,
      KC_F11,                                                             KC_F10,             KC_F12,           KC_U,             KC_Y,
      // right thumb
      _____,                                                              _____,              _____,
      _____,                                                              KC_ENTER,           KC_SPACE),

   // QWERTY for reference and for guests
   [LAYER_QWERTY] = LAYOUT_ergodox(     // left fingers
      KC_ESCAPE,                                                          KC_1,               KC_2,             KC_3,             KC_4,                   KC_5,              KC_6,
      KC_LALT,                                                            KC_Q,               KC_W,             KC_E,             KC_R,                   KC_T,              KC_TAB,
      KC_LCTL,                                                            KC_A,               KC_S,             KC_D,             KC_F,                   KC_G,
      KC_LSHIFT,                                                          KC_Z,               KC_X,             KC_C,             KC_V,                   KC_B,              _____,
      TO(LAYER_KEYMACS),                                                  _____,              _____,            KC_LGUI,          KC_LALT,
      // left thumb
      _____,                                                              _____,              _____,
      KC_SPACE,                                                           KC_ENTER,           _____,
      // right fingers
      TO(LAYER_KEYMACS),                                                  KC_6,               KC_7,             KC_8,             KC_9,                   KC_0,              KC_BSPACE,
      KC_TAB,                                                             KC_Y,               KC_U,             KC_I,             KC_O,                   KC_P,              KC_LALT,
      KC_H,                                                               KC_J,               KC_K,             KC_L,             KC_QUES,                KC_LCTL,
      _____,                                                              KC_N,               KC_M,             KC_COMMA,         KC_DOT,                 KC_SLASH,          KC_RSHIFT,
      _____,                                                              KC_LEFT,            KC_UP,            KC_DOWN,          TO(LAYER_RUSSIAN),
      // right thumb
      _____,                                                              _____,              _____,
      _____,                                                              KC_ENTER,           KC_SPACE),

   // Window manager control (currently for Spectr WM)
   [LAYER_WM] = LAYOUT_ergodox(     // left fingers
      TO(LAYER_KEYMACS),                                                  KC_GRAVE,           KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,           KC_K,
      ALT_T(KC_TAB),                                                      KC_Q,               KC_B,             KC_P,             KC_F,                   KC_RALT,      LCTL(KC_ENTER),
      KC_LCTL,                                                            LT(LAYER_NUMPAD,    KC_R),            KC_A,             KC_E,                   KC_N,              KC_RCTL,
      KC_LSHIFT,                                                          KC_Z,               KC_COMMA,         KC_U,             KC_K,                   KC_RSHIFT,       KC_F,
      TG(LAYER_KEYMACS),                                                  TO(LAYER_GAME),     TO(LAYER_QWERTY), KC_UNDS,          KC_TAB,
      // left thumb
      LCTL(KC_G),                                                         KC_WWW_BACK,        LCTL(KC_V),
      LALT(KC_SPACE),                                                           _____,              KC_INS,
      // right fingers
      KC_K,                                                              KC_ASTR,            KC_7,             KC_8,             KC_9,                   KC_EQUAL,          KC_BSPACE,
      RCTL(KC_ENTER),                                                     KC_LALT,        KC_4,             KC_5,             KC_6,                   KC_QUOTE,          KC_RALT,
      KC_LCTL,                                                          KC_1,               KC_2,             KC_3,             LT(LAYER_NUMPAD,        KC_H),             KC_RCTL,
      KC_F,                                                             KC_LSHIFT,        KC_C,             KC_0,             KC_DOT,                 KC_SLASH,          KC_RSHIFT,
      KC_TAB,                                                             KC_UNDS,            _____,            _____,            TO(LAYER_RUSSIAN),
      // right thumb
      KC_WWW_FORWARD,                                                     RCTL(KC_W),         KC_WWW_REFRESH,
      KC_DELETE,                                                          _____,              LALT(KC_SPACE)),
};



extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void)
{
   rgb_matrix_enable();
}

#define BLANK_HSV      { 0, 0, 0 }
#define WHITE_HSV      { 85, 30, 255 }
#define DRED_HSV       { 0, 255, 64 }
#define RED_HSV        { 0, 255, 158 }
#define BRED_HSV       { 0, 255, 255 }
#define ORANGE_HSV     { 10, 255, 213 }
#define BLUE_HSV       { 134, 255, 213 }
#define DBLUE_HSV      { 134, 255, 64 }
#define PURPLE_HSV     { 234, 255, 158 }
#define GREEN_HSV      { 85, 255, 158 }
#define BGREEN_HSV     { 85, 255, 255 }
#define TEAL_HSV       { 85, 203, 158 }
#define BPURPLE_HSV    { 243, 222, 255 }
#define YELLOW_HSV     { 40, 255, 158 }

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] =
{
   [LAYER_KEYMACS] =
   {
   // right
   BLANK_HSV,  BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   BLANK_HSV,  BLANK_HSV, BLANK_HSV, BLANK_HSV, TEAL_HSV,
   BLANK_HSV,  BLANK_HSV, BLANK_HSV, BLANK_HSV, DBLUE_HSV,
   TEAL_HSV,   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   DRED_HSV,  PURPLE_HSV, BLANK_HSV, BLANK_HSV,
   // left mirrored
   BLANK_HSV,  BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   BLANK_HSV,  BLANK_HSV, BLANK_HSV, BLANK_HSV, TEAL_HSV,
   BLANK_HSV,  BLANK_HSV, BLANK_HSV, BLANK_HSV, DBLUE_HSV,
   PURPLE_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   BLANK_HSV,  BLANK_HSV, WHITE_HSV, DBLUE_HSV
   },

   [LAYER_CONTROL] =
   {
   // right
   BLANK_HSV, BRED_HSV,  BRED_HSV,  BRED_HSV,  BLANK_HSV,
   DRED_HSV,  DRED_HSV,  DRED_HSV,  DRED_HSV,  BLANK_HSV,
   DRED_HSV,  BRED_HSV,  BRED_HSV,  DRED_HSV,  BLANK_HSV,
   BLANK_HSV, DRED_HSV,  DRED_HSV,  DRED_HSV,  BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   // left mirrored
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   BLANK_HSV, BRED_HSV,  BRED_HSV,  BLANK_HSV, BLANK_HSV,
   BLANK_HSV, DRED_HSV,  DRED_HSV,  DRED_HSV,  BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV
   },

   [LAYER_PTR] =
   {
   // right
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   BLANK_HSV, DRED_HSV,  DRED_HSV,  BRED_HSV,  BLANK_HSV,
   BLANK_HSV, DRED_HSV,  DRED_HSV,  BRED_HSV,  BLANK_HSV,
   BLANK_HSV, DRED_HSV,  DRED_HSV,  BRED_HSV,  BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   // left mirrored
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,  BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,  BLANK_HSV,
   BLANK_HSV, DRED_HSV,  DRED_HSV,  BLANK_HSV,  BLANK_HSV,
   BLANK_HSV, DRED_HSV,  DRED_HSV,  BLANK_HSV,  BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV
   },

   [LAYER_AUX] =
   {
   // right
   DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV,
   BLANK_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV,
   BLANK_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV,
   BLANK_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   // left mirrored
   DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV,
   BLANK_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV,
   BLANK_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV,
   BLANK_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV
   },

   [LAYER_AUX_RU] =
   {
   // right
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   WHITE_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV,
   BLUE_HSV,  DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV,
   RED_HSV,   DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   // left mirrored
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   WHITE_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV,
   BLUE_HSV,  DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV,
   RED_HSV,   DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV
   },

   [LAYER_NUMPAD] =
   {
   // right
   BLANK_HSV, TEAL_HSV,  TEAL_HSV,  TEAL_HSV,  BLANK_HSV,
   BLANK_HSV, TEAL_HSV,  GREEN_HSV, TEAL_HSV,  BLANK_HSV,
   BLANK_HSV, TEAL_HSV,  TEAL_HSV,  TEAL_HSV,  BLANK_HSV,
   BLANK_HSV, BLANK_HSV, TEAL_HSV,  BLANK_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   // left mirrored
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV
   },

   [LAYER_RUSSIAN] =
   {
   // right
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   WHITE_HSV, WHITE_HSV, WHITE_HSV, WHITE_HSV, WHITE_HSV,
   BLUE_HSV,  BLUE_HSV,  BLUE_HSV,  BLUE_HSV,  BLUE_HSV,
   RED_HSV,   RED_HSV,   RED_HSV,   RED_HSV,   RED_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   // left mirrored
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV,
   WHITE_HSV, WHITE_HSV, WHITE_HSV, WHITE_HSV, WHITE_HSV,
   BLUE_HSV,  BLUE_HSV,  BLUE_HSV,  BLUE_HSV,  BLUE_HSV,
   RED_HSV,   RED_HSV,   RED_HSV,   RED_HSV,   RED_HSV,
   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV
   },

   [LAYER_WM] =
   {
   // right
   BLANK_HSV, ORANGE_HSV, ORANGE_HSV, ORANGE_HSV, BLANK_HSV,
   BLANK_HSV, ORANGE_HSV, ORANGE_HSV, ORANGE_HSV, BLANK_HSV,
   BLANK_HSV, ORANGE_HSV, ORANGE_HSV, ORANGE_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV,  ORANGE_HSV, BLANK_HSV,  BLANK_HSV,
   BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV,
   // left mirrored
   BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV,  BLANK_HSV,
   BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV,  BLANK_HSV,
   BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV,  BLANK_HSV,
   BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV,  BLANK_HSV,
   BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV
   },

   [LAYER_GAME] =
   {
   // right
   TEAL_HSV,  TEAL_HSV,   TEAL_HSV,   TEAL_HSV,   TEAL_HSV,
   BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV,
   BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV,
   BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV,
   // left mirrored
   TEAL_HSV,  TEAL_HSV,   TEAL_HSV,   TEAL_HSV,   TEAL_HSV,
   BLANK_HSV, BLANK_HSV,  BRED_HSV,   BLANK_HSV,  BLANK_HSV,
   BLANK_HSV, BRED_HSV,   BRED_HSV,   BRED_HSV,   BLANK_HSV,
   BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV,  BLANK_HSV,
   BLANK_HSV, TEAL_HSV,   TEAL_HSV,   TEAL_HSV
   },

   [LAYER_FN] =
   {
   // right
   BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV,
   BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV,
   BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV,
   BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV,
   // left mirrored
   BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV,
   BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV,
   BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV,
   BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV,
   BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV
   },
};

void set_layer_color(int layer)
{
   for(int i = 0; i < DRIVER_LED_TOTAL; i++){
       HSV hsv =
       {
	  .h = pgm_read_byte(&ledmap[layer][i][0]),
	  .s = pgm_read_byte(&ledmap[layer][i][1]),
	  .v = pgm_read_byte(&ledmap[layer][i][2]),
       };
       if(!hsv.h && !hsv.s && !hsv.v){
	  rgb_matrix_set_color(i, 0, 0, 0);
	  }
       else{
	   RGB   rgb = hsv_to_rgb(hsv);
	   float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
	   rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
	   }
       }
}

void rgb_matrix_indicators_user(void)
{
   if(g_suspend_state || keyboard_config.disable_layer_led){
      return;
      }
   int layer = biton32(layer_state);
   if(layer < MAX_LAYER){
      set_layer_color(layer);
      }
   else{
       if(rgb_matrix_get_flags() == LED_FLAG_NONE){
	  rgb_matrix_set_color_all(0, 0, 0);
	  }
       }
}

uint8_t cur_layer = LAYER_KEYMACS;

layer_state_t layer_state_set_user(layer_state_t state) {
    static uint8_t old_layer = 0xff;
    cur_layer = get_highest_layer(state);

    switch (cur_layer) {
    case LAYER_RUSSIAN:
      // Turn on RUS layout on enter to Russian layer.
      if (old_layer != LAYER_RUSSIAN) {
	tap_code(RUS);
      } else {
	tap_code(LAT);
	tap_code(RUS);
      }
      break;
    default:
      // Switch back to English when we leave Russian layer.
      if (old_layer == LAYER_RUSSIAN) {
	tap_code(LAT);
      }
    }
    old_layer = cur_layer;
    xprintf("LAYER: %d \n", cur_layer); // left for debugging yet
    return state;
}

// implements user hook on the each key press/release
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    // For compatibility with software that not understand how to map
    // non-English keys with modifiers. Just temporary switch to
    // Keymacs layer when modifier pressed. It works only for Russian
    // layer.
    static bool back_to_ussr = false;
    if (cur_layer == LAYER_RUSSIAN && record->event.pressed) {
	switch (keycode) {
	case KC_LCTL:
	case KC_RCTL:
	case KC_LALT:
	case KC_RALT:
	case KC_APP:
	case CTL_T(KC_TAB):
	case CTL_T(KC_ENTER):
	case ALT_T(KC_DEL):
	case ALT_T(KC_INS):
	    layer_off(LAYER_RUSSIAN);
	    layer_on(LAYER_KEYMACS);
	    back_to_ussr = true;
	}
    }
    if (back_to_ussr && !record->event.pressed) {
	switch (keycode) {
	case KC_LCTL:
	case KC_RCTL:
	case KC_LALT:
	case KC_RALT:
	case KC_APP:
	case CTL_T(KC_TAB):
	case CTL_T(KC_ENTER):
	case ALT_T(KC_DEL):
	case ALT_T(KC_INS):
	    layer_off(LAYER_KEYMACS);
	    layer_on(LAYER_RUSSIAN);
	    back_to_ussr = false;
	}
    }

   switch(keycode){
	    case KC_LSHIFT:
	    case KC_RSHIFT:
		if (record->event.pressed) ergodox_right_led_3_on();
		else ergodox_right_led_3_off();
		return (true);
	    case KC_LCTL:
	    case KC_RCTL:
		if (record->event.pressed) ergodox_right_led_2_on();
		else ergodox_right_led_2_off();
		return (true);
	    case KC_LALT:
	    case KC_RALT:
		if (record->event.pressed) ergodox_right_led_1_on();
		else ergodox_right_led_1_off();
		return (true);
       case RU_ASTR:
	  if(record->event.pressed){
	     SEND_STRING(SS_TAP(XLAT) "*" SS_TAP(XRUS));
	     }
	  return(false);

       case ASSIGN:
	  if(record->event.pressed){
	    SEND_STRING(":=");
	  }
	  return(false);

       case ACCENT:
	  if(record->event.pressed){
	    SEND_STRING(SS_DOWN(X_CAPSLOCK) "a");
	  } else {
	    SEND_STRING(SS_UP(X_CAPSLOCK));
	  }
	  return(false);

       case EMACS_TAB:
	 if(!record->event.pressed){
	   SEND_STRING(SS_LCTL("g") SS_TAP(X_TAB));
	 }
	 return(false);

       case EMACS_SELECT:
	 if(!record->event.pressed){
	   // Emacs: reset the selection and activate a new one
	   SEND_STRING(SS_LCTL("g "));
	 }
	 return(false);
       case EMACS_BLOCK_SELECT:
	  if(record->event.pressed){
	    SEND_STRING(SS_LCTL("gx") " ");
	  }
	  return(false);

       case EMACS_ALTX:
	  if(record->event.pressed){
	      if(cur_layer == LAYER_RUSSIAN){
		 layer_off(LAYER_RUSSIAN);
	      }
	  } else {
	    SEND_STRING(SS_LALT("x"));
	  }
	 return(false);
       case EMACS_RESET:
	  if(record->event.pressed){
	      if(cur_layer == LAYER_RUSSIAN){
		 layer_off(LAYER_RUSSIAN);
	      }
	  } else {
	    SEND_STRING(SS_LCTL("g"));
	  }
	 return(false);
  }

   return(true);
}

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
   [TD_GRAVEACCENT] = ACTION_TAP_DANCE_FN(dance_graveaccent),
   [TD_DASH]        = ACTION_TAP_DANCE_FN(dance_dash),
   [TD_SHSIG]       = ACTION_TAP_DANCE_FN(dance_shsig),
   [TD_LELKILAPKI]  = ACTION_TAP_DANCE_FN(dance_elkilapki_left),
   [TD_RELKILAPKI]  = ACTION_TAP_DANCE_FN(dance_elkilapki_right),
   [TD_TSE]         = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_5),              // ч/;
   [TD_HE]          = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_4),       // х/"
   [TD_SCHCOLON]    = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_EQUAL),          // щ/:
   [TD_YO]          = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_TILD),       // ч/;
};
