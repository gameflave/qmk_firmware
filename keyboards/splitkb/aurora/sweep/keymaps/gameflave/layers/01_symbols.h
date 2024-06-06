#pragma once
#include "gameflave.h"

#define SY_EGRV KC_EXEC

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
                tap_code16(US_ACUT);
                tap_code16(US_A);
            }
            return false;
        case SY_EGRV:
            if (is_pressed(record)) {
                tap_code16(US_DGRV);
                tap_code(US_E);
            }
            return false;
    }
    return true;
}

void set_rgblight_sym(void) {
    rgblight_setrgb_range(RGB_SYM, 6,21);
    rgblight_setrgb_range(RGB_SYM,29,44);
    rgblight_setrgb_at(RGB_SYM,22);

    rgblight_setrgb_at(RGB_NUM,44);
}
