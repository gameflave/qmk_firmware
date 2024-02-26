#pragma once
#include <stdint.h>
#include QMK_KEYBOARD_H
#include "../../../../../../../quantum/keymap_extras/keymap_us_international.h"
#include "utils.h"

#define JP_MHEN KC_INT5 // Muhenkan (無変換) -> no convertion
#define JP_HENK KC_INT4 // Henkan (変換) -> convertion to kanji
#define JP_HIRA KC_INT2 // Katakana ↔ Hiragana ↔ Rōmaji (カタカナ ↔ ひらがな ↔ ローマ字)
#define JP_KATA S(KC_INT2)
#define JP_ROMA ALGR(KC_INT2)

#define SS_KC(keycode, string) case keycode: if(is_pressed(record)) SEND_STRING(string); return false;

enum japanese_keycodes {
    JP_A=SAFE_RANGE,JP_KA,	JP_SA,	JP_TA,	JP_NA,	JP_HA,	JP_MA,	JP_YA,	JP_RA,  JP_WA,
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

bool process_record_user_jp(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
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
    }
    return true;
}

void set_rgblight_jp(const uint8_t layer_index) {
    const LCh col = {0.65f, 0.15f, 0.0f};
    const RGB rgb = oklch_to_srgb(&col);

    rgblight_setrgb_range(rgb.r, rgb.g, rgb.b,  6,23);
    rgblight_setrgb_range(rgb.r, rgb.g, rgb.b, 29,46);
}
