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
    _EXT1  = 2,
    _NUMS  = 4,
    _LNUMK = 7,
};

enum custom_keycodes {
    MY_L1= SAFE_RANGE,
    MY_L2
};

// --------------------
// キーのalias
// --------------------
#define SPC      KC_SPC
#define ESC      KC_ESC
#define ENT      KC_ENT
#define BS       KC_BSPC
#define CLN      S(KC_SCLN)
#define L1       KC_LNG1
#define L2       KC_LNG2
#define S_SPC    LSFT_T(KC_SPC)
#define S_ENT    LSFT_T(KC_ENT)
#define S_BS     LSFT_T(KC_BSPC)
#define S_DEL    LSFT_T(KC_DEL)
#define S_S      LSFT_T(KC_S)
#define S_D      LSFT_T(KC_D)
#define S_K      LSFT_T(KC_K)
#define S_L      LSFT_T(KC_L)
#define S_LBRC   LSFT_T(KC_LBRC)
#define S_UP     LSFT_T(KC_UP)
#define S_RIGHT  LSFT_T(KC_RIGHT)
#define CTLA     LCTL_T(KC_A)
#define CTLSCN   RCTL_T(KC_SCLN)
#define CTLTAB   LCTL_T(KC_TAB)
#define CTLL2    LCTL_T(L2)
#define A_Z      RALT_T(KC_Z)
#define ALTESC   RALT_T(KC_ESC)
#define ALTSLSH  RALT_T(KC_SLSH)
#define F_MARK   LT(_MARK, KC_F)
#define J_MARK   LT(_MARK, KC_J)
#define RAISE    MO(_MARK)
#define LOWER    MO(_NUMS)
#define ADJUST   MO(_EXT1)
#define G_EN     LGUI_T(L2)
#define A_JP     RALT_T(L1)

