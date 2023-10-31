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
  LNUM = 2,
  LEXT = 3,
  LCONF = 4,
  LBALL = 5,
};

enum custom_keycodes {
  MY_L1 = SAFE_RANGE,
  MY_L2,
  MY_CTLA,
  MY_SCRL,
  MY_TGCPI,
  MY_TGCPU,
};

// --------------------
// キーのalias
// --------------------
#define L1  KC_LNG1
#define L2  KC_LNG2
#define SPC KC_SPC
#define ESC KC_ESC
#define ENT KC_ENT
#define BS  KC_BSPC

// Control
#define CTL_A   LCTL_T(KC_A)
#define CTL_TAB LCTL_T(KC_TAB)
#define CTL_SCN LCTL_T(KC_SCLN)

// GUI
#define GUI_W   LGUI_T(KC_W)
#define GUI_DOT LGUI_T(KC_DOT)

// ALT
#define ALT_E  RALT_T(KC_E)
#define ALT_L  RALT_T(KC_L)
#define ALT_K  RALT_T(KC_K)
#define ALT_CM RALT_T(KC_COMM)

// Shift
#define SF_J    LSFT_T(KC_J)
#define SF_F    LSFT_T(KC_F)
#define SF_Z    LSFT_T(KC_Z)
#define SF_SL   LSFT_T(KC_SLSH)
#define SF_QUOT LSFT_T(KC_QUOT)
#define SF_GRV  LSFT_T(KC_GRV)
#define SFTDEL  LSFT_T(KC_DEL)
#define SFTSPC  LSFT_T(KC_SPC)
#define SFTENT  LSFT_T(KC_ENT)
#define SFTBS   LSFT_T(KC_BSPC)
#define SF_RPRN LSFT_T(KC_RPRN)
#define SF_DOWN LSFT_T(KC_DOWN)

