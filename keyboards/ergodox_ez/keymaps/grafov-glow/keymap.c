#include QMK_KEYBOARD_H
#include "version.h"

// Just for aesthetics
#define XXXX KC_NO

// Switchers
//#define RUS      KC_SCROLLLOCK
//#define LAT      KC_SCROLLLOCK
// return to shift-shift utility for layout switching
#define RUS      KC_RSFT
#define LAT      KC_LSFT

enum layers {
    KEYMACS, // default layer
    RUSSIAN,
    NUMPAD,
    SYMBOLS,
    FN,
    CONTROL,
    WM,
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    ____,
    EMACS_SELECT,
    EMACS_BLOCK_SELECT,
    EMACS_CMD,
    EMACS_RESET,
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
    * |Ctl-Find|   q  |   b  |   p  |   f  |   g  | Emacs|           |      |   v  |   w  |   l  |   y  |   '  | C-X-B  |
    * |--------+------+------+------+------+------| Sel  |           |      |------+------+------+------+------+--------|
    * |  Find  |   r  |   a  |   e  |.  n  |   s  |------|           |------|   d  |.  o  |   t  |   i  |   h  |  A-X   |
    * |--------+------+------+------+------+------| Win  |           |  F   |------+------+------+------+------+--------|
    * |C-A-Find|   z  |   ,  |   u  |   k  |   j  | Mgmt |           |  N   |   m  |   c  |   x  |   .  |   /  | A-Find |
    * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
    *   | LAT  |      | LAT  |  Alt |  Ctl |                                       |  Sft |  Alt | RUS  |      |  RUS |
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
      KC_ESC,                               KC_GRAVE,              KC_COLON,         KC_MINUS,         KC_EXLM,           KC_PLUS,         LCTL(KC_G),
      LCTL(KC_FIND),                        LT(NUMPAD,KC_Q),       KC_B,             KC_P,             KC_F,              KC_G,            EMACS_SELECT,
      KC_FIND,                              LT(SYMBOLS,KC_R),      KC_A,             KC_E,             KC_N,              KC_S,
      LCA_T(KC_FIND),                       KC_Z,                  KC_COMMA,         KC_U,             KC_K,              LT(FN,  KC_J),   MO(WM),

      TO(KEYMACS),                          XXXX,                  TO(KEYMACS),      KC_LALT,          KC_LCTL,

      // left thumb
      KC_LCTL, KC_LSFT,  KC_LCTL,
      LT(CONTROL, KC_BSPC), LSFT_T(KC_TAB), ALT_T(KC_DEL),

      // right finger
      MO(NUMPAD),                           KC_ASTR,            KC_QUES,          KC_DQUO,          KC_SCLN,          ____,                   KC_UNDO,
      XXXX,                                 KC_V,               KC_W,             KC_L,             KC_Y,             LT(NUMPAD,KC_QUOTE),    KC_RALT,
					    KC_D,               KC_O,             KC_T,             KC_I,             LT(SYMBOLS,KC_H),       EMACS_CMD,
      MO(FN),                               LT(NUMPAD,KC_M),    KC_C,             KC_X,             KC_DOT,           KC_SLASH,               LALT(KC_FIND),

