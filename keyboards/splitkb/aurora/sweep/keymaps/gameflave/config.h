/* Copyright 2022 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef MOUSEKEY_ENABLE
// The default is 100
#    define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 100
#endif

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define NO_MUSIC_MODE

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define TAPPING_TERM 180
#define QUICK_TAP_TERM 0
#define PERMISSIVE_HOLD
#undef HOLD_ON_OTHER_KEY_PRESS

#define TAP_CODE_DELAY 20

#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
