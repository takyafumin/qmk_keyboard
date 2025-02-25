#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE
};

enum layer_number {
    _QWERTY = 0,
    _RAISE,
    _LOWER,
};

// common
#define KC_ KC_TRNS
#define KC_XXXX KC_NO
#define KC_RST RESET
#define KC_VD KC__VOLDOWN
#define KC_VU KC__VOLUP

// layer
#define KC_L_SPC LT(_LOWER, KC_SPC)
#define KC_R_ENT LT(_RAISE, KC_ENT)

// shift_t
#define KC_S_EN LSFT_T(KC_LANG2)
#define KC_S_JA LSFT_T(KC_LANG1)

// cmd_t
#define KC_G_F LCMD_T(KC_F)
#define KC_G_J RCMD_T(KC_J)
#define KC_CMDLBRC LCMD(KC_LBRC)
#define KC_CMDRBRC LCMD(KC_RBRC)
#define KC_CMDLCBR LCMD(KC_LCBR)
#define KC_CMDRCBR LCMD(KC_RCBR)

// ctl_t
#define KC_C_G LCTL_T(KC_G)
#define KC_C_H RCTL_T(KC_H)

#define KC_C1 LCTL(KC_1)
#define KC_C2 LCTL(KC_2)
#define KC_C3 LCTL(KC_3)
#define KC_C4 LCTL(KC_4)
#define KC_C5 LCTL(KC_5)

// alt_t
#define KC_A_D ALT_T(KC_D)
#define KC_A_K ALT_T(KC_K)

// cmd+shift_t
#define KC_GS_S SCMD_T(KC_S)
#define KC_GS_L SCMD_T(KC_L)

//
#define KC_MISS C(KC_UP)

#define TAPPING_LAYER_TERM 230
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_GS_S:
      return TAPPING_LAYER_TERM;
    case KC_GS_L:
      return TAPPING_LAYER_TERM;
    case KC_A_D:
      return TAPPING_LAYER_TERM;
    case KC_A_K:
      return TAPPING_LAYER_TERM;
    default:
      return TAPPING_TERM;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // M_ = LCMD_T(
  // A_ = ALT_T(
  // C_ = LCTL_T(
  // MS_ = SMD_T(
  // R_ = LT(_RAISE
  // L_ = LT(_LOWER

  [_QWERTY] = LAYOUT_kc( \
  //,----+----+----+----+----+----.        ,----+----+----+----+----+----.
      ESC, Q  , W  , E  , R  , T  ,          Y  , U  , I  , O  , P  ,MINS,
  //|----+----+----+----+----+----|        |----+----+----+----+----+----|
      TAB, A  ,GS_S,A_D ,G_F ,C_G , NO,  BSPC,  C_H ,G_J ,A_K ,GS_L,SCLN,ESC ,
  //|----+----+----+----+----+----+        |----+----+----+----+----+----|
     LEFT, Z  , X  , C  , V  , B  , NO,  DEL,   N  , M  ,COMM,DOT ,SLSH,RGHT,
  //`----+----+----+----+----+----/        \----+----+----+----+----+----'
                CMDLBRC,S_EN,L_SPC,       R_ENT,S_JA,CMDRBRC
  //          `----+----+----+----'        `----+----+----+----'
  ),

  //   \ ! & |      = + * %
  //   # ` " ' ~  ← ↓ ↑ → $
  //       { [ (  ) ] } @ ^

  [_RAISE] = LAYOUT_kc( \
  //,----+----+----+----+----+----.        ,----+----+----+----+----+----.
         ,BSLS,EXLM,AMPR,PIPE,XXXX,         XXXX,EQL ,PLUS,ASTR,PERC,MINS,
  //|----+----+----+----+----+----|        |----+----+----+----+----+----|
         ,HASH,GRV ,DQT ,QUOT,TILD,  ,   ,  LEFT,DOWN, UP ,RGHT,DLR ,    ,
  //|----+----+----+----+----+----|        |----+----+----+----+----+----|
         ,    ,    ,LCBR,LBRC,LPRN,  ,   ,  RPRN,RBRC,RCBR,AT  ,CIRC,    ,
  //`----+----+----+----+----+----/        \----+----+----+----+----+----'
                 CMDLCBR,    ,BSPC         ,    ,    ,RST
  //          `----+----+----+----'        `----+----+----+----'
  ),

  [_LOWER] = LAYOUT_kc( \
  //,----+----+----+----+----+----.        ,----+----+----+----+----+----.
         , C1 , C2 , C3 , C4 , C5 ,         XXXX,EQL ,PLUS,ASTR,PERC,MINS,
  //|----+----+----+----+----+----|        |----+----+----+----+----+----|
         , 1  , 2  , 3  , 4  , 5  ,  ,   ,   6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----|        |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,  ,   ,      ,    ,COMM,DOT ,SLSH,    ,
  //`----+----+----+----+----+----/        \----+----+----+----+----+----'
                    RST ,    ,    ,        DEL ,    ,CMDRCBR
  //          `----+----+----+----'        `----+----+----+----'
  ),

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {        // left ↓
        if (clockwise) {
            tap_code(KC_WH_U);
        } else {
            tap_code(KC_WH_D);
        }
    } else if (index == 1) { // left ↑
        if (clockwise) {
            //tap_code(KC__VOLDOWN);
            tap_code16(RSA(KC_F11));

        } else {
            //tap_code(KC__VOLUP);
            tap_code16(RSA(KC_F12));
        }
    } else if (index == 2) { // left ↑
        if (clockwise) {
            tap_code(KC_WH_U);

        } else {
            tap_code(KC_WH_D);
        }
     } else if (index == 3) { // left ↑
        if (clockwise) {
            //tap_code(KC__VOLDOWN);
            tap_code16(RSA(KC_F11));

        } else {
            //tap_code(KC__VOLUP);
            tap_code16(RSA(KC_F12));
        }
    }




    return true;
}
