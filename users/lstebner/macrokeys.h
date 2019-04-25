enum macro_keys {
  COPY,
  GUP, 
  NEW_TAB,
  NEW_WINDOW,
  NEXT_TAB,
  PASTE,
  PREV_TAB,
  TOGGLE_INSPECTOR,
};

bool do_macro_key(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  switch (keycode) {
    case COPY:
      SEND_STRING(SS_LGUI("c"));
      break;

    case PASTE:
      SEND_STRING(SS_LGUI("v"));
      break;

    case NEXT_TAB:
      SEND_STRING(SS_DOWN(X_LGUI X_LSHIFT) SS_TAP(X_RBRACKET) SS_UP(X_LGUI X_LSHIFT));
      break;

    case PREV_TAB:
      SEND_STRING(SS_DOWN(X_LGUI X_LSHIFT) SS_TAP(X_LBRACKET) SS_UP(X_LGUI X_LSHIFT));
      break;

    case NEW_TAB:
      SEND_STRING(SS_LGUI("t"));
      break;

    case NEW_WINDOW:
      SEND_STRING(SS_LGUI("n"));
      break;

    case TOGGLE_INSPECTOR:
      SEND_STRING(SS_DOWN(X_LGUI X_LALT) SS_TAP(X_I) SS_UP(X_LALT X_LGUI));
      break;

    default:
      return false;
  }

  return true;
};

