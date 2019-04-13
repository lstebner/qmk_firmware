#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum custom_keycodes {
  GIT_ADD_P = SAFE_RANGE,
  GIT_BRANCH,
  GIT_CHERRY_PICK,
  GIT_DIFF,
  GIT_FETCH,
  GIT_LOG,
  GIT_PULL,
  GIT_PUSH,
  GIT_STASH_POP,
  GIT_STASH_SAVE,
  GIT_STATUS,
  GIT_CURRENT_BRANCH,
  GIT_RESET,
  GUP, 
  NEW_TAB,
  NEW_WINDOW,
  PREV_TAB,
  NEXT_TAB,
  VIM_NEXT_TAB,
  VIM_PREV_TAB,
  VIM_WRITE,
  VIM_QUIT,
  VIM_QUITALL,
  VIM_NERDTREE_TOGGLE,
  VIM_PANE_LEFT,
  VIM_PANE_RIGHT,
  VIM_PANE_DOWN,
  VIM_PANE_UP,
  CTRLP,
  COPY,
  PASTE,
  NEXT_APP,
  PREV_APP,
  CHANGE_WINDOW,
};

enum layers {
  LAYER_BASE,
  LAYER_BASE_ALT,
  LAYER_MACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_ortho_4x4(
    KC_7,   KC_8,   KC_9,   KC__VOLUP, \
    KC_4,   KC_5,   KC_6,   KC__VOLDOWN, \
    KC_1,   KC_2,   KC_3,   OSL(LAYER_BASE_ALT), \
    KC_0,   MO(LAYER_MACRO),  PREV_TAB, NEXT_TAB
  ),
  [LAYER_BASE_ALT] = LAYOUT_ortho_4x4(
    GIT_BRANCH,   GIT_RESET,   GIT_STASH_POP, PASTE, \
    GIT_LOG,   GUP,         GIT_STASH_SAVE,   COPY, \
    GIT_DIFF,   GIT_FETCH,   GIT_PUSH,   NEW_WINDOW, \
    GIT_STATUS,   GIT_PULL,  GIT_ADD_P, NEW_TAB 
  ),
  [LAYER_MACRO] = LAYOUT_ortho_4x4(
    KC_ESC, XXXXXXX, VIM_PANE_UP, VIM_PANE_DOWN, \
    CTRLP, XXXXXXX, VIM_PANE_LEFT, VIM_PANE_RIGHT, \
    VIM_NERDTREE_TOGGLE, XXXXXXX, PREV_APP, NEXT_APP, \
    CHANGE_WINDOW, _______, VIM_PREV_TAB, VIM_NEXT_TAB
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case GIT_ADD_P:
      if (record->event.pressed) {
        SEND_STRING("git add -p" SS_TAP(X_ENTER));
      } else {
      }
      break;

    case GIT_BRANCH:
      if (record->event.pressed) {
        SEND_STRING("git branch" SS_TAP(X_ENTER));
      } else {
      }
      break;

    case GIT_CHERRY_PICK:
      if (record->event.pressed) {
        //SEND_STRING("git cherry-pick " MACRO( D(LGUI), T(C), U(LGUI), END  ) SS_TAP(X_ENTER));
        SEND_STRING("coming soon");
      } else {
      }
      break;

    case GIT_DIFF:
      if (record->event.pressed) {
        SEND_STRING("git diff" SS_TAP(X_ENTER));
      } else {
      }
      break;

    case GIT_FETCH:
      if (record->event.pressed) {
        SEND_STRING("git fetch" SS_TAP(X_ENTER));
      } else {
      }
      break;

    case GIT_LOG:
      if (record->event.pressed) {
        SEND_STRING("git log --name-only --stat" SS_TAP(X_ENTER));
      } else {
      }
      break;

    case GIT_PULL:
      if (record->event.pressed) {
        SEND_STRING("git pull --rebase origin HEAD" SS_TAP(X_ENTER));
      } else {
      }
      break;

    case GIT_PUSH:
      if (record->event.pressed) {
        SEND_STRING("git push origin HEAD" SS_TAP(X_ENTER));
      } else {
      }
      break;

    case GUP:
      if (record->event.pressed) {
        SEND_STRING("gup master" SS_TAP(X_ENTER));
      } else {
      }
      break;

    case GIT_STASH_POP:
      if (record->event.pressed) {
        SEND_STRING("git stash pop" SS_TAP(X_ENTER));
      } else {
      }
      break;

    case GIT_STASH_SAVE:
      if (record->event.pressed) {
        SEND_STRING("git stash save" SS_TAP(X_ENTER));
      } else {
      }
      break;

    case GIT_STATUS:
      if (record->event.pressed) {
        SEND_STRING("git status" SS_TAP(X_ENTER));
      } else {
      }
      break;
      
    case GIT_CURRENT_BRANCH:
      if (record->event.pressed) {
        SEND_STRING("git branch | grep \\* | cut -d ' ' -f2" SS_TAP(X_ENTER));
      } else {
      }
      break;

    case GIT_RESET:
      if (record->event.pressed) {
        SEND_STRING("git reset" SS_TAP(X_ENTER));
      } else {
      }
      break;

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

    case VIM_NERDTREE_TOGGLE:
      if (record->event.pressed) {
        SEND_STRING(":NERDTreeFind" SS_TAP(X_ENTER));
      }
      break;

    case CTRLP:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("p"));
      }
      break;

    case VIM_WRITE:
      if (record->event.pressed) {
        SEND_STRING(":w" SS_TAP(X_ENTER));
      }
      break;

    case VIM_QUIT:
      if(record->event.pressed) {
        SEND_STRING(":q" SS_TAP(X_ENTER));
      }
      break;

    case VIM_QUITALL:
      if (record->event.pressed) {
        SEND_STRING(":qall" SS_TAP(X_ENTER));
      }
      break;

    case VIM_NEXT_TAB:
      if (record->event.pressed) {
        SEND_STRING("gt");
      }
      break;

    case VIM_PREV_TAB:
      if (record->event.pressed) {
        SEND_STRING("gT");
      }
      break;

    case VIM_PANE_LEFT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("w") SS_TAP(X_LEFT));
      }
      break;

    case VIM_PANE_RIGHT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("w") SS_TAP(X_RIGHT));
      }
      break;
      
    case VIM_PANE_UP:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("w") SS_TAP(X_UP));
      }
      break;

    case VIM_PANE_DOWN:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("w") SS_TAP(X_DOWN));
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

