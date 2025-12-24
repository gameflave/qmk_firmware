#pragma once

#include <math.h>
#include "action_code.h"
#include "color.h"

uint8_t led_map[] = {
        0, 1, 2,        25,24,23,
        3, 4, 5,        28,27,26,

     6, 7, 8, 9,10,  29,30,31,32,33,
    11,12,13,14,15,  34,35,36,37,38,
    16,17,18,19,20,  39,40,41,42,43,
             21,22,  44,45,
};

enum colors_names {
    BLACK_C,
    BASE_C ,
    SHRT_C ,
    FUN_C  ,
    BSYM_C ,
    NUM_C  ,
    NUMP_C ,
    NAV_C  ,
    MOUSE_C,
    GAME_C ,
    JP1_C  ,
    JP2_C  ,
    JP3_C  ,
    JP4_C  ,
    MOD_C  ,
};

rgb_t rgb_colors[] = {
    [BLACK_C]={   0,   0,   0},
    [BASE_C ]={0xB4,0xB4,0xB4},
    [SHRT_C ]={0xFF,0x70,0x00},
    [FUN_C  ]={ 10, 50, 10},
    [BSYM_C ]={ 35,101,244},
    [NUM_C  ]={0x00,0xFF,0x51},
    [NUMP_C ]={ 10, 50, 10},
    [NAV_C  ]={ 54, 74,225},
    [MOUSE_C]={ 31, 54,225},
    [GAME_C ]={100, 10, 10},
    [JP1_C  ]={100, 80,100},
    [MOD_C  ]={100, 80,100},
};

void rgb_matrix_set_layer(enum colors_names rgb_layer[static RGB_MATRIX_LED_COUNT]){
    for(int i=0; i<RGB_MATRIX_LED_COUNT; i++){
        rgb_t col = rgb_colors[rgb_layer[i]];
        rgb_matrix_set_color(led_map[i], col.r,col.g,col.b);
    }
}

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

    BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,     BLACK_C,BSYM_C ,BSYM_C ,BLACK_C,BLACK_C,
    SHRT_C ,SHRT_C ,SHRT_C ,SHRT_C ,SHRT_C ,     BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,BSYM_C ,
    BLACK_C,BLACK_C,BLACK_C,BLACK_C,SHRT_C ,     SHRT_C ,GAME_C ,NAV_C  ,JP1_C  ,BLACK_C,
                            MOD_C  ,BASE_C ,     BASE_C ,SHRT_C ,
};
enum colors_names rgb_num[] = {
            NUM_C  ,NUM_C  ,NUM_C  ,                     NUM_C  ,NUM_C  ,NUM_C  ,
            NUM_C  ,NUM_C  ,NUM_C  ,                     NUM_C  ,NUM_C  ,NUM_C  ,

    BLACK_C,NUM_C  ,NUM_C  ,NUM_C  ,BLACK_C,     BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,
    NAV_C  ,NUM_C  ,NUM_C  ,NUM_C  ,NUM_C  ,     BLACK_C,BLACK_C,BLACK_C,NUMP_C ,BLACK_C,
    BLACK_C,NUM_C  ,NUM_C  ,NUM_C  ,BLACK_C,     BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,
                            MOD_C  ,BLACK_C,     BASE_C ,BLACK_C,
};
enum colors_names rgb_nav[] = {
            NAV_C  ,NAV_C  ,NAV_C  ,                     NAV_C  ,NAV_C  ,NAV_C  ,
            NAV_C  ,NAV_C  ,NAV_C  ,                     NAV_C  ,NAV_C  ,NAV_C  ,

    BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,     NAV_C  ,NAV_C  ,BLACK_C,NAV_C  ,BLACK_C,
    BLACK_C,BLACK_C,BLACK_C,BLACK_C,BLACK_C,     NAV_C  ,NAV_C  ,NAV_C  ,NAV_C  ,NAV_C  ,
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
