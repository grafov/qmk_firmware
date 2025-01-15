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
    LAY_RST,
    LAY_RUS,
    EMACS_SELECT,
    EMACS_BLSEL,
    EMACS_CMD,
    EMACS_RESET,
    EMACS_CHBUF,
    EMACS_WIN,
    RU_ASTR,
    RU_NUM,
    RU_SLASH,
    CONTROL_LKEEP,
    CONTROL_RKEEP,
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
    * |   Esc  |   `  |   :  |   -  |   !  |   +  | Ctl-G|           | ASST |   *  |   ?  |   "  |   ;  |      |  Undo  |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |Emacs <>|   q  |   b  |   p  |   f  |   g  |Emacs |           | Tab  |   m  |   w  |   l  |   y  |   '  | C-X-B  |
    * |--------+------+------+------+------+------|Select|           |      |------+------+------+------+------+--------|
    * |  Find  |   r  |   a  |   e  |.  n  |   s  |------|           |------|   d  |.  o  |   t  |   i  |   h  |  A-X   |
    * |--------+------+------+------+------+------| Win  |           |  F   |------+------+------+------+------+--------|
    * |Ctl-Find|   z  |   ,  |   u  |   k  |   j  | Mgmt |           |  N   |   v  |   c  |   x  |   .  |   /  | A-Find |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | LAT  | Menu | LGUI |  Alt | Ctrl |                                       | Ctrl | Alt  | RGUI | Menu |  RUS |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,1------2------.     ,1-------2-----.
    *                                        | Ctrl | Int2  |     | Int4  | Ctrl |
    *                                 ,------|------|3------|     |3------+------+------.
    *                                 |      |      | Int1  |     | Int3  |      |      |
    *                                 | BSpc |      |-------|     |-------| Enter| SPC  |
    *                                 | +nav | Shift|Del/Ctl|     |Ins/Ctl| Shift| +nav |
    *                                 `4------5------6------'     `4-------5------6-----'
    *
    *  thumb combos:
    *  LCtl+Int1 -> LAlt
    *  LCtl+Int1+Int2 -> LCtl+LAlt
    *  the same logic for RCtl/Int3/Int4
    */
    [KEYMACS] = LAYOUT_ergodox(
      // left fingers
      KC_ESC,                       KC_GRAVE,              KC_COLON,           KC_MINUS,         KC_EXLM,           KC_PLUS,       EMACS_RESET,
      EMACS_WIN,                    LT(NUMPAD,KC_Q),       KC_B,               KC_P,             KC_F,              KC_G,          EMACS_SELECT,
      KC_FIND,                      LT(SYMBOLS,KC_R),      KC_A,               KC_E,             KC_N,              KC_S,
      LCTL(KC_FIND),                KC_Z,                  KC_COMMA,           KC_U,             KC_K,              LT(FN,KC_J),     MO(WM),
	       // lower row
	       LAY_RST,                  KC_APP,              KC_LGUI,        KC_LALT,      KC_LCTL,

      // left thumb
      KC_LCTL, KC_INT2,  KC_INT1, // 1,2,3
      LT(CONTROL, KC_BSPC), KC_LSFT, LCTL_T(KC_DEL), // 4,5,6

      // right finger
      KC_EXEC,              KC_ASTR,            KC_QUES,          KC_DQUO,          KC_SCLN,          RU_NUM,                       KC_UNDO,
      KC_TAB,               KC_M,               KC_W,             KC_L,             KC_Y,             LT(NUMPAD,KC_QUOTE),  EMACS_CHBUF,
			    KC_D,               KC_O,             KC_T,             KC_I,             LT(SYMBOLS,KC_H),     EMACS_CMD,
      XXXX,                 LT(FN,KC_V),    KC_C,             KC_X,             KC_DOT,           KC_SLASH,               LALT(KC_FIND),
	       // lower row
	       KC_RCTL,            KC_RALT,            KC_RGUI,      KC_MENU,             TG(RUSSIAN),

      // right thumb
      KC_INT4, KC_RCTL, KC_INT3, // 1,2,3
      RCTL_T(KC_INS), LSFT_T(KC_ENTER), LT(CONTROL, KC_SPACE) // 4,5,6
   ),

   /* Russian Wave (ВОЛНА0) layout slightly opimized for home square. My experiment.
    *
    * ,--------------------------------------------------.           ,--------------------------------------------------.
    * |        |  « „ |   :  |   -  |   !  |   +  |Ctl+G |           |      |   *  |   ?  |   "  |   ;  |  » “ |   BSP  |
    * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
    * |        |   у  |   ч  ц   к  ю   д  |   ы  |      |           | Tab  |   г  |   в  ф   р  щ   з  |   ш  |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |   х  |   а  э   е  ё   о  |   п  |------|           |------|   й  |   т  |   и  |   н  |   л  |        |
    * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
    * |        |   я  |   ,  |   с  |   м  |      |      |           |      |      |   ь  ъ   б  ж   .  |   /  |        |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | LAT  |      |      |      |      |                                       |      |      |      |      |      |
    *   `----------------------------------'                                       `----------------------------------'
    *                                        ,-------------.       ,-------------.
    *                                        |      |      |       |      |      |
    *                                 ,------|------|------|       |------+------+------.
    *                                 |      |      |      |       |      |      |      |
    *                                 |      |      |------|       |------|      |      |
    *                                 |      |      |      |       |      |      |      |
    *                                 `--------------------'       `--------------------'
    */
    [RUSSIAN] = LAYOUT_ergodox(
      // left fingers
      KC_ESC,               ____,                KC_5,             KC_KP_MINUS,   KC_MINUS,      KC_TILDE,        EMACS_RESET,
      EMACS_WIN,        LT(NUMPAD,KC_E),     KC_X,             KC_R,          KC_L,          KC_S,            EMACS_SELECT,
      KC_FIND,              LT(SYMBOLS,KC_LBRC), KC_F,             KC_T,          KC_J,          KC_G,
      LCTL(KC_FIND),       KC_Z,                KC_6,             KC_C,          KC_V,          MO(FN),            MO(WM),

	       // lower row
	       TO(KEYMACS),                  KC_APP,              KC_LGUI,        KC_LALT,      KC_LCTL,

      // left thumb
      KC_LCTL, KC_INT2,  KC_INT1, // 1,2,3
      LT(CONTROL, KC_BSPC), KC_LSFT, LCTL_T(KC_DEL), // 4,5,6


      // right fingers
      KC_EXEC,              RU_ASTR,           KC_9,            KC_4,        KC_EQUAL,        KC_1,                 KC_UNDO,
      KC_TAB,               KC_U,              KC_D,            KC_H,        KC_P,            KC_I,                 EMACS_CHBUF,
			    KC_Q,            KC_N,            KC_B,        KC_Y,            LT(SYMBOLS,KC_K),     EMACS_CMD,
      ____,                MO(FN),        KC_M,            KC_COMMA,    KC_7,            RU_SLASH,                 LALT(KC_FIND),

	       // lower row
	       KC_RCTL,            KC_RALT,            KC_RGUI,      KC_MENU,          LAY_RUS,

      // right thumb
      KC_INT4, KC_RCTL, KC_INT3, // 1,2,3
      RCTL_T(KC_INS), LSFT_T(KC_ENTER), LT(CONTROL, KC_SPACE) // 4,5,6
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
      KC_LCTL, KC_INT2,  KC_INT1, // 1,2,3
      LT(CONTROL, KC_BSPC), KC_LSFT, LCTL_T(KC_DEL), // 4,5,6


      // right fingers
      KC_NUM,                                                        KC_KP_ASTERISK,     KC_7,             KC_8,             KC_9,                   XXXX,          KC_BSPC,
      KC_KP_PLUS,                                                    KC_PIPE,            KC_4,             KC_5,             KC_6,                   KC_QUOTE,          KC_RALT,
      ____,                                                          KC_1,               KC_2,             KC_3,             KC_KP_MINUS,            KC_RCTL,
      KC_KP_SLASH,                                                   KC_KP_ENTER,        KC_KP_EQUAL,      KC_0,             KC_DOT,              ____,             KC_RSFT,
      ____,                                                              ____,              ____,            ____,            ____,
      // right thumb
      KC_INT4, KC_RCTL, KC_INT3, // 1,2,3
      RCTL_T(KC_INS), LSFT_T(KC_ENTER), LT(CONTROL, KC_SPACE) // 4,5,6
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
      KC_LCTL, KC_INT2,  KC_INT1, // 1,2,3
      LT(CONTROL, KC_BSPC), KC_LSFT, LCTL_T(KC_DEL), // 4,5,6

      // right fingers
      KC_EXEC,                                                           KC_ASTR,            KC_QUES,          KC_DQUO,          KC_SCLN,              ____,            ____,
      ____,                                                              KC_PIPE,            KC_CIRC,          KC_DLR,           KC_AMPR,                KC_QUOTE,          KC_RALT,
      KC_NO,                                                              KC_LCBR,            KC_RCBR,          KC_HASH,          XXXX,                  KC_RCTL,
      ____,                                                              KC_ENTER,           KC_EQUAL,         KC_BSLS,        KC_RABK,                KC_SLASH,         KC_RSFT,
      ____,                                            ____,   ____,            ____,            ____,

      // right thumb
      KC_INT4, KC_RCTL, KC_INT3, // 1,2,3
      RCTL_T(KC_INS), LSFT_T(KC_ENTER), LT(CONTROL, KC_SPACE) // 4,5,6
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
      ____,                                                  ____,              ____,            ____,            ____,

      // left thumb
      KC_LCTL, KC_INT2,  KC_INT1, // 1,2,3
      LT(CONTROL, KC_BSPC), KC_LSFT, LCTL_T(KC_DEL), // 4,5,6

      // right fingers
      KC_EXEC,                                                           KC_KP_ASTERISK,     KC_F7,            KC_F8,            KC_F9,                  KC_NUM,          KC_BSPC,
      ____,                                                              KC_LALT,            KC_F4,            KC_F5,            KC_F6,                  KC_RALT,        KC_RALT,
      KC_LCTL,                                                            KC_F1,              KC_F2,            KC_F3,            KC_KP_MINUS,            KC_RCTL,
      KC_LSFT,                                                          ____,              KC_F11,           KC_F10,           KC_F12,                 KC_LSFT,          KC_LSFT,
	  ____,              ____,               ____,            ____,            ____,

      // right thumb
      KC_INT4, KC_RCTL, KC_INT3, // 1,2,3
      RCTL_T(KC_INS), LSFT_T(KC_ENTER), LT(CONTROL, KC_SPACE) // 4,5,6
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
       ____,                               XXXX,              KC_LEFT,          KC_UP,         KC_RIGHT,           KC_ESCAPE,         KC_LGUI,
       ____,              RCTL(KC_R),      KC_HOME,           KC_UP,            KC_DOWN,            ____,
       ____,                               RCTL(KC_Z),        RSFT(KC_ENTER),   KC_PGUP,         KC_PGDN,             KC_ENTER,          LCTL(KC_QUES),

					 // lower row
					 TO(KEYMACS),        KC_APP,              KC_LGUI,        KC_LALT,      KC_LCTL,

      // left thumb
      KC_LCTL, KC_INT2,  KC_INT1, // 1,2,3
      CONTROL_LKEEP, KC_LSFT, LCTL_T(KC_DEL), // 4,5,6

      // right fingers
      KC_EXEC,                    XXXX,               XXXX,             XXXX,             KC_MENU,           ____,           KC_UNDO,
      ____,                       XXXX,               XXXX,             XXXX,             XXXX,              XXXX,            ____,
				  KC_DEL,             KC_LEFT,          KC_RIGHT,         KC_END,            KC_WWW_BACK,     KC_WWW_FORWARD,
      ____,                       XXXX,               KC_MS_BTN1,       KC_MS_BTN2,       KC_MS_BTN3,        KC_MS_BTN4,      KC_MS_BTN5,

  		   // lower row
	       KC_RCTL,            KC_RALT,            KC_RGUI,      KC_MENU,             TG(RUSSIAN),

      // right thumb
      KC_INT4, KC_RCTL, KC_INT3, // 1,2,3
      RCTL_T(KC_INS), LSFT_T(KC_ENTER), CONTROL_RKEEP // 4,5,6
   ),

   // Window manager control (currently for i3 / Sway WMs)
   [WM] = LAYOUT_ergodox(
      // left fingers
      LGUI(KC_PSCR),          KC_GRAVE,           KC_COLON,         KC_MINUS,         KC_EXLM,            KC_PLUS,          LGUI(KC_K),
      ALT_T(KC_TAB),          KC_Q,               KC_B,             KC_P,             KC_F,               KC_RALT,           LCTL(KC_ENTER),
			      KC_LCTL,            LT(NUMPAD,KC_R),  KC_A,             KC_E,               KC_N,              KC_RCTL,
      KC_LSFT,                KC_Z,               KC_COMMA,         KC_U,             KC_K,               ____,  TG(GAME),

      // lower row
      TO(KEYMACS),     ____,     ____, ____,     ____,
      // left thumb
      ____,                         ____,        ____,
      LGUI(KC_BSPC),       LGUI(KC_LSFT),     LGUI(KC_DEL),

      // right fingers
      LGUI(KC_F4),                                       LGUI(KC_T),         LGUI(KC_7),       LGUI(KC_8),             LGUI(KC_9),             XXXX,             LGUI(KC_UNDO),
      LGUI(KC_F),                                        LGUI(KC_F12),       LGUI(KC_4),       LGUI(KC_5),             LGUI(KC_6),             LGUI(KC_UP),      LGUI(KC_F13),
							                     LGUI(KC_LEFT),              LGUI(KC_1),       LGUI(KC_2),             LGUI(KC_3),             LGUI(KC_RIGHT),   LGUI(KC_F14),
      LGUI(KC_F1),                                       LGUI(KC_F11),       KC_C,             LGUI(KC_0),             KC_DOT,                 LGUI(KC_DOWN),    LGUI(KC_F15),
      LGUI(KC_RALT),                                      LGUI(KC_RCTL),             ____,            ____,            TO(RUSSIAN),

      // right thumb
      ____, ____, ____,
      LGUI(KC_INS),      LGUI(KC_ENTER),     C(LGUI(KC_SPACE))
   ),

   // Gaming mode mostly for action games
   // modelled here https://configure.zsa.io/ergodox-ez/layouts/bZgO5/latest/0
   [GAME] = LAYOUT_ergodox(     // left fingers
      KC_ESC,                                                 KC_1,              KC_2,             KC_3,             KC_4,                   KC_5,              KC_MINUS,
      KC_TAB,                                                 KC_LALT,           KC_Q,             KC_W,             KC_E,                   KC_T,              KC_G,
      KC_BSPC,                                                KC_LSFT,           KC_A,             KC_S,             KC_D,                   KC_F,
      KC_DEL,                                                 KC_LCTL,           KC_Z,             KC_X,             KC_C,                   KC_V,              KC_B,
	  KC_F1,                                              KC_F2,             KC_F3,            KC_F4,             KC_F5,
      // left thumb
      KC_MENU,                                            KC_LGUI,      KC_PGUP,
      KC_SPACE,                                           KC_R,         KC_PGDN,
				// right fingers
      KC_F12,                                               KC_6,               KC_7,             KC_8,             KC_9,                   KC_0,              KC_EQUAL,
      KC_F11,                                               KC_Y,               KC_U,             KC_I,             KC_O,                   KC_P,              KC_HOME,
							    KC_H,               KC_J,             KC_K,             KC_L,                   KC_SCLN,           KC_END,
      KC_F10,                                               KC_N,               KC_M,             KC_COMMA,         KC_DOT,                 KC_UP,             KC_RCTL,
										KC_RALT,          KC_LSFT,          KC_LEFT,                KC_DOWN,           KC_RIGHT,
      // right thumb
      KC_F7,                                       KC_F8,             KC_F9,
      KC_F6,                                       KC_RGUI,           KC_ENTER),

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
uint8_t old_layer = 0xff;

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    cur_layer = get_highest_layer(state);

    switch (cur_layer) {
    case RUSSIAN:
      // Turn on RUS layout on enter to Russian layer.
      if (old_layer != RUSSIAN) {
	tap_code(RUS);
	xprintf("LAYER: %d %d ->RUS\n", old_layer, cur_layer); // left for debugging yet
      }  else {
	xprintf("LAYER: %d %d (RUS)\n", old_layer, cur_layer); // left for debugging yet
       }
      break;
    default:
      // Switch back to English when we leave Russian layer.
      if (old_layer == RUSSIAN) {
	tap_code(LAT);
	xprintf("LAYER: %d %d ->LAT\n", old_layer, cur_layer); // left for debugging yet
      } else {
	xprintf("LAYER: %d %d (LAT)\n", old_layer, cur_layer); // left for debugging yet
      }
    }

    //old_layer = cur_layer;
    old_layer = cur_layer;
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (cur_layer) {
	case 0:
	    break;
	case 1:
	    ergodox_right_led_1_on();
	    break;
	case 2:
	    ergodox_right_led_2_on();
	    break;
	case 3:
	    ergodox_right_led_3_on();
	    break;
	case 4:
	    ergodox_right_led_1_on();
	    ergodox_right_led_2_on();
	    break;
	case 5:
	    ergodox_right_led_1_on();
	    ergodox_right_led_3_on();
	    break;
	case 6:
	    ergodox_right_led_2_on();
	    ergodox_right_led_3_on();
	    break;
	case 7:
	    ergodox_right_led_1_on();
	    ergodox_right_led_2_on();
	    ergodox_right_led_3_on();
	    break;
	default:
	    break;
    }

    return state;
}

