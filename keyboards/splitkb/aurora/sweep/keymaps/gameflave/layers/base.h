#pragma once
#include "gameflave.h"

#define BA_LAYER_R TD(TAP_DANCE_INDEX_BASE)
#define BA_LAYER_L TD(TAP_DANCE_INDEX_BASE + 1)

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

const uint16_t PROGMEM ucomm_combo[] = {US_U, US_COMM, COMBO_END};
const uint16_t PROGMEM pt_combo[] = {US_P, US_T, COMBO_END};

#define KEY_COMBOS_BASE COMBO(ucomm_combo, TG(NAV_L)), COMBO(pt_combo, TG(NAV_R)),

#define TAP_DANCE_ACTIONS_BASE [TAP_DANCE_INDEX_BASE] = ACTION_TAP_DANCE_DOUBLE(MO(SYM), TG(NAV_L)), [TAP_DANCE_INDEX_BASE+1] = ACTION_TAP_DANCE_DOUBLE(MO(NUM), TG(NAV_R)),

void set_rgblight_base(void) {
    rgblight_setrgb_range(RGB_BASE,  6,23);
    rgblight_setrgb_range(RGB_BASE, 29,46);
}
