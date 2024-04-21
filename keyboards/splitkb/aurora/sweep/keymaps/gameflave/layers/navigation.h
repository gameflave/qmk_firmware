#pragma once
#include "gameflave.h"

bool process_record_user_nav(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {

    }
    return true;
}

void set_rgblight_nav(const enum layer_sides side) {
    if (side == LEFT) {
        rgblight_setrgb_at(RGB_BLACK, 6);
        rgblight_setrgb_at(RGB_BLACK, 8);
        rgblight_setrgb_range(RGB_BLACK,16,21);

        rgblight_setrgb_at(RGB_BLACK,29);
        rgblight_setrgb_at(RGB_BLACK,32);
        rgblight_setrgb_range(RGB_BLACK,39,44);

    } else {
        rgblight_setrgb_at(RGB_BLACK, 7);
        rgblight_setrgb_at(RGB_BLACK,10);
        rgblight_setrgb_range(RGB_BLACK,16,21);

        rgblight_setrgb_at(RGB_BLACK,31);
        rgblight_setrgb_at(RGB_BLACK,33);
        rgblight_setrgb_range(RGB_BLACK,39,44);
    }

    /*
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
    */
}
