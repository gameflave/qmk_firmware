#pragma once
#include "gameflave.h"

bool process_record_user_mod(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {

    }
    return true;
}

void set_rgblight_mod(const enum layer_sides side) {
    if (side == LEFT) {
        rgblight_setrgb_at(RGB_MOD, 6);
        rgblight_setrgb_range(RGB_MOD, 8,10);
        rgblight_setrgb_range(RGB_MOD,11,16);
    } else {
        rgblight_setrgb_range(RGB_MOD,30,32);
        rgblight_setrgb_range(RGB_MOD,33,39);
    }
}
