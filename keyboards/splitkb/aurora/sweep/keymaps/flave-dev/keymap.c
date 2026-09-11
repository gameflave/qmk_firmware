#include <stdint.h>

#include "action.h"
#include "action_layer.h"
#include "action_util.h"
#include "color.h"
#include "debug.h"
#include "host.h"
#include "info_config.h"
#include "keyboard.h"
#include "modifiers.h"
#include "print.h"
#include "quantum_keycodes.h"
#include "report.h"

#include QMK_KEYBOARD_H

#include "keymap_us_international.h"
#include "g/keymap_combo.h" // Get combos from combos.def

#include "keycodes.h"
#include "rgb.h"

#include "config.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        AGRV   ,MOUS_J ,US_EACU,US_B   ,QU_Q   ,      US_F   ,US_D   ,US_L   ,QUOT   ,US_X   ,
        NAV_A  ,SYM_I  ,CTL_O  ,SHFT_U ,ALT_COM,      ALT_P  ,SHFT_T ,CTL_S  ,SYM_R  ,NUM_N  ,
        US_K   ,US_Y   ,EGRV   ,US_DOT ,US_W   ,      US_G   ,US_C   ,FUN_M  ,US_H   ,US_V   ,
                                KC_LGUI,US_E   ,      KC_SPC ,MO(_SHRT)
    ),

    [_JP1] = LAYOUT(
        JP_こ  ,JP_ん  ,JP_っ  ,JP_か  ,JP_し  ,      JP_る  ,JP_を  ,JP_ら  ,JP_ま  ,JP_も  ,
        NAV_と ,SYM_い ,JP_は  ,JP_の  ,US_COMM,      JP_た  ,JP_て  ,JP_に  ,SYM_な ,NUM_う ,
        JP_そ  ,JP_あ  ,JP_す  ,US_DOT ,JP_だ  ,      JP_が  ,JP_で  ,JP_れ  ,JP_り  ,JP_く  ,
                                JAP    ,JP2    ,      _______,JP3
    ),
    [_JP2] = LAYOUT(
        JP_ひ  ,JP_ず  ,JP_ね  ,JP_ふ  ,JP_ほ  ,      JP_え  ,JP_や  ,JP_へ  ,JP_わ  ,JP_め  ,
        JP_き  ,JP_よ  ,JP_ち  ,JP_じ  ,JP_み  ,      JP_つ  ,JP_さ  ,JP_お  ,JP_け  ,JP_ど  ,
        JP_げ  ,JP_ご  ,JP_む  ,JP_び  ,JP_ぐ  ,      JP_ろ  ,JP_ば  ,JP_せ  ,JP_ょ  ,JP_ゃ  ,
                                _______,_______,      _______,_______
    ),
    [_JP3] = LAYOUT(
        JP_ぁ  ,JP_ぃ  ,JP_ぇ  ,JP_ぉ  ,JP_ぅ  ,      JP_ゎ  ,JP_ヵ  ,JP_ヶ  ,JP_ゔ  ,JP_ゐ  ,
        JP_ざ  ,JP_べ  ,JP_ぬ  ,JP_ぶ  ,JP_ぎ  ,      JP_ゆ  ,JP_ぼ  ,JP_ぜ  ,JP_づ  ,JP_ぞ  ,
        JP_ぱ  ,JP_ぢ  ,JP_ぽ  ,JP_ぴ  ,JP_ぺ  ,      JP_ゅ  ,JP_ぷ  ,JP_ゑ  ,XXXXXXX,XXXXXXX,
                                _______,_______,      _______,_______
    ),
    [_SYML] = LAYOUT(
        US_EXLM,US_LCBR,US_RCBR,US_HASH,TIL    ,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        CIR    ,US_LPRN,US_RPRN,US_UNDS,DQUOT  ,      XXXXXXX,KC_ENT ,KC_ESC ,XXXXXXX,XXXXXXX,
        US_BSLS,US_AT  ,US_EQL ,KP_DOT ,US_NDAC,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                _______,_______,      _______,_______
    ),
    [_SYMR] = LAYOUT(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,      US_PERC,US_QUES,US_LABK,US_RABK,US_ASTR,
        XXXXXXX,XXXXXXX,KC_BSPC,KC_DEL ,KC_TAB ,      US_SLSH,US_COLN,US_LBRC,US_RBRC,US_DLR ,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,      US_MINS,US_AMPR,US_PIPE,US_SCLN,US_PLUS,
                                _______,_______,      _______,_______
    ),
    [_SHRT] = LAYOUT(
        _______,GAME   ,_______,_______,_______,      _______,US_EURO,US_YEN ,_______,_______, //TODO: shortcut ctr+alt+F(1-2-3)
        _______,_______,_______,_______,_______,      US_DTIL,US_ACUT,US_DCIR,US_DIAE,US_DGRV,
        _______,_______,_______,_______,S(KC_F1),     KC_PSCR,_______,_______,_______,_______,
                                JAP    ,_______,      _______,_______
    ),
    [_NAV] = LAYOUT(
        _______,_______,KC_BSPC,KC_DEL ,_______,      KC_PGUP,KC_HOME,_______,KC_END ,_______ ,
      _______,MO(_MOUS),KC_LCTL,KC_LSFT,_______,      KC_PGDN,KC_LEFT,KC_DOWN,KC_UP  ,KC_RIGHT,
        _______,_______,_______,_______,_______,      _______,_______,_______,_______,_______ ,
                                _______,_______,      _______,_______
    ),
    [_NUM] = LAYOUT(
        XXXXXXX ,US_1  ,US_2   ,US_3   ,XXXXXXX,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX  ,XXXXXXX,
        MO(_NAV),US_4  ,US_5   ,US_6   ,US_0   ,      KC_LALT,KC_LSFT,KC_LCTL,MO(_NUMP),XXXXXXX,
        XXXXXXX ,US_7  ,US_8   ,US_9   ,XXXXXXX,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX  ,XXXXXXX,
                                _______,_______,      _______,_______
    ),
    [_NUMP] = LAYOUT(
        XXXXXXX,KC_KP_1,KC_KP_2,KC_KP_3,XXXXXXX,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
       MO(_NAV),KC_KP_4,KC_KP_5,KC_KP_6,KC_KP_0,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,KC_KP_7,KC_KP_8,KC_KP_9,XXXXXXX,      XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                _______,_______,      _______,_______
    ),
    [_MOUS] = LAYOUT(
        _______,_______,MS_BTN3,MS_BTN2,_______,      MS_WHLU,KC_HOME,_______,KC_END ,_______ ,
        _______,_______,KC_LCTL,KC_LSFT,KC_LALT,      MS_WHLD,MS_LEFT,MS_DOWN,MS_UP  ,MS_RGHT ,
        _______,_______,_______,_______,_______,      _______,MS_ACL0,MS_ACL1,MS_ACL2,_______ ,
                                _______,MS_BTN1,      _______,_______
    ),
    [_FUN] = LAYOUT(
        _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F11 ,      _______,_______,_______,_______,_______,
        _______,KC_F4  ,KC_F5  ,KC_F6  ,KC_F10 ,      _______,_______,_______,_______,_______,
        _______,KC_F7  ,KC_F8  ,KC_F9  ,KC_F12 ,      _______,_______,_______,_______,_______,
                                _______,_______,      _______,_______
    ),
    [_GAME] = LAYOUT(
        KC_ESC ,US_1   ,US_2   ,US_3   ,US_4   ,      US_5   ,US_6   ,US_7   ,US_8   ,US_9   ,
        KC_TAB ,US_Q   ,US_W   ,US_E   ,US_R   ,      US_T   ,US_Y   ,US_U   ,US_I   ,US_O   ,
        KC_LSFT,US_A   ,US_S   ,US_D   ,US_F   ,      US_G   ,US_H   ,US_J   ,US_K   ,US_L   ,
                                KC_LCTL,KC_SPACE,     TG(_GAME),XXXXXXX
    ),
};
// clang-format on

