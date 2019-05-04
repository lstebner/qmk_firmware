#include QMK_KEYBOARD_H
#include "keys.h"

enum custom_keycodes {
  FN = SAFE_RANGE,
  MAKE_CMD,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // DEFAULT LAYER
    // -------------------------------------
    // |  KP 7  |  KP 8  |  KP 9  |        |
    // ---------------------------|  KP +  |
    // |  KP 4  |  KP 5  |  KP 6  |        |
    // -------------------------------------
    // |  KP 1  |  KP 2  |  KP 3  |        |
    // ---------------------------| ENTER  |
    // |  KP 0  |  KP .  | NUMLOCK|        |
    // -------------------------------------
    LAYOUT_ortho_4x4(
        KC_KP_7, KC_KP_8,   KC_KP_9,   KC_KP_PLUS,
        KC_KP_4, KC_KP_5,   KC_KP_6,   xxx,
        KC_KP_1, KC_KP_2,   KC_KP_3,   KC_ENTER,
        KC_KP_0, KC_KP_DOT, KC_NUMLOCK, xxx
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case FN:
            if (record->event.pressed) {
              // todo
            }
            break;
        case MAKE_CMD:
            if (record->event.pressed) {
              SEND_STRING("make 1upkeyboards/sweet16:lstebner");
            }
            break;
    }
    return true;
}
