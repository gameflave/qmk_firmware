#pragma once
#include <stdint.h>
#include QMK_KEYBOARD_H
#include "../../../../../../../quantum/keymap_extras/keymap_us_international.h"
#include "utils.h"

bool process_record_user_nav(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {

    }
    return true;
}

void set_rgblight_nav(const bool left_side) {
    const LCh col_main = {0.60f, 0.40f, 160.0f};
    const RGB rgb_main = oklch_to_srgb(&col_main);

    const LCh col_secondary = {0.65f, 0.5f, 175.0f};
    const RGB rgb_secondary = oklch_to_srgb(&col_secondary);

    const LCh col_terciary = {0.65f, 0.35f, 125.0f};
    const RGB rgb_terciary = oklch_to_srgb(&col_terciary);

    if(left_side) {
        rgblight_setrgb_at(RGB_BLACK, 6);
        rgblight_setrgb_at(RGB_BLACK, 8);
        rgblight_setrgb_at(RGB_BLACK,10);
        rgblight_setrgb_at(RGB_BLACK,15);
        rgblight_setrgb_at(RGB_BLACK,20);

        //Mouse movements
        rgblight_setrgb_range(rgb_main.r, rgb_main.g, rgb_main.b, 17, 20);
        rgblight_setrgb_at(rgb_main.r, rgb_main.g, rgb_main.b, 13);

        //Mouse butons
        rgblight_setrgb_at(rgb_secondary.r, rgb_secondary.g, rgb_secondary.b, 44);
        rgblight_setrgb_at(rgb_secondary.r, rgb_secondary.g, rgb_secondary.b, 12);
        rgblight_setrgb_at(rgb_secondary.r, rgb_secondary.g, rgb_secondary.b, 14);
        rgblight_setrgb_range(rgb_secondary.r, rgb_secondary.g, rgb_secondary.b, 21, 23);

        //Mouse wheel
        rgblight_setrgb_at(rgb_terciary.r, rgb_terciary.g, rgb_terciary.b,  7);
        rgblight_setrgb_at(rgb_terciary.r, rgb_terciary.g, rgb_terciary.b,  9);
        rgblight_setrgb_at(rgb_terciary.r, rgb_terciary.g, rgb_terciary.b, 11);
        rgblight_setrgb_at(rgb_terciary.r, rgb_terciary.g, rgb_terciary.b, 16);

        //Layer key
        rgblight_setrgb_at(rgb_main.r, rgb_main.g, rgb_main.b, 42);
    } else {
        rgblight_setrgb_at(RGB_BLACK, 31);
        rgblight_setrgb_at(RGB_BLACK, 33);
        rgblight_setrgb_range(RGB_BLACK, 39, 44);

        //Arrows
        rgblight_setrgb_range(rgb_main.r, rgb_main.g, rgb_main.b, 35, 39);

        //Other nav
        rgblight_setrgb_range(rgb_secondary.r, rgb_secondary.g, rgb_secondary.b, 29, 31);
        rgblight_setrgb_at(rgb_secondary.r, rgb_secondary.g, rgb_secondary.b, 32);
        rgblight_setrgb_at(rgb_secondary.r, rgb_secondary.g, rgb_secondary.b, 34);

        //Layer key
        rgblight_setrgb_at(rgb_main.r, rgb_main.g, rgb_main.b, 17);
    }
}
