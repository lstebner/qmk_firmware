/* Copyright 2018 sevenseacat
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  KBD4X = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_niu_wrapper (
    KC_GESC,        KG_QWERTYUIOP,  KC_BSPC,
    LT(2, KC_TAB),  KG_ASDFGHJKL,    KC_SCLN, KC_QUOT,
    KC_LSHIFT,      KG_ZXCVBNM,    KC_COMM, KC_DOT,  KC_SLSH,   KC_GRAVE,
    CTRL, ALT, CMD,    KC_2,    OSL(1),    KC_UNDERSCORE, KC_SPACE,   MO(1),   KC_SLSH, KC_LBRC, KC_RBRC, KC_ENTER
  ),

  [1] = LAYOUT_niu_wrapper (
    KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
    ___,      RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, ___,  ___,  ___,  ___,  ___,  ___,  KC_EQL,
    ___,      BL_TOGG, BL_STEP, ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,      ___,     ___,     ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  RESET
  ),

  [2] = LAYOUT_niu_wrapper (
    ___,  ___,   ___,  ___,  ___, ___,  ___,  ___,  KC_UP,  ___,  ___,  ___,
    ___,  ___,   ___,  ___,  ___,     ___,  ___, KC_LEFT,  KC_DOWN,  KC_RIGHT,  ___,  ___,
    ___,  ___,   ___,  ___,  ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    ___,  ___,   ___,  ___,  ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}
