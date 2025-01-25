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
    _LEFT,
    _RIGHT,
    _EXTRA,
};

enum custom_keycodes {
    MAC_PRSC = SAFE_RANGE,
};



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

#define EXZERO  LT(_EX, KC_0)

// modifier

// 親指
#define GUIESC   LGUI_T(ESC)
#define LT_EN    LT(_LEFT, EN)
#define S_SPC    LSFT_T(SPC)
#define S_ZERO   LSFT_T(KC_0)
// 親指
#define S_ENT    LSFT_T(ENT)
#define S_BS     LSFT_T(BS)
#define RT_JP    LT(_RIGHT, JP)
#define GUITAB   LGUI_T(TAB)

// home mods, left
#define SFTF     LSFT_T(KC_F)
#define SFTZ     LSFT_T(KC_Z)
#define ALTD     RALT_T(KC_D)
#define GUIS     LGUI_T(KC_S)
#define CTLA     LCTL_T(KC_A)
#define CTLTAB   LCTL_T(TAB)
#define CTLQUOT  LCTL_T(KC_QUOT)
// home mods, right
#define SFTJ     LSFT_T(KC_J)
#define SFTSLSH  LSFT_T(KC_SLSH)
#define ALTK     RALT_T(KC_K)
#define GUIL     LGUI_T(KC_L)
#define CTLSCN   RCTL_T(KC_SCLN)
#define SFT_DN   LSFT_T(KC_DOWN)
#define ALT_UP   RALT_T(KC_UP)
#define GUI_RT   LGUI_T(KC_RIGHT)
#define CTLSCN   RCTL_T(KC_SCLN)

// Layer
#define LFT_V    LT(_LEFT, KC_V)
#define RIGHT    MO(_RIGHT)
#define EXTRA    MO(_EXTRA)
#define EXT_0    LT(_EXTRA, KC_0)
#define EXTMINS  LT(_EXTRA, KC_MINS)
#define LT_EN    LT(_LEFT, EN)
#define RT_JP    LT(_RIGHT, JP)

// OSM/OSL
#define OSL_LEFT OSL(_LEFT)
#define TO_BASE  TO(_base)
#define TO_LEFT  TO(_LEFT)
#define TO_RIGHT TO(_RIGHT)
#define TO_EXTRA TO(_EXTRA)
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
        XXXXXXX, SFTZ   , KC_X   , KC_C   , KC_V   , KC_B   ,  _______, _______,    KC_N   , KC_M    , KC_COMM, KC_DOT  , SFTSLSH, XXXXXXX,
    //`--------+--------+--------+--------+--------+--------/                     \--------+---------+--------+---------+--------+--------'
                                   GUIESC , LT_EN  , S_SPC  ,                       S_ENT  , RT_JP   , GUITAB
    //                          `+--------+--------+--------'                     `--------+---------+--------+'
    ),

    [_MK] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                     ,--------+---------+--------+--------+--------+--------.
    //  _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                       KC_CIRC, KC_AMPR , KC_ASTR, KC_LPRN, KC_RPRN, _______,
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7    , KC_8   , KC_9   , KC_0   , _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+---------+--------+--------+--------+--------|
        _______, KC_TILD, _______, KC_LBRC, KC_RBRC, KC_PIPE,  _______, _______,    KC_LEFT, KC_DOWN , KC_UP  ,KC_RIGHT, KC_COLN, _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+---------+--------+--------+--------+--------|
        _______, KC_GRV , _______, KC_LCBR, KC_RCBR, KC_BSLS,  _______, _______,    KC_DQT , KC_MINS , KC_LT  , KC_GT  , KC_QUES, _______,
    //`--------+--------+--------+--------+--------+--------/                     \--------+---------+--------+--------+--------+--------'
                                   _______, _______, _______,                       KC_BSPC, EXZERO  , KC_DEL
    //                          `+--------+--------+--------'                     `--------+---------+--------+'
    ),

    [_NO] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                     ,--------+---------+--------+--------+--------+--------.
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7    , KC_8   , KC_9   , KC_0   , _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+---------+--------+--------+--------+--------|
        _______, KC_TILD, _______, KC_LBRC, KC_RBRC, KC_PIPE,  _______, _______,    _______, OSM_SFT , OSM_ALT, OSM_GUI, OSM_CTL, _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+---------+--------+--------+--------+--------|
        _______, KC_GRV , _______, KC_LCBR, KC_RCBR, KC_BSLS,  _______, _______,    _______, _______ , _______, _______, KC_LSFT, _______,
    //`--------+--------+--------+--------+--------+--------/                     \--------+---------+--------+--------+--------+--------'
                                  _______ , EXZERO , _______,                       _______, _______ , _______
    //                          `+--------+--------+--------'                     `--------+---------+--------+'
    ),

    [_RIGHT] = LAYOUT(
    //,--------+--------+--------+--------+--------+--------.                     ,--------+--------+--------+--------+--------+--------.
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                       KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,  _______, _______,    KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, EE_CLR , QK_BOOT, QK_RBT ,  _______, _______,    KC_PSCR, KC_F11 , KC_F12 , _______, _______, _______,
    //`--------+--------+--------+--------+--------+--------/                     \--------+--------+--------+--------+--------+--------'
                                   _______, _______, _______,                       _______, _______, _______
    //                          `+--------+--------+--------'                     `--------+--------+--------+'
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_base]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
    [_LEFT]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MS_L, KC_MS_R), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MS_U, KC_MS_D)  },
    [_RIGHT] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MS_L, KC_MS_R), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MS_U, KC_MS_D)  },
    [_EXTRA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MS_L, KC_MS_R), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MS_U, KC_MS_D)  }
};
#endif

// --------------------
// クリック時イベント
// --------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Left Ctrlが押されているか
    bool lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);

    switch (keycode) {

        // Ctrl + j = Enter
        case SFTJ:
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
    }

    return true;
}

