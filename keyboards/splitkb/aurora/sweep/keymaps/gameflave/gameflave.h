#pragma once
#include <stdint.h>

#include QMK_KEYMAP_H
#include "keymap_us_international.h"

#include "utils.h"
#include "colors.h"

#define TAP_DANCE_INDEX_BASE 0

enum layer_names {
    BASE,
    SYM,
    NUM,
    NAV_L,
    NAV_R,
    FN,
    GAME_1,
    GAME_2,
    MOD_L,
    MOD_R,
    JP_1,
    JP_2,
    JP_3,
    JP_4,
};
