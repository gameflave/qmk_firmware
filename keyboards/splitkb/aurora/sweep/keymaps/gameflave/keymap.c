#include <stdint.h>
#include "action_layer.h"
#include "color.h"
#include "config.h"
#include QMK_KEYBOARD_H

#include "action.h"
#include "quantum.h"
#include "keymap_us_international.h"
#include "g/keymap_combo.h"

#include "keycodes.h"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        AGRV   ,EGRV   ,US_EACU,US_B   ,QK_REP ,      US_F    ,US_D    ,US_L   ,QUOT   ,US_X,
        US_A   ,US_I   ,US_O   ,US_U   ,US_COMM,      US_P    ,US_T    ,US_S   ,US_R   ,US_N,
        US_K   ,US_Y   ,US_J   ,US_DOT ,US_W   ,      US_G    ,US_C    ,US_M   ,US_H   ,US_V,
                                SHRT   ,E      ,      SPACE   ,XXXXXXX
    ),
    [_BSYM] = LAYOUT(
        US_UNDS,US_LPRN,US_RPRN,_______, _______,     _______,_______,_______,_______,_______ ,
        _______,_______,_______,_______, _______,     _______,_______,_______,_______,_______ ,
        _______,_______,_______,_______, _______,     _______,_______,_______,_______,_______ ,
                                _______,_______,      _______,_______
    ),
    [_SHRT] = LAYOUT(
        C(US_E),US_S,   US_R,   US_G,   _______,      _______, NAV,     MOD,    SYM,    _______,
        C(US_X),C(US_C),C(US_S),C(US_V),C(US_Z),      US_DGRV, US_DIAE, US_DCIR,US_ACUT,US_DTIL,
        C(US_B),C(US_W),C(US_D),C(US_R),S(KC_F1),     KC_PSCR, GAME,    US_CURR,JAP,    _______,
                                SHRT,   US_E,         KC_SPACE,MO(_FUN)
    ),
    [_NAV] = LAYOUT(
        _______,_______,_______,_______, _______,     _______,_______,_______,_______,_______ ,
        KC_LGUI,KC_HOME,C_UP   ,KC_END , KC_PGUP,     _______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RIGHT,
        KC_ENT ,KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDN,     _______,_______,_______,_______,_______ ,
                                _______,MO(_WNAV),    CANCEL ,_______
    ),
    [_WNAV] = LAYOUT(
        _______,_______,_______,G(US_8),_______,      _______,G(US_9),_______,_______,_______,
        G(US_6),G(US_4),G(US_0),G(US_2),_______,      _______,G(US_3),G(US_1),G(US_5),G(US_7),
        _______,_______,_______,_______,_______,      _______,_______,_______,_______,_______,
                                _______,XXXXXXX,      _______,_______
    ),
    [_NUM] = LAYOUT(
        US_UNDS,US_LPRN,US_RPRN,US_8   ,XXXXXXX,      XXXXXXX,US_9   ,KC_PPLS,KC_PMNS,KC_PAST,
        US_6   ,US_4   ,US_0   ,US_2   ,US_COMM,      KC_PSLS,US_3   ,US_1   ,US_5   ,US_7   ,
        US_K   ,S(US_G),US_J   ,KC_PDOT,XXXXXXX,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                XXXXXXX,CANCEL ,      SPACE  ,XXXXXXX
    ),
    [_FUN] = LAYOUT(
        _______,_______,_______,KC_F8  ,_______,      _______,KC_F9  ,_______,_______,_______,
        KC_F6  ,KC_F4  ,KC_F10 ,KC_F2  ,KC_F12 ,      KC_F11 ,KC_F3  ,KC_F1  ,KC_F5  ,KC_F7,
        _______,_______,_______,_______,_______,      _______,_______,_______,_______,_______,
                                _______,_______,      _______,_______
    ),
    [_MOD] = LAYOUT(
        _______,_______,_______,_______,_______,      _______,_______,_______,_______,_______,
        OSM(KC_LGUI),OSM(KC_LALT),OSM(KC_LCTL),OSM(KC_LSFT),_______,_______,OSM(KC_RSFT),OSM(KC_RCTL),OSM(KC_LALT),OSM(KC_LGUI),
        _______,_______,_______,_______,_______,      _______,_______,_______,_______,_______,
                                _______,_______,      _______,_______
    ),
    [_SYM] = LAYOUT(
        US_UNDS,US_LPRN,US_RPRN,CIR    ,_______,      US_BSLS,US_DLR ,US_PLUS,US_MINS,US_ASTR,
        TIL    ,US_LABK,US_LCBR,US_AMPR,_______,      US_SLSH,US_QUES,US_RCBR,US_RABK,US_HASH,
        _______,US_PERC,US_LBRC,_______,GRV    ,      _______,_______,US_RBRC,US_PIPE,_______,
                                _______,_______,      _______,_______
    ),
    [_GAME] = LAYOUT(
        KC_ESC ,US_1   ,US_2   ,US_3   ,US_4   ,      US_5   ,US_6   ,US_7   ,US_8   ,US_9   ,
        KC_TAB ,US_Q   ,US_W   ,US_E   ,US_R   ,      US_T   ,US_Y   ,US_U   ,US_I   ,US_O   ,
        KC_LSFT,US_A   ,US_S   ,US_D   ,US_F   ,      US_G   ,US_H   ,US_J   ,US_K   ,US_L   ,
                                KC_RCTL,KC_SPACE,     CANCEL ,XXXXXXX
    ),
};

