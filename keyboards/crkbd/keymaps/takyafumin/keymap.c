/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

enum layer_names {
    _BASE  = 0,
    _LEFT  = 1,
    _RIGHT = 2,
    _EXTRA = 3,
    _NUMS  = 4,
};

enum custom_keycodes {
    MAC_PRSC = SAFE_RANGE,
    MN_JP,
    MN_EN
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
#define SFT_F    LSFT_T(KC_F)
#define SFT_J    LSFT_T(KC_J)
#define ALTTAB   RALT_T(TAB)
#define GUIESC   LGUI_T(ESC)
#define CTL_A    LCTL_T(KC_A)
#define CTLSCN   RCTL_T(KC_SCLN)

// Layer
#define LEFT     MO(_LEFT)
#define RIGHT    MO(_RIGHT)
#define EXTRA    MO(_EXTRA)
#define NUMS     MO(_NUMS)
#define NUMS_Z   LT(NUMS, KC_Z)
#define LT_EN    LT(LEFT, EN)
#define RT_JP   LT(RIGHT, JP)

// --------------------
// custom keyterms
// --------------------
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case CTL_A:
      return TAPPING_TERM + 30;

    default:
      return TAPPING_TERM;
  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            CTLTAB , CTL_A  , KC_S   , KC_D   , SFT_F  , KC_G   ,                      KC_H   , SFT_J  , KC_K   , KC_L   , CTLSCN , KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LGUI, NUMS_Z , KC_X   , KC_C   , KC_V   , KC_B   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RALT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                GUIESC , LT_EN  , S_SPC ,    S_ENT  , RT_JP   , ALTTAB
                                            //`--------------------------'  `--------------------------'
  ),
  [_LEFT] = LAYOUT_split_3x6_3(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_UNDS,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, CTLTAB , KC_RALT, KC_LGUI, KC_LSFT, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, KC_COLN, KC_DQT ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS, KC_EQL , KC_LT  , KC_GT  , KC_QUES, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,    S_BS   , EXTRA  , DEL
                                           //`--------------------------'  `--------------------------'
  ),
  [_RIGHT] = LAYOUT_split_3x6_3(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, KC_GRV , KC_LBRC, KC_QUOT, KC_RBRC, KC_BSLS,                      XXXXXXX, KC_RSFT, KC_RGUI, KC_RALT, KC_RCTL, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_TILD, KC_LCBR, KC_DQT , KC_RCBR, KC_PIPE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______ , EXTRA , _______,    _______, _______, _______
                                           //`--------------------------'  `--------------------------'
  ),
  [_EXTRA] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______,MAC_PRSC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, XXXXXXX, XXXXXXX, QK_RBT , EE_CLR , QK_BOOT,                      KC_PSCR, XXXXXXX, KC_MENU, KC_F11 , KC_F12 , _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,    _______, _______, _______
                                            //`--------------------------'  `--------------------------'
  ),
  [_NUMS] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_ASTR, KC_7   , KC_8   , KC_9   , XXXXXXX, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS, KC_4   , KC_5   , KC_6   , KC_COLN, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_PLUS, KC_1   , KC_2   , KC_3   , KC_SLSH, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,    KC_EQL , KC_0   , _______
                                            //`--------------------------'  `--------------------------'
  ),
};

static struct {
    bool pressed;
    uint16_t time;
} lower_key = {false, 0};
static struct {
    bool pressed;
    uint16_t time;
} raise_key = {false, 0};

// クリック時イベント
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);

    switch (keycode) {
        case MN_EN:
           if (record->event.pressed) {
                if (!lower_key.pressed) {
                    lower_key.time = record->event.time;
                } else if (lower_key.pressed && (TIMER_DIFF_16(record->event.time, lower_key.time) > TAPPING_TERM * 2)) {
                    lower_key.time = record->event.time;
                    lower_key.pressed = false;
                }
                layer_on(_LEFT);
           } else {
                layer_off(_LEFT);
                if(!lower_key.pressed && (TIMER_DIFF_16(record->event.time, lower_key.time) <= TAPPING_TERM)) {
                    lower_key.pressed = true;
                } else if (lower_key.pressed && (TIMER_DIFF_16(record->event.time, lower_key.time) <= TAPPING_TERM * 2)) {
                    lower_key.pressed = false;
                    tap_code(EN);
                } else {
                    lower_key.pressed = false;
                }
           }
           return false;
           break;

        case MN_JP:
           if (record->event.pressed) {
               if (!raise_key.pressed) {
                   raise_key.time = record->event.time;
               } else if (raise_key.pressed && (TIMER_DIFF_16(record->event.time, raise_key.time) > TAPPING_TERM * 2)) {
                   raise_key.time = record->event.time;
                   raise_key.pressed = false;
               }
               layer_on(_RIGHT);
           } else {
               layer_off(_RIGHT);
               if(!raise_key.pressed && (TIMER_DIFF_16(record->event.time, raise_key.time) <= TAPPING_TERM)) {
                   raise_key.pressed = true;
               } else if (raise_key.pressed && (TIMER_DIFF_16(record->event.time, raise_key.time) <= TAPPING_TERM * 2)) {
                   raise_key.pressed = false;
                   tap_code(JP);
               } else {
                   raise_key.pressed = false;
               }
           }
           return false;
           break;

        // Ctrl + H = Backspace
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
    }

    return true;
}
