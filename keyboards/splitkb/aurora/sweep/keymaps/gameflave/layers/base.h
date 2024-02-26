#pragma once
#include <stdint.h>
#include QMK_KEYBOARD_H
#include "../../../../../../../quantum/keymap_extras/keymap_us_international.h"
#include "utils.h"

bool process_record_user_base(uint16_t keycode, keyrecord_t* record) {

    switch (keycode) {
        //Left side --------------------------------------------------
        case US_ACUT:
            if (is_pressed(record)) {
                tap_code16(US_ACUT);
                tap_code16(KC_SPC);
           }
            return false;
        case US_AACU:
            if (is_pressed(record) &&
                get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {

                unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
                tap_code16(US_DGRV);
                register_mods(MOD_BIT(KC_RSFT));
                tap_code16(US_A);
                return false;
            }
            break;
        case LT(NUM_R,US_Q):
            if (is_long_pressed(record)) {
                layer_on(NUM_R);
                return false;
            }
            if (is_long_press_released(record))
                return false;
            break;
        case LT(GAME_1,US_B):
            if (is_long_pressed(record)) {
                layer_on(GAME_1);
                return false;
            }
            if (is_long_press_released(record))
                return false;
            break;
        case LT(NAV_R,US_Y):
            if (is_long_pressed(record)) {
                layer_on(NAV_R);
                return false;
            }
            if (is_long_press_released(record))
                return false;
            break;
        //Right side -------------------------------------------------
        case LT(NAV_L,US_H):
            if (is_long_pressed(record)) {
                layer_on(NAV_L);
                return false;
            }
            if (is_long_press_released(record))
                return false;
            break;
        case LT(JP_1,US_F):
            if (is_long_pressed(record)) {
                layer_on(JP_1);
                return false;
            }
            if (is_long_press_released(record))
                return false;
            break;
    }
    return true;
}

const key_override_t s_comm_dot = ko_make_basic(MOD_MASK_SHIFT, US_COMM, US_DOT);

#define KEY_OVERRIDES_BASE &s_comm_dot,

void set_rgblight_base(void) {
    const LCh col = {0.65f, 0.0f, 0.0f};
    if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)));
        //col = {0.65f, };

    const RGB rgb = oklch_to_srgb(&col);

    rgblight_setrgb_range(rgb.r, rgb.g, rgb.b,  6,23);
    rgblight_setrgb_range(rgb.r, rgb.g, rgb.b, 29,46);
}