// implements user hook on the each key press/release
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    static bool switch_layouts = false;
    if (switch_layouts) {
	switch_layouts = false;
	if (!record->event.pressed) {
	    switch(keycode) {
	    case KC_RALT:
		layer_on(GAME);
		return true;
	    }
	}
    }

    // control
    // need rework! TODO
    /* static bool lc_pressed, rc_pressed = false; */
    /* switch (keycode) { */
    /* case CONTROL_LKEEP: */
    /*	lc_pressed = false; */
    /*	if (record->event.pressed) { */
    /*	    lc_pressed = true; */
    /*	} */
    /*	return false; */
    /* case CONTROL_RKEEP: */
    /*	rc_pressed = false; */
    /*	if (record->event.pressed) { */
    /*	    rc_pressed = true; */
    /*	} */
    /*	return false; */
    /* } */
    /* if (lc_pressed || rc_pressed) { */
    /*	layer_on(CONTROL); */
    /* } else { */
    /*	layer_off(CONTROL); */
    /* } */

    // SNAP TAP (separate A/D key press in games)
    static bool apressed = false;
    static bool dpressed = false;
    if (cur_layer == GAME) {
	    switch(keycode) {
	    case KC_A:
	    if (record->event.pressed) {
		apressed = true;
		if (dpressed) {
		    SEND_STRING(SS_UP(X_D));
		    dpressed = false;
		};
	    } else {
		// to prevent double key release
		if (!apressed) {
		    return false;
		}
		apressed = false;
	    }
	    return true;
	    case KC_D:
	    if (record->event.pressed) {
		dpressed = true;
		if (apressed) {
		    SEND_STRING(SS_UP(X_A));
		};
	    } else {
		// to prevent double key release
		if (!dpressed) {
		    return false;
		}
		dpressed = false;
	    }
	    if (!record->event.pressed) {
		// to prevent double release
		if (dpressed) {
		    return false;
		}
	    }
	    return true;
	    }
    }

    switch(keycode) {
    case LAY_RST: // explicitely switch to Keymacs layer
	if (!record->event.pressed) {
	    layer_off(RUSSIAN);
	    layer_on(KEYMACS);
	    tap_code(LAT);
	    switch_layouts = true;
	    return false;
	}
    case LAY_RUS: // explicitely switch to Russian Wave layer
	if (!record->event.pressed) {
	    layer_off(KEYMACS);
	    layer_on(RUSSIAN);
	    tap_code(RUS);
	    return false;
	}
    case KC_LSFT:
    case KC_RSFT:
	if (record->event.pressed) {
		return true;
	}
    }

    // Exit game mode by F1 + RIGHT in the same time.
    static bool left_game_exit = false;
    static bool right_game_exit = false;
    if (cur_layer == GAME && record->event.pressed) {
	switch (keycode) {
	case KC_F1:
	    left_game_exit = true;
	    break;
	case KC_RIGHT:
	    right_game_exit = true;
	    break;
	default:
	    // reset when any other key pressed
	    left_game_exit = right_game_exit = false;
	}
	if (left_game_exit && right_game_exit) {
	    left_game_exit = right_game_exit = false;
	    layer_off(GAME);
	    layer_on(KEYMACS);
	    return true;
	}
    }

    // For compatibility with software that not understand how to map
    // non-English keys with modifiers. Just temporary switch to
    // Keymacs layer when modifier pressed. It works only for Russian
    // layer.
    static bool back_to_ussr = false;
    // on modifier key press:
    if (!back_to_ussr && cur_layer == RUSSIAN && record->event.pressed) {
	switch (keycode) {
	case KC_LCTL:
	case KC_RCTL:
	case KC_LALT:
	case KC_RALT:
	case KC_LGUI:
	case KC_MENU:
    case KC_INT1:
    case KC_INT2:
    case KC_INT3:
    case KC_INT4:
	case RCTL_T(KC_INS):
    case LCTL_T(KC_DEL):
	case RCTL_T(KC_ENTER):
	    back_to_ussr = true;
	    layer_off(RUSSIAN);
	    layer_on(KEYMACS);
	}
    }
    // on modifier key release:
    if (back_to_ussr && cur_layer != RUSSIAN && !record->event.pressed) {
	switch (keycode) {
	case KC_LCTL:
	case KC_RCTL:
	case KC_LALT:
	case KC_RALT:
	case KC_LGUI:
	case KC_MENU:
    case KC_INT1:
    case KC_INT2:
    case KC_INT3:
    case KC_INT4:
	case RCTL_T(KC_INS):
    case LCTL_T(KC_DEL):
	    back_to_ussr = false;
	    layer_off(KEYMACS);
	    layer_on(RUSSIAN);
	}
   }

   switch(keycode){
   case EMACS_SELECT:
	 if(record->event.pressed){
	   // Emacs: reset the selection and activate a new one
	   switch_russian_layer(false);
	   SEND_STRING(SS_LCTL(" "));
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
   case EMACS_WIN:
	  if (record->event.pressed){
	     switch_russian_layer(false);
	     SEND_STRING(SS_LCTL("x") SS_DELAY(100) "o");
	     switch_russian_layer(true);
	  }
	  return(false);
   case EMACS_CMD:
       if(record->event.pressed){
	  switch_russian_layer(false);
	  SEND_STRING(SS_LALT("x"));
	  switch_russian_layer(true);
       }
       return(false);
   case EMACS_RESET:
	 if(record->event.pressed){
	     switch_russian_layer(false);
	 } else {
	     SEND_STRING(SS_LCTL("g"));
	     switch_russian_layer(true);
	 }
	 return(false);
   case RU_SLASH:
     if (record->event.pressed) {
	  switch_russian_layer(false);
     } else {
	 SEND_STRING("/");
	 switch_russian_layer(true);
     }
     return (false);
   case RU_ASTR: // for Russian layer only
     if (record->event.pressed) {
	  switch_russian_layer(false);
     } else {
	 SEND_STRING("*");
	 switch_russian_layer(true);
     }
     return (false);
   case RU_NUM: // FIXME yet works only on Keymacs layer
     if (record->event.pressed) {
	  layer_on(RUSSIAN);
     } else {
	 SEND_STRING("1");
	 layer_off(RUSSIAN);
     }
     return (false);
   }
   return(true);
}

