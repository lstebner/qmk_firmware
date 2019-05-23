#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum custom_keycodes {
  MAKE_CMD = SAFE_RANGE,
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
  EMOJI_COOLGHOST,
  EMOJI_PLUSONE,
};

#define LAYER_NUMPAD  0
#define LAYER_EMOJI   1

#define _NUMPAD MO(LAYER_NUMPAD)
#define _EMOJI MO(LAYER_EMOJI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // NUMPAD
  // 
  // -------------------------
  // |  7  |  8  |  9  | BACK|
  // -------------------------
  // |  4  |  5  |  6  |  +  |
  // -------------------------
  // |  1  |  2  |  3  |  -  |
  // -------------------------
  // |  .  |  0  |LAYER|ENTER|
  // -------------------------
  [LAYER_NUMPAD] = LAYOUT_ortho_4x4(
      KC_KP_7, KC_KP_8, KC_KP_9, KC_BSPACE,
      KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS,
      KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_MINUS,
      KC_KP_DOT, KC_KP_0, _EMOJI, KC_ENTER
  ),

  // SYMBOLS
  // 
  // -------------------------
  // |  &  |  *  |  (  |  *  |
  // -------------------------
  // |  $  |  %  |  ^  |  /  |
  // -------------------------
  // |  !  |  @  |  #  |WIND |
  // -------------------------
  // | ___ |  ~  |PRTAB|NETAB|
  // -------------------------
  [LAYER_EMOJI] = LAYOUT_ortho_4x4(
    EMOJI_SMILE, EMOJI_JOY,   EMOJI_TEAR,   KC_KP_PLUS,
    EMOJI_RAISED_HANDS, EMOJI_INFO_DESK,   EMOJI_SPARKLE_THUMB,   EMOJI_DANGO,
    EMOJI_THUMBS_DOWN, EMOJI_PEACE,   EMOJI_FIRE,   EMOJI_COOLGHOST,
    EMOJI_THUMBS_UP, EMOJI_CRY_HAPPY, _NUMPAD, KC_ENTER
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MAKE_CMD:
            if (record->event.pressed) {
              SEND_STRING("make thevankeyboards/roadkit:lstebner");
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

        case EMOJI_COOLGHOST:
            if (record->event.pressed) {
              SEND_STRING(":coolghost:");
            }
            break;

        case EMOJI_PLUSONE:
            if (record->event.pressed) {
              SEND_STRING(":1:");
            }
            break;
    }
  return true;
};