// Layer
#define F_MARK  LT(LMARK, KC_F)
#define J_MARK  LT(LMARK, KC_J)
#define V_MARK  LT(LMARK, KC_V)
#define M_MARK  LT(LMARK, KC_M)
#define ESCLEXT LT(LEXT, KC_ESC)

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [LBASE] = LAYOUT_universal(
    KC_Q     , GUI_W    , KC_E     , KC_R     , KC_T      ,                           KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    CTL_A    , KC_S     , KC_D     , SF_F     , KC_G      ,                           KC_H     , SF_J     , ALT_K    , ALT_L    , CTL_SCN  ,
    SF_Z     , KC_X     , KC_C     , KC_V     , KC_B      ,                           KC_N     , KC_M     , ALT_CM   , GUI_DOT  , SF_SL    ,
    MY_SCRL  , TG(LCONF), TG(LNUM) , ESCLEXT  , MY_L2     , SFTSPC   ,     ENT      , MY_L1    , XXXXXXX  , XXXXXXX  , XXXXXXX  , TG(LBALL)
  ),

  [LMARK] = LAYOUT_universal(
    KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC   ,                           KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_EQL   ,  KC_MINS  ,
    CTL_TAB  , KC_LPRN  , _______  , SF_RPRN  , KC_BTN1   ,                           KC_LEFT  , SF_DOWN  , KC_UP    , KC_RGHT  ,  KC_COLN  ,
    KC_GRV   , KC_LBRC  , _______  , KC_RBRC  , KC_BTN2   ,                           KC_BSLS  , KC_QUOT  , KC_LT    , KC_GT    ,  S(KC_SLSH),
    KC_DEL   , _______  , _______  , KC_DEL   , KC_LSFT   , KC_BTN4  ,     BS       , KC_RSFT  , _______  , _______  , _______  ,  _______
  ),

  // [LMARK] = LAYOUT_universal(
  //   KC_EXLM  , KC_AT    , KC_HASH  , KC_DLR   , KC_PERC   ,                           KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_EQL   ,  KC_MINS  ,
  //   CTL_TAB  , KC_LBRC  , SF_GRV   , KC_RBRC  , _______   ,                           KC_DQUO  , KC_LPRN  , SF_QUOT  , KC_RPRN  ,  KC_COLN  ,
  //   SF_Z     , KC_LCBR  , KC_TILD  , KC_RCBR  , _______   ,                           KC_BSLS  , KC_PIPE  , KC_LT    , KC_GT    ,  S(KC_SLSH),
  //   KC_DEL   , _______  , _______  , KC_DEL   , KC_LSFT   , _______  ,     SFTBS    , KC_RSFT  , _______  , _______  , _______  ,  _______
  // ),

  [LNUM] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5      ,                           KC_6     , KC_7     , KC_8     , KC_9     ,  KC_MINS  ,
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5     ,                           KC_DOT   , KC_4     , KC_5     , KC_6     ,  KC_COLN  ,
    KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10    ,                           KC_COMM  , KC_1     , KC_2     , KC_3     ,  KC_SLSH  ,
    KC_F12   , KC_F11   , _______  , KC_DEL   , KC_0      , _______  ,     _______  , KC_0     , _______  , _______  , _______  ,  _______
  ),

  [LEXT] = LAYOUT_universal(
    KC_ESC   , KC_LGUI  , KC_WH_U  , EE_CLR   ,  _______  ,                           KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   ,  KC_PSCR  ,
    CTL_TAB  , KC_BTN2  , KC_WH_D  , KC_BTN1  ,  _______  ,                           KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  ,  KC_ENT   ,
    MY_CTLA  , _______  , _______  , _______  ,  QK_BOOT  ,                           _______  , _______  , _______  , KC_APP   ,  _______  ,
    _______  , _______  , _______  , _______  ,  _______  , SFTDEL   ,     SFTBS    , _______  , _______  , _______  , _______  ,  _______
  ),

  [LCONF] = LAYOUT_universal(
    RGB_TOG  , _______  , DT_UP    , DT_DOWN  ,  DT_PRNT  ,                           _______  , _______  , _______  , _______  , _______ ,
    _______  , _______  , _______  , _______  ,  SCRL_DVI ,                           _______  , _______  , _______  , _______  , RGB_M_TW ,
    _______  , _______  , _______  , _______  ,  SCRL_DVD ,                           CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    _______  , _______  , _______  , _______  ,  _______  , _______  ,     _______  , _______  , _______  , _______  , _______  , _______
  ),

  [LBALL] = LAYOUT_universal(
    _______  , _______  , KC_WH_U  , _______  ,  _______  ,                           _______  , _______  , _______  , _______  ,  _______  ,
    _______  , KC_BTN2  , KC_WH_D  , KC_BTN1  ,  _______  ,                           KC_BTN4  , _______  , _______  , _______  ,  _______  ,
    _______  , _______  , _______  , _______  ,  _______  ,                           _______  , MY_TGCPI , MY_TGCPU , _______  ,  _______  ,
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

// auto mouse feature
void pointing_device_init_user(void) {
  // always required before the auto mouse feature will work
  set_auto_mouse_enable(true);
}
#ifdef OLED_ENABLE

#include "lib/oledkit/oledkit.h"

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
  bool in_tapping_term =
      (record->event.time - last_pressed.time) <= TAPPING_TERM;

  switch (keycode) {

  case MY_L2:
    if (record->event.pressed) {
      last_pressed.keycode = keycode;
      last_pressed.time = record->event.time;
      layer_on(LMARK);
    } else {
      layer_off(LMARK);
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
      layer_on(LNUM);
    } else {
      layer_off(LNUM);
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
      layer_move(LBASE);
    }
    return false;
    break;

  case MY_TGCPI:
    if (record->event.pressed) {
      last_pressed.keycode = keycode;
      last_pressed.time = record->event.time;
    } else {
      if (in_tapping_term) {
        pointing_device_set_cpi(1);
      }
    }
    return false;
    break;

  case MY_TGCPU:
    if (record->event.pressed) {
      last_pressed.keycode = keycode;
      last_pressed.time = record->event.time;
    } else {
      if (in_tapping_term) {
        pointing_device_set_cpi(5);
      }
    }
    return false;
    break;
  }

  // set_keylog(keycode, record);
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {

  uint8_t layer = biton32(state);
  switch (layer) {
  case LBASE:
    rgblight_sethsv(HSV_OFF);
    break;
  case LEXT:
    rgblight_sethsv(HSV_CYAN);
    break;
    case LMARK:
    rgblight_sethsv(HSV_BLUE);
    break;
  case LNUM:
    rgblight_sethsv(HSV_GREEN);
    break;
  case LBALL:
    rgblight_sethsv(HSV_PURPLE);
    break;
  }

  return state;
}
