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
  // | ESC   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |LG+BSPC |
  // -----------------------------------------------------------------------------------------------------
  // | ______ | LG+Q | LG+W | LG+E | LG+R | LG+T | xxxx | xxxx |  UP  | xxxx | xxxx | LG+{ | LG+} | ____ |
  // -----------------------------------------------------------------------------------------------------
  // | ______   | LG+A | LG+S | LG+D | LG+F | LG+G | ____ | LEFT | DOWN | RIGHT| ____ |  `~  |    ______ |
  // -----------------------------------------------------------------------------------------------------
  // | ______     | LG+Z | LG+X | LG+C | LG+V | LG+B | xxxx | xxxx | xxxx | :gT  | :gt  |         ______ |
  // -----------------------------------------------------------------------------------------------------
  // | ______ | xxxxxx | _______ |                  _                | xxxxxx | xxxxxx | xxxxxx | xxxxxx |
  // -----------------------------------------------------------------------------------------------------
  [LAYER_BASE_ALT] = LAYOUT_60_ansi(
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, LGUI(KC_BSPC),
      KC_TRNS, LGUI(KC_Q), LGUI(KC_W), LGUI(KC_E), LGUI(KC_R), LGUI(KC_T), XXXXXXX, XXXXXXX, KC_UP, XXXXXXX, XXXXXXX, LGUI(S(KC_LBRC)), LGUI(S(KC_RBRC)), XXXXXXX,
      KC_TRNS, LGUI(KC_A), LGUI(KC_S), LGUI(KC_D), LGUI(KC_F), LGUI(KC_G), XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, KC_GRAVE, KC_TRNS,
      KC_TRNS, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C),  LGUI(KC_V), LGUI(KC_B),  XXXXXXX, XXXXXXX, XXXXXXX, VIM_PREV_TAB, VIM_NEXT_TAB, KC_TRNS, 
      KC_TRNS, XXXXXXX, KC_TRNS,                   KC_UNDERSCORE,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
      ),

  // LAYER MACRO
  //
  // -----------------------------------------------------------------------------------------------------
  // | ESC  | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxx | xxxxxx |
  // -----------------------------------------------------------------------------------------------------
  // | xxxxxx |  :q  |  :w  |  :e  | xxxx | LG+T | xxxx | xxxx | xxxx | INSP | xxxx | xxxx | xxxx | xxxx |
  // -----------------------------------------------------------------------------------------------------
  // | xxxxxx   | xxxx | xxxx |  dd  | xxxx | xxxx | :noh | xxxx | xxxx | xxxx | xxxx | xxxx |    xxxxxx |
  // -----------------------------------------------------------------------------------------------------
  // | xxxxxx     | xxxx | xxxx | COPY | PASTE| xxxx | LG+N | xxxx | xxxx | xxxx | xxxx |         xxxxxx |
  // -----------------------------------------------------------------------------------------------------
  // | ______ | xxxxxx | _______ |                ______             | ______ | xxxxxx | ______ | ______ |
  // -----------------------------------------------------------------------------------------------------
  [LAYER_MACRO] = LAYOUT_60_ansi(
      KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, VIM_QUIT, VIM_WRITE, VIM_RELOAD, XXXXXXX, NEW_TAB, XXXXXXX, XXXXXXX, TOGGLE_INSPECTOR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, VIM_DELETE_LINE, XXXXXXX, XXXXXXX, VIM_NO_HIGHLIGHTS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, COPY, PASTE, XXXXXXX, NEW_WINDOW, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_TRNS, XXXXXXX, KC_TRNS,                   KC_TRNS,                   KC_TRNS, XXXXXXX, KC_TRNS, KC_TRNS
      ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  do_vim_key(keycode, record);
  do_macro_key(keycode, record);

  return true;
};

