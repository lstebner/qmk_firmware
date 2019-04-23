// remappings with nicer names
#define CMD     LGUI
#define ALT     LALT
#define CTRL    LCTL
#define SPACE   KC_SPC


// convenient rows

#define NUMBER_KEYS = KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0
#define QWERTYUIOP = KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P
#define ASDFGHJKL = KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L
#define ZXCVBNM = KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M


// this is a complete row
#define NUM_ROW_60          KC_GESC, NUMBER_KEYS, KC_MINS, KC_EQL, KC_BSPC
// this is a complete row
#define QWERTY_ROW_60       KC_TAB, QWERTYUIOP, KC_LBRC, KC_RBRC, KC_BSLS
// this row needs an initial key added for capslock when used
#define ASDF_ROW_60         ASDFGHJKL, KC_SCLN, KC_QUOT, KC_ENT
// this row needs a trailing key added for right shift when used
#define LSHFT_ROW_60        KC_LSFT, ZXCVBNM, KC_COMM, KC_DOT, KC_SLSH
