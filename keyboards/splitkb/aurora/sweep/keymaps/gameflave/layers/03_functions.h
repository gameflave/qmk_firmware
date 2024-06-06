#pragma once
#include "gameflave.h"

void set_rgblight_fn(void) {
    rgblight_setrgb_at(RGB_BLACK, 7);
    rgblight_setrgb_at(RGB_BLACK,10);
    rgblight_setrgb_at(RGB_BLACK,22);
    rgblight_setrgb_range(RGB_BLACK,16,21);

    rgblight_setrgb_at(RGB_BLACK,43);
    rgblight_setrgb_range(RGB_FN,29,43);
}
