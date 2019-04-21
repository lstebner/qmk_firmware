#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum custom_keycodes {
  NEW_TAB,
  NEW_WINDOW,
  PREV_TAB,
  NEXT_TAB,
  COPY,
  PASTE,
  NEXT_APP,
  PREV_APP,
  CHANGE_WINDOW,
};

enum layers {
  LAYER_NUMPAD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // NUMPAD
  // 
  // -------------------------
  // |  7  |  8  |  9  |  +  |
  // -------------------------
  // |  4  |  5  |  6  |  -  |
  // -------------------------
  // |  1  |  2  |  3  |BACK |
  // -------------------------
  // |  .  |  0  |LEFT |RIGHT|
  // -------------------------
  [LAYER_NUMPAD] = LAYOUT_ortho_4x4(
    KC_7,     KC_8,     KC_9,     KC_KP_PLUS, \
    KC_4,     KC_5,     KC_6,     KC_KP_MINUS, \
    KC_1,     KC_2,     KC_3,     KC_BSPACE, \
    KC_KP_DOT,KC_0,     KC_LEFT,  KC_RIGHT 
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NEXT_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSHIFT) SS_TAP(X_RBRACKET) SS_UP(X_LGUI) SS_UP(X_LSHIFT));
      }
      break;

    case PREV_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSHIFT) SS_TAP(X_LBRACKET) SS_UP(X_LGUI) SS_UP(X_LSHIFT));
      }
      break;

    case NEW_TAB:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("t"));
      }
      break;

    case NEW_WINDOW:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("n"));
      }
      break;

    case COPY:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("c"));
      }
      break;

    case PASTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI("v"));
      }
      break;

    case CHANGE_WINDOW:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_GRAVE)));
      }
      break;

    case NEXT_APP:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_TAB)));
      }
      break;

    case PREV_APP:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LGUI) SS_DOWN(X_LSHIFT) SS_TAP(X_TAB) SS_UP(X_LGUI) SS_UP(X_LSHIFT));
      }
      break;
        
  }
  return true;
};