// --------------------
// custom keyterms
// --------------------
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case CTLA:
    case S_S:
    case S_D:
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
            CTLTAB , CTLA   , S_S    , S_D    , F_MARK , KC_G   ,                      KC_H   , J_MARK , S_K    , S_L    , CTLSCN , KC_QUOT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LGUI, A_Z    , KC_X   , KC_C   , KC_V   , KC_B   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , ALTSLSH, KC_LGUI,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                G_EN   , RAISE  , S_SPC ,    S_ENT   , LOWER  , A_JP
                                            //`--------------------------'  `--------------------------'
  ),

  [_MARK] = LAYOUT_split_3x6_3(
        //,------------------------------------------------------.                    ,-----------------------------------------------------.
            _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, CTLTAB , S_LBRC , _______, KC_RBRC, KC_BSLS,                      KC_LEFT, KC_DOWN, S_UP   , S_RIGHT, KC_COLN, KC_DQT ,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV ,                      KC_GRV , KC_EQL , KC_LT  , KC_GT  , KC_QUES, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, L2     , _______,    S_BS   , ADJUST , _______
                                            //`--------------------------'  `--------------------------'
  ),
  [_NUMS] = LAYOUT_split_3x6_3(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               _______ , ADJUST , KC_0   ,    S_BS  , _______, _______
                                           //`--------------------------'  `--------------------------'
  ),
  [_EXT1] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6   , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_HOME, KC_DOWN, KC_UP  , KC_END , XXXXXXX, KC_PSCR,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_LSFT, XXXXXXX, QK_RBT , EE_CLR , QK_BOOT,                      XXXXXXX,  KC_APP, XXXXXXX, KC_F11 , KC_F12 , _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,    S_BS  , ADJUST , KC_DEL
                                            //`--------------------------'  `--------------------------'
  ),
  [_LNUMK] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_7   , KC_8   , KC_9   , KC_0   , _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_0   , XXXXXXX,                      KC_DOT , KC_4   , KC_5   , KC_6   , KC_COLN, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_COMM, KC_1   , KC_2   , KC_3   , _______, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, _______, _______,    _______, _______, _______
                                            //`--------------------------'  `--------------------------'
  ),

  // [_BASE] = LAYOUT_split_3x6_3(
  //       //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //           KC_ESC , KC_Q   ,    KC_W,    KC_E, KC_R   ,    KC_T,                         KC_Y, KC_U   ,    KC_I,    KC_O,    KC_P, KC_MINS,
  //       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //           CTLTAB , CTLA   ,    KC_S,    KC_D, F_MARK ,    KC_G,                         KC_H, J_MARK ,    KC_K,    KC_L, CTLSCN , KC_QUOT,
  //       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //           KC_LGUI, S_Z   ,    KC_X,    KC_C, V_NUMS ,    KC_B,                         KC_N, KC_M   , KC_COMM,  ALTDOT, S_SLSH, KC_RALT,
  //       //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                               TABEXT , CTLL2  , S_SPC ,    S_ENT , MY_L1  , ALTESC
  //                                           //`--------------------------'  `--------------------------'
  // ),

  // [_MARK] = LAYOUT_split_3x6_3(
  //       //,------------------------------------------------------.                    ,-----------------------------------------------------.
  //           _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_EQL ,
  //       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //           _______, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_GRV ,                      KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, KC_COLN, KC_DQT ,
  //       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //           _______, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, KC_TILD,                      KC_BSLS, KC_PIPE,   KC_LT,   KC_GT, KC_QUES, _______,
  //       //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                               _______, KC_LSFT, S_DEL ,    S_BS  , KC_RSFT, _______
  //                                           //`--------------------------'  `--------------------------'
  //       ),

  // [_NUMS] = LAYOUT_split_3x6_3(
  //       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //           _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
  //       //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //           _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, _______, _______,
  //       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //           _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                      KC_F11 , KC_F12 , _______, _______, _______, _______,
  //       //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                              _______, KC_0   , _______,    BS     ,  KC_0  , KC_DEL
  //                                          //`--------------------------'  `--------------------------'
  // ),

  // [_EXT1] = LAYOUT_split_3x6_3(
  //       //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //           _______,  KC_ESC, XXXXXXX, KC_PGUP, QK_RBT , XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_DEL ,
  //       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //           _______, KC_LCTL, KC_HOME, KC_PGDN, KC_END , XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCTL, _______,
  //       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //           _______, KC_LGUI, XXXXXXX, XXXXXXX, EE_CLR , QK_BOOT,                      XXXXXXX,  KC_APP, XXXXXXX, XXXXXXX, KC_RALT, _______,
  //       //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                               _______, _______, _______,    BS     , _______, KC_DEL
  //                                           //`--------------------------'  `--------------------------'
  // ),

  // [0] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI, TL_LOWR,  KC_SPC,     KC_ENT, TL_UPPR, KC_RALT
  //                                     //`--------------------------'  `--------------------------'

  // ),

  // [1] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
  //                                     //`--------------------------'  `--------------------------'
  // ),

  // [2] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
  //                                     //`--------------------------'  `--------------------------'
  // ),

  // [3] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //       QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
  //                                     //`--------------------------'  `--------------------------'
  // )
};

// --------------------
// layerキーを押しているか
// --------------------
// static bool layer_switch_pressed = false;
static struct {
    uint16_t keycode;
    uint16_t time;
} last_pressed = {0, 0};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool in_tapping_term = (record->event.time - last_pressed.time) <= TAPPING_TERM;
    bool lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);

    switch (keycode) {
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
        case MY_L2:
            if (record->event.pressed) {
               last_pressed.time = record->event.time;
               layer_on(_EXT1);
           } else {
               layer_off(_EXT1);
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
               layer_on(_NUMS);
           } else {
               layer_off(_NUMS);
               if (in_tapping_term) {
                   tap_code(KC_LNG1);
               }
           }
           return false;
           break;
    }

    // set_keylog(keycode, record);
    return true;
}
