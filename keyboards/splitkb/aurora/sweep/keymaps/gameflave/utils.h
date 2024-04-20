#pragma once
#include <stdint.h>
#include <sys/types.h>

#include QMK_KEYBOARD_H
#include "keycode.h"

static bool should_clear_oneshot_layer = false;

bool is_long_pressed(const keyrecord_t* record) {return !record->tap.count && record->event.pressed;}
bool is_long_press_released(const keyrecord_t* record) {return !record->tap.count && !record->event.pressed;}
bool is_taped(const keyrecord_t* record) {return record->tap.count && record->event.pressed;}
bool is_tap_released(const keyrecord_t* record) {return record->tap.count && !record->event.pressed;}
bool is_pressed(const keyrecord_t* record) {return record->event.pressed;}
bool is_released(const keyrecord_t* record) {return !record->event.pressed;}

uint8_t get_pressedShift(void) {
    uint8_t pressedShiftBit = 0;
    if(get_mods() & MOD_BIT(KC_LSFT))
        pressedShiftBit = MOD_BIT(KC_LSFT);
    if(get_mods() & MOD_BIT(KC_RSFT))
        pressedShiftBit = MOD_BIT(KC_RSFT);

    return pressedShiftBit;
}
