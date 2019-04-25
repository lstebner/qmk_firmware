#pragma once

enum numpad_layers {
  LAYER_NUMPAD,
  LAYER_SYMBOLS,
};


// keys
#define LT_SYMBOLS      LT(LAYER_SYMBOLS, KC_KP_DOT)


// rows
#define NUMPAD_ROW_3  KC_7,     KC_8,     KC_9,     KC_KP_PLUS
#define NUMPAD_ROW_2  KC_4,     KC_5,     KC_6,     KC_KP_MINUS
#define NUMPAD_ROW_1  KC_1,     KC_2,     KC_3,     KC_BSPACE
#define NUMPAD_ROW_0  LT_SYMBOLS, KC_0,     KC_LEFT,  KC_RIGHT 


// layout wrapper(s)
#define LAYOUT_ortho_4x4_wrapper(...) LAYOUT_ortho_4x4(__VA_ARGS__)
