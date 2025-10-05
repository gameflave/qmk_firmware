#include <stdint.h>

#include "keycodes.h"

#include QMK_KEYBOARD_H

#include "keymap_us_international.h"
#include "g/keymap_combo.h" // Get combos from combos.def

#include "config.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        AGRV   ,EGRV   ,US_EACU,US_B   ,QK_REP ,      US_F    ,US_D    ,US_L   ,QUOT   ,US_X,
        US_A   ,US_I   ,US_O   ,US_U   ,US_COMM,      US_P    ,US_T    ,US_S   ,US_R   ,US_N,
        US_K   ,US_Y   ,US_J   ,US_DOT ,US_W   ,      US_G    ,US_C    ,US_M   ,US_H   ,US_V,
                                SHRT   ,US_E   ,      SPACE   ,MO(_NUM)
    ),
    [_BSYM] = LAYOUT(
        US_UNDS,US_LPRN,US_RPRN,_______,_______,     _______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,     _______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,     _______,_______,_______,_______,_______,
                                _______,_______,     _______,_______
    ),
    [_SHRT] = LAYOUT(
        C(US_E),US_S,   US_R,   US_G,   _______,      _______,  NAV  ,_______,_______,_______,
        C(US_X),C(US_C),C(US_S),C(US_V),C(US_Z),      US_DGRV,US_DIAE,US_DCIR,US_ACUT,US_DTIL,
        C(US_B),C(US_W),C(US_D),C(US_R),S(KC_F1),     KC_PSCR,  GAME ,US_CURR,  JAP  ,_______,
                                SHRT,   _______,      KC_SPACE,MO(_FUN)
    ),
    [_NAV] = LAYOUT(
        _______,_______,_______,_______,_______,     KC_PGUP,KC_HOME,_______,KC_END ,_______ ,
        KC_LGUI,KC_LALT,KC_LCTL,KC_LSFT,_______,     KC_PGDN,KC_LEFT,KC_DOWN,KC_UP  ,KC_RIGHT,
        _______,_______,_______,_______,_______,     _______,_______,_______,_______,_______ ,
                                _______,MO(_WNAV),   _______,_______
    ),
    [_WNAV] = LAYOUT(
        _______,_______,_______,G(US_8),_______,      _______,G(US_9),_______,_______,_______,
        G(US_6),G(US_4),G(US_0),G(US_2),_______,      _______,G(US_3),G(US_1),G(US_5),G(US_7),
        KC_LGUI,KC_LALT,KC_LCTL,KC_LSFT,_______,      _______,KC_LSFT,KC_LCTL,KC_LALT,KC_LGUI,
                                _______,XXXXXXX,      _______,_______
    ),
    [_NUM] = LAYOUT(
        US_UNDS,US_LPRN,US_RPRN,US_8   ,AT_U   ,      _______,US_9   ,KC_PPLS,KC_PMNS,KC_PAST,
        US_6   ,US_4   ,US_0   ,US_2   ,US_COMM,      KC_PSLS,US_3   ,US_1   ,US_5   ,US_7   ,
        US_K   ,S(US_G),US_J   ,US_DOT ,XXXXXXX,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                XXXXXXX,XXXXXXX,      SPACE  ,XXXXXXX
    ),
    [_FUN] = LAYOUT(
        _______,_______,_______,KC_F8  ,_______,      _______,KC_F9  ,_______,_______,_______,
        KC_F6  ,KC_F4  ,KC_F10 ,KC_F2  ,KC_F12 ,      KC_F11 ,KC_F3  ,KC_F1  ,KC_F5  ,KC_F7,
        _______,_______,_______,_______,_______,      _______,_______,_______,_______,_______,
                                _______,_______,      _______,_______
    ),
    [_GAME] = LAYOUT(
        KC_ESC ,US_1   ,US_2   ,US_3   ,US_4   ,      US_5   ,US_6   ,US_7   ,US_8   ,US_9   ,
        KC_TAB ,US_Q   ,US_W   ,US_E   ,US_R   ,      US_T   ,US_Y   ,US_U   ,US_I   ,US_O   ,
        KC_LSFT,US_A   ,US_S   ,US_D   ,US_F   ,      US_G   ,US_H   ,US_J   ,US_K   ,US_L   ,
                                KC_LCTL,KC_SPACE,     XXXXXXX,XXXXXXX
    ),
    [_JP1] = LAYOUT(
        JP_RA  ,JP_RU  ,JP_KO  ,JP_HA  ,JP_YO  ,      JP_KI  ,JP_NO  ,JP_KU  ,JP_A   ,JP_RE  ,
        JP_TA  ,JP_TO  ,JP_KA  ,JP_TE  ,JP_MO  ,      JP_WO  ,JP_I   ,JP_U   ,JP_SI  ,JP_N   ,
        JP_MA  ,JP_RI  ,JP_NI  ,JP_SA  ,JP_NA  ,      JP_SU  ,JP_TU  ,KC_TAB ,XXXXXXX,JP_S_TU,
                                KC_SPC ,MO(_JP2),     MO(_JP3),KC_ENT
    ),
    [_JP2] = LAYOUT(
        JP_HI  ,JP_SO  ,KC_BSPC,JP_S_YA,JP_HO  ,      JP_GI  ,JP_GE  ,JP_GU  ,XXXXXXX,XXXXXXX,
        JP_NU  ,JP_NE  ,JP_S_YU,JP_S_YO,JP_HU  ,      XXXXXXX,JP_DI  ,JP_VU  ,JP_ZI  ,XXXXXXX,
        JP_S_E ,JP_S_O ,JP_SE  ,JP_YU  ,JP_HE  ,      JP_ZU  ,JP_DU  ,TG(_JP1),XXXXXXX,XXXXXXX,
                                _______,_______,      MO(_JP4),_______
    ),
    [_JP3] = LAYOUT(
        JP_BI  ,JP_ZO  ,JP_GO  ,JP_BA  ,JP_BO  ,      JP_E   ,JP_KE  ,JP_ME  ,JP_MU  ,JP_RO  ,
        JP_DA  ,JP_DO  ,JP_GA  ,JP_DE  ,JP_BU  ,      JP_O   ,JP_TI  ,KC_PMNS,JP_MI  ,JP_YA  ,
        JP_S_KA,JP_S_KE,JP_ZE  ,JP_ZA  ,JP_BE  ,      JP_WA  ,JP_S_I ,JP_S_A ,XXXXXXX,XXXXXXX,
                                _______,MO(_JP4),     _______,_______
    ),

    [_JP4] = LAYOUT(
        JP_PI  ,XXXXXXX,XXXXXXX,JP_PA  ,JP_PO  ,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,S(KC_SPC),JP_PU,      XXXXXXX,JP_MHEN,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,JP_PE  ,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                _______,_______,      _______,_______
    )
};

