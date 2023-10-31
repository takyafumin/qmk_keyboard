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
    _LBASE  = 0,
    _LMARK  = 1,
    _LEXT   = 2,
    _LNUMS  = 3,
    _LEX2   = 4,
};

enum custom_keycodes {
    MY_L1= SAFE_RANGE,
    MY_L2
};

// --------------------
// custom keyterms
// --------------------
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LCTL_T(KC_A):
      return TAPPING_TERM + 20;

    case RCTL_T(KC_SCLN):
      return TAPPING_TERM + 20;

    default:
      return TAPPING_TERM;
  }
}

// --------------------
// キーのalias
// --------------------
#define SFTSPC   LSFT_T(KC_SPC)
#define SFTENT   LSFT_T(KC_ENT)
#define SFT_BS   LSFT_T(KC_BSPC)
#define SFT_DEL  LSFT_T(KC_DEL)
#define SFTESC   LSFT_T(KC_ESC)
#define CTL_TAB  LCTL_T(KC_TAB)
#define CTL_A    LCTL_T(KC_A)
#define ALT_C    RALT_T(KC_C)
#define GUI_Z    LGUI_T(KC_Z)
#define CTL_SCN  LCTL_T(KC_SCLN)
#define GUI_DOT  LGUI_T(KC_DOT)
#define ALTSLSH  RALT_T(KC_SLSH)
#define SPC      KC_SPC
#define ESC      KC_ESC
#define ENT      KC_ENT
#define BS       KC_BSPC
#define CLN      S(KC_SCLN)
#define L1       KC_LNG1
#define L2       KC_LNG2
#define L1_LEXT  LT(_LEXT, L1)
#define L2_LEXT  LT(_LEXT, L2)
#define F_MARK   LT(_LMARK, KC_F)
#define J_MARK   LT(_LMARK, KC_J)
#define V_NUMS   LT(_LNUMS, KC_V)
#define M_NUMS   LT(_LNUMS, KC_M)
#define S_NUMS   LT(_LNUMS, KC_S)
#define L_NUMS   LT(_LNUMS, KC_L)
#define LCTG     LGUI_T(KC_RCTL)








const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LBASE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        //         ,     Q  ,     W  ,     E  ,     R  ,    T   ,                    ,     Y  ,     U  ,     I  ,    O   ,     P  ,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        //         ,     A  ,     S  ,     D  ,     F  ,    G   ,                    ,     H  ,     J  ,     K  ,    L   ,     -  ,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        //         ,     Z  ,     X  ,     C  ,     v  ,    B   ,                    ,     N  ,     M  ,     ,  ,    .   ,     /  ,
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,   CTL_A,  S_NUMS,    KC_D,  F_MARK,    KC_G,                         KC_H,  J_MARK,    KC_K,  L_NUMS, CTL_SCN, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______,   GUI_Z,    KC_X,   ALT_C,  V_NUMS,    KC_B,                         KC_N,  M_NUMS, KC_COMM, GUI_DOT, ALTSLSH, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                    // ESC, L2_LEXT,  SFTSPC,     SFTENT, L1_LEXT, KC_RCTL
                                                    ESC,   MY_L2,  SFTSPC,     SFTENT,   MY_L1, KC_RCTL
                                            //`--------------------------'  `--------------------------'
  ),

  [_LMARK] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,------------------------------------------------------
        //         ,     !  ,     @  ,     #  ,     $  ,    %   ,                    ,    ^   ,    &   ,    *   ,    (   ,    )   ,
        //,------------------------------------------------------.                    ,-----------------------------------------------------.
        //         ,   CTRL ,   HOME ,   PGUP ,   END  ,    =   ,                    ,   LEFT ,  DOWN  ,   UP   ,  RIGHT ,    '   ,
        //,------------------------------------------------------.                    ,-----------------------------------------------------.
        //         ,    GUI ,        ,   PGDN ,    \   ,    `   ,                    ,    [   ,    ]   ,     <  ,    >   ,    ?   ,
        //,------------------------------------------------------.                    ,-----------------------------------------------------.
            // _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
            _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR,  KC_EQL, KC_MINS, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_LCTL, KC_LPRN, KC_TILD, KC_RPRN, KC_PIPE,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_COLN, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_LGUI, KC_LBRC,  KC_GRV, KC_RBRC, KC_BSLS,                      XXXXXXX, KC_QUOT,   KC_LT,   KC_GT, KC_QUES, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, KC_LSFT, _______,    _______, KC_RSFT, _______
                                            //`--------------------------'  `--------------------------'
        ),

  [_LEXT] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______,  KC_ESC, XXXXXXX,  EE_CLR, QK_BOOT,  QK_RBT,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_PSCR, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, CTL_TAB, KC_BTN4, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_LCTL, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_APP, XXXXXXX, XXXXXXX, KC_RALT, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, KC_RALT,  KC_DEL,    KC_BSPC, KC_BSPC, _______
                                            //`--------------------------'  `--------------------------'
  ),

  [_LNUMS] = LAYOUT_split_3x6_3(
           // _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                      XXXXXXX,    KC_7,    KC_8,    KC_9, KC_MINS, _______,
       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9, KC_MINS, _______,
       //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_DOT,    KC_4,    KC_5,    KC_6, KC_COLN, _______,
       //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
           _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_COMM,    KC_1,    KC_2,    KC_3, KC_SLSH, _______,
       //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_F11,  KC_F12, _______,       KC_0,    KC_0, _______
                                           //`--------------------------'  `--------------------------'
  ),

  [_LEX2] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______,  KC_ESC, XXXXXXX,  EE_CLR, QK_BOOT,  QK_RBT,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END, KC_PSCR, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, CTL_TAB, KC_BTN4, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_LCTL, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_APP, XXXXXXX, XXXXXXX, KC_RALT, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______, KC_RALT,  KC_DEL,    KC_BSPC, KC_BSPC, _______
                                            //`--------------------------'  `--------------------------'
  ),
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

    switch (keycode) {
        case MY_L2:
            if (record->event.pressed) {
               last_pressed.time = record->event.time;
               layer_on(_LEXT);
           } else {
               layer_off(_LEXT);
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
               layer_on(_LEXT);
           } else {
               layer_off(_LEXT);
               if (in_tapping_term) {
                   tap_code(KC_LNG1);
               }
           }
           return false;
           break;

        case KC_ESC:
           if (record->event.pressed) {
               tap_code(KC_ESC);
               tap_code(KC_LNG2);
           }
           return false;
           break;
    }

    // set_keylog(keycode, record);
    return true;
}
