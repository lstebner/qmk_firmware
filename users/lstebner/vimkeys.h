#pragma once

enum vim_keycodes {
  VIM_DELETE_LINE = SAFE_RANGE,
  VIM_NEXT_TAB,
  VIM_NO_HIGHLIGHTS,
  VIM_NOH,
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
  switch (keycode) {
    case VIM_WRITE:
      if (!record->event.pressed) {
        SEND_STRING(":w" SS_TAP(X_ENTER));
      }
      break;

    case VIM_QUIT:
      if (!record->event.pressed) {
        SEND_STRING(":q" SS_TAP(X_ENTER));
      }
      break;

    case VIM_QUITALL:
      if (!record->event.pressed) {
        SEND_STRING(":qall" SS_TAP(X_ENTER));
      }
      break;

    case VIM_NEXT_TAB:
      if (!record->event.pressed) {
        SEND_STRING("gt");
      }
      break;
      
    case VIM_PREV_TAB:
      if (!record->event.pressed) {
        SEND_STRING("gT");
      }
      break;

    case VIM_PANE_LEFT:
      if (!record->event.pressed) {
        SEND_STRING(SS_LCTRL("w") SS_TAP(X_LEFT));
      }
      break;
      
    case VIM_PANE_RIGHT:
      if (!record->event.pressed) {
        SEND_STRING(SS_LCTRL("w") SS_TAP(X_RIGHT));
      }
      break;

    case VIM_PANE_UP:
      if (!record->event.pressed) {
        SEND_STRING(SS_LCTRL("w") SS_TAP(X_UP));
      }
      break;

    case VIM_PANE_DOWN:
      if (!record->event.pressed) {
        SEND_STRING(SS_LCTRL("w") SS_TAP(X_DOWN));
      }
      break;

    case VIM_RELOAD:
      if (!record->event.pressed) {
        SEND_STRING(":e" SS_TAP(X_ENTER));
      }
      break;

    case VIM_DELETE_LINE:
      if (!record->event.pressed) {
        SEND_STRING("dd" SS_TAP(X_ENTER));
      }
      break;

    case VIM_NO_HIGHLIGHTS:
    case VIM_NOH:
      if (!record->event.pressed) {
        SEND_STRING(":noh" SS_TAP(X_ENTER));
      }
      break;
  }

  return true;
};