#define UNDEAD(Key,DKey) case Key: if(record->event.pressed) {tap_code16(DKey);tap_code16(KC_SPACE);} return false;

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
        return false;
        case EGRV:
            if(record->event.pressed)
                { tap_code16(US_DGRV); tap_code16(US_E); }
        return false;
        case ECIR:
            if(record->event.pressed)
                { tap_code16(US_DCIR); tap_code16(US_E); }
        return false;
        case NEQL:
            if (record->event.pressed) {
                tap_code16(US_EXLM);
                tap_code16(US_EQL);
            }
            return false;
        case GRT:
            if (record->event.pressed) {
                tap_code16(US_LABK);
                tap_code16(US_EQL);
            }
            return false;
        case INF:
            if (record->event.pressed) {
                tap_code16(US_RABK);
                tap_code16(US_EQL);
            }
            return false;
        case QU:
            if (record->event.pressed) {
                tap_code16(US_Q);
                tap_code16(US_U);
            }
            return false;
        case AROW:
            if (record->event.pressed) {
                tap_code16(US_MINS);
                tap_code16(US_RABK);
            }
            return false;

        case AT_U:
            if (record->event.pressed) {
                tap_code16(US_AT);
                tap_code16(US_U);
            }
            return false;

#ifndef DIRECT_KANA
        SS_KC(JP_A,"a")      SS_KC(JP_KA,"ka")	SS_KC(JP_SA,"sa")  SS_KC(JP_TA,"ta")  SS_KC(JP_NA,"na")	 SS_KC(JP_HA,"ha")	SS_KC(JP_MA,"ma")	SS_KC(JP_YA,"ya")	SS_KC(JP_RA,"ra")  SS_KC(JP_WA,"wa")
        SS_KC(JP_I,"i")      SS_KC(JP_KI,"ki")	SS_KC(JP_SI,"si")  SS_KC(JP_TI,"ti")  SS_KC(JP_NI,"ni")	 SS_KC(JP_HI,"hi")	SS_KC(JP_MI,"mi")	                    SS_KC(JP_RI,"ri")  SS_KC(JP_WI,"wi")
        SS_KC(JP_U,"u")      SS_KC(JP_KU,"ku")	SS_KC(JP_SU,"su")  SS_KC(JP_TU,"tu")  SS_KC(JP_NU,"nu")	 SS_KC(JP_HU,"hu")	SS_KC(JP_MU,"mu")	SS_KC(JP_YU,"yu")	SS_KC(JP_RU,"ru")
        SS_KC(JP_E,"e")      SS_KC(JP_KE,"ke")	SS_KC(JP_SE,"se")  SS_KC(JP_TE,"te")  SS_KC(JP_NE,"ne")	 SS_KC(JP_HE,"he")	SS_KC(JP_ME,"me")	                    SS_KC(JP_RE,"re")  SS_KC(JP_WE,"we")
        SS_KC(JP_O,"o")      SS_KC(JP_KO,"ko")	SS_KC(JP_SO,"so")  SS_KC(JP_TO,"to")  SS_KC(JP_NO,"no")	 SS_KC(JP_HO,"ho")	SS_KC(JP_MO,"mo")	SS_KC(JP_YO,"yo")	SS_KC(JP_RO,"ro")  SS_KC(JP_WO,"wo")  SS_KC(JP_N,"nn")

                             SS_KC(JP_GA,"ga")  SS_KC(JP_ZA,"za")  SS_KC(JP_DA,"da")                     SS_KC(JP_BA,"ba")  SS_KC(JP_PA,"pa")
                             SS_KC(JP_GI,"gi")  SS_KC(JP_ZI,"zi")  SS_KC(JP_DI,"di")                     SS_KC(JP_BI,"bi")  SS_KC(JP_PI,"pi")
        SS_KC(JP_VU,"vu")    SS_KC(JP_GU,"gu")  SS_KC(JP_ZU,"zu")  SS_KC(JP_DU,"du")                     SS_KC(JP_BU,"bu")  SS_KC(JP_PU,"pu")
                             SS_KC(JP_GE,"ge")  SS_KC(JP_ZE,"ze")  SS_KC(JP_DE,"de")                     SS_KC(JP_BE,"be")  SS_KC(JP_PE,"pe")
                             SS_KC(JP_GO,"go")  SS_KC(JP_ZO,"zo")  SS_KC(JP_DO,"do")                     SS_KC(JP_BO,"bo")  SS_KC(JP_PO,"po")

        SS_KC(JP_S_A,"xa")   SS_KC(JP_S_KA,"xka")                                                                                               SS_KC(JP_S_YA,"xya")                   SS_KC(JP_S_WA,"xwa")
        SS_KC(JP_S_I,"xi")
        SS_KC(JP_S_U,"xu")                                         SS_KC(JP_S_TU,"xtu")                                                         SS_KC(JP_S_YU,"xyu")
        SS_KC(JP_S_E,"xe")   SS_KC(JP_S_KE,"xke")
        SS_KC(JP_S_O,"xo")                                                                                                                      SS_KC(JP_S_YO,"xyo")
