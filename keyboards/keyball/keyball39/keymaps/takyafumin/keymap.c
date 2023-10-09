/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// keymap layer number
enum keymap_layer {
  LBASE = 0,
  LMARK = 1,
  LNUM  = 2,
  LEXT  = 3,
  LEX2  = 4,
  LBALL = 5,
  LMS   = 6,
};

enum custom_keycodes {
    MY_L1= SAFE_RANGE,
    MY_L2,
    MY_ESC,
    MY_CTLA,
    MY_SCRL,
    MY_SPC,
};

// --------------------
// キーのalias
// --------------------
#define L1       KC_LNG1
#define L2       KC_LNG2
#define SPC      KC_SPC
#define ESC      KC_ESC
#define BS       KC_BSPC


#define CTL_A    LCTL_T(KC_A)
#define CTL_TAB  LCTL_T(KC_TAB)
#define CTL_SCN  LCTL_T(KC_SCLN)
#define GUI_X    LGUI_T(KC_X)
#define GUI_W    LGUI_T(KC_W)
#define GUICOMM  LGUI_T(KC_COMM)
#define ALT_C    RALT_T(KC_C)
#define ALTSLSH  RALT_T(KC_SLSH)
#define ALTDOT   RALT_T(KC_DOT)
#define SFTDEL   LSFT_T(KC_DEL)
#define SFTSPC   LSFT_T(KC_SPC)
#define SFTENT   LSFT_T(KC_ENT)
#define SFTBS    LSFT_T(KC_BSPC)
#define SFTESC   LSFT_T(KC_ESC)
#define SFT_L1   LSFT_T(L1)
#define SFTSLSH  RSFT_T(KC_SLSH)
#define SFTZ     RSFT_T(KC_Z)


#define F_MARK   LT(LMARK, KC_F)
#define J_MARK   LT(LMARK, KC_J)
#define ESCBALL  LT(LBALL, KC_ESC)
#define ESCLEXT  LT(LEXT, KC_ESC)
#define ESCNUM   LT(LNUM, KC_ESC)
#define V_NUM    LT(LNUM, KC_V)
#define M_NUM    LT(LNUM, KC_M)
#define S_NUMS   LT(LNUM, KC_S)
#define L_NUMS   LT(LNUM, KC_L)
#define SPCLEXT  LT(LEXT, SPC)
#define L1_LEXT  LT(LEX2, L1)
#define L2_LEXT  LT(LEXT, L2)
#define L1_LBALL LT(LBALL, L1)
#define L2_LBALL LT(LBALL, L2)
#define ENT_LEX2 LT(LEX2, KC_ENT)


