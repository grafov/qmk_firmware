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
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "process_keycode/process_tap_dance.h"

// #include "keymap_german.h"
// #include "keymap_nordic.h"

// Just for aesthetics
#define _____ KC_TRANSPARENT
#define XXXXX KC_NO

// Switchers
// #define RUS KC_SCROLLLOCK
#define RUS KC_RSHIFT
// #define LAT KC_SCROLLLOCK
#define LAT KC_LSHIFT
// #define MRUS SCROLLLOCK
#define MRUS RSHIFT
// #define MLAT SCROLLLOCK
#define MLAT LSHIFT
#define XLAT X_SCROLLLOCK
#define XRUS X_SCROLLLOCK
#define LV3 KC_CAPSLOCK
#define MLV3 CAPSLOCK
#define TAP(kc)        \
    register_code(kc); \
    unregister_code(kc)

// Layer names
enum { LAYER_KEYMACS = 0, LAYER_AUXCHARS, LAYER_RUSSIAN, LAYER_AUXCHARS_RU, LAYER_MOUSE, LAYER_QWERTY, LAYER_NUMPAD, LAYER_CONTROL, LAYER_FN, LAYER_MEDIA, LAYER_WM };

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EMACS_SELECT,
    EMACS_BLOCK_SELECT,
    EMACS_ALTX,
    EPRM,
    RGB_SLD,
    RGB_0000FF,
    RGB_008000,
    RGB_FFA500,
    RGB_800080,
    RGB_FF0000,
    RU_ASTR,
};

// Macros IDs
enum {
    M_EMACS_SELECT = 0,
    M_EMACS_BLOCK_SELECT,
    M_RUASTR,
    ACCENT,
    RU_NOSIGN,
    KEYNAV,
    M_WMDOWN,
    M_WMUP,
    M_LAYER_IS_KEYMACS,
    M_LAYER_IS_AUXCHARS,
    M_LAYER_IS_RUSSIAN,
    M_LAYER_IS_AUXCHARS_RU,
    M_LAYER_IS_CONTROL,
    M_LAYER_IS_MOUSE,
    M_LAYER_IS_QWERTY,
    M_LAYER_IS_NUMPAD,
    M_LAYER_IS_FN,
    M_LAYER_IS_MEDIA,
    M_LAYER_IS_WM,
};

// Tap Dance Declarations
enum {
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default layer based on Keymacs layout
     * This is the adaptation of the layout for common keyboards for Ergodox EZ
     * https://github.com/keyboard-ergonomics/keymacs
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   Esc  |   `  |   :  |   -  |   !  |   +  | Ctl-G|           | NumLk|   *  |   ?  |   "  |   ;  |   =  |   BSP  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |   Alt  |   q  |   b  |   p  |   f  |   g  | Emacs|           | LGUI |   v  |   w  |   l  |   y  |   '  |   Alt  |
     * |--------+------+------+------+------+------|Select|           |      |------+------+------+------+------+--------|
     * |   Ctl  |   r  |   a  |   e  |.  n  |   s  |------|           |------|   d  |.  o  |   t  |   i  |   h  |   Ctl  |
     * |--------+------+------+------+------+------| FIND |           | Emacs|------+------+------+------+------+--------|
     * |  Shift |   z  |   ,  |   u  |   k  |   j  |      |           | Alt+X|   m  |   c  |   x  |   .  |   /  |  Shift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   | LAT  |QWERTY| LGUI |   _  | Shift|                                       |M/Tab | APP  | RGUI |  CAPS|  RUS |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | Shft | Shft |       | Shft | Shft |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      | Ctrl |       | Ctrl |      |      |
     *                                 | BSPCE|  Tab |------|       |------| Ret  | SPC  |
     *                                 |CTRLER|  Ctrl|DL/Alt|       |INSAlt| Ctrl |CTRLER|
     *                                 `--------------------'       `--------------------'
     */
    [LAYER_KEYMACS] = LAYOUT_ergodox( // left fingers
                                      // top row
        KC_ESCAPE, KC_GRAVE, KC_COLON, KC_MINUS, KC_EXLM, KC_PLUS, LCTL(KC_G),
        // row 2
        KC_LALT, LT(LAYER_NUMPAD, KC_Q), KC_B, KC_P, KC_F, KC_G, EMACS_SELECT,
        // row 3
        KC_LCTL, LT(LAYER_AUXCHARS, KC_R), KC_A, KC_E, KC_N, KC_S,
        // row 4
        KC_LSHIFT, LSFT_T(KC_Z), KC_COMMA, KC_U, KC_K, LT(LAYER_FN, KC_J), KC_FIND,
        // row 5
        TG(LAYER_KEYMACS), _____, KC_LGUI, KC_UNDS, KC_LSHIFT,
        // left thumb top
        KC_LSHIFT, KC_LSHIFT, KC_LCTRL,
        // thumb low
        LT(LAYER_CONTROL, KC_BSPACE), CTL_T(KC_TAB), ALT_T(KC_DEL),
        // right fingers top
        TG(LAYER_NUMPAD), KC_ASTR, KC_QUES, KC_DQUO, KC_SCOLON, KC_EQUAL, KC_UNDO,
        // row 2
        OSL(LAYER_WM), KC_V, KC_W, KC_L, KC_Y, LT(LAYER_NUMPAD, KC_QUOTE), KC_RALT,
        // row 3
        KC_D, KC_O, KC_T, KC_I, LT(LAYER_AUXCHARS, KC_H), KC_RCTL,
        // row 4
        EMACS_ALTX, LT(LAYER_NUMPAD, KC_M), KC_C, KC_X, KC_DOT, RSFT_T(KC_SLASH), KC_RSHIFT,
        // row 5
        KC_LSHIFT, KC_EQUAL, KC_RGUI, KC_CAPSLOCK, TO(LAYER_RUSSIAN),
        // right thumb
        KC_LSHIFT, KC_LSHIFT, KC_RCTRL,
        // thumb 2
        ALT_T(KC_INS), CTL_T(KC_ENTER), LT(LAYER_CONTROL, KC_SPACE)),

