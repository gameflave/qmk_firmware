#include "action.h"
#include "keycodes.h"
#include "keymap_us_international.h"
#include "quantum.h"

#include QMK_KEYBOARD_H
/* #include "g/keymap_combo.h" */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        AGRV   ,EGRV   ,US_EACU,US_B   ,QK_REP ,      US_F    ,US_D    ,US_L   ,QUOT   ,US_X,
        US_A   ,US_I   ,US_O   ,US_U   ,US_COMM,      US_P    ,US_T    ,US_S   ,US_R   ,US_N,
        US_K   ,US_Y   ,US_J   ,US_DOT ,US_W   ,      US_G    ,US_C    ,US_M   ,US_H   ,US_V,
                                SHRT   ,E      ,      SPACE   ,XXXXXXX
    ),
    [_SHRT] = LAYOUT(
        C(US_E),US_S,   US_R,   US_G,   _______,      _______, NAV,     MOD,    SYM,    _______,
        C(US_X),C(US_S),C(US_C),C(US_Z),C(US_V),      US_DGRV, US_DIAE, US_DCIR,US_ACUT,US_DTIL,
        C(US_B),C(US_W),C(US_D),C(US_R),S(KC_F1),     KC_PSCR, GAME,    US_CURR,JAP,    _______,
                                SHRT,   US_E,         KC_SPACE,MO(_FUN)
    ),
    [_NAV] = LAYOUT(
        _______,_______,_______,_______, _______,     _______,_______,_______,_______,_______ ,
        KC_LGUI,KC_HOME,C_UP   ,KC_END , KC_PGUP,     _______,KC_LEFT,KC_DOWN,KC_UP  ,KC_RIGHT,
        KC_ENT ,KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDN,     _______,_______,_______,_______,_______ ,
                                _______, _______,     MO(_WNAV),_______
    ),
    [_WNAV] = LAYOUT(
        _______,_______,_______,G(US_8),_______,      _______,G(US_9),_______,_______,_______,
        G(US_6),G(US_4),G(US_0),G(US_2),_______,      _______,G(US_3),G(US_1),G(US_5),G(US_7),
        _______,_______,_______,_______,_______,      _______,_______,_______,_______,_______,
                                _______,XXXXXXX,      _______,_______
    ),
    [_NUM] = LAYOUT(
        US_UNDS,US_LPRN,US_RPRN,US_8   ,_______,      _______,US_9   ,KC_PPLS,KC_PMNS,KC_PAST,
        US_6   ,US_4   ,US_0   ,US_2   ,_______,      KC_PSLS,US_3   ,US_1   ,US_5   ,US_7   ,
        _______,S(US_G),_______,KC_PDOT,_______,      _______,_______,_______,_______,_______,
                                _______,_______,      CANCEL ,_______
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
};

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode) {
        // These are dead key by default make the non-dead version
        case GRV:
        case TIL:
        case QUOT:
        case CIR:
            if(record->event.pressed)
                { tap_code(keycode); tap_code(KC_SPACE); }
        return true;

        case AGRV:
            if(record->event.pressed)
                { tap_code(US_DGRV); tap_code(US_A); }
        return true;
        case EGRV:
            if(record->event.pressed)
                { tap_code(US_DGRV); tap_code(US_E); }
        return true;

        default:
            return true;
    }
}
