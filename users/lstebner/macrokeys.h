#pragma once

enum macro_keys {
  GUP = SAFE_RANGE, 
  NEXT_TAB,
  PREV_TAB,
  TOGGLE_INSPECTOR,
  UP_DIR,
  SUPER,
  HYPER,
  MAGNET_FULLSCREEN,
  MAGNET_CENTER,
  MAGNET_RESTORE,
};

#define HOLD_CMD        SS_DOWN(KC_LGUI)
#define HOLD_ALT        SS_DOWN(KC_LALT)
#define HOLD_CTRL       SS_DOWN(KC_LCTL)

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

    case SUPER:
      SEND_STRING(SS_DOWN(X_LGUI X_LALT X_LCTL));
      break;
    
    case HYPER:
      SEND_STRING(SS_DOWN(X_LGUI X_LALT X_LCTL));
      break;

    case MAGNET_FULLSCREEN:
      SEND_STRING(SS_DOWN(X_LGUI X_ALT) TAP_ENTER);
      break;

    case MAGNET_CENTER:
      SEND_STRING(HOLD_CMD HOLD_ALT SS_TAP(X_C));
      break;

    case MAGNET_RESTORE:
      SEND_STRING(HOLD_CMD HOLD_ALT SS_TAP(X_BACKSPACE));
      break;

    default:
      return false;
  }

  return true;
};

