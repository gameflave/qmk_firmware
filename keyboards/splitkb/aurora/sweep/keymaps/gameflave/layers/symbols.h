#pragma once
#include <stdint.h>
#include QMK_KEYBOARD_H
#include "../../../../../../../quantum/keymap_extras/keymap_us_international.h"
#include "utils.h"

bool process_record_user_sym(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        // Tap: ` (dead)    Pressed: `
        case LT(0, US_DGRV):
            if (is_taped(record)) {
                tap_code16(US_DGRV);
            } else if (is_pressed(record)) {
                tap_code16(US_DGRV);
                tap_code16(KC_SPC);
            }
            return false;
        // Tap: ~ (dead) -> ~   Pressed: ~ (dead)
        case LT(1, US_DTIL):
            if (is_taped(record)) {
                tap_code16(US_DTIL);
                tap_code16(KC_SPC);
            } else if (is_pressed(record)) {
                tap_code16(US_DTIL);
            }
            return false;
        // Pressed: ^ (dead) -> ^
        case LT(0, US_DCIR):
            if (is_taped(record)) {
                tap_code16(US_DCIR);
            } else if(is_pressed(record)) {
                tap_code16(US_DCIR);
                tap_code16(KC_SPC);
            }
            return false;
        case US_AACU:
            if (is_pressed(record)) {
                tap_code16(US_DGRV);
                tap_code16(US_A);
            }
            return false;
        case LT(0,US_E):
            if (is_pressed(record)) {
                tap_code16(US_DGRV);
                tap_code(US_E);
            }
            return false;
    }
    return true;
}

void set_rgblight_sym(const bool left_side) {
    const LCh col = {0.65f, 0.2f, 237.0f};
    const RGB rgb = oklch_to_srgb(&col);

    if(left_side) {
        rgblight_setrgb_range(rgb.r, rgb.g, rgb.b, 6,23);
        rgblight_setrgb_at(rgb.r, rgb.g, rgb.b, 40);
    } else {
        rgblight_setrgb_range(rgb.r, rgb.g, rgb.b, 29, 46);
        rgblight_setrgb_at(rgb.r, rgb.g, rgb.b, 19);
    }
}
