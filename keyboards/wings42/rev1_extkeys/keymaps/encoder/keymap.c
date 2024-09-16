/* Copyright 2021 yfuku
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
    _ADJUST,
};

#define KC_G_TAB LGUI_T(KC_TAB)
#define KC_G_BS LGUI_T(KC_BSPC)
#define KC_L_SPC LT(_LOWER, KC_SPC)
#define KC_R_ENT LT(_RAISE, KC_ENT)
#define KC_S_JA LSFT_T(KC_LANG1)
#define KC_S_EN LSFT_T(KC_LANG2)
#define KC_A_DEL ALT_T(KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
    //,--------+--------+---------+--------+---------+--------.                    ,--------+---------+--------+---------+--------+--------.
       KC_ESC , KC_Q   , KC_W    , KC_E   , KC_R    , KC_T   ,                      KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , KC_MINS,
    //|--------+--------+---------+--------+---------+--------|                    |--------+---------+--------+---------+--------+--------|
      KC_G_TAB, KC_A   , KC_S    , KC_D   , KC_F    , KC_G   ,   KC_NO,  KC_A,   KC_H   , KC_J    , KC_K   , KC_L    , KC_SCLN, KC_G_BS ,
    //|--------+--------+---------+--------+---------+--------|                    |--------+---------+--------+---------+--------+--------|
       KC_LCTL, KC_Z   , KC_X    , KC_C   , KC_V    , KC_B   ,   KC_NO, KC_B,  KC_N   , KC_M    , KC_COMM, KC_DOT  , KC_SLSH, KC_RCTL,
    //`--------+--------+---------+--------+---------+--------/                    \--------+---------+--------+---------+--------+--------'
                                  KC_A_DEL, KC_S_EN ,KC_L_SPC,                      KC_R_ENT, KC_S_JA , KC_A_DEL
    //                           `+--------+---------+--------'                    `--------+---------+--------+'
    ),

    [_RAISE] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
       _______, KC_BSLS, KC_CIRC, KC_EXLM, KC_AMPR, KC_PIPE,                        KC_AT  , KC_EQL , KC_PLUS, KC_ASTR, KC_PERC, KC_MINS,
    //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
       KC_LPRN, KC_HASH, KC_DLR , KC_DQT , KC_QUOT, KC_TILD,     _______, _______,  KC_LEFT, KC_DOWN,  KC_UP , KC_RGHT, KC_GRV , KC_RPRN,
    //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, KC_LCBR, KC_LBRC,     _______, _______,  KC_RBRC, KC_RCBR, _______, _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/                      \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,                        _______, _______, RESET
    //                          `+--------+--------+--------'                      `--------+---------+--------+'
    ),

    [_LOWER] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
       KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                        _______, KC_EQL , KC_PLUS, KC_ASTR, KC_PERC, KC_MINS,
    //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
       _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,    _______, _______,   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
    //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
       KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 ,    _______, _______,   _______, _______, KC_COMM, KC_DOT , KC_SLSH, _______,
    //`--------+--------+--------+--------+--------+--------/                      \--------+--------+--------+--------+--------+--------'
                                  RESET  , _______, _______,                        _______, _______, _______
    //                          `+--------+--------+--------'                      `--------+--------+--------+'
    ),

    [_ADJUST] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                      ,--------+--------+--------+--------+--------+--------.
       _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,    _______, _______,   _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,    _______, _______,   _______, _______, _______, _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/                      \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,                        _______, _______, _______
    //                          `+--------+--------+--------'                      `--------+--------+--------+'
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {        // left ↓
        if (clockwise) {
            tap_code(KC_1);
        } else {
            tap_code(KC_2);
        }
    } else if (index == 1) { // left ↑
        if (clockwise) {
            tap_code(KC_3);
        } else {
            tap_code(KC_4);
        }
    } else if (index == 2) { // right ↓
        if (clockwise) {
            tap_code(KC_5);
        } else {
            tap_code(KC_6);
        }
    } else if (index == 3) { // right ↑
        if (clockwise) {
            tap_code(KC_7);
        } else {
            tap_code(KC_8);
        }
    }
}