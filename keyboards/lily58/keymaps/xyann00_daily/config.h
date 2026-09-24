// Copyright 2026 xYann00
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Preserve the handedness already stored in each half's EEPROM.
#define EE_HANDS

// Handle sleep in the keymap so QMK cannot wake the unused or disabled OLED.
#define OLED_TIMEOUT 0
#define OLED_BRIGHTNESS 128
#define STATUS_OLED_TIMEOUT 60000
