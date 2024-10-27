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
#define GUITAB   LGUI_T(TAB)
#define GUIESC   LGUI_T(ESC)
// home mod key left
#define SFT_F    LSFT_T(KC_F)
#define ALT_D    RALT_T(KC_D)
#define GUI_S    LGUI_T(KC_S)
#define CTL_A    LCTL_T(KC_A)
#define SFT_Z    LSFT_T(KC_Z)
#define SFTQUOT  LSFT_T(KC_QUOT)
#define CTLQUOT  LCTL_T(KC_QUOT)

// home mod key right
#define SFT_J    LSFT_T(KC_J)
#define ALT_K    RALT_T(KC_K)
#define GUI_L    LGUI_T(KC_L)
#define SFT_DN   LSFT_T(KC_DOWN)
#define ALT_UP   RALT_T(KC_UP)
#define GUI_RT   LGUI_T(KC_RIGHT)
#define CTLSCN   RCTL_T(KC_SCLN)
#define SFTSLS   LSFT_T(KC_SLSH)
#define SFTLBRC  LSFT_T(KC_LBRC)
#define ALTRBRC  RALT_T(KC_RBRC)
#define SFTRBRC  LSFT_T(KC_RBRC)
#define ALTLBRC  RALT_T(KC_LBRC)

// Layer
#define LEFT     MO(_LEFT)
#define LFT_V    LT(_LEFT, KC_V)
#define RIGHT    MO(_RIGHT)
#define EXTRA    MO(_EXTRA)
#define EXT_0    LT(_EXTRA, KC_0)
#define EXTMINS  LT(_EXTRA, KC_MINS)
#define NUMS     MO(_NUMS)
#define LT_EN    LT(LEFT, EN)
#define RT_JP    LT(RIGHT, JP)

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
            KC_LGUI, SFT_Z  , KC_X   , KC_C   , LFT_V  , KC_B   ,                      KC_N   , KC_M   , KC_COMM, KC_DOT , SFTSLS , KC_RALT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                GUIESC , MN_EN  , S_SPC ,     S_ENT  , MN_JP  , GUITAB
                                            //`--------------------------'  `--------------------------'
  ),
  [_LEFT] = LAYOUT_split_3x6_3(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_UNDS,
        //|-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, CTLTAB , KC_LGUI, ALTLBRC, SFTRBRC, KC_BSLS,                      KC_LEFT, SFT_DN , ALT_UP , GUI_RT , CTLQUOT, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_LSFT, XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE,                      KC_EQL , KC_MINS, KC_LT  , KC_GT  , KC_QUES, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                               _______, _______, _______,     S_BS   , EXTMINS, DEL
                                           //`--------------------------'  `--------------------------'
  ),
  [_RIGHT] = LAYOUT_split_3x6_3(
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        //|-----------------------------------------------------.                    ,-----------------------------------------------------.
            _______, KC_GRV , XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS,                      KC_LEFT, SFT_DN , ALT_UP , GUI_RT , KC_RCTL, _______,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            _______, KC_TILD, XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT, _______,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                _______ , EXT_0 , _______,    _______, _______, _______
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
                                                _______, _______, _______,    _______, _______, _______
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

typedef struct {
    bool pressed;
    uint16_t time;
    bool tap;
    bool double_tap;
    uint16_t active_keycode;
    uint16_t prev_active_keycode;
} key_state_t;

static key_state_t lower_key = {false, 0, false, false, KC_NO, KC_NO}; // 初期状態は無効なキーコード
static key_state_t raise_key = {false, 0, false, false, KC_NO, KC_NO}; // 初期状態は無効なキーコード

void handle_key_press(key_state_t *key_state, uint16_t event_time, uint16_t current_keycode) {
    if (!key_state->pressed) {
        // 初回のキー押下
        key_state->time = event_time;
        key_state->pressed = true;
        key_state->tap = true;
        key_state->prev_active_keycode = key_state->active_keycode; // 現在の状態を保存
        key_state->active_keycode = current_keycode; // 現在のキーコードを更新
    } else if (key_state->pressed && (TIMER_DIFF_16(event_time, key_state->time) <= TAPPING_TERM)) {
        // ダブルタップの2回目の押下
        key_state->pressed = false;
        key_state->double_tap = true;
        key_state->tap = false;
    } else {
        // 長押しの開始
        key_state->time = event_time;
        key_state->pressed = true;
        key_state->tap = true;
        key_state->prev_active_keycode = key_state->active_keycode; // 現在の状態を保存
        key_state->active_keycode = current_keycode; // 現在のキーコードを更新
    }
}

void handle_key_release(key_state_t *key_state, uint16_t event_time, uint16_t tap_keycode, uint8_t layer) {
    if (key_state->tap && (TIMER_DIFF_16(event_time, key_state->time) <= TAPPING_TERM)) {
        // タップ時の処理
        tap_code(tap_keycode);
        key_state->prev_active_keycode = key_state->active_keycode; // 前の状態を更新
        key_state->active_keycode = tap_keycode;
        key_state->tap = false;
    } else if (key_state->double_tap && (TIMER_DIFF_16(event_time, key_state->time) <= TAPPING_TERM)) {
        // ダブルタップ時の処理
        key_state->double_tap = false;
        // タップ前の状態に戻す
        if (key_state->prev_active_keycode != tap_keycode) {
            tap_code(key_state->prev_active_keycode);
            key_state->active_keycode = key_state->prev_active_keycode;
        }
    }
    // キーが離されたときの共通処理
    key_state->pressed = false;
    layer_off(layer); // レイヤーを無効にする
}

// --------------------
// クリック時イベント
// --------------------
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Left Ctrlが押されているか
    bool lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);

    switch (keycode) {

        case MN_EN:
            if (record->event.pressed) {
                handle_key_press(&lower_key, record->event.time, EN);
                layer_on(_LEFT); // レイヤーを有効にする
            } else {
                handle_key_release(&lower_key, record->event.time, EN, _LEFT);
            }
            return false;

        case MN_JP:
            if (record->event.pressed) {
                handle_key_press(&raise_key, record->event.time, JP);
                layer_on(_RIGHT); // レイヤーを有効にする
            } else {
                handle_key_release(&raise_key, record->event.time, JP, _RIGHT);
            }
            return false;

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
