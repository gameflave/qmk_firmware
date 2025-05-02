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
    _JAP1,
    _JAP2,
    _JAP3,
    _JAP4,
    _MOD,
    _SYM,
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

enum japanese_keycodes_ {
    JP_A=JPJP_RANGE,JP_KA,	JP_SA,	JP_TA,	JP_NA,	JP_HA,	JP_MA,	JP_YA,	JP_RA,  JP_WA,
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
#else
#define TAP_CODES(keycode, tapcode_1, tapcode_2) case keycode: if(record->event.pressed) {tap_code16(tapcode_1); tap_code16(tapcode_2);} return false;

enum japanese_keycodes_ {
    JP_A=KC_3,  JP_KA=KC_T   ,	JP_SA=KC_X,	JP_TA=KC_Q,	JP_NA=KC_U   ,	JP_HA=KC_F   ,	JP_MA=KC_J   ,	JP_YA=KC_7,	JP_RA=KC_O   ,  JP_WA=KC_0,
    JP_I=KC_E,  JP_KI=KC_G   ,	JP_SI=KC_D,	JP_TI=KC_A,	JP_NI=KC_I   ,	JP_HI=KC_V   ,	JP_MI=KC_N   ,	            JP_RI=KC_L   ,  JP_WI=KC_NO,
    JP_U=KC_4,  JP_KU=KC_H   ,	JP_SU=KC_R,	JP_TU=KC_Z,	JP_NU=KC_1   ,	JP_HU=KC_2   ,	JP_MU=KC_NUHS,	JP_YU=KC_8,	JP_RU=KC_DOT ,
    JP_E=KC_5,  JP_KE=KC_HELP,	JP_SE=KC_P,	JP_TE=KC_W,	JP_NE=KC_COMM,	JP_HE=KC_EQL ,	JP_ME=KC_SLSH,              JP_RE=KC_SCLN,  JP_WE=KC_NO,
    JP_O=KC_6,  JP_KO=KC_B   ,	JP_SO=KC_C,	JP_TO=KC_S,	JP_NO=KC_K   ,	JP_HO=KC_MINS,	JP_MO=KC_M   ,	JP_YO=KC_9,	JP_RO=KC_INT1,  JP_WO=KC_0,  JP_N=KC_Y,

    JP_S_A=KC_3,  JP_S_KA=KC_NO,                                                                     JP_S_YA=KC_7,
    JP_S_I=KC_E,
    JP_S_U=KC_4,                            JP_S_TU=KC_Z,                                            JP_S_YU=KC_8,
    JP_S_E=KC_5,  JP_S_KE=KC_NO,
    JP_S_O=KC_6,                                                                                     JP_S_YO=KC_9,

    JP_S_WA=JP_RANGE,
                JP_GA           ,  JP_ZA,  JP_DA,                       JP_BA,  JP_PA,
                JP_GI           ,  JP_ZI,  JP_DI,                       JP_BI,  JP_PI,
    JP_VU,      JP_GU           ,  JP_ZU,  JP_DU,                       JP_BU,  JP_PU,
                JP_GE           ,  JP_ZE,  JP_DE,                       JP_BE,  JP_PE,
                JP_GO           ,  JP_ZO,  JP_DO,                       JP_BO,  JP_PO,
};
#endif
