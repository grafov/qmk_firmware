#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap.h"

enum layers {
    KEYMACS, // default layer
    RUSSIAN,
    NUMPAD,
    SYMBOLS,
    FN,
    GAME,
    CONTROL,
    WM,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    ____,
    EMACS_SELECT,
    EMACS_BLSEL,
    EMACS_CMD,
    EMACS_RESET,
    EMACS_CHBUF,
    RU_ASTR,
};

// Tap Dance declarations
enum {
    TD_GAME_KEYMACS,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* Default layer based on Keymacs layout
    * This is the adaptation of the layout for common keyboards for Ergodox EZ
    * https://github.com/keyboard-ergonomics/keymacs
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |   Esc  |   `  |   :  |   -  |   !  |   +  | Ctl-G|           | NumLk|   *  |   ?  |   "  |   ;  |  :=  |  Undo  |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |Ctl-Find|   q  |   b  |   p  |   f  |   g  | Emacs|           | Win  |   m  |   w  |   l  |   y  |   '  | C-X-B  |
    * |--------+------+------+------+------+------| Sel  |           | move |------+------+------+------+------+--------|
    * |  Find  |   r  |   a  |   e  |.  n  |   s  |------|           |------|   d  |.  o  |   t  |   i  |   h  |  A-X   |
    * |--------+------+------+------+------+------| Win  |           |  F   |------+------+------+------+------+--------|
    * |C-A-Find|   z  |   ,  |   u  |   k  |   j  | Mgmt |           |  N   |   v  |   c  |   x  |   .  |   /  | A-Find |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | LAT  | LGUI | LAT  |  Ctl |  Alt |                                       |  Alt | Ctl  | RUS  | Menu |  RUS |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,--------------.     ,--------------.
    *                                        |  Ctl |  Shift|     |  Shift| Shift|
    *                                 ,------|------|-------|     |-------+------+------.
    *                                 |      |      |  Ctl  |     |  Ctl  |      |      |
    *                                 | BSpc |  Tab |-------|     |-------| Enter| SPC  |
    *                                 | nav  | Shift|Del/Alt|     |Ins/Alt| Ctlr | nav  |
    *                                 `---------------------'     `---------------------'
    */
    [KEYMACS] = LAYOUT_ergodox(
      // left fingers
      KC_ESC,                       KC_GRAVE,              KC_COLON,           KC_MINUS,         KC_EXLM,           KC_PLUS,       EMACS_RESET,
      LCTL(KC_FIND),                LT(NUMPAD,KC_Q),       KC_B,               KC_P,             KC_F,              KC_G,          EMACS_SELECT,
      KC_FIND,                      LT(SYMBOLS,KC_R),      KC_A,               KC_E,             KC_N,              KC_S,
      C(A(KC_FIND)),                KC_Z,                  KC_COMMA,           KC_U,             KC_K,              KC_J,          MO(WM),
	       // lower row
	       TO(KEYMACS),                  KC_LGUI,              TO(KEYMACS),        KC_LCTL,        KC_LALT,

      // left thumb
      KC_LCTL, KC_LSFT,  KC_LCTL,
      LT(CONTROL, KC_BSPC), LSFT_T(KC_TAB), ALT_T(KC_DEL),

      // right finger
      XXXX,                           KC_ASTR,            KC_QUES,          KC_DQUO,          KC_SCLN,          ____,                       KC_UNDO,
      LGUI(KC_MS_BTN1),                     KC_M,               KC_W,             KC_L,             KC_Y,             LT(NUMPAD,KC_QUOTE),  EMACS_CHBUF,
					    KC_D,               KC_O,             KC_T,             KC_I,             LT(SYMBOLS,KC_H),     EMACS_CMD,
      XXXX,                           LT(FN,KC_V),    KC_C,             KC_X,             KC_DOT,           KC_SLASH,               LALT(KC_FIND),
	       // lower row
	       KC_RALT,                     KC_RCTL,            TG(RUSSIAN),      KC_MENU,             TG(RUSSIAN),

      // right thumb
      KC_LSFT, KC_LSFT, KC_RCTL,
      ALT_T(KC_INS), RCTL_T(KC_ENTER), LT(CONTROL, KC_SPACE)
   ),

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
   /* QWERTY for Russian Typewriter layout adapted for Ergodox/Keymacs */
    [RUSSIAN] = LAYOUT_ergodox(
      // left fingers
      KC_ESC,               ____,                KC_5,             KC_KP_MINUS,   KC_MINUS,      KC_TILDE,        EMACS_RESET,
      LCTL(KC_FIND),        LT(NUMPAD,KC_E),     KC_X,             KC_R,          KC_L,          KC_S,            EMACS_SELECT,
      KC_FIND,              LT(SYMBOLS,KC_LBRC), KC_F,             KC_T,          KC_J,          KC_G,
      LCA_T(KC_FIND),       KC_Z,                KC_6,             KC_C,          KC_V,          XXXX,            MO(WM),

		      // lower row
		      TO(KEYMACS),       KC_LGUI,             TO(KEYMACS),          KC_LCTL,          KC_LALT,


      // left thumb
      KC_LCTL,    KC_RSFT,  KC_LCTL,
      LT(CONTROL, KC_BSPC), LSFT_T(KC_TAB), ALT_T(KC_DEL),

      // right fingers
      ____,                 RU_ASTR,           KC_9,            KC_4,        KC_PLUS,         KC_1,                 KC_UNDO,
      ____,                 KC_U,              KC_D,            KC_H,        KC_P,            KC_I,                 EMACS_CHBUF,
			    KC_DOT,            KC_N,            KC_B,        KC_Y,            LT(SYMBOLS,KC_K),     EMACS_CMD,
      MO(FN),               MO(NUMPAD),        KC_M,            KC_COMMA,    KC_7,            KC_Q,                 LALT(KC_FIND),

			     // lower row
			     KC_RALT,          KC_RCTL,         XXXX,     KC_MENU,            XXXX,

      // right thumb
      KC_RSFT, KC_RSFT, KC_RCTL,
      ALT_T(KC_INS), RCTL_T(KC_ENTER), LT(CONTROL, KC_SPACE)
   ),

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
   [NUMPAD] = LAYOUT_ergodox(
      // left fingers
      KC_NUM,                                                         ____, KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,           ____,
      KC_LALT,                                                            ____,             KC_PERC,          KC_LBRC,      KC_RBRC,            XXXX,             ____,
      KC_LCTL,                                                            XXXX,              KC_AT,            KC_LPRN,          KC_RPRN,                XXXX,
      KC_LSFT,                                                          XXXX,              KC_LABK,          KC_UNDS,          KC_TILD,                KC_TAB,            ____,
      ____,                                                              ____,              ____,            ____,            ____,
      // left thumb
      ____,                                                              ____,              ____,
      LT(CONTROL,                                                   KC_SPACE),          LT(WM,      KC_TAB),          ____,

      // right fingers
      KC_NUM,                                                        KC_KP_ASTERISK,     KC_7,             KC_8,             KC_9,                   KC_EQUAL,          KC_BSPC,
      KC_KP_PLUS,                                                    KC_PIPE,            KC_4,             KC_5,             KC_6,                   KC_QUOTE,          KC_RALT,
      ____,                                                          KC_1,               KC_2,             KC_3,             KC_KP_MINUS,            KC_RCTL,
      KC_KP_SLASH,                                                   KC_KP_ENTER,        KC_KP_EQUAL,      KC_0,             KC_DOT,              ____,             KC_RSFT,
      ____,                                                              ____,              ____,            ____,            ____,
      // right thumb
      ____,                                                              ____,              ____
      ,                                                                   ____,              LT(WM,      KC_ENTER),        LT(CONTROL,       KC_SPACE)
   ),

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
   [SYMBOLS] = LAYOUT_ergodox(
      // left fingers
      ____,                                                              ____, KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,          KC_UNDO,
      KC_LALT,                                                            ____,             KC_PERC,          KC_LBRC,      KC_RBRC,            XXXX,             ____,
      KC_LCTL,                                                            ____,          KC_AT,            KC_LPRN,          KC_RPRN,                XXXX,
      KC_LSFT,                                                          XXXX,              KC_LABK,          KC_UNDS,          KC_TILD,                KC_ENTER,          ____,
      ____,                                                              ____,              ____,            ____,            ____,

      // left thumb
      ____,                                                              ____,              ____,
      LT(CONTROL,                                                   KC_BSPC),          ____,            ____,

      // right fingers
      ____,                                                              KC_ASTR,            KC_QUES,          KC_DQUO,          KC_SCLN,              ____,            ____,
      ____,                                                              KC_PIPE,            KC_CIRC,          KC_DLR,           KC_AMPR,                KC_QUOTE,          KC_RALT,
      KC_NO,                                                              KC_LCBR,            KC_RCBR,          KC_HASH,          XXXX,                  KC_RCTL,
      ____,                                                              KC_ENTER,           KC_EQUAL,         KC_BSLS,        KC_RABK,                KC_SLASH,         KC_RSFT,
      ____,                                            ____,   ____,            ____,            ____,

      // right thumb
      ____,                                                              ____,              ____,
      ____,                                                              ____,              LT(CONTROL, KC_SPACE)
   ),

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
   [FN] = LAYOUT_ergodox(
      // left fingers
      KC_NUM,                                                         ____, KC_F7,            KC_F8,            KC_F9,                KC_PLUS,           ____,
      KC_LALT,                                                            ____,             KC_F4,            KC_F5,            KC_F6,                KC_RALT,             ____,
      KC_LCTL,                                                            KC_NO,              KC_F1,            KC_F2,            KC_F3,                KC_RCTL,
      KC_LSFT,                                                          KC_NO,              KC_F11,           KC_F10,           KC_F12,                KC_LSFT,            ____,
      KC_LSFT,                                                  KC_LGUI,              ____,            KC_LCTL,            KC_LALT,

      // left thumb
      ____,                                                              ____,              ____,
      LT(CONTROL,KC_SPACE),          LT(WM,      KC_TAB),          ____,

      // right fingers
      ____,                                                              KC_KP_ASTERISK,     KC_F7,            KC_F8,            KC_F9,                  KC_EQUAL,          KC_BSPC,
      ____,                                                              KC_LALT,            KC_F4,            KC_F5,            KC_F6,                  KC_RALT,        KC_RALT,
      KC_LCTL,                                                            KC_F1,              KC_F2,            KC_F3,            KC_KP_MINUS,            KC_RCTL,
      KC_LSFT,                                                          ____,              KC_F11,           KC_F10,           KC_F12,                 KC_LSFT,          KC_LSFT,
	  KC_RALT,                                                     KC_RCTL,              ____,            ____,            ____,

      // right thumb
      ____,                                                              ____,              ____,
      ____,                                                              LT(WM,        KC_ENTER),        LT(CONTROL, KC_SPACE)
   ),

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
   [CONTROL] = LAYOUT_ergodox(
      // left fingers
      KC_ESC,                             XXXX,              XXXX,            XXXX,            XXXX,                  ____,             ____,
      ____,                               XXXX,              KC_LEFT,          KC_PGUP,         KC_RIGHT,           KC_ESCAPE,         KC_LGUI,
					  ____,              RCTL(KC_R),         KC_HOME,       KC_UP,            KC_DOWN,            ____,
      ____,                               RCTL(KC_Z),        RSFT(KC_ENTER),   XXXX,            KC_PGDN,             KC_ENTER,          LCTL(KC_QUES),

					 // lower row
					 TO(KEYMACS),        ____,             ____,            XXXX,       XXXX,
      // left thumb
      ____,      KC_LSFT,              ____,            ____,            ____,                  ____,

      // right fingers
      ____,                       XXXX,               XXXX,             XXXX,             KC_MENU,           ____,           KC_UNDO,
      ____,                       XXXX,               XXXX,             XXXX,             XXXX,              XXXX,            ____,
				  KC_DEL,             KC_LEFT,          KC_RIGHT,         KC_END,            KC_WWW_BACK,     KC_WWW_FORWARD,
      ____,                       XXXX,               KC_MS_BTN1,       KC_MS_BTN2,       KC_MS_BTN3,        KC_MS_BTN4,      KC_MS_BTN5,

				 // lower row
				 XXXX,  XXXX, XXXX, XXXX, TO(RUSSIAN),

      // right thumb
      ____,                        ____,              ____,            ____,            KC_LCTL,               ____
   ),

