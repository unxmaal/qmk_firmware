#include "bigswitch.h"

enum {
    TD_RGB = 0
};

void dance_rgb_finished (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        rgblight_toggle();
    } else {
        rgblight_step();
    }
}

//All tap dance functions would go here. Only showing this one.
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_RGB ] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_rgb_finished, NULL)
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		TD(TD_RGB)),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS),

	KEYMAP(
		KC_TRNS)

};

/* const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    keyevent_t event = record->event;

    switch (id) {
        case TILDE_NO:
            return (event.pressed ? MACRO( D(RALT), T(RBRC), U(RALT), T(SPC), END ) : MACRO_NONE);
        case LESS_NO:
            return (event.pressed ? MACRO( T(NUBS), END ) : MACRO_NONE);
        case GRTR_NO:
            return (event.pressed ? MACRO( D(LSFT), T(NUBS), U(LSFT), END ) : MACRO_NONE);
        case CIRC_NO:
            return (event.pressed ? MACRO( D(LSFT), T(RBRC), U(LSFT), T(SPC), END ) : MACRO_NONE);
        case ACUT_NO:
            return (event.pressed ? MACRO( D(RALT), T(EQL), U(RALT), T(SPC),  END ) : MACRO_NONE);
        case GRV_NO:
            return (event.pressed ? MACRO( D(LSFT), T(EQL), T(SPC), U(LSFT),  END ) : MACRO_NONE);
        case LESS_NO_MAC:
            return (event.pressed ? MACRO( T(GRV), END ) : MACRO_NONE);
        case GRTR_NO_MAC:
            return (event.pressed ? MACRO( D(LSFT), T(GRV), U(LSFT), END ) : MACRO_NONE);
        case ACUT_NO_MAC:
            return (event.pressed ? MACRO( T(EQL), T(SPC),  END ) : MACRO_NONE);
    }
    return MACRO_NONE;
};
 */

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}
