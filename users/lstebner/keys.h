#pragma once

#if (!defined(LAYOUT) && defined(KEYMAP))
#define LAYOUT  KEYMAP
#endif


// remappings with nicer names
#define ALT             KC_LALT
#define CLOSE_WINDOW    LGUI(KC_W)
#define CMD             KC_LGUI
#define COPY            LGUI(X_C)
#define CTRL            KC_LCTL
#define CUT             LGUI(KC_X)
#define DROP            LGUI(KC_D)
#define ENTER           KC_ENT
#define FIND            LGUI(KC_F)
#define FIND_NEXT       LGUI(KC_G)
#define NEW_TAB         LGUI(KC_T)
#define NEW_WINDOW      LGUI(X_N)
#define PASTE           LGUI(X_V)
#define QUIT            LGUI(KC_Q)
#define RELOAD          LGUI(KC_R)
#define SAVE            LGUI(KC_S)
#define SELECT_ALL      LGUI(KC_A)
#define SPACE           KC_SPC
#define UNDO            LGUI(KC_Z)
#define ___             KC_TRNS
#define xxx             XXXXXXX
#define HOLD_CMD        SS_DOWN(KC_LGUI)
#define HOLD_ALT        SS_DOWN(KC_LALT)
#define HOLD_CMD_ALT    SS_DOWN(KC_LALT KC_LGUI)
#define HOLD_CTRL       SS_DOWN(KC_LCTL)
#define TAP_ENTER       SS_TAP(KC_ENTER)
#define TAP_DELETE      SS_TAP(KC_BACKSPACE)


// convenient rows, or "groups"

#define KG_NUMBER_KEYS   KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0
#define KG_QWERTYUIOP    KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P
#define KG_ASDFGHJKL     KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L
#define KG_ZXCVBNM       KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M
#define KG_FKEYS         KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12

// blank rows

#define BLANK1    ___
#define BLANK2    ___, ___
#define BLANK3    ___, ___, ___
#define BLANK4    ___, ___, ___, ___
#define BLANK5    ___, ___, ___, ___, ___
#define BLANK6    ___, ___, ___, ___, ___, ___
#define BLANK7    ___, ___, ___, ___, ___, ___, ___
#define BLANK8    ___, ___, ___, ___, ___, ___, ___, ___
#define BLANK9    ___, ___, ___, ___, ___, ___, ___, ___, ___
#define BLANK10   ___, ___, ___, ___, ___, ___, ___, ___, ___, ___
#define BLANK11   ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___
#define BLANK12   ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___
#define BLANK13   ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___
#define BLANK14   ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___
#define BLANK15   ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___
#define BLANK16   ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___


// this is a complete row
#define ROW_NUM_60          KC_GESC, KG_NUMBER_KEYS, KC_MINS, KC_EQL, KC_BSPC
// this is a complete row
#define ROW_QWERTY_60       KC_TAB, KG_QWERTYUIOP, KC_LBRC, KC_RBRC, KC_BSLS
// this row needs an initial key added for capslock when used
#define ROW_ASDF_60         KG_ASDFGHJKL, KC_SCLN, KC_QUOT, KC_ENT
// this row needs a trailing key added for right shift when used
#define ROW_SHIFT_60        KC_LSFT, KG_ZXCVBNM, KC_COMM, KC_DOT, KC_SLSH


// wrapper's should go somewhere else
#define LAYOUT_WRAPPER(...)           LAYOUT(__VA_ARGS__)
#define KEYMAP_WRAPPER(...)           LAYOUT(__VA_ARGS__)
#define LAYOUT_60_ansi_wrapper(...)   LAYOUT_60_ansi(__VA_ARGS__)
#define LAYOUT_niu_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)



