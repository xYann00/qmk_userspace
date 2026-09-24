// Copyright 2026 xYann00
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Windows Czech (QWERTY), KLID 00010405. QMK's keymap_czech.h targets
// QWERTZ, whose AltGr positions are different. Keep Y/Z as KC_Y/KC_Z.
// Source: https://learn.microsoft.com/en-us/globalization/keyboards/kbdcz1
#define CQ_PLUS KC_1
#define CQ_ECAR KC_2
#define CQ_SCAR KC_3
#define CQ_CCAR KC_4
#define CQ_RCAR KC_5
#define CQ_ZCAR KC_6
#define CQ_YACU KC_7
#define CQ_AACU KC_8
#define CQ_IACU KC_9
#define CQ_EACU KC_0
#define CQ_ACUT KC_EQL
#define CQ_UACU KC_LBRC
#define CQ_URNG KC_SCLN
#define CQ_MINS KC_SLSH
#define CQ_EQL  KC_MINS
#define CQ_QUOT S(KC_NUHS)
#define CQ_DQUO S(KC_SCLN)
#define CQ_1 S(KC_1)
#define CQ_2 S(KC_2)
#define CQ_3 S(KC_3)
#define CQ_4 S(KC_4)
#define CQ_5 S(KC_5)
#define CQ_6 S(KC_6)
#define CQ_7 S(KC_7)
#define CQ_8 S(KC_8)
#define CQ_9 S(KC_9)
#define CQ_0 S(KC_0)
#define CQ_GRV  RALT(KC_GRV)
#define CQ_TILD RALT(S(KC_GRV))
#define CQ_EXLM RALT(KC_1)
#define CQ_AT   RALT(KC_2)
#define CQ_HASH RALT(KC_3)
#define CQ_CIRC RALT(KC_6)
#define CQ_ASTR RALT(KC_8)
#define CQ_LPRN RALT(KC_9)
#define CQ_RPRN RALT(KC_0)
#define CQ_BSLS RALT(KC_NUHS)
#define CQ_PIPE RALT(S(KC_NUHS))
#define CQ_LBRC RALT(KC_LBRC)
#define CQ_RBRC RALT(KC_RBRC)
#define CQ_LCBR RALT(S(KC_LBRC))
#define CQ_RCBR RALT(S(KC_RBRC))
#define CQ_COLN S(KC_DOT)
#define CQ_UNDS S(KC_SLSH)