      KC_LSFT,                              KC_RALT,            TO(RUSSIAN),      XXXX,             TO(RUSSIAN),

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
   /* QWERTY for Russian Typewriter layout adapted for Ergodox */
   /* -------------------------------------------------------- */
   /* Х moved to top for right index finger */
   /* Э moved to down for right pinky */
   /* Tap dance: */
   /* - double-tap for Ь produces Ъ */
   /* - unresovled because RCTL_T: double-tap for Е should produce Ё but not yet */
   /* It has used shift-shift switcher (https://github.com/grafov/shift-shift). */
   [RUSSIAN] = LAYOUT_ergodox(
      // left fingers
      KC_ESCAPE,                                           XXXX,  XXXX,       KC_KP_MINUS,      KC_MINUS,               XXXX,         EMACS_RESET,
      KC_LALT,                                             LT(NUMPAD,    KC_Q),            KC_W,             KC_E,                   KC_R,              ALT_T(KC_S),     ____,
      KC_LCTL,                                             LT(SYMBOLS,    KC_A),            KC_F,             KC_T,                   KC_D,              RCTL_T(KC_G),
      KC_RSFT,                                           LSFT_T(KC_Z),       KC_6,             KC_C,             KC_V,                   LT(SYMBOLS,   KC_B),           ____,
      TO(KEYMACS),                                         KC_CAPS,         ____,            KC_UNDS,          ____,

      // left thumb
      ____,      ____,          ____,
      LT(CONTROL,KC_BSPC),    ____,     ____,

      // right fingers
      ____,                                                            ____,            KC_9,             ____,        ____,        ____, ____,
      ____,                                                            ALT_T(KC_Y),        KC_U,             KC_I,             KC_DOT,                 LT(NUMPAD,   KC_P),           KC_RALT,
      LCTL_T(KC_H),                                                    KC_J,               KC_K,             KC_L,             LT(SYMBOLS,        KC_SCLN),        KC_RCTL,
      EMACS_CMD,                                                      LT(NUMPAD,    KC_N),            ____,     KC_COMMA,               KC_7,              RSFT_T(KC_QUOTE), KC_RSFT,
      ____,                                            LT(FN,KC_APP),   XXXX,            KC_CAPS,            ____,

      // right thumb
      ____,                                   ____,              ____,
      ____,                           LSFT_T(KC_ENTER),              LT(CONTROL, KC_SPACE)
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
      KC_NUM,                                                         KC_KP_ASTERISK,     KC_7,             KC_8,             KC_9,                   KC_EQUAL,          KC_BSPC,
      KC_KP_PLUS,                                                         KC_PIPE,            KC_4,             KC_5,             KC_6,                   KC_QUOTE,          KC_RALT,
      ____,                                                          KC_1,               KC_2,             KC_3,             KC_KP_MINUS,            KC_RCTL,
      KC_KP_SLASH,                                                        KC_KP_ENTER,        KC_KP_EQUAL,      KC_0,             KC_DOT,              ____,             KC_RSFT,
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
      ____,                                                              ____, KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,           ____,
      KC_LALT,                                                            ____,             KC_PERC,          KC_LBRC,      KC_RBRC,            XXXX,             ____,
      KC_LCTL,                                                            ____,          KC_AT,            KC_LPRN,          KC_RPRN,                XXXX,
      KC_LSFT,                                                          XXXX,              KC_LABK,          KC_UNDS,          KC_TILD,                KC_ENTER,          ____,
      ____,                                                              ____,              ____,            ____,            KC_TAB,

      // left thumb
      ____,                                                              ____,              ____,
      LT(CONTROL,                                                   KC_BSPC),          ____,            ____,

      // right fingers
      ____,                                                              KC_ASTR,            KC_QUES,          KC_DQUO,          KC_SCLN,              ____,            ____,
      ____,                                                              KC_PIPE,            KC_CIRC,          KC_DLR,           KC_AMPR,                KC_QUOTE,          KC_RALT,
      KC_NO,                                                              KC_LCBR,            KC_RCBR,          KC_HASH,          XXXX,                  KC_RCTL,
      ____,                                                              KC_ENTER,           KC_EQUAL,         KC_BSLS,        KC_RABK,                KC_SLASH,         KC_RSFT,
      ____,                                            LT(FN,KC_APP),   XXXX,            KC_CAPS,            ____,

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
      KC_LSFT,                                                  ____,              ____,            ____,            ____,

      // left thumb
      ____,                                                              ____,              ____,
      LT(CONTROL,KC_SPACE),          LT(WM,      KC_TAB),          ____,

      // right fingers
      ____,                                                              KC_KP_ASTERISK,     KC_F7,            KC_F8,            KC_F9,                  KC_EQUAL,          KC_BSPC,
      ____,                                                              KC_LALT,            KC_F4,            KC_F5,            KC_F6,                  KC_RALT,        KC_RALT,
      KC_LCTL,                                                            KC_F1,              KC_F2,            KC_F3,            KC_KP_MINUS,            KC_RCTL,
      KC_LSFT,                                                          ____,              KC_F11,           KC_F10,           KC_F12,                 KC_LSFT,          KC_LSFT,
      ____,                                                              ____,              ____,            ____,            KC_LSFT,

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
   [CONTROL] = LAYOUT_ergodox(     // left fingers
      ____,                                                              XXXX,              XXXX,            XXXX,            XXXX,                  ____,             ____,
      ____,                                                              XXXX,              KC_LEFT,          KC_PGUP,          KC_RIGHT,               KC_ESCAPE,         KC_LGUI,
      ____,                                                              RCTL(KC_R),         KC_HOME,          KC_UP,            KC_DOWN,                ____,
      ____,                                                              RCTL(KC_Z),         RSFT(KC_ENTER),   XXXX,            KC_PGDN,              KC_ENTER,          LCTL(KC_QUES),
      TG(KEYMACS),                                                 ____,     ____, XXXX,            KC_TAB,

      // left thumb
      KC_SPACE,                                                           ____,              ____,            ____,            ____,                  ____,

      // right fingers
      ____,                                                              RGUI(KC_F6),        XXXX,       XXXX,       KC_MENU,             ____,             KC_UNDO,
      KC_LGUI,                                                            LCTL(KC_V),         LALT(KC_W),       LCTL(KC_W),       LCTL(KC_Y),             XXXX,             ____,
      KC_DELETE,                                                          KC_LEFT,            KC_RIGHT,         KC_END,           KC_WWW_BACK,            KC_WWW_FORWARD,
      XXXX,                                                             KC_MS_BTN1,           KC_MS_BTN2,       KC_MS_BTN3,        KC_MS_BTN4,            KC_MS_BTN5, ____,
      XXXX,  XXXX, XXXX, XXXX, XXXX,

      // right thumb
      ____,                                                              ____,              ____,            ____,            KC_ENTER,               KC_SPACE
   ),

   // Window manager control (currently for Spectr WM)
   [WM] = LAYOUT_ergodox(     // left fingers
      TO(KEYMACS),                                                  KC_GRAVE,           KC_COLON,         KC_MINUS,         KC_EXLM,                KC_PLUS,           KC_K,
      ALT_T(KC_TAB),                                                      KC_Q,               KC_B,             KC_P,             KC_F,                   KC_RALT,      LCTL(KC_ENTER),
      KC_LCTL,                                                            LT(NUMPAD,    KC_R),            KC_A,             KC_E,                   KC_N,              KC_RCTL,
      KC_LSFT,                                                          KC_Z,               KC_COMMA,         KC_U,             KC_K,               LGUI(KC_MS_BTN1),       XXXX,
      TG(KEYMACS),                                                  ____,     ____, KC_UNDS,          KC_TAB,
      // left thumb
      LCTL(KC_G),                                                         KC_WWW_BACK,        LCTL(KC_V),
      LALT(KC_SPACE),                                                           ____,              KC_INS,

      // right fingers
      KC_K,                                                              KC_ASTR,            LGUI(KC_7),             LGUI(KC_8),             LGUI(KC_9),                   KC_EQUAL,          KC_BSPC,
      RCTL(KC_ENTER),                                                     KC_LALT,        LGUI(KC_4),             LGUI(KC_5),             LGUI(KC_6),                   KC_QUOTE,          KC_RALT,
      KC_LCTL,                                                          LGUI(KC_1),               LGUI(KC_2),             LGUI(KC_3),             LT(NUMPAD,        KC_H),             KC_RCTL,
      KC_F,                                                             KC_LSFT,        KC_C,             LGUI(KC_0),             KC_DOT,                 KC_SLASH,          KC_RSFT,
      KC_TAB,                                                             KC_UNDS,            ____,            ____,            TO(RUSSIAN),
      // right thumb
      KC_WWW_FORWARD,                                                     RCTL(KC_W),         KC_WWW_REFRESH,
      KC_DELETE,                                                          LGUI(KC_ENTER),     C(LGUI(KC_SPACE))
   ),
};

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

uint8_t cur_layer = KEYMACS;

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    static uint8_t old_layer = 0xff;
    cur_layer = get_highest_layer(state);