#define UNDEAD(Key,DKey) case Key: if(record->event.pressed) {tap_code16(DKey);tap_code16(KC_SPACE);} return true;

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        // These are dead key by default make the non-dead version
        UNDEAD(GRV,US_DGRV)
        UNDEAD(TIL, US_DTIL)
        UNDEAD(QUOT, US_ACUT)
        UNDEAD(CIR, US_DCIR)
        UNDEAD(DQUOT, S(US_ACUT))

        case AGRV:
            if(record->event.pressed)
                { tap_code16(US_DGRV); tap_code16(US_A); }
        return true;
        case EGRV:
            if(record->event.pressed)
                { tap_code16(US_DGRV); tap_code16(US_E); }
        return true;
        case ECIR:
            if(record->event.pressed)
                { tap_code16(US_DCIR); tap_code16(US_E); }
        return true;

        // Disable numwords
        case US_LPRN:
        case US_RPRN:
        case US_K:
        case US_J:
        case S(US_G):
        case SPACE:
        case KC_ENT:
            if(record->event.pressed && get_highest_layer(layer_state)==_NUM)
                layer_off(_NUM);
            return true;
        case CANCEL:
            if (record->event.pressed)
                layer_and(1);
        return false;
        case NEQL:
            if (record->event.pressed) {
                tap_code16(US_EXLM);
                tap_code16(US_EQL);
            }
            return true;
        case GRT:
            if (record->event.pressed) {
                tap_code16(US_LABK);
                tap_code16(US_EQL);
            }
            return true;
        case INF:
            if (record->event.pressed) {
                tap_code16(US_RABK);
                tap_code16(US_EQL);
            }
            return true;
        case QU:
            if (record->event.pressed) {
                tap_code16(US_Q);
                tap_code16(US_U);
            }
            return true;
        case AROW:
            if (record->event.pressed) {
                tap_code16(US_MINS);
                tap_code16(US_RABK);
            }
            return true;

        default:
            return true;
    }
}

uint16_t get_combo_term(uint16_t combo_index, combo_t* combo){
    switch (combo->keycode) {
        case CW_TOGG:
        case NUMW:
        case KC_LCTL:
            return 50;
    }
    return COMBO_TERM;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    rgblight_sethsv_range(HSV_WHITE,0,45);
    switch(get_highest_layer(layer_state)) {
    case _BSYM:
        rgblight_sethsv_range(HSV_BLUE,6,9);
        break;
    case _SHRT:
        rgblight_sethsv_range(HSV_GREEN,6,10);
        rgblight_sethsv_range(HSV_GREEN,11,21);
        rgblight_sethsv_range(HSV_GREEN,23,26);
        rgblight_sethsv_range(HSV_GREEN,28,37);
        rgblight_sethsv_at(HSV_GREEN,38);
        rgblight_sethsv_at(HSV_GREEN,40);
        break;
    case _NUM:
        rgblight_sethsv_at(HSV_GOLDENROD,6);
        rgblight_sethsv_range(HSV_CHARTREUSE,7,9);
        rgblight_sethsv_at(HSV_GOLDENROD,9);
        rgblight_sethsv_range(HSV_GOLDENROD,11,16);
        rgblight_sethsv_range(HSV_CHARTREUSE,16,19);
        rgblight_sethsv_at(HSV_GOLDENROD,19);
        rgblight_sethsv_range(HSV_BLACK,20,22);
        break;

    }
}
