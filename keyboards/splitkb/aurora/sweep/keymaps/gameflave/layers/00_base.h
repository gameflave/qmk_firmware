#pragma once
#include "gameflave.h"

bool process_record_user_base(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case US_ACUT:
            if (is_pressed(record)) {
                tap_code16(US_ACUT);
                tap_code16(KC_SPC);
            }
            return false;
        case US_AACU: ;
            uint8_t pressedShiftBit = get_pressedShift();
            if (is_pressed(record) && pressedShiftBit) {
                unregister_mods(pressedShiftBit);
                tap_code16(US_DGRV);
                register_mods(pressedShiftBit);
                tap_code16(US_A);
                return false;
            } else if(is_pressed(record)){
                tap_code16(US_DGRV);
                tap_code16(US_A);
                return false;
            }
            break;
        case LT(GAME_1,US_B):
            if (is_long_pressed(record)) {
                layer_on(GAME_1);
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
        case LT(0, US_C):
            if (is_long_pressed(record)) {
                tap_code16(US_CCED);
                return false;
            }
            break;
    }

    return true;
}

const key_override_t s_comm_dot = ko_make_basic(MOD_MASK_SHIFT, US_COMM, US_DOT);

#define KEY_OVERRIDES_BASE &s_comm_dot,


const uint16_t PROGMEM eu_combo[] = {US_E, US_U, COMBO_END};
const uint16_t PROGMEM ts_combo[] = {US_T, US_S, COMBO_END};

const uint16_t PROGMEM iu_combo[] = {US_I, US_U, COMBO_END};
const uint16_t PROGMEM tr_combo[] = {US_T, US_R, COMBO_END};

#define KEY_COMBOS_BASE COMBO(eu_combo, TG(NAV_L)), COMBO(ts_combo, TG(NAV_R)), COMBO(iu_combo, TG(MOD_L)), COMBO(tr_combo, TG(MOD_R)),


void set_rgblight_base(void) {
    rgblight_setrgb_range(RGB_BASE,  6,23);
    rgblight_setrgb_range(RGB_BASE, 29,46);
}
