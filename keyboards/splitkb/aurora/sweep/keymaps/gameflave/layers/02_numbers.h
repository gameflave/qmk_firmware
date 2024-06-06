#pragma once
#include "gameflave.h"

bool process_record_user_num(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {

    }
    return true;
}

void set_rgblight_num(void) {
    rgblight_setrgb_at(RGB_BLACK, 7);
    rgblight_setrgb_at(RGB_BLACK,10);
    rgblight_setrgb_at(RGB_BLACK,22);
    rgblight_setrgb_range(RGB_BLACK,16,21);

    rgblight_setrgb_at(RGB_MOD, 6);
    rgblight_setrgb_range(RGB_MOD, 8,10);
    rgblight_setrgb_range(RGB_MOD,11,16);

    rgblight_setrgb_range(RGB_NUM,30,45);

    rgblight_setrgb_at(RGB_FN,29);
}
