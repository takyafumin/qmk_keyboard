#include QMK_KEYBOARD_H

#define BASE 0
#define HHKB 1
#define VIM  2
#define NUM  3
#define EXT  4

// --------------------
// キーのalias
// --------------------
// control
#define CT_QUOT   LCTL_T(KC_QUOT)
#define CT_TAB    LCTL_T(KC_TAB)
#define CTL_A     LCTL_T(KC_A)
#define CTLSCLN   LCTL_T(KC_SCLN)

// gui
#define GUI_W     LGUI_T(KC_W)
#define GUI_L1    LGUI_T(KC_LNG1)

// alt
#define ALT_L     RALT_T(KC_L)

// shift
#define SFT_SPC   LSFT_T(KC_SPC)
#define SFT_K     LSFT_T(KC_K)
#define SFT_D     LSFT_T(KC_D)
#define SFT_F     LSFT_T(KC_F)
#define SFT_J     LSFT_T(KC_J)

// layer
#define L1_EXT    LT(EXT, KC_LNG1)
#define L2_EXT    LT(EXT, KC_LNG2)
#define F_VIM     LT(VIM, KC_F)
#define J_VIM     LT(VIM, KC_J)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE Level: Default Layer
     |--------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | ESC    | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | -     | =   | \     | ` |
     |--------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Tab    | Q | W | E | R | T | Y | U | I | O | P | [     | ]   | Backs |   |
     |--------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | CntlTab| A | S | D | F | G | H | J | K | L | ; | '     | Ent |       |   |
     |--------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|
     | Shift  | Z | X | C | V | B | N | M | , | . | / | Shift | Fn0 |       |   |
     |--------+---+---+---+---+---+---+---+---+---+---+-------+-----+-------+---|

            |------+------+-----------------------+------+------|
            | LGUI | LNG2 | ******* Space ******* | LNG1 | RAlt |
            |------+------+-----------------------+------+------|
    */

    [BASE] = LAYOUT( //  default layer
        KC_ESC,   KC_1,   KC_2,   KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,      KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_GRV,
        KC_TAB,   KC_Q,   GUI_W,  KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,      KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,
        CT_TAB,   CTL_A,  KC_S,   SFT_D,   SFT_F,   KC_G,    KC_H,    SFT_J,   SFT_K,     ALT_L,   CTLSCLN,  CT_QUOT,  KC_ENT,
        KC_RSFT,  KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,   KC_DOT,  KC_SLSH,  KC_LSFT,  MO(HHKB),
        MO(NUM),  L2_EXT, /*           */  KC_SPC,  GUI_L1,  KC_RALT
    ),

    /* Layer HHKB: HHKB mode (HHKB Fn)
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Pwr  | F1  | F2  | F3  | F4 | F5 | F6 | F7 | F8  | F9  | F10 | F11 | F12   | Ins   | Del |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      | Caps |     |     |     |    |    |    |    | Psc | Slk | Pus | Up  |       | Backs |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      | VoD | VoU | Mut |    |    | *  | /  | Hom | PgU | Lef | Rig | Enter |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|
      |      |     |     |     |    |    | +  | -  | End | PgD | Dow |     |       |       |     |
      |------+-----+-----+-----+----+----+----+----+-----+-----+-----+-----+-------+-------+-----|

                 |------+------+----------------------+------+------+
                 | **** | **** | ******************** | **** | **** |
                 |------+------+----------------------+------+------+

     */

    [HHKB] = LAYOUT(
        KC_PWR,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_DEL,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SCRL, KC_PAUS, KC_UP,   KC_TRNS, KC_BSPC,
        KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [VIM] = LAYOUT(
        KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,  KC_ESC, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_HOME, KC_PGDN, KC_END,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_APP,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,/*              */ KC_BSPC, XXXXXXX, XXXXXXX),

    [NUM] = LAYOUT(
        KC_TRNS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_0, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,/*              */    KC_0, KC_ENT,  XXXXXXX),

    [EXT] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_ESC , KC_LGUI, KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX,
         CT_TAB, CT_TAB , KC_HOME, KC_PGDN, KC_END,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_RALT,/*              */ KC_BSPC, KC_DEL , XXXXXXX),

};