   // Window manager control (currently for Spectr WM)
   [WM] = LAYOUT_ergodox(
      // left fingers
      LGUI(KC_P),            KC_GRAVE,           KC_COLON,         KC_MINUS,         KC_EXLM,            KC_PLUS,           KC_K,
      ALT_T(KC_TAB),          KC_Q,               KC_B,             KC_P,             KC_F,               KC_RALT,           LCTL(KC_ENTER),
			      KC_LCTL,            LT(NUMPAD,KC_R),  KC_A,             KC_E,               KC_N,              KC_RCTL,
      KC_LSFT,                KC_Z,               KC_COMMA,         KC_U,             KC_K,               ____,  TG(GAME),

      // lower row
      TO(KEYMACS),     ____,     TG(GAME), ____,     ____,
      // left thumb
      ____,                         ____,        ____,
      LGUI(KC_LSFT),       LGUI(KC_LSFT),     LGUI(KC_DEL),

      // right fingers
      LGUI(KC_F),                                        LGUI(KC_T),         LGUI(KC_7),       LGUI(KC_8),             LGUI(KC_9),             XXXX,          LGUI(KC_BSPC),
      LGUI(KC_F4),                                       LGUI(KC_F4),        LGUI(KC_4),       LGUI(KC_5),             LGUI(KC_6),             LGUI(KC_F3),      XXXX,
							 LGUI(KC_F1),        LGUI(KC_1),       LGUI(KC_2),             LGUI(KC_3),             XXXX,          LGUI(KC_F2),
      LGUI(KC_F1),                                       ____,               KC_C,             LGUI(KC_0),             KC_DOT,                 KC_SLASH,         LGUI(KC_F3),
      KC_TAB,                                            ____,             ____,            ____,            TO(RUSSIAN),

      // right thumb
      ____, ____, ____,
      LGUI(KC_INS),      LGUI(KC_ENTER),     C(LGUI(KC_SPACE))
   ),

