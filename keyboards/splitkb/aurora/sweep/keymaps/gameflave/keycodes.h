#pragma once

#include QMK_KEYBOARD_H

#include "quantum_keycodes.h"
#include "keymap_us_international.h"

enum layers____ {
    _BASE,
    _BSYM,
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
    AGRV = QK_USER,
    EGRV,
    GRV,
    QUOT,
    CIR,
    TIL,
    CANCEL,
    NEQL,
    GRT,
    INF,
    QU,
    AROW,
    DQUOT,
    ECIR,
};

#define SHRT MO(_SHRT)
#define NAV  TG(_NAV)
#define MOD  OSL(_MOD)
#define SYM  TG(_SYM)
#define GAME TG(_GAME)
#define JAP  TG(_JAP1)
// #define E    LT(_WNAV,US_E)
#define E US_E
#define SPACE LT(_NAV,KC_SPACE)
#define C_UP LCTL_T(KC_UP)
#define NUMW TG(_NUM)
