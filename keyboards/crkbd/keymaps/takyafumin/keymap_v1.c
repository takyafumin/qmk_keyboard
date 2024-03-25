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
    _MARK  = 1,
    _FUNC  = 2,
    _NUMS  = 4,
    _EXTRA = 7,
    _LNUMK = 7,
};

enum custom_keycodes {
    MY_JP= SAFE_RANGE,
    MY_EN,
    MAC_PRSC
};

// --------------------
// キーのalias
// --------------------
#define SPC      KC_SPC
#define ESC      KC_ESC
#define ENT      KC_ENT
#define BS       KC_BSPC
#define JP       KC_LNG1
#define EN       KC_LNG2

#define CTLTAB   RCTL_T(KC_TAB)
#define S_SPC    LSFT_T(KC_SPC)
#define S_TAB    LSFT_T(KC_TAB)
#define S_ENT    LSFT_T(KC_ENT)
#define S_BS     LSFT_T(KC_BSPC)

#define S_LBRC   LSFT_T(KC_LBRC)
#define S_UP     LSFT_T(KC_UP)
#define S_RIGHT  LSFT_T(KC_RIGHT)

#define F_MARK   LT(_MARK, KC_F)
#define S_S      LSFT_T(KC_S)
#define S_D      LSFT_T(KC_D)
#define C_A      LCTL_T(KC_A)
#define G_X      LGUI_T(KC_X)
#define ALT_Z    RALT_T(KC_Z)

#define G_ESC    LGUI_T(KC_ESC)
#define G_MINS   LGUI_T(KC_MINUS)

#define J_MARK   LT(_MARK, KC_J)
#define S_K      LSFT_T(KC_K)
#define S_L      LSFT_T(KC_L)
#define C_SCN    RCTL_T(KC_SCLN)
#define G_DOT    LGUI_T(KC_DOT)
#define A_SLSH   RALT_T(KC_SLSH)

#define C_EN     LCTL_T(EN)
#define C_JP     LCTL_T(JP)
#define G_EN     LGUI_T(EN)
#define G_JP     LGUI_T(JP)
#define A_JP     RALT_T(JP)

#define RAISE    MO(_MARK)
#define LOWER    MO(_NUMS)
#define ADJUST   MO(_FUNC)
#define EXTRA    MO(_EXTRA)
#define F_EXT    LT(_EXTRA, KC_F)
#define J_EXT    LT(_EXTRA, KC_J)
#define ESC_EXT  LT(_EXTRA, KC_ESC)

// --------------------
// custom keyterms
// --------------------
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case C_A:
    case S_S:
    case S_D:
      return TAPPING_TERM + 50;

    default:
      return TAPPING_TERM;
  }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
        // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        //     KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        //     CTLTAB , KC_A   , KC_S   , KC_D   , F_EXT  , KC_G   ,                      KC_H   , J_EXT  , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        //     KC_LGUI, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RALT,
        // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        //                                         EXTRA  , C_EN   , S_SPC  ,    S_SPC  , MY_JP  , LOWER
        //                                     //`--------------------------'  `--------------------------'
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            CTLTAB , C_A    , KC_S   , KC_D   , F_EXT  , KC_G   ,                      KC_H   , J_EXT  , KC_K   , KC_L   , C_SCN  , KC_ENT ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LGUI, ALT_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RALT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               G_ESC   , MY_EN   , S_SPC ,    S_ENT  , MY_JP  , LOWER
                                            //`--------------------------'  `--------------------------'
  ),

  [_MARK] = LAYOUT_split_3x6_3(
        // //,------------------------------------------------------.                    ,-----------------------------------------------------.
        //     _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        //     XXXXXXX, KC_GRV , XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS,                      KC_BSLS, KC_SCLN, KC_EQL , XXXXXXX, KC_COLN, KC_DQT ,
        // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        //     _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                      KC_PIPE, XXXXXXX, KC_LT  , KC_GT  , KC_QUES, _______,
        // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        //                                         _______, _______, _______,    _______, _______, _______
        //                                     //`--------------------------'  `--------------------------'
        //,------------------------------------------------------.                    ,-----------------------------------------------------.
            _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_GRV , KC_BSLS, KC_EQL , KC_MINS, KC_LBRC,                      KC_RBRC, KC_COLN, KC_QUOT, KC_DQT , KC_COLN, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_TILD, KC_PIPE, KC_PLUS, KC_UNDS, KC_LCBR,                      KC_RCBR, KC_SCLN, KC_LT  , KC_GT  , KC_QUES, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,    _______, _______, _______
                                            //`--------------------------'  `--------------------------'
  ),
  [_NUMS] = LAYOUT_split_3x6_3(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_F11 , KC_F12 , _______,
        //|--------+--------5--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               ADJUST  , _______, _______,    _______, _______, _______
                                           //`--------------------------'  `--------------------------'
  ),
  [_FUNC] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------|
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, KC_F11 , KC_F12 , _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,   _______ ,_______ , _______
                                            //`--------------------------'  `--------------------------'
            // _______,MAC_PRSC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_DOWN, KC_UP  , KC_END , KC_PSCR, KC_PSCR,
  ),
  [_EXTRA] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______,MAC_PRSC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_TAB , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, XXXXXXX, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, XXXXXXX, XXXXXXX, QK_RBT , EE_CLR , QK_BOOT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, KC_ESC , _______,    KC_BSPC, KC_DEL , _______
                                            //`--------------------------'  `--------------------------'
  ),
  // [_LNUMK] = LAYOUT_split_3x6_3(
  //       //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //           _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_7   , KC_8   , KC_9   , KC_0   , _______,
  //       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //           _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_0   , XXXXXXX,                      KC_DOT , KC_4   , KC_5   , KC_6   , KC_COLN, _______,
  //       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //           _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_COMM, KC_1   , KC_2   , KC_3   , _______, _______,
  //       //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                               _______, _______, _______,    _______, _______, _______
  //                                           //`--------------------------'  `--------------------------'
  // ),
};

// --------------------
// layerキーを押しているか
// --------------------
static struct {
    uint16_t keycode;
    uint16_t time;
} last_pressed = {0, 0};

// クリック時イベント
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool in_tapping_term = (record->event.time - last_pressed.time) <= TAPPING_TERM;
    bool lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);

    switch (keycode) {
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

        case S_ENT:
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

        case MY_EN:
            if (record->event.pressed) {
                last_pressed.time = record->event.time;
                layer_on(_EXTRA);
            } else {
                layer_off(_EXTRA);
                if (in_tapping_term) {
                    tap_code(EN);
                }
           }
           return false;
           break;

        case MY_JP:
           if (record->event.pressed) {
                last_pressed.time = record->event.time;
                layer_on(_MARK);
           } else {
                layer_off(_MARK);
                if (in_tapping_term) {
                    tap_code(JP);
                }
           }
           return false;
           break;
    }

    return true;
}
