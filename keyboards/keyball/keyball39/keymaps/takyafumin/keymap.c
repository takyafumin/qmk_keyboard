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
    _BASE  = 0,
    _LEFT  = 1,
    _RIGHT = 2,
    _EXTRA = 3,
    _NUMS  = 4,
    _LBALL = 5,
};

enum custom_keycodes {
    MAC_PRSC = SAFE_RANGE,
    MN_JP,
    MN_EN,
    MY_SCRL,
};

// --------------------
// キーのalias
// --------------------
// basic
#define SPC      KC_SPC
#define TAB      KC_TAB
#define ESC      KC_ESC
#define ENT      KC_ENT
#define BS       KC_BSPC
#define DEL      KC_DEL
#define JP       KC_LNG1
#define EN       KC_LNG2

// modifier
#define CTLTAB   RCTL_T(TAB)
#define S_SPC    LSFT_T(SPC)
#define S_ENT    LSFT_T(ENT)
#define S_BS     LSFT_T(BS)
#define GUIESC   LGUI_T(ESC)

// home mod key left
#define SFT_F    LSFT_T(KC_F)
#define ALT_D    RALT_T(KC_D)
#define GUI_S    LGUI_T(KC_S)
#define CTL_A    LCTL_T(KC_A)

// home mod key right
#define SFT_J    LSFT_T(KC_J)
#define ALT_K    RALT_T(KC_K)
#define GUI_L    LGUI_T(KC_L)
#define CTLSCN   RCTL_T(KC_SCLN)

// Layer
#define LEFT     MO(_LEFT)
#define RIGHT    MO(_RIGHT)
#define EXTRA    MO(_EXTRA)
#define NUMS     MO(_NUMS)
#define LT_EN    LT(LEFT, EN)
#define RT_JP    LT(RIGHT, JP)
#define BALL     MO(_LBALL)
#define EXT_0    LT(EXTRA, KC_0)
#define EXTMINS  LT(EXTRA, KC_MINS)

// OSM/OSL
#define TO_BASE  TO(_BASE)
#define TO_EXT   TO(_EXTRA)
#define OSM_SFT  OSM(MOD_LSFT)
#define OSM_CTL  OSM(MOD_LCTL)
#define OSM_ALT  OSM(MOD_LALT)
#define OSM_GUI  OSM(MOD_LGUI)

// --------------------
// custom keyterms
// --------------------
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    // case CTL_A:
    case ALT_D:
    case ALT_K:
    case GUI_S:
    case GUI_L:
      return TAPPING_TERM + 50;

    default:
      return TAPPING_TERM;
  }
}

