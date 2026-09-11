#pragma once

#include <math.h>
#include "action_code.h"
#include "color.h"

// clang-format off
uint8_t led_map[] = {
        0, 1, 2,        25,24,23,
        3, 4, 5,        28,27,26,

     6, 7, 8, 9,10,  29,30,31,32,33,
    11,12,13,14,15,  34,35,36,37,38,
    16,17,18,19,20,  39,40,41,42,43,
             21,22,  44,45,
};
// clang-format on

enum colors_names {
    BLACK_C,
    BASE_C,
    SHRT_C,
    FUN_C,
    BSYM_C,
    NUM_C,
    NUMP_C,
    NAV_C,
    MOUSE_C,
    GAME_C,
    JNMR_C,
    JVOW_C,
    JKST_C,
    JSML_C,
    JHYW_C,
    JWHT_C,
    MOD_C,
};

rgb_t rgb_colors[] = {
    [BLACK_C] = {0, 0, 0},
    [BASE_C]  = {0xF2, 0x24, 0x9E},
    // [BASE_C ]={0xB4,0xB4,0xB4},
    [SHRT_C]  = {0xFF, 0x70, 0x00},
    [FUN_C]   = {10, 50, 10},
    [BSYM_C]  = {35, 101, 244},
    [NUM_C]   = {0x00, 0xFF, 0x51},
    [NUMP_C]  = {10, 50, 10},
    [NAV_C]   = {54, 74, 225},
    [MOUSE_C] = {31, 54, 225},
    [GAME_C]  = {100, 10, 10},
    [JNMR_C]   = {0xB0, 0x1A, 0xFF},
    [JVOW_C]   = {0xE2, 0x1C, 0x1C},
    [JKST_C]   = {0x2A, 0xFF, 0x2A},
    [JSML_C]   = {0xE2, 0xA5, 0x1C},
    [JHYW_C]   = {0x00, 0x80, 0xFF},
    [JWHT_C]   = {0xC8, 0xC8, 0xC8},
    [MOD_C]   = {0x60, 0x22, 0xF3},
};

void rgb_matrix_set_layer(enum colors_names rgb_layer[static RGB_MATRIX_LED_COUNT]) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        rgb_t col = rgb_colors[rgb_layer[i]];
        rgb_matrix_set_color(led_map[i], col.r, col.g, col.b);
    }
}

// clang-format off
enum colors_names rgb_base[] = {
            BASE_C ,BASE_C ,BASE_C ,                     BASE_C ,BASE_C ,BASE_C ,
            BASE_C ,BASE_C ,BASE_C ,                     BASE_C ,BASE_C ,BASE_C ,

    BASE_C ,BASE_C ,BASE_C ,BASE_C ,BASE_C ,     BASE_C ,BASE_C ,BASE_C ,BASE_C ,BASE_C ,
    BASE_C ,BASE_C ,BASE_C ,BASE_C ,BASE_C ,     BASE_C ,BASE_C ,BASE_C ,BASE_C ,BASE_C ,
    BASE_C ,BASE_C ,BASE_C ,BASE_C ,BASE_C ,     BASE_C ,BASE_C ,BASE_C ,BASE_C ,BASE_C ,
                            MOD_C  ,BASE_C ,     BASE_C ,BASE_C ,
};
enum colors_names rgb_bsym_l[] = {
            BSYM_C ,BSYM_C ,BSYM_C ,                     BSYM_C ,BSYM_C ,BSYM_C ,
            BSYM_C ,BSYM_C ,BSYM_C ,                     BSYM_C ,BSYM_C ,BSYM_C ,

    BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,     BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,
    BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,     BLACK_C,MOD_C  ,MOD_C  ,BSYM_C ,BLACK_C,
    BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,     BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,
                            MOD_C  ,BASE_C ,     BASE_C ,BASE_C ,
};
enum colors_names rgb_bsym_r[] = {
            BSYM_C ,BSYM_C ,BSYM_C ,                     BSYM_C ,BSYM_C ,BSYM_C ,
            BSYM_C ,BSYM_C ,BSYM_C ,                     BSYM_C ,BSYM_C ,BSYM_C ,

    BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,     BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,
    BLACK_C,BSYM_C ,MOD_C  ,MOD_C  ,MOD_C  ,     BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,
    BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,     BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,
                            MOD_C  ,BASE_C ,     BASE_C ,BASE_C ,
};
enum colors_names rgb_shrt[] = {
            SHRT_C ,SHRT_C ,SHRT_C ,                     SHRT_C ,SHRT_C ,SHRT_C ,
            SHRT_C ,SHRT_C ,SHRT_C ,                     SHRT_C ,SHRT_C ,SHRT_C ,

