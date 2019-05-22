#include QMK_KEYBOARD_H
#include "keys.h"

enum custom_keycodes {
  FN = SAFE_RANGE,
  MAKE_CMD,
  EMOJI_JOY, //
  EMOJI_SMILE, //
  EMOJI_TEAR, //
  EMOJI_RAISED_HANDS, //
  EMOJI_SPARKLE_THUMB, //
  EMOJI_PEACE, //
  EMOJI_FIRE, //
  EMOJI_INFO_DESK, //
  EMOJI_THUMBS_UP, //
  EMOJI_THUMBS_DOWN, //
  EMOJI_CRY_HAPPY, //
  EMOJI_DANGO, //
  EMOJI_TACO,
  SAC, //
};

#define LAYER_EMOJI        0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // DEFAULT LAYER
    // -------------------------------------
    // | smile  |  joy   |  tear  |        |
    // ---------------------------|  plus  |
    // |raisedhands|infodesk|sparklethumb|        |
    // -------------------------------------
    // |  -1    |  peace |  dango  |        |
    // ---------------------------| ENTER  |
    // |  fire  |  cryhappy| SAC    |        |
    // -------------------------------------
    [LAYER_EMOJI] = LAYOUT_ortho_4x4(
        EMOJI_SMILE, EMOJI_JOY,   EMOJI_TEAR,   KC_KP_PLUS,
        EMOJI_RAISED_HANDS, EMOJI_INFO_DESK,   EMOJI_SPARKLE_THUMB,   xxx,
        EMOJI_THUMBS_DOWN, EMOJI_PEACE,   EMOJI_FIRE,   KC_ENTER,
        EMOJI_THUMBS_UP, EMOJI_CRY_HAPPY, SAC, xxx
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAKE_CMD:
            if (record->event.pressed) {
              SEND_STRING("make 1upkeyboards/sweet16:lstebner");
            }
            break;

        case EMOJI_JOY:
            if (record->event.pressed) {
              SEND_STRING(":joy:");
            }
            break;

        case EMOJI_SMILE:
            if (record->event.pressed) {
              SEND_STRING(":smile:");
            }
            break;

        case EMOJI_TEAR:
            if (record->event.pressed) {
              SEND_STRING(":cry:");
            }
            break;

        case EMOJI_RAISED_HANDS:
            if (record->event.pressed) {
              SEND_STRING(":raised_hands:");
            }
            break;

        case EMOJI_SPARKLE_THUMB:
            if (record->event.pressed) {
              SEND_STRING(":sparklethumb:");
            }
            break;

        case EMOJI_PEACE:
            if (record->event.pressed) {
              SEND_STRING(":peace:");
            }
            break;

        case EMOJI_FIRE:
            if (record->event.pressed) {
              SEND_STRING(":fire:");
            }
            break;

        case EMOJI_INFO_DESK:
            if (record->event.pressed) {
              SEND_STRING(":information_desk_person:");
            }
            break;

        case EMOJI_THUMBS_UP:
            if (record->event.pressed) {
              SEND_STRING(":+1:");
            }
            break;

        case EMOJI_THUMBS_DOWN:
            if (record->event.pressed) {
              SEND_STRING(":-1:");
            }
            break;

        case EMOJI_CRY_HAPPY:
            if (record->event.pressed) {
              SEND_STRING(":cry_happy:");
            }
            break;

        case EMOJI_DANGO:
            if (record->event.pressed) {
              SEND_STRING(":dango:");
            }
            break;

        case EMOJI_TACO:
            if (record->event.pressed) {
              SEND_STRING(":taco:");
            }
            break;

        case SAC:
            if (record->event.pressed) {
              SEND_STRING("Streamline Account Creation");
            }
            break;
    }
    return true;
}