// #include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [_BASE] = LAYOUT_universal(
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T      ,                           KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    CTL_A    , GUI_S    , ALT_D    , SFT_F    , KC_G      ,                           KC_H     , SFT_J    , ALT_K    , GUI_L    , CTLSCN   ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B      ,                           KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    BALL     , TG(NUMS) , XXXXXXX  , GUIESC   , MN_EN     , S_SPC    ,     S_ENT    , MN_JP    , XXXXXXX  , XXXXXXX  , XXXXXXX  , KC_TAB
  ),

  [_LEFT] = LAYOUT_universal(
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5      ,                           KC_6     , KC_7     , KC_8     , KC_9     ,  KC_0     ,
    OSM_CTL  , OSM_GUI  , OSM_ALT  , OSM_SFT  , KC_BSLS   ,                           KC_LEFT  , KC_DOWN  , KC_UP    , KC_RIGHT ,  KC_QUOT  ,
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , KC_PIPE   ,                           KC_EQL   , KC_MINS  , KC_LT    , KC_GT    ,  KC_QUES  ,
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    _______  , _______  , _______  , _______  , _______   , _______  ,     S_BS     , EXTMINS  , DEL      , XXXXXXX  , XXXXXXX  ,  XXXXXXX
  ),

  [_RIGHT] = LAYOUT_universal(
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5      ,                           KC_6     , KC_7     , KC_8     , KC_9     ,  KC_0     ,
    KC_GRV   , XXXXXXX  , KC_LBRC  , KC_RBRC  , KC_BSLS   ,                           XXXXXXX  , OSM_SFT  , OSM_ALT  , OSM_GUI  ,  OSM_CTL  ,
    KC_TILD  , XXXXXXX  , KC_LCBR  , KC_RCBR  , KC_PIPE   ,                           XXXXXXX  , JP       , XXXXXXX  , XXXXXXX  ,  KC_SLSH  ,
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , EXT_0     , XXXXXXX  ,     _______  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,  XXXXXXX
  ),

  [_EXTRA] = LAYOUT_universal(
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5     ,                           KC_F6    , KC_F7    , KC_F8    , KC_F9    ,  KC_F10   ,
    MAC_PRSC , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX   ,                           KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   ,  KC_PSCR  ,
    KC_CAPS  , XXXXXXX  , QK_RBT   , EE_CLR   , QK_BOOT   ,                           KC_F11   , KC_F12   , KC_MENU  , KC_APP   ,  XXXXXXX  ,
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , TO_BASE   , XXXXXXX  ,     XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  , XXXXXXX  ,  XXXXXXX
  ),

  [_NUMS] = LAYOUT_universal(
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    RGB_TOG  , _______  , DT_UP    , DT_DOWN  ,  DT_PRNT  ,                           _______  , _______  , _______  , _______  , _______ ,
    _______  , _______  , _______  , _______  ,  SCRL_DVI ,                           _______  , _______  , _______  , _______  , RGB_M_TW ,
    _______  , _______  , _______  , _______  ,  SCRL_DVD ,                           CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    _______  , _______  , _______  , _______  ,  _______  , _______  ,     _______  , _______  , _______  , _______  , _______  , _______
  ),

  [_LBALL] = LAYOUT_universal(
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    _______  , _______  , _______  , _______  ,  _______  ,                           _______  , _______  , _______  , _______  ,  _______  ,
    _______  , KC_BTN4  , KC_BTN2  , KC_BTN1  ,  KC_BTN5  ,                           KC_WH_L  , KC_WH_D  , KC_WH_U  , KC_WH_R  ,  _______  ,
    _______  , _______  , KC_BTN4  , KC_BTN5  ,  SCRL_DVD ,                           CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE  ,
    //|---------------------------------------------------.                         ,------------------------------------------------------.
    _______  , _______  , _______  , _______  ,  MY_SCRL  , _______  ,     _______  , _______  , _______  , _______  , _______  ,  _______
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

typedef struct {
    bool pressed;
    uint16_t time;
    bool tap;
    bool double_tap;
    uint16_t active_keycode;
    uint16_t prev_active_keycode;
} key_state_t;

static key_state_t lower_key = {false, 0, false, false, KC_NO, KC_NO}; // 初期状態は無効なキーコード
static key_state_t raise_key = {false, 0, false, false, KC_NO, KC_NO}; // 初期状態は無効なキーコード
                                                                       //
void handle_key_press(key_state_t *key_state, uint16_t event_time, uint16_t current_keycode) {
    if (!key_state->pressed) {
        // 初回のキー押下
        key_state->time = event_time;
        key_state->pressed = true;
        key_state->tap = true;
        key_state->prev_active_keycode = key_state->active_keycode; // 現在の状態を保存
        key_state->active_keycode = current_keycode; // 現在のキーコードを更新
    } else if (key_state->pressed && (TIMER_DIFF_16(event_time, key_state->time) <= TAPPING_TERM)) {
        // ダブルタップの2回目の押下
        key_state->pressed = false;
        key_state->double_tap = true;
        key_state->tap = false;
    } else {
        // 長押しの開始
        key_state->time = event_time;
        key_state->pressed = true;
        key_state->tap = true;
        key_state->prev_active_keycode = key_state->active_keycode; // 現在の状態を保存
        key_state->active_keycode = current_keycode; // 現在のキーコードを更新
    }
}

void handle_key_release(key_state_t *key_state, uint16_t event_time, uint16_t tap_keycode, uint8_t layer) {
    if (key_state->tap && (TIMER_DIFF_16(event_time, key_state->time) <= TAPPING_TERM)) {
        // タップ時の処理
        tap_code(tap_keycode);
        key_state->prev_active_keycode = key_state->active_keycode; // 前の状態を更新
        key_state->active_keycode = tap_keycode;
        key_state->tap = false;
    } else if (key_state->double_tap && (TIMER_DIFF_16(event_time, key_state->time) <= TAPPING_TERM)) {
        // ダブルタップ時の処理
        key_state->double_tap = false;
        // タップ前の状態に戻す
        if (key_state->prev_active_keycode != tap_keycode) {
            tap_code(key_state->prev_active_keycode);
            key_state->active_keycode = key_state->prev_active_keycode;
        }
    }
    // キーが離されたときの共通処理
    key_state->pressed = false;
    layer_off(layer); // レイヤーを無効にする
}

// --------------------
// クリック時イベント
// --------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Left Ctrlが押されているか
    bool lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);

    switch (keycode) {

        case MN_EN:
            if (record->event.pressed) {
                handle_key_press(&lower_key, record->event.time, EN);
                layer_on(_LEFT); // レイヤーを有効にする
            } else {
                handle_key_release(&lower_key, record->event.time, EN, _LEFT);
            }
            return false;

        case MN_JP:
            if (record->event.pressed) {
                handle_key_press(&raise_key, record->event.time, JP);
                layer_on(_RIGHT); // レイヤーを有効にする
            } else {
                handle_key_release(&raise_key, record->event.time, JP, _RIGHT);
            }
            return false;

        // Ctrl + j = Enter
        case SFT_J:
            if (record->event.pressed) {
                if (lctrl) {
                    unregister_code(KC_LCTL);
                    tap_code(KC_ENT);
                    register_code(KC_LCTL);
                    return false;
                }
            }
            break;

        // Ctrl + h = Backspace
        case KC_H:
            if (record->event.pressed) {
                if (lctrl) {
                    unregister_code(KC_LCTL);
                    tap_code(KC_BSPC);
                    register_code(KC_LCTL);
                    return false;
                }
            }
            break;

        // MAC_PRSC
        case MAC_PRSC:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_LGUI);
                tap_code(KC_4);
                unregister_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            return false;
            break;

        case MY_SCRL:
          if (record->event.pressed) {
            keyball_set_scroll_mode(true);
          } else {
            keyball_set_scroll_mode(false);
            layer_move(_BASE);
          }
          return false;
          break;
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {

  uint8_t layer = biton32(state);
  switch (layer) {
  case _BASE:
    rgblight_sethsv(HSV_OFF);
    break;
  case _LEFT:
    rgblight_sethsv(HSV_CYAN);
    break;
    case _RIGHT:
    rgblight_sethsv(HSV_BLUE);
    break;
  case _NUMS:
    rgblight_sethsv(HSV_GREEN);
    break;
  case _LBALL:
    rgblight_sethsv(HSV_PURPLE);
    break;
  }

  return state;
}
