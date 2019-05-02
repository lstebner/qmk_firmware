#pragma once

enum macro_keys {
  GUP = SAFE_RANGE, 
  NEXT_TAB,
  PREV_TAB,
  TOGGLE_INSPECTOR,
  UP_DIR,
};

bool do_macro_key(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  switch (keycode) {
    case NEXT_TAB:
      SEND_STRING(SS_DOWN(X_LGUI X_LSHIFT) SS_TAP(X_RBRACKET) SS_UP(X_LGUI X_LSHIFT));
      break;

    case PREV_TAB:
      SEND_STRING(SS_DOWN(X_LGUI X_LSHIFT) SS_TAP(X_LBRACKET) SS_UP(X_LGUI X_LSHIFT));
      break;

    case TOGGLE_INSPECTOR:
      SEND_STRING(SS_DOWN(X_LGUI X_LALT) SS_TAP(X_I) SS_UP(X_LALT X_LGUI));
      break;

    case UP_DIR:
      SEND_STRING("../");
      break;

    default:
      return false;
  }

  return true;
};