   // Gaming mode mostly for action games
   [GAME] = LAYOUT_ergodox(     // left fingers
      KC_ESC,                                                             KC_1,               KC_2,             KC_3,             KC_4,                   KC_5,              KC_PLUS,
      KC_TAB,                                                             KC_LALT,            KC_Q,             KC_W,             KC_E,                   KC_T,              KC_H,
      KC_M,                                                               KC_LCTL,            KC_A,             KC_S,             KC_D,                   KC_F,
      KC_K,                                                               KC_LSFT,            KC_Z,             KC_X,             KC_C,                   KC_V,              KC_G,
      TO(KEYMACS),                                                    LALT(KC_1),         LALT(KC_2),       LALT(KC_3),       KC_R,
      // left thumb
      KC_B,                                                               ____,              ____,
      KC_SPACE,                                                           KC_MS_BTN3,         KC_KP_DOT,
      // right fingers
      KC_EQUAL,                                                           KC_6,               KC_7,             KC_8,             KC_9,                   KC_0,              KC_BSPC,
      KC_I,                                                               KC_O,               KC_F7,            KC_F8,            KC_F9,                  KC_W,              KC_RALT,
      KC_P,                                                               KC_F4,              KC_F5,            KC_F6,            KC_H,                   KC_RCTL,
      KC_J,                                                               KC_N,               KC_F1,            KC_F2,            KC_F3,                  KC_SLASH,          KC_RSFT,
      KC_F11,                                                             KC_F10,             KC_F12,           KC_U,             KC_Y,
      // right thumb
      ____,                                                              ____,              ____,
      ____,                                                              KC_ENTER,           KC_SPACE),

};

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif

  // Customise these values to desired behaviour
  // debug_enable=true;
  // debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

