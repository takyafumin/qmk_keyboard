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

enum layer_names {
    _BASE  = 0,
    _LEFT  = 1,
    _RIGHT = 2,
    _EXTRA = 3,
};

enum custom_keycodes {
    MAC_PRSC = SAFE_RANGE,
    L1_EN,
    L2_JP,
    HOTKEY 
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
#define GUITAB   RGUI_T(TAB)
#define GUIESC   LGUI_T(KC_ESC)
#define S_SPC    LSFT_T(SPC)
#define S_ENT    LSFT_T(ENT)
#define S_BS     LSFT_T(BS)
// left home mods key
#define CTL_A    LCTL_T(KC_A)
#define ALT_D    RALT_T(KC_D)
#define GUI_S    LGUI_T(KC_S)
#define SFT_Z    LSFT_T(KC_Z)
#define GUIQUIT  RGUI_T(KC_QUOT)
#define ALTLBRC  RALT_T(KC_LBRC)
// right home mods key
#define CTLSCN   RCTL_T(KC_SCLN)
#define ALT_K    RALT_T(KC_K)
#define GUI_L    RGUI_T(KC_L)
#define SFTSLS   RSFT_T(KC_SLSH)
#define CTLQUOT  RCTL_T(KC_QUOT)

// Layer
#define LEFT     MO(_LEFT)
#define RIGHT    MO(_RIGHT)
#define NUMS     MO(_NUMS)
// #define LT_EN    LT(_LEFT , EN)
// #define RT_JP    LT(_RIGHT, JP)
#define EXTENT   LT(_EXTRA, KC_ENT)
#define EXT_0    LT(_EXTRA, KC_0)
#define L1_F     LT(_LEFT , KC_F)
#define L1_J     LT(_LEFT , KC_J)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3_2(
    //,--------+--------+--------+--------+--------+--------.                     ,--------+---------+--------+---------+--------+--------.
        XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U    , KC_I   , KC_O    , KC_P   , XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                     |--------+---------+--------+---------+--------+--------|
        XXXXXXX, CTL_A  , GUI_S  , ALT_D  , L1_F   , KC_G   ,                       KC_H   , L1_J    , ALT_K  , GUI_L   , CTLSCN , XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|                     |--------+---------+--------+---------+--------+--------|
        XXXXXXX, SFT_Z  , KC_X   , KC_C   , KC_V   , KC_B   ,                       KC_N   , KC_M    , KC_COMM, KC_DOT  , SFTSLS , XXXXXXX,
    //`--------+--------+--------+--------+--------+--------/                     \--------+---------+--------+---------+--------+--------'
                                   GUIESC , L1_EN  , S_SPC  ,                       S_ENT  , L2_JP   , GUITAB 
    //                          `+--------+--------+--------'                     `--------+---------+--------+'
    ),

    [_LEFT] = LAYOUT_split_3x6_3_2(
    //,--------+--------+--------+--------+--------+--------.                     ,--------+--------+--------+--------+--------+--------.
        _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, QK_RBT ,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______, CTLTAB , GUIQUIT, ALTLBRC, KC_RBRC, KC_BSLS,                       KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, KC_COLN, EE_CLR ,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______, KC_LSFT, KC_DQT , KC_LCBR, KC_RCBR, KC_PIPE,                       KC_EQL , KC_MINS, KC_LT  , KC_GT  , KC_QUES, QK_BOOT,
    //`--------+--------+--------+--------+--------+--------/                     \--------+--------+--------+--------+--------+--------'
                                  _______, _______,  _______,                        S_BS   , EXTENT , DEL
    //                          `+--------+--------+--------'                      `--------+-------+--------+'
    ),

    [_RIGHT] = LAYOUT_split_3x6_3_2(
    //,--------+--------+--------+--------+--------+--------.                     ,--------+--------+--------+--------+--------+--------.
        _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______, KC_GRV , KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS,                       XXXXXXX, XXXXXXX, KC_RALT, KC_RGUI, CTLQUOT, _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______, KC_TILD, KC_DQT , KC_LCBR, KC_RCBR, KC_PIPE,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, _______,
    //`--------+--------+--------+--------+--------+--------/                     \--------+--------+--------+--------+--------+--------'
                                  _______ , EXT_0 ,  KC_LSFT,                       _______, _______, _______
    //                          `+--------+--------+--------'                     `--------+--------+--------+'
    ),

    [_EXTRA] = LAYOUT_split_3x6_3_2(
    //,--------+--------+--------+--------+--------+--------.                     ,--------+--------+--------+--------+--------+--------.
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                       KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______,MAC_PRSC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_PSCR, _______,
    //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
        _______, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       KC_F11 , KC_F12 , HOTKEY , XXXXXXX, KC_MENU, _______,
    //`--------+--------+--------+--------+--------+--------/                     \--------+--------+--------+--------+--------+--------'
                                  _______, _______, _______,                        _______, _______, _______
    //                          `+--------+--------+--------'                     `--------+--------+--------+'
    ),
};

