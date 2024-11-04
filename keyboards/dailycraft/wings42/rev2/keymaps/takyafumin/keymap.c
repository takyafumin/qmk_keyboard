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
    _base = 0,
    _MK,
    _NO,
    _EX,
};

// enum custom_keycodes {
//     MAC_PRSC = SAFE_RANGE,
// };


// --------------------
// キーのalias
// --------------------
// basic
#define SPC      KC_SPC
#define SFT      KC_LSFT
#define TAB      KC_TAB
#define ESC      KC_ESC
#define ENT      KC_ENT
#define BS       KC_BSPC
#define DEL      KC_DEL
#define JP       KC_LNG1
#define EN       KC_LNG2

// modifier

// 親指
#define GUIESC   LGUI_T(ESC)
#define LT_EN    LT(_EX, EN)
#define S_SPC    LSFT_T(SPC)
#define S_ZERO   LSFT_T(KC_0)
// 親指
#define S_ENT    LSFT_T(ENT)
#define S_BS     LSFT_T(BS)
#define RT_JP    LT(_NO, JP)
#define GUITAB   LGUI_T(TAB)

// home mods, left
#define SFTF     LSFT_T(KC_F)
#define ALTD     RALT_T(KC_D)
#define GUIS     LGUI_T(KC_S)
#define CTLA     LCTL_T(KC_A)
// home mods, right
#define SFTJ     LSFT_T(KC_J)
#define ALTK     RALT_T(KC_K)
#define GUIL     LGUI_T(KC_L)
#define CTLSCN   RCTL_T(KC_SCLN)

// OSM/OSL
#define OSL_MK   OSL(_MK)
#define TO_BASE  TO(_base)
#define TO_MK    TO(_MK)
#define TO_NO    TO(_NO)
#define TO_EX    TO(_EX)
#define OSM_SFT  OSM(MOD_LSFT)
#define OSM_CTL  OSM(MOD_LCTL)
#define OSM_ALT  OSM(MOD_LALT)
#define OSM_GUI  OSM(MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_base] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                     ,--------+---------+--------+---------+--------+--------.
        XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                     |--------+---------+--------+---------+--------+--------|
        XXXXXXX, CTLA   , GUIS   , ALTD   , SFTF   , KC_G   ,  _______, _______,    KC_H   , SFTJ    , ALTK   , GUIL    , CTLSCN , XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                     |--------+---------+--------+---------+--------+--------|
        XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,  _______, _______,    KC_N   , KC_M    , KC_COMM, KC_DOT  , KC_SLSH, XXXXXXX,
    //`--------+--------+--------+--------+--------+--------/                     \--------+---------+--------+---------+--------+--------'
                                   GUIESC , LT_EN  , S_SPC  ,                       S_ENT  , RT_JP   , OSL_MK
    //                          `+--------+--------+--------'                     `--------+---------+--------+'
    ),

    [_MK] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                     ,--------+---------+--------+--------+--------+--------.
        _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                       KC_CIRC, KC_AMPR , KC_ASTR, KC_LPRN, KC_RPRN, _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+---------+--------+--------+--------+--------|
        _______, KC_TILD, _______, KC_EQL , KC_MINS, KC_PIPE,  _______, _______,    KC_QUOT, KC_LBRC , KC_RBRC, _______, KC_COLN, _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+---------+--------+--------+--------+--------|
        _______, KC_GRV , _______, KC_PLUS, KC_UNDS, KC_BSLS,  _______, _______,    KC_DQT , KC_LCBR , KC_RCBR, _______, KC_QUES, _______,
    //`--------+--------+--------+--------+--------+--------/                     \--------+---------+--------+--------+--------+--------'
                                   _______, TO_BASE, OSM_SFT,                       _______, _______ , OSM_CTL
    //                          `+--------+--------+--------'                     `--------+---------+--------+'
    ),

    [_NO] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                     ,--------+--------+--------+--------+--------+--------.
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,  _______, _______,    _______, OSM_SFT, OSM_ALT, OSM_GUI, OSM_CTL, _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,  _______, _______,    KC_F11 , KC_F12 , _______, _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/                     \--------+--------+--------+--------+--------+--------'
                                  _______ , TO_BASE, OSM_SFT,                       _______, _______, OSM_CTL
    //                          `+--------+--------+--------'                     `--------+--------+--------+'
    ),

    [_EX] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                     ,--------+--------+--------+--------+--------+--------.
        _______, KC_ESC , _______, EE_CLR , QK_BOOT, QK_RBT ,                       TO_MK  , TO_NO  , _______, _______, KC_MINS,_______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______, KC_TAB , OSM_GUI, OSM_ALT, OSM_SFT, _______,  _______, _______,    KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, OSM_CTL, _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______, KC_CAPS, _______, _______, TO_MK  , KC_PSCR,  _______, _______,    KC_HOME, KC_PGDN, KC_PGUP, KC_END , OSM_SFT, _______,
    //`--------+--------+--------+--------+--------+--------/                     \--------+--------+--------+--------+--------+--------'
                                   _______, TO_BASE, _______,                       KC_BSPC, OSL_MK , KC_DEL
    //                          `+--------+--------+--------'                     `--------+--------+--------+'
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_base] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
    [_MK]   = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MS_L, KC_MS_R), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MS_U, KC_MS_D)  },
    [_NO]   = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MS_L, KC_MS_R), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MS_U, KC_MS_D)  },
    [_EX]   = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MS_L, KC_MS_R), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MS_U, KC_MS_D)  }
};
#endif

