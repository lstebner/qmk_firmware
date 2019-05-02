#pragma once

enum vim_keycodes {
  VIM_DELETE_LINE = SAFE_RANGE,
  VIM_NEXT_TAB,
  VIM_NO_HIGHLIGHTS,
  VIM_PANE_DOWN,
  VIM_PANE_LEFT,
  VIM_PANE_RIGHT,
  VIM_PANE_UP,
  VIM_PREV_TAB,
  VIM_QUIT,
  VIM_QUITALL,
  VIM_RELOAD,
  VIM_WRITE,
};

bool do_vim_key(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) {
    return true;
  }

  switch (keycode) {
    case VIM_WRITE:
      SEND_STRING(":w" SS_TAP(X_ENTER));
      break;

    case VIM_QUIT:
      SEND_STRING(":q" SS_TAP(X_ENTER));
      break;

    case VIM_QUITALL:
      SEND_STRING(":qall" SS_TAP(X_ENTER));
      break;

    case VIM_NEXT_TAB:
      SEND_STRING("gt");
      break;
      
    case VIM_PREV_TAB:
      SEND_STRING("gT");
      break;

    case VIM_PANE_LEFT:
      SEND_STRING(SS_LCTRL("w") SS_TAP(X_LEFT));
      break;
      
    case VIM_PANE_RIGHT:
      SEND_STRING(SS_LCTRL("w") SS_TAP(X_RIGHT));
      break;

    case VIM_PANE_UP:
      SEND_STRING(SS_LCTRL("w") SS_TAP(X_UP));
      break;

    case VIM_PANE_DOWN:
      SEND_STRING(SS_LCTRL("w") SS_TAP(X_DOWN));
      break;

    case VIM_RELOAD:
      SEND_STRING(":e" SS_TAP(X_ENTER));
      break;

    case VIM_DELETE_LINE:
      SEND_STRING("dd" SS_TAP(X_ENTER));
      break;

    case VIM_NO_HIGHLIGHTS:
      SEND_STRING(":noh" SS_TAP(X_ENTER));
      break;

    default:
      return false;
  }

  return true;
};
