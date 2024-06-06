#pragma once
#include "gameflave.h"

bool process_record_user_game(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {

    }
    return true;
}

void set_rgblight_game(const bool game1) {
    const LCh col_main = {0.65f, 0.25f, 29.0f};
    const RGB rgb_main = oklch_to_srgb(&col_main);

    const LCh col_secondary = {0.65f, 0.30f, 314.0f};
    const RGB rgb_secondary = oklch_to_srgb(&col_secondary);

    const LCh col_terciary = {0.65f, 0.30f, 360.0f};
    const RGB rgb_terciary = oklch_to_srgb(&col_terciary);

    //WASD
    rgblight_setrgb_at(rgb_secondary.r, rgb_secondary.g, rgb_secondary.b, 13);
    rgblight_setrgb_range(rgb_secondary.r, rgb_secondary.g, rgb_secondary.b, 17, 20);

    if(game1) {
        rgblight_setrgb_at(RGB_BLACK, 45);

        rgblight_setrgb_range(rgb_main.r, rgb_main.g, rgb_main.b,  6,13);
        rgblight_setrgb_range(rgb_main.r, rgb_main.g, rgb_main.b, 14,17);
        rgblight_setrgb_at(rgb_main.r, rgb_main.g, rgb_main.b, 20);
        rgblight_setrgb_at(rgb_main.r, rgb_main.g, rgb_main.b, 22);
        rgblight_setrgb_range(rgb_main.r, rgb_main.g, rgb_main.b, 29,45);

        rgblight_setrgb_at(rgb_terciary.r, rgb_terciary.g, rgb_terciary.b, 21);
    } else {
        rgblight_setrgb_at(RGB_BLACK, 45);

        rgblight_setrgb_range(rgb_terciary.r, rgb_terciary.g, rgb_terciary.b,  6,13);
        rgblight_setrgb_range(rgb_terciary.r, rgb_terciary.g, rgb_terciary.b, 14,17);
        rgblight_setrgb_at(rgb_terciary.r, rgb_terciary.g, rgb_terciary.b, 20);
        rgblight_setrgb_at(rgb_terciary.r, rgb_terciary.g, rgb_terciary.b, 22);
        rgblight_setrgb_range(rgb_terciary.r, rgb_terciary.g, rgb_terciary.b, 29,45);

        rgblight_setrgb_at(rgb_main.r, rgb_main.g, rgb_main.b, 21);
    }
}
