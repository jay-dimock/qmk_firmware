// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    BASE = 0,
    PUNCT,
    NUMB,
    FUNCT,
    MOUSE,
    NAV,
    ALWAYS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [BASE] = LAYOUT_split_3x6_3(MO(FUNCT), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, RALT(CW_TOGG), TG(MOUSE), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, RCTL_T(KC_QUOT), KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_EQL, KC_RSFT, OSL(PUNCT), LT(NUMB,KC_BSPC), LT(NAV,KC_ENT), LT(ALWAYS,KC_TAB), KC_SPC, TG(NUMB)),

    [PUNCT] = LAYOUT_split_3x6_3(KC_TRNS, KC_PSLS, KC_EXLM, KC_QUES, KC_HASH, KC_PAST, KC_DLR, KC_NO, KC_AMPR, KC_PIPE, KC_BSLS, KC_GRV, KC_TRNS, KC_AT, KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, KC_RCBR, KC_RPRN, KC_RBRC, KC_GT, KC_SCLN, KC_QUOT, KC_TRNS, KC_PERC, KC_CIRC, RCTL(KC_SLSH), KC_TRNS, KC_TRNS, KC_UNDS, KC_PMNS, KC_COMM, KC_DOT, KC_EQL, KC_TRNS, KC_NO, KC_TRNS, KC_ENT, TO(0), KC_TRNS, KC_NO),

    [NUMB] = LAYOUT_split_3x6_3(KC_TRNS, KC_SLSH, KC_EXLM, KC_QUES, KC_HASH, KC_PDOT, KC_DLR, KC_P7, KC_P8, KC_P9, KC_BSLS, KC_GRV, KC_TRNS, KC_AT, KC_LT, KC_LBRC, KC_LPRN, KC_LCBR, KC_P0, KC_P1, KC_P2, KC_P3, KC_SCLN, KC_QUOT, KC_TRNS, KC_PERC, KC_CIRC, KC_NO, KC_NO, KC_PCMM, KC_MINS, KC_P4, KC_P5, KC_P6, KC_EQL, KC_TRNS, KC_NO, KC_TRNS, KC_ENT, TO(BASE), KC_TRNS, KC_NO),

    [FUNCT] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F11, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_F12, KC_TRNS, KC_NO, KC_NO, KC_ENT, TO(BASE), KC_TRNS, KC_NO),

    [MOUSE] = LAYOUT_split_3x6_3(KC_NO, RCTL(KC_SLSH), KC_NO, KC_BTN1, KC_WH_U, KC_BTN2, RCTL(KC_Y), KC_BTN1, KC_MS_U, KC_BTN2, KC_ESC, KC_NO, KC_NO, RCTL(KC_A), RCTL(KC_S), KC_WH_L, KC_WH_D, KC_WH_R, RCTL(KC_H), KC_MS_L, KC_MS_D, KC_MS_R, KC_ENT, KC_NO, KC_TRNS, RCTL(KC_Z), RCTL(KC_X), RCTL(KC_C), RCTL(KC_V), RCTL(KC_F), KC_NO, KC_ACL0, KC_ACL1, KC_ACL2, KC_DEL, KC_TRNS, KC_NO, KC_BSPC, KC_ENT, TO(BASE), KC_TRNS, KC_NO),

    [NAV] = LAYOUT_split_3x6_3(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_HOME, KC_NO, KC_UP, KC_NO, KC_PGUP, KC_NO, KC_NO, KC_NO, KC_NO, KC_DEL, KC_ENT, KC_TAB, KC_END, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_BSPC, KC_ENT, TO(BASE), KC_TRNS, KC_NO),

    [ALWAYS] = LAYOUT_split_3x6_3(KC_NO, KC_APP, KC_LGUI, KC_NO, KC_ESC, KC_NO, LCA(KC_DEL), KC_NO, KC_NO, KC_NO, KC_NO, KC_CAPS, KC_NO, OSM(MOD_RALT), OSM(MOD_RCTL), KC_DEL, KC_ENT, KC_TAB, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, RCTL(KC_PSCR), KC_PSCR, RCTL(KC_BSPC), KC_BSPC, LALT(KC_TAB), KC_NO, KC_NO, KC_NO, KC_NO, KC_F12, KC_TRNS, KC_NO, KC_NO, KC_ENT, TO(BASE), KC_TRNS, KC_NO) 

};