#else
        TAP_CODE(JP_A,KC_3)      TAP_CODE(JP_KA,KC_T)	TAP_CODE(JP_SA,KC_X)  TAP_CODE(JP_TA,KC_Q)  TAP_CODE(JP_NA,KC_U)	 TAP_CODE(JP_HA,KC_F)	TAP_CODE(JP_MA,KC_J)	TAP_CODE(JP_YA,KC_7)	TAP_CODE(JP_RA,KC_O)    TAP_CODE(JP_WA,KC_0)
        TAP_CODE(JP_I,KC_E)      TAP_CODE(JP_KI,KC_G)	TAP_CODE(JP_SI,KC_D)  TAP_CODE(JP_TI,KC_A)  TAP_CODE(JP_NI,KC_I)	 TAP_CODE(JP_HI,KC_V)	TAP_CODE(JP_MI,KC_N)	                        TAP_CODE(JP_RI,KC_L)    TAP_CODE(JP_WI,KC_NO)
        TAP_CODE(JP_U,KC_4)      TAP_CODE(JP_KU,KC_H)	TAP_CODE(JP_SU,KC_R)  TAP_CODE(JP_TU,KC_Z)  TAP_CODE(JP_NU,KC_1)	 TAP_CODE(JP_HU,KC_2)	TAP_CODE(JP_MU,KC_NUHS)	TAP_CODE(JP_YU,KC_8)	TAP_CODE(JP_RU,KC_DOT)
        TAP_CODE(JP_E,KC_5)      TAP_CODE(JP_KE,KC_HELP)TAP_CODE(JP_SE,KC_P)  TAP_CODE(JP_TE,KC_W)  TAP_CODE(JP_NE,KC_COMM)	 TAP_CODE(JP_HE,KC_EQL)	TAP_CODE(JP_ME,KC_SLSH)	                        TAP_CODE(JP_RE,KC_SCLN) TAP_CODE(JP_WE,KC_NO)
        TAP_CODE(JP_O,KC_6)      TAP_CODE(JP_KO,KC_B)	TAP_CODE(JP_SO,KC_C)  TAP_CODE(JP_TO,KC_S)  TAP_CODE(JP_NO,KC_K)	 TAP_CODE(JP_HO,KC_MINS)TAP_CODE(JP_MO,KC_M)	TAP_CODE(JP_YO,KC_9)	TAP_CODE(JP_RO,KC_INT1) TAP_CODE(JP_WO,OSM(KC_LSFT))  TAP_CODE(JP_N,KC_Y)

                                            TAP_CODES(JP_GA, JP_KA  , KC_LBRC)     TAP_CODES(JP_ZA, JP_SA, KC_LBRC)     TAP_CODES(JP_DA, JP_TA, KC_LBRC)     TAP_CODES(JP_BA, JP_HA, KC_LBRC)     TAP_CODES(JP_PA, JP_HA, KC_RBRC)
                                            TAP_CODES(JP_GI, JP_KI  , KC_LBRC)     TAP_CODES(JP_ZI, JP_SI, KC_LBRC)     TAP_CODES(JP_DI, JP_TI, KC_LBRC)     TAP_CODES(JP_BI, JP_HI, KC_LBRC)     TAP_CODES(JP_PI, JP_HI, KC_RBRC)
        TAP_CODES(JP_VU, JP_U, KC_LBRC)     TAP_CODES(JP_GU, JP_KU  , KC_LBRC)     TAP_CODES(JP_ZU, JP_SU, KC_LBRC)     TAP_CODES(JP_DU, JP_TU, KC_LBRC)     TAP_CODES(JP_BU, JP_HU, KC_LBRC)     TAP_CODES(JP_PU, JP_HU, KC_RBRC)
                                            TAP_CODES(JP_GE, KC_QUOT, KC_LBRC)     TAP_CODES(JP_ZE, JP_SE, KC_LBRC)     TAP_CODES(JP_DE, JP_TE, KC_LBRC)     TAP_CODES(JP_BE, JP_HE, KC_LBRC)     TAP_CODES(JP_PE, JP_HE, KC_RBRC)
                                            TAP_CODES(JP_GO, JP_KO  , KC_LBRC)     TAP_CODES(JP_ZO, JP_SO, KC_LBRC)     TAP_CODES(JP_DO, JP_TO, KC_LBRC)     TAP_CODES(JP_BO, JP_HO, KC_LBRC)     TAP_CODES(JP_PO, JP_HO, KC_RBRC)
        case JP_S_A:
        case JP_S_I:
        case JP_S_U:
        case JP_S_E:
        case JP_S_O:
        case JP_S_TU:
        case JP_S_YA:
        case JP_S_YU:
        case JP_S_YO:
        case JP_S_WA:
            if(record->event.pressed) {
                tap_code16(OSM(KC_LSFT));
                tap_code16(KC_0);
            }
            return false;

