/* Copyright 2021 yfuku
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

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_split_3x6_3_2( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15, L31, R33, R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25, L32, R34, R20, R21, R22, R23, R24, R25, \
                        L33, L34, L35, R30, R31, R32 \
    ) \
    { \
        { L00, L01, L02, L03, L04, L05 }, \
        { L10, L11, L12, L13, L14, L15 }, \
        { L20, L21, L22, L23, L24, L25 }, \
        { KC_NO, L31, L32, L33, L34, L35 }, \
        { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
        { R05, R04, R03, R02, R01, R00 }, \
        { R15, R14, R13, R12, R11, R10 }, \
        { R25, R24, R23, R22, R21, R20 }, \
        { KC_NO, R34, R33, R32, R31, R30 }, \
        { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
    }

#define LAYOUT_kc( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15, L31, R33, R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25, L32, R34, R20, R21, R22, R23, R24, R25, \
                        L33, L34, L35, R30, R31, R32 \
    ) \
    LAYOUT_split_3x6_3_2( \
        KC_##L00, KC_##L01, KC_##L02, KC_##L03, KC_##L04, KC_##L05,                     KC_##R00, KC_##R01, KC_##R02, KC_##R03, KC_##R04, KC_##R05, \
        KC_##L10, KC_##L11, KC_##L12, KC_##L13, KC_##L14, KC_##L15, KC_##L31, KC_##R33, KC_##R10, KC_##R11, KC_##R12, KC_##R13, KC_##R14, KC_##R15, \
        KC_##L20, KC_##L21, KC_##L22, KC_##L23, KC_##L24, KC_##L25, KC_##L32, KC_##R34, KC_##R20, KC_##R21, KC_##R22, KC_##R23, KC_##R24, KC_##R25, \
                                      KC_##L33, KC_##L34, KC_##L35,                     KC_##R30, KC_##R31, KC_##R32  \
    )