    /* Symbol Layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |   `  |   :  |   -  |   !  |   +  |      |           |Numpad|   *  |   ?  |   "  |   ;  |   =  |   BSP  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |   ́  |   %  |   [  |   ]  |      |      |           |      |   |  |   ^  |   $  |   &  |   '  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |   @  |   (  |.  )  |      |------|           |------|   №  |.  {  |   }  |   #  |      |        |
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
    [LAYER_AUXCHARS] = LAYOUT_ergodox(
        // left fingers
        _____, TD(TD_GRAVEACCENT), KC_COLON, KC_MINUS, KC_EXLM, KC_PLUS, M(M_LAYER_IS_AUXCHARS),
        // row 2
        KC_LALT, M(ACCENT), KC_PERC, KC_LBRACKET, KC_RBRACKET, XXXXX, _____,
        // row 3
        KC_LCTL, M(RU_NOSIGN), KC_AT, KC_LPRN, KC_RPRN, XXXXX,
        // row 4
        KC_LSHIFT, XXXXX, KC_LABK, KC_UNDS, KC_TILD, KC_ENTER,
        // row 5
        _____, _____, _____, _____, _____, _____,
        // left thumb
        _____, _____, _____,
        // low
        LT(LAYER_CONTROL, KC_SPACE), _____, _____,
        // right fingers
        _____, KC_ASTR, KC_QUES, KC_DQUO, KC_SCOLON, KC_EQUAL, _____,
        // row 2
        _____, KC_PIPE, KC_CIRC, KC_DLR, KC_AMPR, KC_QUOTE, KC_RALT,
        // row 3
        KC_NO, KC_LCBR, KC_RCBR, KC_HASH, XXXXX, KC_RCTRL,
        // row 4
        _____, KC_ENTER, KC_EQUAL, KC_BSLASH, KC_RABK, XXXXX, KC_RSHIFT,
        // row 5
        _____, _____, _____, _____, _____,
        // right thumb
        _____, _____, _____,
        // thumb low
        _____, _____, LT(LAYER_CONTROL, KC_SPACE)),

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
        KC_ESCAPE, TD(TD_LELKILAPKI), TD(TD_TSE), KC_KP_MINUS, KC_MINUS, TD(TD_YO), KC_CAPSLOCK,
        // row 2
        KC_LALT, LT(LAYER_NUMPAD, KC_Q), KC_W, KC_E, KC_R, ALT_T(KC_S), _____,
        // row 3
        KC_LCTL, LT(LAYER_AUXCHARS_RU, KC_A), KC_F, KC_T, KC_D, RCTL_T(KC_G),
        // row 4
        KC_LSHIFT, LSFT_T(KC_Z), KC_6, KC_C, KC_V, LT(LAYER_AUXCHARS_RU, KC_B), _____,
        // row 5
        TO(LAYER_KEYMACS), TO(LAYER_KEYMACS), _____, KC_UNDS, _____,
        // left thumb=======
        _____, _____, _____,
        // th 2
        LT(LAYER_CONTROL, KC_SPACE), _____, _____,
        // right fingers
        _____, RU_ASTR, KC_9, TD(TD_HE), TD(TD_SCHCOLON), TD(TD_RELKILAPKI), _____,
        // row 2
        _____, ALT_T(KC_Y), KC_U, KC_I, KC_DOT, LT(LAYER_NUMPAD, KC_P), KC_RALT,
        // row 3
        LCTL_T(KC_H), KC_J, KC_K, KC_L, LT(LAYER_AUXCHARS_RU, KC_SCOLON), KC_RCTL,
        // row 4
        OSL(LAYER_FN), LT(LAYER_NUMPAD, KC_N), TD(TD_SHSIG), KC_COMMA, KC_7, RSFT_T(KC_QUOTE), KC_RSHIFT,
        // row 5
        _____, _____, _____, KC_CAPSLOCK, _____,
        // right thumb
        _____, _____, _____,
        // th 2
        _____, _____, LT(LAYER_CONTROL, KC_SPACE)),

    /* Symbol Layer for Russian layout
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |   `  |   :  |   -  |   !  |   +  |      |           |      |   *  |   ?  |   "  |   ;  |   =  |   BSP  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |   ́  |   %  |   [  |   ]  |      |      |           |      |   |  |   ^  |   $  |   &  |   '  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |   @  |   (  |.  )  |      |------|           |------|   №  |.  {  |   }  |   #  |      |        |
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
    [LAYER_AUXCHARS_RU] = LAYOUT_ergodox( // left fingers
                                          // row 1
        _____, TD(TD_GRAVEACCENT), KC_COLON, KC_MINUS, KC_EXLM, KC_PLUS, M(M_LAYER_IS_AUXCHARS_RU),
        // row 2
        KC_LALT, M(ACCENT), KC_PERC, KC_LBRACKET, KC_RBRACKET, _____, _____,
        // row 3
        KC_LCTL, XXXXX, KC_AT, KC_LPRN, KC_RPRN, KC_NO,
        // row 4
        KC_LSHIFT, XXXXX, KC_LABK, KC_UNDS, KC_TILD, KC_ENTER, _____,
        // row 5
        _____, _____, _____, SFT_T(KC_9), KC_TAB,
        // left thumb
        _____, _____, _____,
        // th 2
        LT(LAYER_CONTROL, KC_SPACE), _____, _____,
        // right fingers
        _____, KC_ASTR, KC_QUES, KC_LBRACKET, KC_SCOLON, KC_EQUAL, _____,
        // row 2
        _____, KC_PIPE, KC_CIRC, KC_DLR, KC_AMPR, KC_QUOTE, KC_RALT,
        // row 3
        M(RU_NOSIGN), KC_LCBR, KC_RCBR, KC_HASH, KC_NO, KC_RCTRL,
        // row 4
        OSL(LAYER_FN), KC_ENTER, KC_EQUAL, KC_BSLASH, KC_RABK, KC_SLASH, KC_RSHIFT,
        // row 5
        KC_TAB, _____, _____, _____, _____,
        // right thumb
        _____, _____, _____, _____, _____, LT(LAYER_CONTROL, KC_ENTER)),

    // Mouse control
    [LAYER_MOUSE] = LAYOUT_ergodox( // left fingers
        _____, _____, _____, _____, _____, _____, KC_MUTE,
        // row 2
        _____, _____, KC_MS_BTN3, _____, LGUI(RCTL(RALT(KC_F))), _____, KC_VOLU,
        // row 3
        _____, _____, KC_MS_BTN1, KC_MS_UP, KC_MS_DOWN, _____,
        // row 4
        _____, _____, KC_MS_BTN2, KC_MS_WH_UP, KC_MS_WH_DOWN, _____, KC_VOLD,
        // row 5
        _____, TO(LAYER_KEYMACS), KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1,
        // left thumb
        _____, _____, _____, _____, _____, _____,
        // right fingers
        KC_MS_ACCEL0, _____, _____, _____, _____, _____, _____,
        // row 2
        KC_MS_ACCEL2, _____, KC_MS_BTN1, KC_MS_BTN2, KC_MS_BTN3, _____, _____,
        // row 3
        _____, KC_MS_LEFT, KC_MS_RIGHT, KC_MS_BTN1, _____, _____,
        // row 4
        KC_MS_ACCEL1, KC_ENTER, KC_MS_WH_LEFT, KC_MS_WH_RIGHT, KC_MS_BTN2, _____, _____,
        // row 5
        _____, KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, _____,
        // right thumb
        _____, _____, _____, _____, _____, _____),

    /* Numpad for the right hand (left hand the same as for Symbols layer)
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |   `  |   :  |   -  |   !  |   +  |      |           |      |   *  |   7  |   8  |   9  |   =  |   BSP  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |   ́  |   %  |   [  |   ]  |      |      |           |      |   |  |   4  |   5  |   6  |   '  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |   @  |   (  |.  )  |      |------|           |------|   №  |.  1  |   2  |   3  |   -  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |   ,  |   _  |   ~  |      |      |           |      |      |   =  |   0  |   .  |   /  |        |
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
    [LAYER_NUMPAD] = LAYOUT_ergodox( // left fingers
                                     // top row
        KC_NUMLOCK, TD(TD_GRAVEACCENT), KC_COLON, KC_MINUS, KC_EXLM, KC_PLUS, M(M_LAYER_IS_NUMPAD),
        // row 2
        KC_LALT, M(ACCENT), KC_PERC, KC_LBRACKET, KC_RBRACKET, XXXXX, _____,
        // row 3
        KC_LCTL, XXXXX, KC_AT, KC_LPRN, KC_RPRN, XXXXX,
        // row 4
        KC_LSHIFT, XXXXX, KC_LABK, KC_UNDS, KC_TILD, KC_TAB, _____,
        // row 5
        _____, _____, _____, _____, _____,
        // left thumb
        _____, _____, _____,
        // th 2
        LT(LAYER_CONTROL, KC_SPACE), LT(LAYER_WM, KC_TAB), _____,
        // right fingers
        _____, KC_KP_ASTERISK, KC_7, KC_8, KC_9, KC_EQUAL, KC_BSPACE,
        // row 2
        KC_NUMLOCK, KC_PIPE, KC_4, KC_5, KC_6, KC_QUOTE, KC_RALT,
        // row 3
        M(RU_NOSIGN), KC_1, KC_2, KC_3, KC_KP_MINUS, KC_RCTRL,
        // row 4
        KC_KP_SLASH, KC_KP_ENTER, KC_KP_EQUAL, KC_0, KC_KP_DOT, _____, KC_RSHIFT,
        // row 5
        _____, _____, _____, _____, _____,
        // right thumb
        _____, _____,
        _____
        // th 2
        ,
        _____, LT(LAYER_WM, KC_ENTER), LT(LAYER_CONTROL, KC_SPACE)),

    /* Control layer for line and page navigation
     * based on https://github.com/keyboard-ergonomics/control-layer.
     * Copypaste keys for Emacs (Alt+W,Ctl+W,Ctl+Y) and WordStar-like (Ctl+C,Ctl+X,Ctl+V) bindinds.
     * Copypaste keys for right hand because I'm using trackball by left hand.
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |  Esc   |      |      |      |      |      |      |           |      |      | MLClk| MRClk| MMClk|      | CAPSLCK|
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
    [LAYER_CONTROL] = LAYOUT_ergodox( // left fingers
                                      // top row
        TO(LAYER_MEDIA), XXXXX, XXXXX, XXXXX, XXXXX, _____, _____,
        // row 2
        _____, XXXXX, KC_LEFT, KC_UP, KC_RIGHT, KC_ESCAPE, KC_LGUI,
        // row 3
        _____, RCTL(KC_R), KC_HOME, KC_UP, KC_DOWN, KC_END,
        // row 4
        _____, RCTL(KC_Z), RSFT(KC_ENTER), KC_PGUP, KC_PGDOWN, KC_ENTER, LCTL(KC_QUES),
        // row 5
        TO(LAYER_KEYMACS), XXXXX, XXXXX, XXXXX, KC_TAB,
        // left thumb
        KC_SPACE, KC_TAB, _____, _____, _____, _____,
        // right fingers
        _____, RGUI(KC_F6), KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, XXXXX, KC_CAPSLOCK,
        // row 2
        KC_LGUI, LCTL(KC_V), LALT(KC_W), LCTL(KC_W), LCTL(KC_Y), XXXXX, _____,
        // row 3
        KC_DELETE, KC_LEFT, KC_RIGHT, KC_BSPACE, KC_TAB, _____,
        // row 4
        XXXXX, KC_ENTER, LCTL(KC_C), LCTL(KC_X), LCTL(KC_V), LCTL(KC_SLASH), _____,
        // row 5
        KC_TAB, XXXXX, XXXXX, XXXXX, XXXXX,
        // right thumb
        _____, _____, _____, _____, KC_ENTER, KC_SPACE),

    /* Fn keys for the right hand (left hand the same as for Symbols layer)
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |   `  |   :  |   -  |   !  |   +  |      |           |      |   *  |   F7 |   F8 |   F9 |   =  |   BSP  |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |   ́  |   %  |   [  |   ]  |      |      |           |      | Alt  |   F4 |   F5 |   F6 |   +  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |   @  |   (  |.  )  |      |------|           |------| Ctrl |.  F1 |   F2 |   F3 |   -  |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |   ,  |   _  |   ~  |      |      |           |      | Shift|      |  F10 |      |   /  |        |
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
    [LAYER_FN] = LAYOUT_ergodox( // left fingers
                                 // top row
        KC_NUMLOCK, TD(TD_GRAVEACCENT), KC_COLON, KC_KP_MINUS, KC_EXLM, KC_PLUS, M(M_LAYER_IS_NUMPAD),
        // row 2
        KC_LALT, M(ACCENT), KC_PERC, KC_LBRACKET, KC_RBRACKET, KC_NO, _____,
        // row 3
        KC_LCTL, KC_NO, KC_AT, KC_LPRN, KC_RPRN, KC_NO,
        // row 4
        KC_LSHIFT, KC_NO, KC_LABK, KC_UNDS, KC_TILD, KC_TAB, _____,
        // row 5
        TO(LAYER_KEYMACS), _____, _____, _____, _____,
        // left thumb
        _____, _____, _____,
        // th 2
        LT(LAYER_CONTROL, KC_SPACE), LT(LAYER_WM, KC_TAB), _____,
        // right fingers
        _____, KC_KP_ASTERISK, KC_F7, KC_F8, KC_F9, KC_EQUAL, KC_BSPACE,
        // row 2
        KC_RALT, KC_PIPE, KC_F4, KC_F5, KC_F6, KC_KP_PLUS, KC_RALT,
        // row 3
        KC_RCTL, KC_F1, KC_F2, KC_F3, KC_KP_MINUS, KC_RCTRL,
        // row 4
        KC_RSHIFT, _____, KC_F11, KC_F10, KC_F12, _____, KC_RSHIFT,
        // row 5
        _____, _____, _____, _____, TO(LAYER_RUSSIAN),
        // right thumb
        _____, _____, _____,
        // th 2
        _____, LT(LAYER_WM, KC_ENTER), LT(LAYER_CONTROL, KC_SPACE)),

    // Media controls and Colors
    // TODO adapt more for mpv
    [LAYER_MEDIA] = LAYOUT_ergodox( // left fingers
                                    // top row
        _____, _____, _____, _____, _____, _____, M(M_LAYER_IS_MEDIA),
        // row 2
        _____, _____, _____, _____, _____, _____, _____,
        // row 3
        _____, _____, _____, _____, _____, _____,
        // row 4
        _____, _____, _____, _____, _____, _____, _____,
        // row 5
        TO(LAYER_KEYMACS), _____, _____, _____, _____,
        // left thumb
        RGB_MOD, _____, _____,
        // th 2
        RGB_VAD, RGB_VAI, _____,
        // right fingers
        _____, RGB_0000FF, RGB_008000, RGB_FFA500, RGB_800080, RGB_FF0000, _____,
        // row 2
        _____, _____, _____, _____, _____, _____, _____,
        // row 3
        _____, _____, _____, _____, _____, _____,
        // row 4
        _____, _____, _____, _____, _____, _____, _____,
        // row 5
        _____, _____, _____, _____, _____,
        // right thumb
        RGB_TOG, RGB_SLD, _____,
        // th 2
        _____, RGB_HUD, RGB_HUI),

    // QWERTY for reference and for guests
    [LAYER_QWERTY] = LAYOUT_ergodox( // left fingers
                                     // row 1
        KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, M(M_LAYER_IS_QWERTY),
        // row 2
        KC_LALT, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_TAB,
        // row 3
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,
        // row 4
        KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, _____,
        // row 5
        TO(LAYER_KEYMACS), _____, _____, KC_LGUI, KC_LALT,
        // left thumb
        _____, _____, _____, KC_SPACE, KC_ENTER, _____,
        // right fingers
        TO(LAYER_KEYMACS), KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPACE,
        // row 2
        KC_TAB, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LALT,
        // row 3
        KC_H, KC_J, KC_K, KC_L, KC_QUES, KC_LCTL,
        // row 4
        _____, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_RSHIFT,
        // row 5
        _____, KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT,
        // right thumb
        _____, _____, _____,
        // th 2
        _____, KC_ENTER, KC_SPACE),

    // Window manager control (currently for Spectr WM)
    [LAYER_WM] = LAYOUT_ergodox( // left fingers
                                 // row 1

        TO(LAYER_KEYMACS), KC_GRAVE, KC_COLON, KC_MINUS, KC_EXLM, KC_PLUS, KC_K,
        // row 2
        ALT_T(KC_TAB), KC_Q, KC_B, KC_P, KC_F, KC_RALT, LCTL(KC_ENTER),
        // row 3
        KC_LCTL, LT(LAYER_NUMPAD, KC_R), KC_A, KC_E, KC_N, KC_RCTL,
        // row 4
        KC_LSHIFT, KC_Z, KC_COMMA, KC_U, KC_K, KC_RSHIFT, KC_F,
        // row 5
        TG(LAYER_KEYMACS), _____, TO(LAYER_QWERTY), KC_UNDS, KC_TAB,
        // left thumb
        LCTL(KC_G), KC_WWW_BACK, LCTL(KC_V),
        // th 2
        LALT(KC_SPACE), _____, KC_INS,
        // right fingers
        KC_K, KC_ASTR, KC_7, KC_8, KC_9, KC_EQUAL, KC_BSPACE,
        // row 2
        RCTL(KC_ENTER), KC_LALT, KC_4, KC_5, KC_6, KC_QUOTE, KC_RALT,
        // row 3
        KC_LCTL, KC_1, KC_2, KC_3, LT(LAYER_NUMPAD, KC_H), KC_RCTL,
        // row 4
        KC_F, KC_LSHIFT, KC_C, KC_0, KC_DOT, KC_SLASH, KC_RSHIFT,
        // row 5
        KC_TAB, KC_UNDS, _____, _____, TO(LAYER_RUSSIAN),
        // right thumb
        KC_WWW_FORWARD, RCTL(KC_W), KC_WWW_REFRESH,
        // th 2
        KC_DELETE, _____, LALT(KC_SPACE)),
};

const uint16_t PROGMEM fn_actions[] = {[1] = ACTION_LAYER_TAP_TOGGLE(1)};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        switch (id) {
            case ACCENT:
                return (MACRO(D(CAPSLOCK), T(A), U(CAPSLOCK), END));

            case RU_NOSIGN:
                return (MACRO(T(SCROLLLOCK), T(3), T(SCROLLLOCK), END));

            case KEYNAV: // run Keynav (it is non default keybinding)
                return (MACRO(D(LCTL), D(LALT), T(N), U(LCTL), U(LALT), END));

            case M_EMACS_SELECT: // Emacs: reset the selection and activate a new one
                return (MACRO(D(LCTL), T(G), T(SPC), U(LCTL), END));

            case M_EMACS_BLOCK_SELECT: // Emacs: reset the selection and activate a new block selection
                return (MACRO(D(LCTL), T(G), T(X), U(LCTL), T(SPC), END));

            case M_WMUP:
                return (MACRO(D(LALT), T(UP), U(LALT), END));

            case M_WMDOWN:
                return (MACRO(D(LALT), T(DOWN), U(LALT), END));

            case M_LAYER_IS_KEYMACS:
                SEND_STRING("Layer is Keymacs [0]");
                break;

            case M_LAYER_IS_AUXCHARS:
                SEND_STRING("Layer is Aux Chars [1]");
                break;

            case M_LAYER_IS_RUSSIAN:
                SEND_STRING("Layer is Russian [2]");
                break;

            case M_LAYER_IS_AUXCHARS_RU:
                SEND_STRING("Layer is Aux Chars Rus [3]");
                break;

            case M_LAYER_IS_MOUSE:
                SEND_STRING("Layer is Mouse [4]");
                break;

            case M_LAYER_IS_QWERTY:
                SEND_STRING("Layer is QWERTY [5]");
                break;

            case M_LAYER_IS_NUMPAD:
                SEND_STRING("Layer is Numpad [6]");
                break;

            case M_LAYER_IS_CONTROL:
                SEND_STRING("Layer is Control [7]");
                break;

            case M_LAYER_IS_MEDIA:
                SEND_STRING("Layer is Media and Color [8]");
                break;

            case M_LAYER_IS_FN:
                SEND_STRING("Layer is Function keys [9]");
                break;

            case M_LAYER_IS_WM:
                SEND_STRING("Layer is WM [B]");
                break;
        }
    }
    return (MACRO_NONE);
};

uint8_t cur_layer = LAYER_KEYMACS;

layer_state_t layer_state_set_user(layer_state_t state) {
    static uint8_t old_layer = 0xff;
    cur_layer                = get_highest_layer(state);

    switch (cur_layer) {
        case LAYER_RUSSIAN:
            // Turn on RUS layout on enter to Russian layer.
            if (old_layer != LAYER_RUSSIAN) {
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
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
            case CTL_T(KC_TAB):
            case CTL_T(KC_ENTER):
            case ALT_T(KC_DEL):
            case ALT_T(KC_INS):
            case KC_APP:
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
            case CTL_T(KC_TAB):
            case CTL_T(KC_ENTER):
            case ALT_T(KC_DEL):
            case ALT_T(KC_INS):
            case KC_APP:
                layer_off(LAYER_KEYMACS);
                layer_on(LAYER_RUSSIAN);
                back_to_ussr = false;
        }
    }

    // Macros
    switch (keycode) {
        case KC_LSHIFT:
        case KC_RSHIFT:
            if (record->event.pressed)
                ergodox_right_led_3_on();
            else
                ergodox_right_led_3_off();
            return (true);
        case KC_LCTL:
        case KC_RCTL:
        case CTL_T(KC_TAB):
        case CTL_T(KC_ENTER):
            if (record->event.pressed)
                ergodox_right_led_2_on();
            else
                ergodox_right_led_2_off();
            return (true);
        case KC_LALT:
        case KC_RALT:
        case ALT_T(KC_DEL):
        case ALT_T(KC_INS):
            if (record->event.pressed)
                ergodox_right_led_1_on();
            else
                ergodox_right_led_1_off();
            return (true);
        case RU_ASTR:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(XLAT) "*" SS_TAP(XRUS));
            }
            return (false);

        case EMACS_SELECT:
            if (!record->event.pressed) {
                // Emacs: reset the selection and activate a new one
                SEND_STRING(SS_LCTL("g "));
            }
            return (false);

        case EMACS_BLOCK_SELECT:
            if (!record->event.pressed) {
                SEND_STRING(SS_LCTL("gx") " ");
            }
            return (false);

        case EMACS_ALTX:
            if (!record->event.pressed) {
                SEND_STRING(SS_LALT("x"));
            }
            return (false);

        case EPRM:
            if (record->event.pressed) {
                eeconfig_init();
            }
            return (false);

        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return (false);

        case RGB_0000FF:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0x00, 0x00, 0xff);
#endif
            }
            return (false);

        case RGB_008000:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0x00, 0x80, 0x00);
#endif
            }
            return (false);
        case RGB_FFA500:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0xff, 0xa5, 0x00);
#endif
            }
            return (false);
        case RGB_800080:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0x80, 0x00, 0x80);
#endif
            }
            return (false);

            break;

        case RGB_FF0000:
            if (record->event.pressed) {
#ifdef RGBLIGHT_ENABLE
                rgblight_enable();
                rgblight_mode(1);
                rgblight_setrgb(0xff, 0x00, 0x00);
#endif
            }
            return (false);
    }
    return (true);
}

#define LEDOFF                 \
    ergodox_board_led_off();   \
    ergodox_right_led_1_off(); \
    ergodox_right_led_2_off(); \
    ergodox_right_led_3_off()

// implements scan hook
// use it only for fast actions!
void matrix_scan_user(void) {
    static uint32_t old_layer_state = 0xffff;

    if (layer_state == old_layer_state) {
        return;
    }
    old_layer_state = layer_state;
    uint8_t layer   = biton32(layer_state);

    switch (layer) {
        case LAYER_KEYMACS:
            LEDOFF;
            // rgblight_effect_christmas();
            rgblight_show_solid_color(0, 0, 0);
            break;

        case LAYER_CONTROL:
            LEDOFF;
            ergodox_right_led_1_on();
            rgblight_show_solid_color(0xff, 0x00, 0x00);
            break;

        case LAYER_AUXCHARS:
            LEDOFF;
            ergodox_right_led_3_on();
            rgblight_show_solid_color(0x00, 0x00, 0xff);
            break;

        case LAYER_RUSSIAN:
            LEDOFF;
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            rgblight_show_solid_color(0xff, 0x00, 0xff);
            break;

        case LAYER_AUXCHARS_RU:
            LEDOFF;
            ergodox_right_led_3_on();
            rgblight_show_solid_color(0x00, 0x00, 0xff);
            break;

        case LAYER_MOUSE:
            LEDOFF;
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_1_on();
            rgblight_show_solid_color(0x22, 0x00, 0x00);
            break;

        case LAYER_NUMPAD:
            LEDOFF;
            ergodox_right_led_2_on();
            rgblight_show_solid_color(0x00, 0xff, 0x00);
            break;

        case LAYER_FN:
            LEDOFF;
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            rgblight_show_solid_color(0x00, 0xa0, 0xa0);
            break;

        case LAYER_WM:
            LEDOFF;
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            // ergodox_right_led_3_on();
            // rgblight_effect_christmas();
            rgblight_show_solid_color(0x99, 0x77, 0x0A);
            break;

        default:
            LEDOFF;
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            rgblight_show_solid_color(0x20, 0x20, 0x10);
    }
};

// XXX I have stopped using it
// Grave vs accent sign
void dance_graveaccent(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
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
void dance_dash(qk_tap_dance_state_t *state, void *user_data) {
    uint8_t layer = biton32(layer_state); // get the current layer

    switch (state->count) {
        case 1:
            if (layer == LAYER_RUSSIAN) {
                TAP(LAT);
            }
            TAP(KC_MINUS);
            if (layer == LAYER_RUSSIAN) {
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
void dance_elkilapki_left(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
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
void dance_elkilapki_right(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
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
void dance_shsig(qk_tap_dance_state_t *state, void *user_data) {
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

// And finally the Dancings!
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_DASH]        = ACTION_TAP_DANCE_FN(dance_dash),
    [TD_GRAVEACCENT] = ACTION_TAP_DANCE_FN(dance_graveaccent),
    [TD_SHSIG]       = ACTION_TAP_DANCE_FN(dance_shsig),
    [TD_LELKILAPKI]  = ACTION_TAP_DANCE_FN(dance_elkilapki_left),
    [TD_RELKILAPKI]  = ACTION_TAP_DANCE_FN(dance_elkilapki_right),
    [TD_TSE]         = ACTION_TAP_DANCE_DOUBLE(KC_X, KC_5),        // ч/;
    [TD_HE]          = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_4), // х/"
    [TD_SCHCOLON]    = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_EQUAL),    // щ/:
    [TD_YO]          = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_TILD), // ч/;
};
