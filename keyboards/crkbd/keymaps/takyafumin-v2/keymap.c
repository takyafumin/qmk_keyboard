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
    _MK    = 1,
    _NO    = 2,
    _EX    = 3,
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

// OSM/OSL
#define OSL_MK   OSL(_MK)
#define TO_BASE  TO(_BASE)
#define TO_MK    TO(_MK)
#define TO_NO    TO(_NO)
#define TO_EX    TO(_EX)
#define OSM_SFT  OSM(MOD_LSFT)
#define OSM_CTL  OSM(MOD_LCTL)
#define OSM_ALT  OSM(MOD_LALT)
#define OSM_GUI  OSM(MOD_LGUI)

// --------------------
// custom keyterms
// --------------------
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case ALT_D:
    case GUI_S:
    case ALT_K:
    case GUI_L:
      return TAPPING_TERM + 50;

    default:
      return TAPPING_TERM;
  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
        //|-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            CTLTAB , CTL_A  , GUI_S  , ALT_D  , SFT_F  , KC_G   ,                      KC_H   , SFT_J  , ALT_K  , GUI_L  , CTLSCN , _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LGUI, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RALT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                GUIESC , MN_EN  , S_SPC ,     S_ENT  , MN_JP  , OSL_MK
                                            //`--------------------------'  `--------------------------'
  ),
  [_MK] = LAYOUT_split_3x6_3(
        //|--------+--------+--------+--------+--------+--------|                    |--------+---------+--------+--------+--------+--------|
            _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_AMPR , KC_ASTR, KC_LPRN, KC_RPRN, _______,
        //|-----------------------------------------------------.                    ,------------------------------------------------------.
            _______, KC_TILD, _______, KC_EQL , KC_MINS, KC_PIPE,                      KC_QUOT, KC_LBRC , KC_RBRC, _______, KC_COLN, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+---------+--------+--------+--------+--------|
            _______, KC_GRV , _______, KC_PLUS, KC_UNDS, KC_BSLS,                      KC_DQT , KC_LCBR , KC_RCBR, _______, KC_QUES, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+---------+--------+--------+--------+--------|
                                                _______, TO_BASE, OSM_SFT,    _______, _______, _______
                                           //`--------------------------'  `--------------------------'
  ),
  [_NO] = LAYOUT_split_3x6_3(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        //|-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      _______, OSM_SFT, OSM_ALT, OSM_GUI, OSM_CTL, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                      KC_F11 , KC_F12 , _______, _______, _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, TO_BASE, OSM_SFT,    _______, _______, _______
                                           //`--------------------------'  `--------------------------'
  ),
  [_EX] = LAYOUT_split_3x6_3(
        //|-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, KC_ESC , _______, EE_CLR , QK_BOOT, QK_RBT ,                      TO_MK  , TO_NO  , _______, _______, KC_MINS,_______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_TAB , OSM_GUI, OSM_ALT, OSM_SFT, _______,                      KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, OSM_CTL, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_CAPS, _______, _______, TO_MK  , KC_PSCR,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END , OSM_SFT, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, TO_BASE, _______,    KC_BSPC, OSL_MK , KC_DEL
                                            //`--------------------------'  `--------------------------'
  ),
  [_NUMS] = LAYOUT_split_3x6_3(
        //|-----------------------------------------------------.                    ,-----------------------------------------------------.
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

// --------------------
// クリック時イベント
// --------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);

    switch (keycode) {

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
    }

    return true;
}