    switch (cur_layer) {
    case KEYMACS:
	if (old_layer == KEYMACS) {
	    tap_code(RUS);
	    tap_code(LAT);
	}
	break;
    case RUSSIAN:
      // Turn on RUS layout on enter to Russian layer.
      if (old_layer != RUSSIAN) {
	tap_code(RUS);
      } else {
	tap_code(LAT);
	tap_code(RUS);
      }
      break;
    default:
      // Switch back to English when we leave Russian layer.
      if (old_layer == RUSSIAN) {
	tap_code(LAT);
      }
    }

    old_layer = cur_layer;
    xprintf("LAYER: %d \n", cur_layer); // left for debugging yet

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
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
	case LCTL_T(KC_DEL):
	case RCTL_T(KC_ENTER):
	case KC_LALT:
	case KC_RALT:
	    layer_off(RUSSIAN);
	    layer_on(KEYMACS);
	    back_to_ussr = true;
	}
	if (record->event.key.col == 0) {
	    switch (record->event.key.row) {
	    case 0:
	    layer_off(RUSSIAN);
	    layer_on(KEYMACS);
	    back_to_ussr = true;
	    }
	}
    }
    if (back_to_ussr && !record->event.pressed) {
	switch (keycode) {
	case KC_LCTL:
	case KC_RCTL:
	case LCTL_T(KC_DEL):
	case RCTL_T(KC_ENTER):
	case KC_LALT:
	case KC_RALT:
	    layer_off(KEYMACS);
	    layer_on(RUSSIAN);
	    back_to_ussr = false;
	}
	if (record->event.key.col == 0) {
	    switch (record->event.key.row) {
	    case 0:
	    layer_off(KEYMACS);
	    layer_on(RUSSIAN);
	    back_to_ussr = false;
	    }
	}
    }

   switch(keycode){
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

       case EMACS_CMD:
	  if(record->event.pressed){
	      if(cur_layer == RUSSIAN){
		 layer_off(RUSSIAN);
	      }
	  } else {
	    SEND_STRING(SS_LALT("x"));
	  }
	 return(false);
       case EMACS_RESET:
	  if(record->event.pressed){
	      if(cur_layer == RUSSIAN){
		 layer_off(RUSSIAN);
	      }
	  } else {
	    SEND_STRING(SS_LCTL("g"));
	  }
	 return(false);
   }

   return(true);
}