uint8_t cur_layer = KEYMACS;

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    static uint8_t old_layer = 0xff;
    cur_layer = get_highest_layer(state);

    switch (cur_layer) {
    case RUSSIAN:
      // Turn on RUS layout on enter to Russian layer.
      if (old_layer != RUSSIAN) {
	tap_code(RUS);
      } // else {
	// tap_code(LAT);
	// tap_code(RUS);
      // }
      break;
    default:
      // Switch back to English when we leave Russian layer.
      if (old_layer == RUSSIAN) {
	tap_code(LAT);
      }
    }

    //old_layer = cur_layer;
    xprintf("LAYER: %d %d\n", old_layer, cur_layer); // left for debugging yet
    old_layer = cur_layer;
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (cur_layer) {
	case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
	    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
	    break;
	case 1:
	    ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
	    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
	    break;
	case 2:
	    ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
	    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
	    break;
	case 3:
	    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
	    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
	    break;
	case 4:
	    ergodox_right_led_1_on();
	    ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
	    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
	    break;
	case 5:
	    ergodox_right_led_1_on();
	    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
	    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
	    break;
	case 6:
	    ergodox_right_led_2_on();
	    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
	    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
	    break;
	case 7:
	    ergodox_right_led_1_on();
	    ergodox_right_led_2_on();
	    ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
	    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
	    break;
	default:
	    break;
    }

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
    if (cur_layer == RUSSIAN && record->event.pressed) {
	switch (keycode) {
	case KC_LCTL:
	case KC_RCTL:
	case KC_LALT:
	case KC_RALT:
	case KC_LGUI:
	case KC_MENU:
	case ALT_T(KC_INS):
	case ALT_T(KC_DEL):
	case RCTL_T(KC_ENTER):
	    back_to_ussr = true;
	    layer_off(RUSSIAN);
	    layer_on(KEYMACS);
	}
	/* if (record->event.key.col == 0) { */
	/*     switch (record->event.key.row) { */
	/*     case 0: */
	/*     layer_off(RUSSIAN); */
	/*     layer_on(KEYMACS); */
	/*     back_to_ussr = true; */
	/*     } */
	/* } */
    }
    if (back_to_ussr && !record->event.pressed) {
	switch (keycode) {
	case KC_LCTL:
	case KC_RCTL:
	case KC_LALT:
	case KC_RALT:
	case KC_LGUI:
	case KC_MENU:
	case ALT_T(KC_INS):
	case ALT_T(KC_DEL):
	case RCTL_T(KC_ENTER):
	    back_to_ussr = false;
	    layer_off(KEYMACS);
	    layer_on(RUSSIAN);
	}
	/* if (record->event.key.col == 0) { */
	/*     switch (record->event.key.row) { */
	/*     case 0: */
	/*     layer_off(KEYMACS); */
	/*     layer_on(RUSSIAN); */
	/*     back_to_ussr = false; */
	/*     } */
	/* } */
   }

   switch(keycode){
   case EMACS_SELECT:
	 if(record->event.pressed){
	   // Emacs: reset the selection and activate a new one
	   switch_russian_layer(false);
	   SEND_STRING(SS_LCTL("g") SS_DELAY(100) SS_LCTL(" "));
	   switch_russian_layer(true);
	 }
	 return(false);
   case EMACS_BLSEL:
	  if(record->event.pressed){
	      switch_russian_layer(false);
	      SEND_STRING(SS_LCTL("gx") " ");
	      switch_russian_layer(true);
	  }
	  return(false);
   case EMACS_CHBUF:
	  if (record->event.pressed){
	     switch_russian_layer(false);
	     SEND_STRING(SS_LCTL("g") SS_DELAY(100) SS_LCTL("x") SS_DELAY(50) "b");
	     switch_russian_layer(true);
	  }
	  return(false);
   case EMACS_CMD:
       if(record->event.pressed){
	  switch_russian_layer(false);
	  SEND_STRING(SS_LCTL("g") SS_DELAY(100) SS_LALT("x"));
	  switch_russian_layer(true);
       }
       return(false);
   case EMACS_RESET:
	 if(record->event.pressed){
	     switch_russian_layer(false);
	 } else {
	     SEND_STRING(SS_LCTL("g") SS_DELAY(100) SS_LCTL("g"));
	     switch_russian_layer(true);
	 }
	 return(false);
   case RU_ASTR: // for Russian layer only
     if (record->event.pressed) {
	 tap_code(LAT);
	 SEND_STRING("*");
	 tap_code(RUS);
     }
     return (false);
   }
   return(true);
}

