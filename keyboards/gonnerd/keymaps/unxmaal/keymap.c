#include "gonnerd.h"

// Keymap layers
#define BASE_LAYER 0
#define FUNCTION_LAYER 1
#define SYSTEM_LAYER 2

// Key aliases
#define __x__ KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /*
   *  ANSI Base, Mac style
   * ,-----------------------------------------------------------------------------.
   * |Esc   |  1|   2|   3|   4|   5|   6|   7|   8|   9|   0|   -|   = |   Backsp |
   * |-----------------------------------------------------------------------------|
   * |Tab    |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I|   O|  P|  [|  ]|     \|
   * |-----------------------------------------------------------------------------|
   * |Control      |    A|    S|    D|    F|   G|  H|  J|  K|  L|  ;|  '|   Enter  |
   * |-----------------------------------------------------------------------------|
   * |Shift      |    Z|     X|    C|     V|  B|  N|  M|  ,|  .|  /|     Shift     |
   * |-----------------------------------------------------------------------------|
   * |Fn|Alt |Gui | Space(tapped), Fn(held) |Gui |Alt  |Menu(tapped, Fn2(held)|Ctrl|
   * `-----------------------------------------------------------------------------'
   */
  [BASE_LAYER] = KEYMAP_60(
      F(0),     KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, \
      KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, \
      KC_LCTL,    KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  __x__,    KC_ENT,  \
      KC_LSFT,  __x__,    KC_Z,     KC_X,     KC_C,    KC_V,     KC_B,     KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  __x__,   \
      MO(FUNCTION_LAYER),  KC_LALT,  KC_LGUI,      LT(FUNCTION_LAYER,KC_SPACE),           KC_RGUI,  KC_RALT,  LT(SYSTEM_LAYER,KC_MENU),    KC_RCTL  \
  ),

   /*
   * Pok3r style arrow cluster
   * ,-----------------------------------------------------------.
   * |`~ | F1| F2| F3| F4| F5| F6| F7| F8| F9| F10| F11| F12|DEL |
   * |-----------------------------------------------------------|
   * |     |   |    |   |   |   |   |   |Up|   |   |   |   |     |
   * |-----------------------------------------------------------|
   * |       |   |   |   |   |   |   |Left|Down|Right|   |   |   |
   * |-----------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
   [FUNCTION_LAYER] = KEYMAP_60(
       KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL, \
       __x__,   KC_MPRV, KC_MPLY, KC_MNXT, __x__,   __x__,   KC_PGUP, KC_HOME, KC_UP,   KC_END,  __x__,   __x__, __x__, __x__,  \
       __x__, KC_MUTE, KC_VOLD, KC_VOLU, __x__,   __x__,   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, __x__,   __x__,    __x__,  __x__,  \
       __x__,  __x__,  __x__,   __x__,   __x__,   __x__,   __x__,   __x__,   __x__,   __x__,   __x__,   __x__,    __x__,  __x__,  \
       KC_TRNS, __x__, __x__,                            KC_TRNS,                             __x__,   __x__,   KC_TRNS,   __x__   \
   ),

  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |  RESET|
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |BL-|BL+|BL   |
   * |-----------------------------------------------------------|
   * |      |   |   |   |   |   |   |       |   |   |   |        |
   * |-----------------------------------------------------------|
   * |  | RGB on|RGB step|Hue+|Hue- |Sat+|Sat-|Val+| Val-| | |   |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
  [SYSTEM_LAYER] = KEYMAP_60(
      __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,   RESET, \
      __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,   __x__, \
      __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,   __x__, \
      __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,  __x__,   __x__, \
      __x__,  __x__,  __x__,                          __x__,                          __x__,  __x__,  KC_TRNS, __x__  \
  ),
};

enum function_id {
    ESC_GRV, // Makes Esc behave like `~ when pressed with the left GUI modifier. This is the "switch between windows of the same application" key combination in macOS
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(ESC_GRV),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t esc_grv_mask;
  switch (id) {
    case ESC_GRV:
      esc_grv_mask = get_mods() & MOD_BIT(KC_LGUI);
      if (record->event.pressed) {
        if (esc_grv_mask) {
          add_key(KC_GRV);
          send_keyboard_report();
        } else {
          add_key(KC_ESC);
          send_keyboard_report();
        }
      } else {
        if (esc_grv_mask) {
          del_key(KC_GRV);
          send_keyboard_report();
        } else {
          del_key(KC_ESC);
          send_keyboard_report();
        }
      }
      break;
  }
}