// Handle ctl-alt by single-double-triple keys on thumb cluster.
/* bool thumb_ctl_alt(uint16_t keycode, keyrecord_t *record) { */
/*     static int pressed; // ctl->alt->ctl+alt */
/*                         // 001 - ctl */
/*                         // 002 - alt */
/*                         // 003 - ctl+alt */
/*     switch (keycode) { */
/*         case CTL_T(KC_DEL): */
/*         case CTL_T(KC_INS): */
/*             if (record->event.pressed) { */
/*                 SEND_STRING() */
/*             } */
/*     } */
/* } */

// Russian Wave & Thumb combos
enum combos {
    // ru left
    RU_TSE,
    RU_AE,
    RU_YO,
    LTHUMB_ALT,
    LTHUMB_CTL_ALT,
    // ru right
    RU_SCSHE,
    RU_DZJ,
    RU_TVZN,
    RU_FE,
    RU_YU,
    RTHUMB_ALT,
    RTHUMB_CTL_ALT,
};

// on left hand:
const uint16_t PROGMEM xr_combo[] = {KC_X, KC_R, COMBO_END};
const uint16_t PROGMEM rl_combo[] = {KC_R, KC_L, COMBO_END};
const uint16_t PROGMEM ft_combo[] = {KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM tj_combo[] = {KC_T, KC_J, COMBO_END};
const uint16_t PROGMEM ctl_int1[] = {LCTL_T(KC_DEL), KC_INT1, COMBO_END};
const uint16_t PROGMEM ctl_int1_int2[] = {LCTL_T(KC_DEL), KC_INT1, KC_INT2, COMBO_END};

// on right hand:
const uint16_t PROGMEM hp_combo[] = {KC_H, KC_P, COMBO_END};
const uint16_t PROGMEM dh_combo[] = {KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM mcom_combo[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM com7_combo[] = {KC_COMMA, KC_7, COMBO_END};
const uint16_t PROGMEM ctl_int3[] = {RCTL_T(KC_INS), KC_INT3, COMBO_END};
const uint16_t PROGMEM ctl_int3_int4[] = {RCTL_T(KC_INS), KC_INT3, KC_INT4, COMBO_END};

combo_t key_combos[] = {
    // left
    [RU_TSE] = COMBO(xr_combo, KC_W), // Ц
    [RU_YU] = COMBO(rl_combo, KC_DOT), // Ю
    [RU_AE] = COMBO(ft_combo, KC_QUOTE), // Э
    [RU_YO] = COMBO(tj_combo, KC_SLASH), // Ё
    [LTHUMB_ALT] = COMBO(ctl_int1, KC_LALT), // ALT only
    [LTHUMB_CTL_ALT] = COMBO_ACTION(ctl_int1_int2), // CTL+ALT
    // right
    [RU_SCSHE] = COMBO(hp_combo, KC_O), // Щ
    [RU_FE] = COMBO(dh_combo, KC_A), // Ф
    [RU_TVZN] = COMBO(mcom_combo, KC_RBRC), // Ъ
    [RU_DZJ] = COMBO(com7_combo, KC_SCLN), // Ж
    [RTHUMB_ALT] = COMBO(ctl_int3, KC_RALT), // ALT only
    [RTHUMB_CTL_ALT] = COMBO_ACTION(ctl_int3_int4), // CTL+ALT
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case LTHUMB_CTL_ALT:
      if (pressed) {
          SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LALT));
      } else {
          SEND_STRING(SS_UP(X_LCTL) SS_UP(X_LALT));
      }
      break;
    case RTHUMB_CTL_ALT:
      if (pressed) {
          SEND_STRING(SS_DOWN(X_RCTL) SS_DOWN(X_RALT));
      } else {
          SEND_STRING(SS_UP(X_RCTL) SS_UP(X_RALT));
      }
      break;
  }
}

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

