#include QMK_KEYBOARD_H

#include "features/achordion.h"

#define HOME_C LALT_T(KC_C)
#define HOME_R LGUI_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LCTL_T(KC_T)
#define HOME_N LCTL_T(KC_N)
#define HOME_E LSFT_T(KC_E)
#define HOME_I LGUI_T(KC_I)
#define HOME_A LALT_T(KC_A)


enum layers {
    _BASE,
    _NAV,
    _SYM,
    _FUNC,
    _BOARD,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        //+------------------------------------------------------------------------+       +---------------------------------------------------------------------------+
        /**/ KC_W        , KC_L        , KC_Y        , KC_P        , KC_B        ,/*       */ KC_Z        , KC_F        , KC_O        , KC_U        , KC_GRV      , /**/
        /**/ HOME_C      , HOME_R      , HOME_S      , HOME_T      , KC_G        ,/*       */ KC_M        , HOME_N      , HOME_E      , HOME_I      , HOME_A      , /**/
        /**/ KC_Q        , KC_J        , KC_V        , KC_D        , KC_K        ,/*       */ KC_X        , KC_H        , KC_SLSH     , KC_COMM     , KC_DOT      , /**/
        /*------------------------------------------*/ KC_BSPC     , MO(_SYM)    ,/*       */ MO(_NAV)    , KC_SPC        /*------------------------------------------*/ 
                                                    /*----------------------------*/       /*-----------------------------*/
    ),
    
    [_NAV] = LAYOUT(
        //+------------------------------------------------------------------------+       +---------------------------------------------------------------------------+
        /**/ KC_VOLU     , LGUI(KC_9)  , LGUI(KC_5)  , LGUI(KC_4)  , KC_MNXT     ,/*       */ KC_MPLY     , KC_PSTE     , KC_COPY     , KC_CUT      , KC_HOME     , /**/
        /**/ LGUI(KC_TAB), LGUI(KC_3)  , LGUI(KC_2)  , LGUI(KC_1)  , LGUI(KC_0)  ,/*       */ KC_LEFT     , KC_UP       , KC_DOWN     , KC_RGHT     , KC_ENT      , /**/
        /**/ KC_VOLD     , LGUI(KC_8)  , LGUI(KC_7)  , LGUI(KC_6)  , KC_MPRV     ,/*       */ KC_INS      , KC_PGDN     , KC_PGUP     , KC_UNDO     , KC_END      , /**/
        /*------------------------------------------*/ KC_NO       , MO(_FUNC)   ,/*       */ KC_TRNS     , MO(_BOARD)    /*------------------------------------------*/ 
                                                    /*----------------------------*/       /*-----------------------------*/
    ),
    
    [_SYM] = LAYOUT(
        //+------------------------------------------------------------------------+       +---------------------------------------------------------------------------+
        /**/ KC_EXLM     , KC_AT       , KC_HASH     , KC_LCBR     , KC_LT       ,/*       */ KC_GT       , KC_RCBR     , KC_DLR      , KC_AMPR     , KC_BSLS     , /**/
        /**/ KC_COLN     , KC_SCLN     , KC_ASTR     , KC_LPRN     , KC_LBRC     ,/*       */ KC_RBRC     , KC_RPRN     , KC_MINS     , KC_UNDS     , KC_EQL      , /**/
        /**/ KC_1        , KC_2        , KC_3        , KC_4        , KC_5        ,/*       */ KC_6        , KC_7        , KC_8        , KC_9        , KC_0        , /**/
        /*------------------------------------------*/ MO(_BOARD)  , KC_TRNS     ,/*       */ MO(_FUNC)   , KC_NO         /*------------------------------------------*/
                                                    /*----------------------------*/       /*-----------------------------*/
    ),
    
    [_FUNC] = LAYOUT(
        //+------------------------------------------------------------------------+       +---------------------------------------------------------------------------+
        /**/ KC_NO       , KC_NO       , KC_NO       , KC_NO       , KC_NO       ,/*       */ KC_NO       , KC_NO       , KC_NO       , KC_NO       , KC_NO       , /**/
        /**/ KC_F1       , KC_F2       , KC_F3       , KC_F4       , KC_F5       ,/*       */ KC_F6       , KC_F7       , KC_F8       , KC_F9       , KC_F10      , /**/
        /**/ KC_NO       , KC_NO       , KC_F11      , KC_F12      , KC_NO       ,/*       */ KC_NO       , KC_NO       , KC_NO       , KC_NO       , KC_NO       , /**/
        /*------------------------------------------*/ KC_NO       , KC_TRNS     ,/*       */ KC_TRNS     , KC_NO         /*------------------------------------------*/
                                                    /*----------------------------*/       /*-----------------------------*/
    ),
    
    [_BOARD] = LAYOUT(
        //+------------------------------------------------------------------------+       +---------------------------------------------------------------------------+
        /**/ KC_NO       , KC_NO       , KC_NO       , KC_NO       , KC_NO       ,/*       */ KC_NO       , KC_NO       , KC_NO       , KC_NO       , KC_NO       , /**/
        /**/ KC_NO       , KC_NO       , KC_NO       , KC_NO       , QK_BOOT     ,/*       */ QK_BOOT     , KC_NO       , KC_NO       , KC_NO       , KC_NO       , /**/
        /**/ KC_NO       , KC_NO       , KC_NO       , KC_NO       , KC_NO       ,/*       */ KC_NO       , KC_NO       , KC_NO       , KC_NO       , KC_NO       , /**/
        /*------------------------------------------*/ KC_TRNS     , KC_TRNS     ,/*       */ KC_TRNS     , KC_TRNS       /*------------------------------------------*/ 
                                                    /*----------------------------*/       /*-----------------------------*/
    )
};
// clang-format on

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    // Increase the tapping term a little for slower ring and pinky fingers.
    case HOME_C:
    case HOME_R:
    case HOME_I:
    case HOME_A:
      return TAPPING_TERM + 15;

    default:
      return TAPPING_TERM;
  }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
    case HOME_N:
        return QUICK_TAP_TERM;
    default:
        return 0;
    }
}

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  return 1000;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }
  // Your macros ...

  return true;
}

void matrix_scan_user(void) {
  achordion_task();
}
