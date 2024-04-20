#include QMK_KEYBOARD_H

#define BASE 0
#define HHKB 1
#define MARK 2
#define NUM  3
#define EXT  4

// --------------------
// キーのalias
// --------------------
// control
#define CTL_A     LCTL_T(KC_A)
#define CTLTAB    LCTL_T(KC_TAB)
#define CT_SCL    LCTL_T(KC_SCLN)

// gui
#define GUI_L1    LGUI_T(KC_LNG1)
#define GUIESC    LGUI_T(KC_ESC)

// alt
#define ALTTAB    RALT_T(KC_TAB)

// shift
#define SFT_SP    LSFT_T(KC_SPC)
#define SFT_F     LSFT_T(KC_F)
#define SFT_J     LSFT_T(KC_J)

// layer
#define L2_EXT    LT(EXT, KC_LNG2)
#define NUM_Z     LT(NUM, KC_Z)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT( //  default layer
        KC_ESC,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5   , XXXXXXX, KC_6,   KC_7,   KC_8,    KC_9,   KC_0,   KC_SLSH,  KC_GRV,  KC_BSLS,
        KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   XXXXXXX, XXXXXXX, KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,   KC_MINS,  KC_EQL,
        CTL_A,   KC_S,   KC_D,   SFT_F,  KC_G,   XXXXXXX, XXXXXXX, KC_H,   SFT_J,  KC_K,    KC_L,   CT_SCL, KC_ENT,
        NUM_Z,   KC_X,   KC_C,   KC_V,   KC_B,   XXXXXXX, XXXXXXX, KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,MO(HHKB),
        GUIESC , L2_EXT, /*           */ SFT_SP, GUI_L1 , ALTTAB
    ),

    [NUM] = LAYOUT(
        KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_0, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,/*              */    KC_0, KC_ENT,  XXXXXXX
    ),

    [EXT] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9, KC_0   , KC_PSCR, XXXXXXX, XXXXXXX,
        KC_TAB , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        XXXXXXX, XXXXXXX,/*              */ KC_BSPC, KC_BSPC, XXXXXXX
    ),

    [HHKB] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, KC_TRNS, KC_TRNS, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP,   KC_BSPC,
        KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, XXXXXXX, XXXXXXX, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
};