// Russian Wave layout combos
enum combos {
    // ru left
    RU_TSE,
    RU_AE,
    RU_YO,
    // ru right
    RU_SCSHE,
    RU_DZJ,
    RU_TVZN,
    RU_FE,
};
// in RUSSIAN on left hand:
const uint16_t PROGMEM xr_combo[] = {KC_X, KC_R, COMBO_END};
const uint16_t PROGMEM ft_combo[] = {KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM tj_combo[] = {KC_T, KC_J, COMBO_END};
// in RUSSIAN on right hand:
const uint16_t PROGMEM hp_combo[] = {KC_H, KC_P, COMBO_END};
const uint16_t PROGMEM dh_combo[] = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM mcom_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM com7_combo[] = {KC_COMMA, KC_7, COMBO_END};
combo_t key_combos[] = {
    [RU_TSE] = COMBO(xr_combo, KC_W),
    [RU_AE] = COMBO(ft_combo, KC_QUOTE),
    [RU_YO] = COMBO(tj_combo, KC_SLASH),
    [RU_SCSHE] = COMBO(hp_combo, KC_O),
    [RU_DZJ] = COMBO(dh_combo, KC_SCLN),
    [RU_TVZN] = COMBO(mcom_combo, KC_RBRC),
    [RU_FE] = COMBO(com7_combo, KC_A),
};

void dance_game_tokeymacs(tap_dance_state_t *state, void *user_data) {
   switch (state->count) {
   case 1:
       SEND_STRING("k");
       break;
   case 3:
       layer_on(KEYMACS);
       break;
   }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_GAME_KEYMACS] = ACTION_TAP_DANCE_FN(dance_game_tokeymacs),
};


void switch_russian_layer(bool back) {
    static bool was_rus = false;
    if (!back && cur_layer == RUSSIAN) {
	was_rus = true;
	layer_off(RUSSIAN);
	return;
    }
    if (back && was_rus) {
	was_rus = false;
	layer_on(RUSSIAN);
    }
}
