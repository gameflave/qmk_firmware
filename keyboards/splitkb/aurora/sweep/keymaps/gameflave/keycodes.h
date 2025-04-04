#pragma once

#include QMK_KEYBOARD_H

#include "quantum_keycodes.h"
#include "keymap_us_international.h"

enum layers {
    _BASE,
    _SHRT,
    _NAV,
    _WNAV,
    _GAME,
    _JAP1,
    _JAP2,
    _JAP3,
    _JAP4,
    _MOD,
    _SYM,
    _NUM,
    _FUN,
};

enum custom_keycodes {
    AGRV = SAFE_RANGE,
    EGRV,
    GRV,
    QUOT,
    CIR,
    TIL,
    CANCEL,
};

#define SHRT MO(_SHRT)
#define NAV  TG(_NAV)
#define MOD  OSL(_MOD)
#define SYM  TG(_SYM)
#define GAME TG(_GAME)
#define JAP  TG(_JAP1)
#define E    LT(_NAV,US_E)
#define SPACE LT(_WNAV,KC_SPACE)
#define C_UP LCTL_T(KC_UP)
