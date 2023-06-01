/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _SYMBOLS,
    _NUMBERS,
    _FKEYS,
    _NAV,
    _SPECIAL,
};

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(MO(3), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, CW_TOGG, 
            KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, RCTL_T(KC_QUOT), 
            KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO, KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_EQL, KC_RSFT, 
            KC_NO, MO(1), LT(2,KC_BSPC), LT(4,KC_ENT), KC_NO, KC_NO, LT(5,KC_TAB ), KC_SPC, TG(2), KC_RALT),

  [_SYMBOLS] = LAYOUT(KC_NO, KC_PSLS, KC_EXLM, KC_QUES, KC_HASH, KC_PAST, KC_DLR, KC_NO, KC_AMPR, KC_PIPE, KC_BSLS, KC_GRV, 
            KC_TRNS, KC_AT, KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, KC_RBRC, KC_GT, KC_TRNS, KC_TRNS, 
            KC_TRNS, KC_PERC, KC_CIRC, RCTL(KC_SLSH), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_UNDS, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
            KC_NO, KC_NO, KC_BSPC, KC_ENT, KC_NO, KC_NO, TO(0), KC_TRNS, KC_TRNS, KC_RALT),

  [_NUMBERS] = LAYOUT(KC_NO, KC_SLSH, KC_EXLM, KC_QUES, KC_HASH, KC_PDOT, KC_DLR, KC_P7, KC_P8, KC_P9, KC_BSLS, KC_GRV, 
            KC_TRNS, KC_AT, KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, KC_P0, KC_P1, KC_P2, KC_P3, KC_SCLN, KC_TRNS, 
            KC_TRNS, KC_PERC, KC_CIRC, KC_NO, KC_NO, KC_PCMM, KC_NO, KC_NO, KC_NO, KC_NO, KC_MINS, KC_P4, KC_P5, KC_P6, KC_EQL, KC_TRNS, 
            KC_NO, KC_NO, KC_BSPC, KC_ENT, KC_NO, KC_NO, TO(0), KC_SPC, KC_TRNS, KC_RALT),
            
  [_FKEYS] = LAYOUT(KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, 
            KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F11, KC_RCTL, 
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_F12, KC_TRNS, 
            KC_NO, KC_NO, KC_BSPC, KC_ENT, KC_NO, KC_NO, TO(0), KC_SPC, KC_NO, KC_RALT),

  [_NAV] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_NO, KC_UP, KC_NO, KC_PGUP, KC_NO, 
            KC_LCTL, KC_NO, KC_NO, KC_DEL, KC_ENT, KC_TAB, KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_RCTL, 
            KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, 
            KC_NO, KC_NO, KC_BSPC, KC_ENT, KC_NO, KC_NO, TO(0), KC_SPC, KC_NO, KC_RALT),

  [_SPECIAL] = LAYOUT(KC_NO, KC_APP, KC_LGUI, KC_NO, KC_ESC, KC_NO, LCA(KC_DEL), KC_NO, KC_NO, KC_NO, KC_NO, KC_CAPS, 
            KC_LCTL, KC_NO, KC_NO, KC_DEL, KC_ENT, KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RCTL, 
            KC_TRNS, RCTL(KC_PSCR), KC_PSCR, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F12, KC_TRNS, 
            KC_NO, KC_NO, KC_BSPC, KC_ENT, KC_NO, KC_NO, TO(0), KC_SPC, KC_NO, KC_RALT) 

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif

layer_state_t layer_state_set_user(layer_state_t state){
    return state;
}

bool set_rgb(int index, uint8_t hue, uint8_t sat, uint8_t val){
    // Using HSV and then converting to RGB allows the brightness 
    // to be limited (important when using the WS2812 driver).
    HSV hsv = {hue, sat, val};
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
    return false;
}

bool set_rgb_all(uint8_t hue, uint8_t sat, uint8_t val){
    // Using HSV and then converting to RGB allows the brightness 
    // to be limited (important when using the WS2812 driver).
    HSV hsv = {hue, sat, val};
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
    return false;
}

bool rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            set_rgb_all(HSV_BLUE);
            set_rgb(14, HSV_GREEN); // F
            set_rgb(45, HSV_GREEN); // J
            break;
        case _SYMBOLS:
            set_rgb_all(HSV_RED);
            break;
        case _NUMBERS:
            set_rgb_all(HSV_BLACK);
            set_rgb(51, HSV_YELLOW); // 7
            set_rgb(52, HSV_YELLOW); // 8
            set_rgb(53, HSV_YELLOW); // 9
            set_rgb(44, HSV_YELLOW); // 0
            set_rgb(45, HSV_YELLOW); // 1
            set_rgb(46, HSV_YELLOW); // 2
            set_rgb(47, HSV_YELLOW); // 3
            set_rgb(39, HSV_YELLOW); // 4
            set_rgb(40, HSV_YELLOW); // 5
            set_rgb(41, HSV_YELLOW); // 6
            break;
        case _FKEYS:
            set_rgb_all(HSV_TEAL);
            break;
        case _NAV:
            set_rgb_all(HSV_BLACK);
            set_rgb(52, HSV_GREEN); // up arrow
            set_rgb(45, HSV_GREEN); // left arrow
            set_rgb(46, HSV_GREEN); // down arrow
            set_rgb(47, HSV_GREEN); // right arrow
            break;
        case _SPECIAL:
            set_rgb_all(HSV_PURPLE);
            break;
        default:
            set_rgb_all(HSV_BLACK);
            break;
    }
    return false;
}