#endif
        default:
            return true;
    }
}
/*
 -enum japanese_keycodes_ {
-    JP_A=KC_3,  JP_KA=KC_T   ,	JP_SA=KC_X,	JP_TA=KC_Q,	JP_NA=KC_U   ,	JP_HA=KC_F   ,	JP_MA=KC_J   ,	JP_YA=KC_7,	JP_RA=KC_O   ,  JP_WA=KC_0,
-    JP_I=KC_E,  JP_KI=KC_G   ,	JP_SI=KC_D,	JP_TI=KC_A,	JP_NI=KC_I   ,	JP_HI=KC_V   ,	JP_MI=KC_N   ,	            JP_RI=KC_L   ,  JP_WI=KC_NO,
-    JP_U=KC_4,  JP_KU=KC_H   ,	JP_SU=KC_R,	JP_TU=KC_Z,	JP_NU=KC_1   ,	JP_HU=KC_2   ,	JP_MU=KC_NUHS,	JP_YU=KC_8,	JP_RU=KC_DOT ,
-    JP_E=KC_5,  JP_KE=KC_HELP,	JP_SE=KC_P,	JP_TE=KC_W,	JP_NE=KC_COMM,	JP_HE=KC_EQL ,	JP_ME=KC_SLSH,              JP_RE=KC_SCLN,  JP_WE=KC_NO,
-    JP_O=KC_6,  JP_KO=KC_B   ,	JP_SO=KC_C,	JP_TO=KC_S,	JP_NO=KC_K   ,	JP_HO=KC_MINS,	JP_MO=KC_M   ,	JP_YO=KC_9,	JP_RO=KC_INT1,  JP_WO=KC_0,  JP_N=KC_Y,
-
-    JP_S_A=KC_3,  JP_S_KA=KC_NO,                                                                     JP_S_YA=KC_7,
-    JP_S_I=KC_E,
-    JP_S_U=KC_4,                            JP_S_TU=KC_Z,                                            JP_S_YU=KC_8,
-    JP_S_E=KC_5,  JP_S_KE=KC_NO,
-    JP_S_O=KC_6,                                                                                     JP_S_YO=KC_9,

*/
uint16_t get_combo_term(uint16_t combo_index, combo_t* combo){
    switch (combo->keycode) {
        case CW_TOGG:
        case KC_LCTL:
            return 50;
    }
    return COMBO_TERM;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _GAME:
            combo_disable();
            break;
        default:
            combo_enable();
        }
    return state;
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