// キー状態を保持する構造体
typedef struct {
    uint16_t tap_timer;  // タップタイマー
    bool is_tap_hold;    // タップ後のホールド状態
    uint8_t tap_count;   // タップ回数
} tap_key_state_t;

// グローバル変数を構造体でグルーピング
static tap_key_state_t l1_state = {
    .tap_timer = 0,
    .is_tap_hold = false,
    .tap_count = 0
};
static tap_key_state_t l2_state = {
    .tap_timer = 0,
    .is_tap_hold = false,
    .tap_count = 0
};

// クリック時イベント
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool lctrl = keyboard_report->mods & MOD_BIT(KC_LCTL);

    switch (keycode) {
        case L1_EN:
            if (record->event.pressed) {
                layer_on(_LEFT);
                l2_state.tap_timer = timer_read();
                // if (l2_state.tap_count > 0) {
                //     // 連続タップ後のホールドが開始された
                //     l2_state.is_tap_hold = true;
                // } else {
                //     // シングルタップのためのタイマーを開始
                //     l2_state.tap_timer = timer_read();
                // }
            } else {
                // キーが離されたとき
                layer_off(_LEFT);
                if (timer_elapsed(l2_state.tap_timer) < TAPPING_TERM) {
                    tap_code(EN);
                }
                // if (l2_state.is_tap_hold) {
                //     l2_state.is_tap_hold = false;
                // } else if (timer_elapsed(l2_state.tap_timer) < TAPPING_TERM) {
                //     tap_code(EN);
                //     l2_state.tap_count++;
                //     wait_ms(50); // 200ms以内に連続タップがなければタップカウントをリセット
                //     l2_state.tap_count = 0;
                // } else {
                //     l2_state.is_tap_hold = true;
                // }
            }
            return false; // このキーのデフォルトの動作を無効化

        case L2_JP:
            if (record->event.pressed) {
                layer_on(_RIGHT);
                l1_state.tap_timer = timer_read();
                // キーが押されたとき
                // if (l1_state.tap_count > 0) {
                //     // 連続タップ後のホールドが開始された
                //     l1_state.is_tap_hold = true;
                // } else {
                //     // シングルタップのためのタイマーを開始
                //     l1_state.tap_timer = timer_read();
                // }
            } else {
                // キーが離されたとき
                layer_off(_RIGHT);
                if (timer_elapsed(l1_state.tap_timer) < TAPPING_TERM) {
                    tap_code(JP);
                }
                // if (l1_state.is_tap_hold) {
                //     l1_state.is_tap_hold = false;
                // } else if (timer_elapsed(l1_state.tap_timer) < TAPPING_TERM) {
                //     tap_code(JP);
                //     l1_state.tap_count++;
                //     wait_ms(50); // 200ms以内に連続タップがなければタップカウントをリセット
                //     l1_state.tap_count = 0;
                // } else {
                //     l1_state.is_tap_hold = true;
                // }
            }
            return false; // このキーのデフォルトの動作を無効化


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

        // Ctrl + J = Enter
        case KC_J:
            if (record->event.pressed) {
                if (lctrl) {
                    unregister_code(KC_LCTL);
                    tap_code(KC_ENT);
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

        // HOTKEY
        case HOTKEY:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                tap_code(KC_LGUI);
                unregister_code(KC_LSFT);
            }
            return false;
            break;
    }

    return true;
}