#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [LBASE] = LAYOUT_universal(
    KC_Q     , GUI_W    , KC_E     , KC_R     , KC_T      ,                           KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    CTL_A    , KC_S     , KC_D     , F_MARK   , KC_G      ,                           KC_H     , J_MARK   , KC_K     , KC_L     , CTL_SCN  ,
    SFTZ     , GUI_X    , ALT_C    , V_NUM    , KC_B      ,                           KC_N     , M_NUM    , KC_COMM  , ALTDOT   , SFTSLSH  ,
    MY_SCRL  , XXXXXXX  , XXXXXXX  , KC_ESC   , MY_SPC    , MY_L2    ,     MY_L1    , SFTENT   , XXXXXXX  , XXXXXXX  , XXXXXXX  , MO(LBALL)
  ),

  [LMARK] = LAYOUT_universal(
    KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC   ,                           KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_EQL   ,  KC_MINS  ,
    _______  , KC_LBRC  , KC_TILD  , KC_RBRC  , KC_PIPE   ,                           XXXXXXX  , KC_LPRN  , KC_QUOT  , KC_RPRN  ,  KC_COLN  ,
    _______  , KC_LCBR  , KC_GRV   , KC_RCBR  , KC_BSLS   ,                           XXXXXXX  , KC_DQT   , KC_LT    , KC_GT    ,  KC_QUES  ,
    _______  , _______  , _______  , _______  , KC_LSFT   , _______  ,     _______  , KC_RSFT  , _______  , _______  , _______  ,  _______
  ),

  [LNUM] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5      ,                           KC_6     , KC_7     , KC_8     , KC_9     ,  KC_MINS  ,
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5     ,                           KC_DOT   , KC_4     , KC_5     , KC_6     ,  KC_COLN  ,
    KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10    ,                           KC_COMM  , KC_1     , KC_2     , KC_3     ,  KC_SLSH  ,
    _______  , _______  , _______  , _______  , KC_F11    , KC_F12   ,     KC_0     , KC_0     , _______  , _______  , _______  ,  _______
  ),

  [LEXT] = LAYOUT_universal(
    KC_ESC   , KC_LGUI  , EE_CLR   , QK_BOOT  ,  QK_RBT   ,                           KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   ,  KC_PSCR  ,
    CTL_TAB  , KC_BTN4  , KC_BTN2  , KC_BTN1  ,  _______  ,                           KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  ,  KC_ENT   ,
    _______  , _______  , _______  , L2       ,  MY_CTLA  ,                           _______  , L1       , _______  , KC_APP   ,  _______  ,
    _______  , _______  , _______  , _______  ,  _______  , SFTDEL   ,     BS       , _______  , _______  , _______  , _______  ,  _______
  ),

  [LEX2] = LAYOUT_universal(
    KC_ESC   , KC_LGUI  , EE_CLR   , QK_BOOT  ,  QK_RBT   ,                           _______  , _______  , _______  , _______  ,  KC_PSCR  ,
    CTL_TAB  , KC_BTN4  , KC_BTN2  , KC_BTN1  ,  _______  ,                           KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  ,  _______  ,
    _______  , _______  , _______  , MY_CTLA  ,  _______  ,                           _______  , _______  , _______  , _______  ,  _______  ,
    _______  , _______  , _______  , _______  ,  _______  , SFTDEL   ,     BS       , _______  , _______  , _______  , _______  ,  _______
  ),

  [LBALL] = LAYOUT_universal(
    RGB_TOG  , _______  , DT_UP    , DT_DOWN  ,  DT_PRNT  ,                           RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  ,  SCRL_DVI ,                           RGB_M_K  , RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  ,  SCRL_DVD ,                           CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  ,  _______  , _______  ,     _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),

  [LMS] = LAYOUT_universal(
    _______  , _______  , _______  , _______  ,  _______  ,                           _______  , _______  , _______  , _______  ,  _______  ,
    _______  , KC_BTN4  , KC_BTN2  , KC_BTN1  ,  _______  ,                           _______  , _______  , _______  , _______  ,  _______  ,
    _______  , _______  , _______  , _______  ,  _______  ,                           KC_BTN4  , KC_BTN1  , KC_BTN2  , _______  ,  _______  ,
    _______  , _______  , _______  , _______  ,  _______  , _______  ,     _______  , _______  , _______  , _______  , _______  ,  _______
  ),

  // [5] = LAYOUT_universal(
  //   _______  , _______  , _______  , _______  ,  _______  ,                           _______  , _______  , _______  , _______  ,  _______  ,
  //   _______  , _______  , _______  , _______  ,  _______  ,                           _______  , _______  , _______  , _______  ,  _______  ,
  //   _______  , _______  , _______  , _______  ,  _______  ,                           _______  , _______  , _______  , _______  ,  _______  ,
  //   _______  , _______  , _______  , _______  ,  _______  , _______  ,     _______  , _______  , _______  , _______  , _______  ,  _______
  // ),
};
// clang-format on

// layer_state_t layer_state_set_user(layer_state_t state) {
//     // Auto enable scroll mode when the highest layer is 3
//     keyball_set_scroll_mode(get_highest_layer(state) == LBALL);
//     return state;
// }
void pointing_device_init_user(void) {
    // set_auto_mouse_layer(LMS); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif


static struct {
    uint16_t keycode;
    uint16_t time;
} last_pressed = {0, 0};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool in_tapping_term = (record->event.time - last_pressed.time) <= TAPPING_TERM;

    switch (keycode) {
        case MY_SPC:
            if (record->event.pressed) {
               last_pressed.keycode = keycode;
               last_pressed.time = record->event.time;
               layer_on(LEXT);
           } else {
               layer_off(LEXT);
               if (in_tapping_term) {
                   tap_code(KC_SPC);
               }
           }
           return false;
           break;

        case MY_L2:
            if (record->event.pressed) {
               last_pressed.keycode = keycode;
               last_pressed.time = record->event.time;
               layer_on(LEXT);
           } else {
               layer_off(LEXT);
               if (in_tapping_term) {
                   tap_code(KC_LNG2);
               }
           }
           return false;
           break;

        case MY_L1:
           if (record->event.pressed) {
               last_pressed.keycode = keycode;
               last_pressed.time = record->event.time;
               layer_on(LEX2);
           } else {
               layer_off(LEX2);
               if (in_tapping_term) {
                   tap_code(KC_LNG1);
               }
           }
           return false;
           break;

        case MY_CTLA:
           if (record->event.pressed) {
               register_code(KC_RCTL);
               tap_code(KC_A);
           } else {
               unregister_code(KC_RCTL);
           }
           return false;
           break;

        case MY_SCRL:
           if (record->event.pressed) {
                keyball_set_scroll_mode(true);
           } else {
                keyball_set_scroll_mode(false);
           }
           return false;
           break;
    }

    // set_keylog(keycode, record);
    return true;
}