    BLACK_C,GAME_C ,JNMR_C  ,BLACK_C,BLACK_C,     BLACK_C,BSYM_C ,BSYM_C ,BLACK_C,BLACK_C,
    BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,     BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,
    BLACK_C,BLACK_C,BLACK_C,BLACK_C,SHRT_C ,     SHRT_C ,BLACK_C,BLACK_C,BLACK_C,BLACK_C,
                            MOD_C  ,BASE_C ,     BASE_C ,SHRT_C ,
};
enum colors_names rgb_num[] = {
            NUM_C  ,NUM_C  ,NUM_C  ,                     NUM_C  ,NUM_C  ,NUM_C  ,
            NUM_C  ,NUM_C  ,NUM_C  ,                     NUM_C  ,NUM_C  ,NUM_C  ,

    BLACK_C,NUM_C  ,NUM_C  ,NUM_C  ,BLACK_C,     BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,
    NAV_C  ,NUM_C  ,NUM_C  ,NUM_C  ,NUM_C  ,     MOD_C  ,MOD_C  ,MOD_C  ,NUMP_C ,BLACK_C,
    BLACK_C,NUM_C  ,NUM_C  ,NUM_C  ,BLACK_C,     BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,
                            MOD_C  ,BLACK_C,     BASE_C ,BLACK_C,
};
enum colors_names rgb_nav[] = {
            NAV_C  ,NAV_C  ,NAV_C  ,                     NAV_C  ,NAV_C  ,NAV_C  ,
            NAV_C  ,NAV_C  ,NAV_C  ,                     NAV_C  ,NAV_C  ,NAV_C  ,

    BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,     NAV_C  ,NAV_C  ,BLACK_C,NAV_C  ,BLACK_C,
    NAV_C  ,BLACK_C,MOD_C  ,MOD_C  ,MOD_C  ,     NAV_C  ,NAV_C  ,NAV_C  ,NAV_C  ,NAV_C  ,
    BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,     BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,
                            MOD_C  ,BLACK_C,     BLACK_C,BLACK_C,
};
enum colors_names rgb_mouse[] = {
            MOUSE_C,MOUSE_C,MOUSE_C,                     MOUSE_C,MOUSE_C,MOUSE_C,
            MOUSE_C,MOUSE_C,MOUSE_C,                     MOUSE_C,MOUSE_C,MOUSE_C,

    BLACK_C,MOUSE_C,BLACK_C,MOUSE_C,BLACK_C,     MOUSE_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,
    BLACK_C,BLACK_C,MOD_C  ,MOD_C  ,MOD_C  ,     MOUSE_C,MOUSE_C,MOUSE_C,MOUSE_C,MOUSE_C,
    BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,     BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,
                            MOD_C  ,MOUSE_C,     BLACK_C,BLACK_C,
};
enum colors_names rgb_fun[] = {
            FUN_C  ,FUN_C  ,FUN_C  ,                     FUN_C  ,FUN_C  ,FUN_C  ,
            FUN_C  ,FUN_C  ,FUN_C  ,                     FUN_C  ,FUN_C  ,FUN_C  ,

    BLACK_C,FUN_C  ,FUN_C  ,FUN_C  ,FUN_C  ,     BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,
    BLACK_C,FUN_C  ,FUN_C  ,FUN_C  ,FUN_C  ,     BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,
    BLACK_C,FUN_C  ,FUN_C  ,FUN_C  ,FUN_C  ,     BLACK_C,BLACK_C,FUN_C  ,BLACK_C,BLACK_C,
                            MOD_C  ,BLACK_C,     BLACK_C,BLACK_C,
};
enum colors_names rgb_game[] = {
            GAME_C ,GAME_C ,GAME_C ,                     GAME_C ,GAME_C ,GAME_C ,
            GAME_C ,GAME_C ,GAME_C ,                     GAME_C ,GAME_C ,GAME_C ,

