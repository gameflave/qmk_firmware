#pragma once
#include <stdint.h>
#include QMK_KEYBOARD_H
#include "../../../../../../../quantum/keymap_extras/keymap_us_international.h"
#include "utils.h"

bool process_record_user_num(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {

    }
    return true;
}

void set_rgblight_num(const bool left_side) {
    const LCh col_main = {0.65f, 0.15f, 96.0f};
    const RGB rgb_main = oklch_to_srgb(&col_main);

    const LCh col_secondary = {0.65f, 0.15f, 58.0f};
    const RGB rgb_secondary = oklch_to_srgb(&col_secondary);

    if(left_side) {
        rgblight_setrgb_range(RGB_BLACK,7,10);
        rgblight_setrgb_range(RGB_BLACK,11,13);
        rgblight_setrgb_range(RGB_BLACK,16,22);

        rgblight_setrgb_range(rgb_main.r, rgb_main.g, rgb_main.b, 13,16);
        rgblight_setrgb_at(rgb_main.r, rgb_main.g, rgb_main.b,  6);
        rgblight_setrgb_at(rgb_main.r, rgb_main.g, rgb_main.b, 10);
        rgblight_setrgb_at(rgb_main.r, rgb_main.g, rgb_main.b, 22);

        rgblight_setrgb_at(rgb_main.r, rgb_main.g, rgb_main.b, 41);
    } else {
        rgblight_setrgb_at(RGB_BLACK,29);

        rgblight_setrgb_range(rgb_main.r, rgb_main.g, rgb_main.b, 30, 33);
        rgblight_setrgb_range(rgb_main.r, rgb_main.g, rgb_main.b, 34, 38);
        rgblight_setrgb_range(rgb_main.r, rgb_main.g, rgb_main.b, 40, 43);

        rgblight_setrgb_at(rgb_secondary.r, rgb_secondary.g, rgb_secondary.b, 33);
        rgblight_setrgb_at(rgb_secondary.r, rgb_secondary.g, rgb_secondary.b, 38);
        rgblight_setrgb_at(rgb_secondary.r, rgb_secondary.g, rgb_secondary.b, 39);
        rgblight_setrgb_at(rgb_secondary.r, rgb_secondary.g, rgb_secondary.b, 43);

        rgblight_setrgb_at(rgb_main.r, rgb_main.g, rgb_main.b, 18);
    }
}
