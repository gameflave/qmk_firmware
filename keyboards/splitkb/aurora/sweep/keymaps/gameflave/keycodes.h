#pragma once

#include QMK_KEYBOARD_H

#include "quantum_keycodes.h"
#include "keycodes.h"
#include "keymap_us_international.h"

enum layers_ {
    _BASE,
    _BSYM,
    _SHRT,
    _NAV,
    _WNAV,
    _GAME,
    _JP1,
    _JP2,
    _JP3,
    _JP4,
    _NUM,
    _FUN,
};

enum custom_keycodes_ {
    AGRV = QK_USER,
    EGRV,
    GRV,
    QUOT,
    CIR,
    TIL,
    NEQL,
    GRT,
    INF,
    QU,
    AROW,
    DQUOT,
    ECIR,
    AT_U,
};

#define SHRT MO(_SHRT)
#define NAV  TG(_NAV)
#define GAME TG(_GAME)
#define JAP  TG(_JP1)
#define SPACE LT(_NAV,KC_SPACE)
#define C_UP LCTL_T(KC_UP)

// #####################################################################
// JAPANESE
// #####################################################################
#define DIRECT_KANA

#define JP_RANGE QK_USER+100

#define JP_MHEN KC_INT5 // Muhenkan (無変換) -> no convertion
#define JP_HENK KC_INT4 // Henkan (変換) -> convertion to kanji
#define JP_KANA KC_INT2 // Katakana ↔ Hiragana ↔ Rōmaji (カタカナ ↔ ひらがな ↔ ローマ字)

#ifndef DIRECT_KANA
#include "sendstring_us_international.h"

#define SS_KC(keycode, string) case keycode: if(record->event.pressed) SEND_STRING(string); return false;

#else
#define TAP_CODE(keycode, tapcode) case keycode: if(record->event.pressed) {tap_code16(tapcode);} return false;
#define TAP_CODES(keycode, tapcode_1, tapcode_2) case keycode: if(record->event.pressed) {tap_code16(tapcode_1); tap_code16(tapcode_2);} return false;

#endif

enum japanese_keycodes_ {
    JP_A=JP_RANGE  ,JP_KA,	JP_SA,	JP_TA,	JP_NA,	JP_HA,	JP_MA,	JP_YA,	JP_RA,  JP_WA,
    JP_I           ,JP_KI,	JP_SI,	JP_TI,	JP_NI,	JP_HI,	JP_MI,	        JP_RI,  JP_WI,
    JP_U           ,JP_KU,	JP_SU,	JP_TU,	JP_NU,	JP_HU,	JP_MU,	JP_YU,	JP_RU,
    JP_E           ,JP_KE,	JP_SE,	JP_TE,	JP_NE,	JP_HE,	JP_ME,	        JP_RE,  JP_WE,
    JP_O           ,JP_KO,	JP_SO,	JP_TO,	JP_NO,	JP_HO,	JP_MO,	JP_YO,	JP_RO,  JP_WO,  JP_N,

                    JP_GA,  JP_ZA,  JP_DA,          JP_BA,  JP_PA,
                    JP_GI,  JP_ZI,  JP_DI,          JP_BI,  JP_PI,
    JP_VU          ,JP_GU,  JP_ZU,  JP_DU,          JP_BU,  JP_PU,
                    JP_GE,  JP_ZE,  JP_DE,          JP_BE,  JP_PE,
                    JP_GO,  JP_ZO,  JP_DO,          JP_BO,  JP_PO,

    JP_S_A         ,JP_S_KA,                                        JP_S_YA,        JP_S_WA,
    JP_S_I         ,
    JP_S_U         ,                JP_S_TU,                        JP_S_YU,
    JP_S_E         ,JP_S_KE,
    JP_S_O         ,                                                JP_S_YO,
};
