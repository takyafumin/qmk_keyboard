/* Copyright 2020 yfuku
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _0,
    _1,
    _2,
    _3
};

#define L_SPC LT(_1, KC_SPC)
#define R_ENT LT(_2, KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_0] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                                   KC_LGUI, KC_LNG2 ,L_SPC,            R_ENT,   KC_LNG1, KC_RALT,
        KC_1,    KC_2,    KC_3
    ),
    [_1] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, KC_EQL,  KC_PLUS, KC_ASTR, KC_PERC, _______,
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, _______, _______, _______, _______,
                                   _______, _______, _______,          KC_DEL,  _______, _______,
        _______, _______, _______ 
    ),
    [_2] = LAYOUT(
        _______, KC_BSLS, KC_EXLM, KC_AMPR, KC_PIPE, XXXXXXX,          XXXXXXX, KC_EQL,  KC_PLUS, KC_ASTR, KC_PERC, _______,
        _______, KC_HASH, KC_GRV,  KC_DQT,  KC_QUOT, KC_TILD,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DLR,  _______,
        _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_LBRC, KC_LPRN,          KC_RPRN, KC_RBRC, KC_RCBR, KC_AT,   KC_CIRC, _______,
                                   _______, _______, KC_BSPC,          _______, _______, _______,
        _______, _______, _______ 
    ),
    [_3] = LAYOUT(
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
                                   _______, _______, ______C,          _______, _______, _______,
        _______, _______, _______ 
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO)  },
    [1] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [2] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
    [3] =   { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______)  },
};
#endif