/* const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = */
/* { */
/*    [KEYMACS] = */
/*    { */
/*    // right */
/*    BLANK_HSV,  BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    BLANK_HSV,  BLANK_HSV, BLANK_HSV, BLANK_HSV, TEAL_HSV, */
/*    BLANK_HSV,  BLANK_HSV, BLANK_HSV, BLANK_HSV, DBLUE_HSV, */
/*    TEAL_HSV,   BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    DRED_HSV,  PURPLE_HSV, BLANK_HSV, BLANK_HSV, */
/*    // left mirrored */
/*    BLANK_HSV,  BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    BLANK_HSV,  BLANK_HSV, BLANK_HSV, BLANK_HSV, TEAL_HSV, */
/*    BLANK_HSV,  BLANK_HSV, BLANK_HSV, BLANK_HSV, DBLUE_HSV, */
/*    PURPLE_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    BLANK_HSV,  BLANK_HSV, WHITE_HSV, DBLUE_HSV */
/*    }, */

/*    [RUSSIAN] = */
/*    { */
/*    // right */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    WHITE_HSV, WHITE_HSV, WHITE_HSV, WHITE_HSV, WHITE_HSV, */
/*    BLUE_HSV,  BLUE_HSV,  BLUE_HSV,  BLUE_HSV,  BLUE_HSV, */
/*    RED_HSV,   RED_HSV,   RED_HSV,   RED_HSV,   RED_HSV, */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    // left mirrored */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    WHITE_HSV, WHITE_HSV, WHITE_HSV, WHITE_HSV, WHITE_HSV, */
/*    BLUE_HSV,  BLUE_HSV,  BLUE_HSV,  BLUE_HSV,  BLUE_HSV, */
/*    RED_HSV,   RED_HSV,   RED_HSV,   RED_HSV,   RED_HSV, */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV */
/*    }, */

