#pragma once

#include "keys.h"

enum macro_keys {
  GUP = SAFE_RANGE, 
  TOGGLE_INSPECTOR,
  UP_DIR,
  MAGNET_FULLSCREEN,
  MAGNET_CENTER,
  MAGNET_RESTORE,
};

#define NEXT_TAB  LGUI(KC_RCBR)
#define PREV_TAB  LGUI(KC_LCBR)

bool do_macro_key(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  switch (keycode) {
    case TOGGLE_INSPECTOR:
      SEND_STRING(SS_DOWN(X_LGUI X_LALT) SS_TAP(X_I) SS_UP(X_LALT X_LGUI));
      return false;
      break;

    case UP_DIR:
      SEND_STRING("../");
      return false;
      break;

    case MAGNET_FULLSCREEN:
      //SEND_STRING(HOLD_CMD_ALT TAP_ENTER);
      break;

    case MAGNET_CENTER:
      //SEND_STRING(HOLD_CMD_ALT SS_TAP(X_C));
      break;

    case MAGNET_RESTORE:
      //SEND_STRING(HOLD_CMD_ALT TAP_DELETE);
      break;
  }

  return true;
};

