#pragma once
#include <math.h>
#include "color.h"

#undef RGB_MOD

#define RGB_BASE 96, 96, 96
#define RGB_SYM  18, 40, 240
#define RGB_NUM  RGB_GOLD
#define RGB_NAV  RGB_GREEN
#define RGB_MOD  230, 2, 2
#define RGB_FN   RGB_PURPLE

float clampf(float val, float minVal, float maxVal) {
    if (val < minVal) return minVal;
    else if (val > maxVal) return maxVal;
    else return val;
}

typedef struct {float L, a, b;} Lab;
typedef struct {float L, C, h;} LCh;
float gamma_correct(const float value) {
    return value;// >= 0.0031308 ? 1.055 * powf(value, 1.0f/2.4f) - 0.055f : 12.92f * value;
}
RGB oklab_to_srgb(const Lab* c) {
    float l_ = c->L + 0.3963377774f * c->a + 0.2158037573f * c->b;
    float m_ = c->L - 0.1055613458f * c->a - 0.0638541728f * c->b;
    float s_ = c->L - 0.0894841775f * c->a - 1.2914855480f * c->b;

    float l = l_*l_*l_;
    float m = m_*m_*m_;
    float s = s_*s_*s_;

    RGB out = {
		clampf(gamma_correct(-1.2684380046f * l + 2.6097574011f * m - 0.3413193965f * s) * 255.0f, 0.0f, 255.0f),
        clampf(gamma_correct(+4.0767416621f * l - 3.3077115913f * m + 0.2309699292f * s) * 255.0f, 0.0f, 255.0f),
		clampf(gamma_correct(-0.0041960863f * l - 0.7034186147f * m + 1.7076147010f * s) * 255.0f, 0.0f, 255.0f),
    };
    return out;
}

RGB oklch_to_srgb(const LCh* c) {
    float hue = 2 * M_PI * (c->h / 360);

	Lab out;
    out.L = c->L;
    out.a = c->C * cosf(hue);
    out.b = c->C * sinf(hue);

    return oklab_to_srgb(&out);
}