/*    [NUMPAD] = */
/*    { */
/*    // right */
/*    BLANK_HSV, TEAL_HSV,  TEAL_HSV,  TEAL_HSV,  BLANK_HSV, */
/*    BLANK_HSV, TEAL_HSV,  GREEN_HSV, TEAL_HSV,  BLANK_HSV, */
/*    BLANK_HSV, TEAL_HSV,  TEAL_HSV,  TEAL_HSV,  BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV, TEAL_HSV,  BLANK_HSV, BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    // left mirrored */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV */
/*    }, */

/*    [SYMBOLS] = */
/*    { */
/*    // right */
/*    DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, */
/*    BLANK_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV, */
/*    BLANK_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV, */
/*    BLANK_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    // left mirrored */
/*    DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, */
/*    BLANK_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV, */
/*    BLANK_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV, */
/*    BLANK_HSV, DBLUE_HSV, DBLUE_HSV, DBLUE_HSV, BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV */
/*    }, */

/*    [FN] = */
/*    { */
/*    // right */
/*    BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV, */
/*    BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV, */
/*    BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV, */
/*    BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV, */
/*    // left mirrored */
/*    BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV, */
/*    BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV, */
/*    BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV, */
/*    BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV */
/*    }, */

/*    [GAME] = */
/*    { */
/*    // right */
/*    TEAL_HSV,  TEAL_HSV,   TEAL_HSV,   TEAL_HSV,   TEAL_HSV, */
/*    BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV, */
/*    BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV, */
/*    BLANK_HSV, PURPLE_HSV, PURPLE_HSV, PURPLE_HSV, BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV, */
/*    // left mirrored */
/*    TEAL_HSV,  TEAL_HSV,   TEAL_HSV,   TEAL_HSV,   TEAL_HSV, */
/*    BLANK_HSV, BLANK_HSV,  BRED_HSV,   BLANK_HSV,  BLANK_HSV, */
/*    BLANK_HSV, BRED_HSV,   BRED_HSV,   BRED_HSV,   BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV,  BLANK_HSV, */
/*    BLANK_HSV, TEAL_HSV,   TEAL_HSV,   TEAL_HSV */
/*    }, */

