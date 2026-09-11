#pragma once

#include QMK_KEYBOARD_H

#include "quantum_keycodes.h"
#include "keycodes.h"
#include "keymap_us_international.h"

enum layers_ {
    _BASE,
    _JP1,
    _JP2,
    _JP3,
    _SYML,
    _SYMR,
    _SHRT,
    _NAV,
    _GAME,
    _NUM,
    _NUMP,
    _FUN,
    _MOUS,
};

enum custom_keycodes_ {
    KP_DOT = KC_KP_DOT,
    AGRV   = QK_USER,
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
    JAP,
    JP2,
    JP3,
    JP_SHF,
};

#define NAV_A LT(_NAV, US_A)
#define SYM_I LT(_SYMR, US_I)
#define CTL_O LCTL_T(US_O)
#define SHFT_U LSFT_T(US_U)
#define ALT_COM LALT_T(US_COMM)
#define ALT_P LALT_T(US_P)
#define SHFT_T RSFT_T(US_T)
#define CTL_S LCTL_T(US_S)
#define SYM_R LT(_SYML, US_R)
#define NUM_N LT(_NUM, US_N)
#define MOUS_J LT(_MOUS, US_J)
#define FUN_M LT(_FUN, US_M)
#define QU_Q LT(0, QU)
#define GAME TG(_GAME)

// #####################################################################
// JAPANESE
// #####################################################################
// #define DIRECT_KANA

#define NAV_と LT(_NAV, JP_と)
#define SYM_い LT(_SYMR, JP_い)
#define SYM_な LT(_SYML, JP_な)
#define NUM_う LT(_NUM, JP_う)
#define JP2 OSL(_JP2)
#define JP3 OSL(_JP3)
#define JP_MHEN KC_INT5 // Muhenkan (無変換) -> no convertion
#define JP_HENK KC_INT4 // Henkan (変換) -> convertion to kanji
#define JP_KANA KC_INT2 // Katakana ↔ Hiragana ↔ Rōmaji (カタカナ ↔ ひらがな ↔ ローマ字)

#define JP_RANGE QK_USER + 100
// clang-format off
enum japanese_keycodes_ {
    JP_あ=JP_RANGE  ,JP_か,	JP_さ,	JP_た,	JP_な,	JP_は,	JP_ま,	JP_や,	JP_ら,  JP_わ,
    JP_い           ,JP_き,	JP_し,	JP_ち,	JP_に,	JP_ひ,	JP_み,	        JP_り,  JP_ゐ,
    JP_う           ,JP_く,	JP_す,	JP_つ,	JP_ぬ,	JP_ふ,	JP_む,	JP_ゆ,	JP_る,
    JP_え           ,JP_け,	JP_せ,	JP_て,	JP_ね,	JP_へ,	JP_め,	        JP_れ,  JP_ゑ,
    JP_お           ,JP_こ,	JP_そ,	JP_と,	JP_の,	JP_ほ,	JP_も,	JP_よ,	JP_ろ,  JP_を,  JP_ん,

                    JP_が,  JP_ざ,  JP_だ,          JP_ば,  JP_ぱ,
                    JP_ぎ,  JP_じ,  JP_ぢ,          JP_び,  JP_ぴ,
    JP_ゔ          ,JP_ぐ,  JP_ず,  JP_づ,          JP_ぶ,  JP_ぷ,
                    JP_げ,  JP_ぜ,  JP_で,          JP_べ,  JP_ぺ,
                    JP_ご,  JP_ぞ,  JP_ど,          JP_ぼ,  JP_ぽ,

    JP_ぁ         ,JP_ヵ,                                        JP_ゃ,        JP_ゎ,
    JP_ぃ         ,
    JP_ぅ         ,                JP_っ,                        JP_ゅ,
    JP_ぇ         ,JP_ヶ,
    JP_ぉ         ,                                              JP_ょ,
    JP_RANGE_END,
};
// clang-format on