    BASE_C ,BASE_C ,BASE_C ,BASE_C ,BASE_C ,     BASE_C ,BASE_C ,BASE_C ,BASE_C ,BASE_C ,
    BASE_C ,BASE_C ,BASE_C ,BASE_C ,BASE_C ,     BASE_C ,BASE_C ,BASE_C ,BASE_C ,BASE_C ,
    BASE_C ,BASE_C ,BASE_C ,BASE_C ,BASE_C ,     BASE_C ,BASE_C ,BASE_C ,BASE_C ,BASE_C ,
                            MOD_C  ,BASE_C ,     BASE_C ,BASE_C ,
};
// JP kana color groups (consonant rows). One color per group, stable across _JP1/_JP2/_JP3:
//   VOWEL (JVOW_C red)   : あいうえお ん っ
//   KST   (JKST_C lime)  : かさた rows + voiced がざだ (かきくけこ さしすせそ たちつてと)
//   NMR   (JNMR_C magen): なまら rows (なにぬねの まみむめも らりるれろ)
//   HYW   (JHYW_C azure): はやわ rows + voiced/halved (はひふへほ ばびぶべぼ ぱぴぷぺぽ やゆよ わゐゑを ゔ)
//   SMALL (JSML_C orange): small kana (ぁぃぅぇぉ ゃゅょっ ヵヶゎ)
//   EXTRA (JWHT_C white) : non-kana function (、。punct HENK MHEN)
// Punct/HENK/MHEN are white so kana hues stay pure. Thumbs are off (BLACK).
enum colors_names rgb_jap1[] = {
            JNMR_C  ,JNMR_C  ,JNMR_C  ,                     JNMR_C  ,JNMR_C  ,JNMR_C  ,
            JNMR_C  ,JNMR_C  ,JNMR_C  ,                     JNMR_C  ,JNMR_C  ,JNMR_C  ,

    JKST_C  ,JVOW_C  ,JVOW_C  ,JKST_C  ,JKST_C  ,     JNMR_C  ,JHYW_C  ,JNMR_C  ,JNMR_C  ,JNMR_C  ,
    JKST_C  ,JVOW_C  ,JHYW_C  ,JNMR_C  ,JWHT_C  ,     JKST_C  ,JKST_C  ,JNMR_C  ,JNMR_C  ,JVOW_C  ,
    JKST_C  ,JVOW_C  ,JKST_C  ,JWHT_C  ,JKST_C  ,     JKST_C  ,JKST_C  ,JNMR_C  ,JNMR_C  ,JKST_C  ,
                            BLACK_C,BLACK_C,     BLACK_C,BLACK_C,
};
enum colors_names rgb_jap2[] = {
            JVOW_C  ,JVOW_C  ,JVOW_C  ,                     JKST_C  ,JKST_C  ,JKST_C  ,
            JVOW_C  ,JVOW_C  ,JVOW_C  ,                     JKST_C  ,JKST_C  ,JKST_C  ,

    JHYW_C  ,JKST_C  ,JNMR_C  ,JHYW_C  ,JHYW_C  ,     JVOW_C  ,JHYW_C  ,JHYW_C  ,JHYW_C  ,JNMR_C  ,
    JKST_C  ,JHYW_C  ,JKST_C  ,JKST_C  ,JNMR_C  ,     JKST_C  ,JKST_C  ,JVOW_C  ,JKST_C  ,JKST_C  ,
    JKST_C  ,JKST_C  ,JNMR_C  ,JHYW_C  ,JKST_C  ,     JNMR_C  ,JHYW_C  ,JKST_C  ,JSML_C  ,JSML_C  ,
                            BLACK_C,BLACK_C,     BLACK_C,BLACK_C
};
enum colors_names rgb_jap3[] = {
            JKST_C  ,JKST_C  ,JKST_C  ,                     JVOW_C  ,JVOW_C  ,JVOW_C  ,
            JKST_C  ,JKST_C  ,JKST_C  ,                     JVOW_C  ,JVOW_C  ,JVOW_C  ,

    JSML_C  ,JSML_C  ,JSML_C  ,JSML_C  ,JSML_C  ,     JSML_C  ,JSML_C  ,JSML_C  ,JHYW_C  ,JHYW_C  ,
    JKST_C  ,JHYW_C  ,JNMR_C  ,JHYW_C  ,JKST_C  ,     JHYW_C  ,JHYW_C  ,JKST_C  ,JKST_C  ,JKST_C  ,
    JHYW_C  ,JKST_C  ,JHYW_C  ,JHYW_C  ,JHYW_C  ,     JSML_C  ,JHYW_C  ,JHYW_C  ,JWHT_C  ,JWHT_C  ,
                            BLACK_C,BLACK_C,     BLACK_C,BLACK_C  ,
};
// clang-format on