/*    [CONTROL] = */
/*    { */
/*    // right */
/*    BLANK_HSV, BRED_HSV,  BRED_HSV,  BRED_HSV,  BLANK_HSV, */
/*    DRED_HSV,  DRED_HSV,  DRED_HSV,  DRED_HSV,  BLANK_HSV, */
/*    DRED_HSV,  BRED_HSV,  BRED_HSV,  DRED_HSV,  BLANK_HSV, */
/*    BLANK_HSV, DRED_HSV,  DRED_HSV,  DRED_HSV,  BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    // left mirrored */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV, */
/*    BLANK_HSV, BRED_HSV,  BRED_HSV,  BLANK_HSV, BLANK_HSV, */
/*    BLANK_HSV, DRED_HSV,  DRED_HSV,  DRED_HSV,  BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV, BLANK_HSV, BLANK_HSV */
/*    }, */

/*    [WM] = */
/*    { */
/*    // right */
/*    BLANK_HSV, ORANGE_HSV, ORANGE_HSV, ORANGE_HSV, BLANK_HSV, */
/*    BLANK_HSV, ORANGE_HSV, ORANGE_HSV, ORANGE_HSV, BLANK_HSV, */
/*    BLANK_HSV, ORANGE_HSV, ORANGE_HSV, ORANGE_HSV, BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV,  ORANGE_HSV, BLANK_HSV,  BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV, */
/*    // left mirrored */
/*    BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV,  BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV,  BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV,  BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV,  BLANK_HSV, */
/*    BLANK_HSV, BLANK_HSV,  BLANK_HSV,  BLANK_HSV */
/*    },    */
/* }; */

/* void set_layer_color(int layer) */
/* { */
/*    for(int i = 0; i < DRIVER_LED_TOTAL; i++){ */
/*        HSV hsv = */
/*        { */
/*	  .h = pgm_read_byte(&ledmap[layer][i][0]), */
/*	  .s = pgm_read_byte(&ledmap[layer][i][1]), */
/*	  .v = pgm_read_byte(&ledmap[layer][i][2]), */
/*        }; */
/*        if(!hsv.h && !hsv.s && !hsv.v){ */
/*	  rgb_matrix_set_color(i, 0, 0, 0); */
/*	  } */
/*        else{ */
/*	   RGB   rgb = hsv_to_rgb(hsv); */
/*	   float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX; */
/*	   rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b); */
/*	   } */
/*        } */
/* } */
