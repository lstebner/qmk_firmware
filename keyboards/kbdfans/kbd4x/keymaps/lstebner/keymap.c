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
#include "lstebner.h"

// Defines the keycodes used by our macros in process_record_user
enum niu_layers {
  LAYER_DEFAULT,
  LAYER_DEFAULT_ALT,
  LAYER_NUMROW,
  LAYER_MACRO,
  LAYER_SYMBOLS,
};

#define TABMO    LT(LAYER_DEFAULT_ALT, KC_TAB)
#define L_ALT    MO(LAYER_DEFAULT_ALT)
#define L_NUM    MO(LAYER_NUMROW)
#define L_SYM    MO(LAYER_SYMBOLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // -------------------------------------------------------------------------------------
  // | gesc |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | back |
  // -------------------------------------------------------------------------------------
  // |tab/mo|   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  |  '   |
  // -------------------------------------------------------------------------------------
  // | shft |   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  |  `   |
  // -------------------------------------------------------------------------------------
  // | ctrl |  alt |      |  cmd |L_NUM |L_SYM | space|L_ALT |   \  |   [  |   ]  | enter|
  // -------------------------------------------------------------------------------------
  [LAYER_DEFAULT] = LAYOUT_niu_wrapper (
    KC_GESC,                      KG_QWERTYUIOP,                         KC_BSPC,
    TABMO,                        KG_ASDFGHJKL,                 KC_SCLN, KC_QUOT,
    KC_LSHIFT,                    KG_ZXCVBNM, KC_COMM, KC_DOT, KC_SLSH, KC_GRAVE,
    CTRL, ALT, CMD,   KC_PIPE,    OSL(1), KC_UNDERSCORE, KC_SPACE,   MO(1),   KC_BSLS, KC_LBRC, KC_RBRC, KC_ENTER
  ),

  // -------------------------------------------------------------------------------------
  // |  esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
  // -------------------------------------------------------------------------------------
  // | ___  |      |      |      |      |      |      |      |   +  |   =  |   `  |  |   |
  // -------------------------------------------------------------------------------------
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // -------------------------------------------------------------------------------------
  // |      |      |      |      |      |      |   _  |      |      |      |      |      |
  // -------------------------------------------------------------------------------------
  [LAYER_NUMROW] = LAYOUT_niu_wrapper (
    KC_GRAVE,                           KG_NUMBER_KEYS,                               KC_MINS,
    ___,      RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, ___,  ___,  ___,  ___,  ___,  ___,  KC_EQL,
    ___,      BL_TOGG, BL_STEP, ___,     ___,     ___,  ___,  ___,  ___,  ___,  ___,  ___,
    BLANK11,                                                                          RESET
  ),

  // -------------------------------------------------------------------------------------
  // |  esc |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  =   |
  // -------------------------------------------------------------------------------------
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // -------------------------------------------------------------------------------------
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // -------------------------------------------------------------------------------------
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // -------------------------------------------------------------------------------------
  [LAYER_DEFAULT_ALT] = LAYOUT_niu_wrapper (
    ___,  ___,   ___,  ___,  ___,  ___,  ___,  ___,  KC_UP,  ___,  ___,  ___,
    ___,  ___,   ___,  ___,  ___,  ___,  ___, KC_LEFT,  KC_DOWN,  KC_RIGHT,  ___,  ___,
    ___,  ___,   ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,  KC_CAPS,
    ___,  ___,   ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___,  ___
  ),

  // -------------------------------------------------------------------------------------
  // |  esc |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   _  |
  // -------------------------------------------------------------------------------------
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // -------------------------------------------------------------------------------------
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // -------------------------------------------------------------------------------------
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // -------------------------------------------------------------------------------------
  [LAYER_SYMBOLS] = LAYOUT_niu_wrapper (
    KC_ESC, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
    BLANK12,
    BLANK12,
    BLANK12
  ),

  // -------------------------------------------------------------------------------------
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // -------------------------------------------------------------------------------------
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // -------------------------------------------------------------------------------------
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // -------------------------------------------------------------------------------------
  // |      |      |      |      |      |      |      |      |      |      |      |      |
  // -------------------------------------------------------------------------------------
  // [TEMPLATE] = LAYOUT_niu_wrapper (
  //  BLANK12,
  //  BLANK12,
  //  BLANK12,
  //  BLANK12
  // ),
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
