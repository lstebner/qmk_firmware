/* Copyright 2018 MechMerlin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum custom_keycodes {
  CHANGE_WINDOW = SAFE_RANGE,
  COPY,
  CTRLP,
  GUP, 
  NEW_TAB,
  NEW_WINDOW,
  NEXT_APP,
  NEXT_TAB,
  PASTE,
  PREV_APP,
  PREV_TAB,
  VIM_DELETE_LINE,
  VIM_NERDTREE_TOGGLE,
  VIM_NEXT_TAB,
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

enum layers {
  LAYER_BASE,
  LAYER_BASE_ALT,
  LAYER_MACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
      MO(LAYER_BASE_ALT), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, OSL(LAYER_MACRO), KC_CAPS,
      KC_LCTL, XXXXXXX, KC_LGUI,                   KC_SPACE,                 KC_LALT, XXXXXXX, KC_ENTER
      ),

  [LAYER_BASE_ALT] = LAYOUT(
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_CAPS, LGUI(KC_BSPC),
      KC_TRNS, LGUI(KC_Q), LGUI(KC_W), LGUI(KC_E), LGUI(KC_R), LGUI(KC_T), RGB_SAD, RGB_VAI, KC_UP, KC_TRNS, KC_TRNS, LGUI(S(KC_LBRC)), LGUI(S(KC_RBRC)), KC_TRNS,
      KC_TRNS, LGUI(KC_A), LGUI(KC_S), LGUI(KC_D), LGUI(KC_F), LGUI(KC_G), KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_GRAVE, KC_TRNS,
      KC_TRNS, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C),  LGUI(KC_V), LGUI(KC_B),  BL_STEP, KC_TRNS, KC__VOLDOWN, KC__VOLUP, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, XXXXXXX, KC_TRNS,                   KC_UNDERSCORE,                   VIM_PREV_TAB, XXXXXXX, VIM_NEXT_TAB
      ),

  [LAYER_MACRO] = LAYOUT(
      VIM_QUITALL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, VIM_QUIT, VIM_WRITE, VIM_RELOAD, XXXXXXX, NEW_TAB, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, VIM_DELETE_LINE, XXXXXXX, VIM_PANE_LEFT, VIM_PANE_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, COPY, PASTE, XXXXXXX, NEW_WINDOW, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_TRNS, XXXXXXX, KC_TRNS,                   KC_TRNS,                   KC_TRNS, XXXXXXX, KC_TRNS
      ),
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

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

    case VIM_NERDTREE_TOGGLE:
      if (record->event.pressed) {
        SEND_STRING(":NERDTreeToggle" SS_TAP(X_ENTER));
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

    case VIM_RELOAD:
      if (record->event.pressed) {
        SEND_STRING(":e" SS_TAP(X_ENTER));
      }
      break;

    case VIM_DELETE_LINE:
      if (record->event.pressed) {
        SEND_STRING("dd" SS_TAP(X_ENTER));
      }
      break;
        
  }
  return true;
};

