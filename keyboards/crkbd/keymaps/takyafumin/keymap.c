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
    LT_EN,
    RT_JP
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
#define GUITAB   LGUI_T(TAB)
#define GUIESC   LGUI_T(ESC)
// home mod key left
#define SFT_F    LSFT_T(KC_F)
#define ALT_D    RALT_T(KC_D)
#define GUI_S    LGUI_T(KC_S)
#define CTL_A    LCTL_T(KC_A)
#define CTLQUOT  LCTL_T(KC_QUOT)

// home mod key right
#define SFT_J    LSFT_T(KC_J)
#define ALT_K    RALT_T(KC_K)
#define GUI_L    LGUI_T(KC_L)
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
    case ALT_UP:
    case GUI_S:
    case GUI_L:
    case GUI_RT:
    // case OSM_SFT:
    // case OSM_CTL:
    // case OSM_ALT:
    // case OSM_GUI:
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
            KC_LGUI, KC_Z   , KC_X   , KC_C   , LFT_V  , KC_B   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RALT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                GUIESC , LT_EN  , S_SPC ,     S_ENT  , RT_JP  , GUITAB
                                            //`--------------------------'  `--------------------------'
  ),
  [_LEFT] = LAYOUT_split_3x6_3(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , TO_EXT ,
        //|-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, OSM_CTL, OSM_GUI, OSM_ALT, OSM_SFT, KC_BSLS,                      KC_LEFT, SFT_DN , ALT_UP , GUI_RT , CTLQUOT, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, XXXXXXX, XXXXXXX, XXXXXXX, EN     , KC_PIPE,                      KC_EQL , KC_MINS, KC_LT  , KC_GT  , KC_QUES, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               _______, _______, _______,     S_BS   , EXTMINS, DEL
                                           //`--------------------------'  `--------------------------'
  ),
  [_RIGHT] = LAYOUT_split_3x6_3(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        //|-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, KC_GRV , XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS,                      KC_LEFT, SFT_DN , ALT_UP , GUI_RT , OSM_CTL, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_TILD, XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE,                      XXXXXXX, JP     , XXXXXXX, XXXXXXX, XXXXXXX, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_TAB , EXT_0 , _______,    _______, _______, _______
                                           //`--------------------------'  `--------------------------'
  ),
  [_EXTRA] = LAYOUT_split_3x6_3(
        //|-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,MAC_PRSC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_PSCR, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_CAPS, XXXXXXX, QK_RBT , EE_CLR , QK_BOOT,                      KC_F11 , KC_F12 , KC_MENU, XXXXXXX, XXXXXXX, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, TO_BASE, _______,    _______, _______, _______
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
    // Left Ctrlが押されているか
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

