/* Copyright 2018 MechMerlin
 * Copyright 2018 Logan Huskins
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
#include "keys.h"
#include "vimkeys.h"
#include "macrokeys.h"

enum {
  LAYER_BASE,
  LAYER_BASE_ALT,
  LAYER_MACRO,
  MAKE_CMD,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // BASE
  //
  // -----------------------------------------------------------------------------------------------------
  // | GESC |  1!  |  2@  |  3#  |  4$  |  5%  |  6^  |  7&  |  8*  |  9(  |  0)  |  -_  |  =+  |  BSPC  |
  // -----------------------------------------------------------------------------------------------------
  // | TAB    |  Q   |  W   |  E   |  R   |  T   |  Y   |  U   |  I   |  O   |  P   |  [{  |  ]}  |  \|  |
  // -----------------------------------------------------------------------------------------------------
  // | BASEALT  |  A   |  S   |  D   |  F   |  G   |  H   |  J   |  K   |  L   |  ;:  |  '"  |    ENTER  |
  // -----------------------------------------------------------------------------------------------------
  // | LSHIFT     |  Z   |  X   |  C   |  V   |  B   |  N   |  M   |  ,>  |  .>  |  /?  | ONESHOT MACRO  |
  // -----------------------------------------------------------------------------------------------------
  // | LCTRL  |  LALT  |  LGUI   |                SPACE              |  RALT  |  CAPS  | BASEALT| ENTER  |
  // -----------------------------------------------------------------------------------------------------
  [LAYER_BASE] = LAYOUT_60_ansi_wrapper(
      ROW_NUM_60, \
      ROW_QWERTY_60, \
      MO(LAYER_BASE_ALT), ROW_ASDF_60, \
      ROW_SHIFT_60, OSL(LAYER_MACRO), \
      CTRL, ALT, CMD, SPACE, KC_RALT, KC_CAPS, MO(LAYER_BASE_ALT), ENTER 
    ),

  // LAYER BASE ALT
  //
  // -----------------------------------------------------------------------------------------------------
  // | ESC   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |LG+BSPC|
  // -----------------------------------------------------------------------------------------------------
  // | ______ | QUIT |CMD+W | xxxx |RELOAD|NEWTAB| xxxx | UPDIR|  UP  | xxxx | xxxx |CMD+{ |CMD+} | ____ |
  // -----------------------------------------------------------------------------------------------------
  // | ______   |CMD+A | SAVE |CMD+D | FIND |CMD+G | ____ | LEFT | DOWN | RIGHT| ____ |  `~  |    ______ |
  // -----------------------------------------------------------------------------------------------------
  // | ______     | UNDO | CUT  | COPY |PASTE | xxxx | xxxx | xxxx | xxxx | :gT  | :gt  |         ______ |
  // -----------------------------------------------------------------------------------------------------
  // | ______ | xxxxxx | _______ |                  _                | xxxxxx | xxxxxx | xxxxxx | xxxxxx |
  // -----------------------------------------------------------------------------------------------------
  [LAYER_BASE_ALT] = LAYOUT_60_ansi_wrapper(
      KC_ESC,  KG_FKEYS, LGUI(KC_BSPC),
      KC_TRNS, QUIT, CLOSE_WINDOW, xxx, RELOAD, NEW_TAB, xxx, UP_DIR, KC_UP, xxx, xxx, PREV_TAB, NEXT_TAB, xxx,
      KC_TRNS, SELECT_ALL, SAVE, DROP, FIND, FIND_NEXT, xxx, KC_LEFT, KC_DOWN, KC_RIGHT, xxx, KC_GRAVE, KC_TRNS,
      KC_TRNS, UNDO, CUT, COPY,  PASTE, xxx,  xxx, xxx, xxx, VIM_PREV_TAB, VIM_NEXT_TAB, KC_TRNS, 
      KC_TRNS, xxx, KC_TRNS,                   KC_UNDERSCORE,                   xxx, xxx, xxx, xxx
      ),

  // LAYER MACRO
  //
  // -----------------------------------------------------------------------------------------------------
  // | ESC  | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxxxx |
  // -----------------------------------------------------------------------------------------------------
  // | MAKE   |  :q  |  :w  |  :e  | xxxx | LG+T | xxxx | xxxx | xxxx | INSP | xxxx | xxxx | xxxx | xxxx |
  // -----------------------------------------------------------------------------------------------------
  // | xxxxxx   | xxxx | xxxx |  dd  | xxxx | xxxx | :noh | xxxx | xxxx | xxxx | xxxx | xxxx |    xxxxxx |
  // -----------------------------------------------------------------------------------------------------
  // | xxxxxx     | xxxx | xxxx | COPY | PASTE| xxxx | LG+N | xxxx | xxxx | xxxx | xxxx |          RESET |
  // -----------------------------------------------------------------------------------------------------
  // | ______ | xxxxxx | _______ |                ______             | ______ | xxxxxx | ______ | ______ |
  // -----------------------------------------------------------------------------------------------------
  [LAYER_MACRO] = LAYOUT_60_ansi_wrapper(
      KC_ESC, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx, xxx,
      MAKE_CMD, VIM_QUIT, VIM_WRITE, VIM_RELOAD, xxx, NEW_TAB, xxx, xxx, TOGGLE_INSPECTOR, xxx, xxx, xxx, xxx, xxx,
      xxx, xxx, xxx, VIM_DELETE_LINE, xxx, xxx, VIM_NO_HIGHLIGHTS,  xxx, xxx, xxx, xxx, xxx, xxx,
      xxx, xxx, xxx, COPY, PASTE, xxx, NEW_WINDOW, xxx, xxx, xxx, xxx, RESET,
      KC_TRNS, xxx, KC_TRNS,                   KC_TRNS,                   KC_TRNS, xxx, KC_TRNS, KC_TRNS
      ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  do_vim_key(keycode, record);
  do_macro_key(keycode, record);

  if (keycode == MAKE_CMD) {
    if (record->event.pressed) {
      SEND_STRING("make 1upkeyboards/1up60hse:lstebner");
    }
  }

  return true;
};