#define JP_LT(Key, Taped)                                 \
    case Key:                                             \
        if (record->tap.count && record->event.pressed) { \
            jp_send_kana(Taped);                          \
            return false;                                 \
        }                                                 \
        break;

#define UNDEAD(Key, DKey)            \
    case Key:                        \
        if (record->event.pressed) { \
            tap_code16(DKey);        \
            tap_code16(KC_SPACE);    \
        }                            \
        return false;

static void jp_send_kana(uint16_t keycode) {
    switch (keycode) {
        // clang-format off
#ifndef DIRECT_KANA
#define SS_KC(keycode, string) case keycode: SEND_STRING(string); break;

        SS_KC(JP_あ,"a")  SS_KC(JP_か,"ka")  SS_KC(JP_さ,"sa")  SS_KC(JP_た,"ta")  SS_KC(JP_な,"na")	 SS_KC(JP_は,"ha")	SS_KC(JP_ま,"ma")	SS_KC(JP_や,"ya")	SS_KC(JP_ら,"ra")  SS_KC(JP_わ,"wa")
        SS_KC(JP_い,"i")  SS_KC(JP_き,"ki")  SS_KC(JP_し,"si")  SS_KC(JP_ち,"ti")  SS_KC(JP_に,"ni")	 SS_KC(JP_ひ,"hi")	SS_KC(JP_み,"mi")	                    SS_KC(JP_り,"ri")  SS_KC(JP_ゐ,"wi")
        SS_KC(JP_う,"u")  SS_KC(JP_く,"ku")  SS_KC(JP_す,"su")  SS_KC(JP_つ,"tu")  SS_KC(JP_ぬ,"nu")	 SS_KC(JP_ふ,"hu")	SS_KC(JP_む,"mu")	SS_KC(JP_ゆ,"yu")	SS_KC(JP_る,"ru")
        SS_KC(JP_え,"e")  SS_KC(JP_け,"ke")  SS_KC(JP_せ,"se")  SS_KC(JP_て,"te")  SS_KC(JP_ね,"ne")	 SS_KC(JP_へ,"he")	SS_KC(JP_め,"me")	                    SS_KC(JP_れ,"re")  SS_KC(JP_ゑ,"we")
        SS_KC(JP_お,"o")  SS_KC(JP_こ,"ko")  SS_KC(JP_そ,"so")  SS_KC(JP_と,"to")  SS_KC(JP_の,"no")	 SS_KC(JP_ほ,"ho")	SS_KC(JP_も,"mo")	SS_KC(JP_よ,"yo")	SS_KC(JP_ろ,"ro")  SS_KC(JP_を,"wo")  SS_KC(JP_ん,"nn")

                          SS_KC(JP_が,"ga")  SS_KC(JP_ざ,"za")  SS_KC(JP_だ,"da")                     SS_KC(JP_ば,"ba")  SS_KC(JP_ぱ,"pa")
                          SS_KC(JP_ぎ,"gi")  SS_KC(JP_じ,"zi")  SS_KC(JP_ぢ,"di")                     SS_KC(JP_び,"bi")  SS_KC(JP_ぴ,"pi")
        SS_KC(JP_ゔ,"vu") SS_KC(JP_ぐ,"gu")  SS_KC(JP_ず,"zu")  SS_KC(JP_づ,"du")                     SS_KC(JP_ぶ,"bu")  SS_KC(JP_ぷ,"pu")
                          SS_KC(JP_げ,"ge")  SS_KC(JP_ぜ,"ze")  SS_KC(JP_で,"de")                     SS_KC(JP_べ,"be")  SS_KC(JP_ぺ,"pe")
                          SS_KC(JP_ご,"go")  SS_KC(JP_ぞ,"zo")  SS_KC(JP_ど,"do")                     SS_KC(JP_ぼ,"bo")  SS_KC(JP_ぽ,"po")

        SS_KC(JP_ぁ,"xa") SS_KC(JP_ヵ,"xka")                                                                                               SS_KC(JP_ゃ,"xya")                   SS_KC(JP_ゎ,"xwa")
        SS_KC(JP_ぃ,"xi")
        SS_KC(JP_ぅ,"xu")                                       SS_KC(JP_っ,"xtu")                                                         SS_KC(JP_ゅ,"xyu")
        SS_KC(JP_ぇ,"xe") SS_KC(JP_ヶ,"xke")
        SS_KC(JP_ぉ,"xo")                                                                                                                      SS_KC(JP_ょ,"xyo")
#else
        //TODO: Fix if I ever go back to this
#define TAP_CODE(keycode, tapcode) case keycode: if(record->event.pressed) {tap_code16(tapcode);} return false;
#define TAP_CODES(keycode, tapcode_1, tapcode_2) case keycode: if(record->event.pressed) {tap_code16(tapcode_1); tap_code16(tapcode_2);} return false;
        TAP_CODE(JP_あ,KC_3)      TAP_CODE(JP_か,KC_T)	TAP_CODE(JP_さ,KC_X)  TAP_CODE(JP_た,KC_Q)  TAP_CODE(JP_な,KC_U)	 TAP_CODE(JP_は,KC_F)	TAP_CODE(JP_ま,KC_J)	TAP_CODE(JP_や,KC_7)	TAP_CODE(JP_ら,KC_O)    TAP_CODE(JP_わ,KC_0)
        TAP_CODE(JP_い,KC_E)      TAP_CODE(JP_き,KC_G)	TAP_CODE(JP_し,KC_D)  TAP_CODE(JP_ち,KC_A)  TAP_CODE(JP_に,KC_I)	 TAP_CODE(JP_ひ,KC_V)	TAP_CODE(JP_み,KC_N)	                        TAP_CODE(JP_り,KC_L)    TAP_CODE(JP_ゐ,KC_NO)
        TAP_CODE(JP_う,KC_4)      TAP_CODE(JP_く,KC_H)	TAP_CODE(JP_す,KC_R)  TAP_CODE(JP_つ,KC_Z)  TAP_CODE(JP_ぬ,KC_1)	 TAP_CODE(JP_ふ,KC_2)	TAP_CODE(JP_む,KC_NUHS)	TAP_CODE(JP_ゆ,KC_8)	TAP_CODE(JP_る,KC_DOT)
        TAP_CODE(JP_え,KC_5)      TAP_CODE(JP_け,KC_QUOT)TAP_CODE(JP_せ,KC_P)  TAP_CODE(JP_て,KC_W)  TAP_CODE(JP_ね,KC_COMM)	 TAP_CODE(JP_へ,KC_EQL)	TAP_CODE(JP_め,KC_SLSH)	                        TAP_CODE(JP_れ,KC_SCLN) TAP_CODE(JP_ゑ,KC_NO)
        TAP_CODE(JP_お,KC_6)      TAP_CODE(JP_こ,KC_B)	TAP_CODE(JP_そ,KC_C)  TAP_CODE(JP_と,KC_S)  TAP_CODE(JP_の,KC_K)	 TAP_CODE(JP_ほ,KC_MINS)TAP_CODE(JP_も,KC_M)	TAP_CODE(JP_よ,KC_9)	TAP_CODE(JP_ろ,KC_INT1) TAP_CODE(JP_を,S(KC_0))  TAP_CODE(JP_ん,KC_Y)

                                            TAP_CODES(JP_が, JP_か  , KC_LBRC)     TAP_CODES(JP_ざ, JP_さ, KC_LBRC)     TAP_CODES(JP_だ, JP_た, KC_LBRC)     TAP_CODES(JP_ば, JP_は, KC_LBRC)     TAP_CODES(JP_ぱ, JP_は, KC_RBRC)
                                            TAP_CODES(JP_ぎ, JP_き  , KC_LBRC)     TAP_CODES(JP_じ, JP_し, KC_LBRC)     TAP_CODES(JP_ぢ, JP_ち, KC_LBRC)     TAP_CODES(JP_び, JP_ひ, KC_LBRC)     TAP_CODES(JP_ぴ, JP_ひ, KC_RBRC)
        TAP_CODES(JP_ゔ, JP_う, KC_LBRC)     TAP_CODES(JP_ぐ, JP_く  , KC_LBRC)     TAP_CODES(JP_ず, JP_す, KC_LBRC)     TAP_CODES(JP_づ, JP_つ, KC_LBRC)     TAP_CODES(JP_ぶ, JP_ふ, KC_LBRC)     TAP_CODES(JP_ぷ, JP_ふ, KC_RBRC)
                                            TAP_CODES(JP_げ, JP_け  , KC_LBRC)     TAP_CODES(JP_ぜ, JP_せ, KC_LBRC)     TAP_CODES(JP_で, JP_て, KC_LBRC)     TAP_CODES(JP_べ, JP_へ, KC_LBRC)     TAP_CODES(JP_ぺ, JP_へ, KC_RBRC)
                                            TAP_CODES(JP_ご, JP_こ  , KC_LBRC)     TAP_CODES(JP_ぞ, JP_そ, KC_LBRC)     TAP_CODES(JP_ど, JP_と, KC_LBRC)     TAP_CODES(JP_ぼ, JP_ほ, KC_LBRC)     TAP_CODES(JP_ぽ, JP_ほ, KC_RBRC)

        TAP_CODE(JP_ぁ,S(KC_3))            TAP_CODE(JP_ゃ,S(KC_7))
        TAP_CODE(JP_ぃ,S(KC_E))
        TAP_CODE(JP_ぅ,S(KC_4))            TAP_CODE(JP_ゅ,S(KC_8))              TAP_CODE(JP_っ, S(KC_Z))
        TAP_CODE(JP_ぇ,S(KC_5))
        TAP_CODE(JP_ぉ,S(KC_6))            TAP_CODE(JP_ょ,S(KC_9))
#endif
        // clang-format on
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // These are dead key by default make the non-dead version
        UNDEAD(GRV, US_DGRV)
        UNDEAD(TIL, US_DTIL)
        UNDEAD(QUOT, US_ACUT)
        UNDEAD(CIR, US_DCIR)
        UNDEAD(DQUOT, S(US_ACUT))

        case AGRV:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                unregister_mods(MOD_MASK_SHIFT);

                tap_code16(US_DGRV);
                if (mods & MOD_MASK_SHIFT) set_mods(mods);

                tap_code16(US_A);
            }
            return false;
        case EGRV:
            if (record->event.pressed) {
                uint8_t mods = get_mods();
                unregister_mods(MOD_MASK_SHIFT);

                tap_code16(US_DGRV);
                if (mods & MOD_MASK_SHIFT) set_mods(mods);

                tap_code16(US_E);
            }
            return false;
        case QU_Q:
            if (record->event.pressed) {
                tap_code16(US_Q);
                if (record->tap.count) tap_code16(US_U);
            }
            return false;

        case JAP:
            if (record->event.pressed) {
                layer_invert(_JP1);
                tap_code16(JP_HENK);
            }
            return false;
        case JP_RANGE ... JP_RANGE_END:
            if (record->event.pressed) jp_send_kana(keycode);
            return false;

            JP_LT(NAV_と, JP_と)
            JP_LT(SYM_い, JP_い)
            JP_LT(SYM_な, JP_な)
            JP_LT(NUM_う, JP_う)
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

void keyboard_post_init_user() {
    if (!host_keyboard_led_state().num_lock) tap_code(KC_NUM_LOCK);
}

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _SHRT:
            rgb_matrix_set_layer(rgb_shrt);
            break;
        case _SYML:
            rgb_matrix_set_layer(rgb_bsym_l);
            break;
        case _SYMR:
            rgb_matrix_set_layer(rgb_bsym_r);
            break;
        case _NUM:
            rgb_matrix_set_layer(rgb_num);
            break;
        case _NUMP:
            rgb_matrix_set_layer(rgb_num);
            break;
        case _NAV:
            rgb_matrix_set_layer(rgb_nav);
            break;
        case _MOUS:
            rgb_matrix_set_layer(rgb_mouse);
            break;
        case _FUN:
            rgb_matrix_set_layer(rgb_fun);
            break;
        case _GAME:
            rgb_matrix_set_layer(rgb_game);
            break;
        case _JP1:
            rgb_matrix_set_layer(rgb_jap1);
            break;
        case _JP2:
            rgb_matrix_set_layer(rgb_jap2);
            break;
        case _JP3:
            rgb_matrix_set_layer(rgb_jap3);
            break;
        case _BASE:
        default:
            rgb_matrix_set_layer(rgb_base);
    }

    return false;
}
