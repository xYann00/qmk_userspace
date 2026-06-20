/* Copyright 2020 Jonathan Rascher
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

enum my_keycodes {
    MC_CTLT = SAFE_RANGE
};

#define LAYER_DEFAULT 0
#define LAYER_LOWER 1
#define LAYER_RAISE 2
#define LAYER_ADJUST 3

#define LY_LWR MO(LAYER_LOWER)
#define LY_RSE MO(LAYER_RAISE)

#define KY_UNDO LCTL(KC_Z)
#define KY_COPY LCTL(KC_C)
#define KY_CUT LCTL(KC_X)
#define KY_PST LCTL(KC_V)
#define KY_GCL LGUI(LCTL(KC_LEFT))
#define KY_GCR LGUI(LCTL(KC_RGHT))
#define KY_SFQT  MT(MOD_RSFT, KC_QUOT)
#define KY_CTGR LCTL(KC_GRV)
#define KY_WPST LGUI(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off

    [LAYER_DEFAULT] = LAYOUT(                                                                                                          // KC_EQL for czech keyboard layout
        KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_EQL,    \
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,   \
        KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KY_SFQT,   \
        KC_LCTL,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KY_GCL,   KY_GCR,   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RCTL,   \
                                      KC_LGUI,  KC_LALT,  LY_LWR,   KC_SPC,   KC_ENT,   LY_RSE,   KC_DEL,   KC_RALT),

	[LAYER_LOWER] = LAYOUT(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_PAUS,   \
        MC_CTLT,  KC_F11,   KC_F12,   KY_CTGR,  KY_WPST,  _______,                      KC_ASTR,  KC_PIPE,  KC_LBRC,  KC_RBRC,  KC_PPLS,  KC_TILD,   \
        _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                      KC_AMPR,  KC_NUHS,  KC_LPRN,  KC_RPRN,  KC_PEQL,  KC_GRV,    \
        _______,  KY_UNDO,  KY_CUT,   KY_COPY,  KY_PST,   _______,  _______,  _______,  KC_CIRC,  KC_UNDS,  KC_LCBR,  KC_RCBR,  KC_PMNS,  _______,   \
                                      _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_APP),

	[LAYER_RAISE] = LAYOUT(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   _______,   \
        KC_CAPS,  KC_F11,   KC_F12,   KC_P7,    KC_P8,    KC_P9,                        KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   _______,  _______,   \
        _______,  _______,  KC_NUM,   KC_P4,    KC_P5,    KC_P6,                        KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_INS,   KC_RSFT,   \
        _______,  _______,  KC_P0,    KC_P1,    KC_P2,    KC_P3,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   \
                            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______),

	[LAYER_ADJUST] = LAYOUT(
        _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,    \
        _______,  _______,  _______,  _______,  _______,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,    \
        _______,  _______,  KC_VOLD,  KC_VOLU,  KC_MPLY,  _______,                      _______,  _______,  _______,  _______,  _______,  _______,    \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    \
                                      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______)
    // clang-format on
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L', 'L',                    'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',                    'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',                    'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L', '*',          '*', 'R', 'R', 'R', 'R', 'R', 'R',
                       '*', '*', '*', '*',          '*', '*', '*', '*');

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_ENABLE

static int8_t ctrl_tab_layer = -1;

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
    #ifdef OLED_ENABLE
        set_keylog(keycode, record);
    #endif
    // set_timelog();
    }
    if (!process_record_keymap(keycode, record)) {
	    return false;
    }
    switch (keycode) {
        case MC_CTLT:
            if (record->event.pressed) {
                if (ctrl_tab_layer < 0) {
                    ctrl_tab_layer= layer_switch_get_layer(record->event.key);
                    register_code(KC_LCTL);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            return false;
        default:
	        return true;
    }
}

layer_state_t layer_state_set_keymap(layer_state_t state) { return update_tri_layer_state(state, LAYER_LOWER, LAYER_RAISE, LAYER_ADJUST); }

layer_state_t layer_state_set_user(layer_state_t state) {
    state = layer_state_set_keymap(state);
    
    if (ctrl_tab_layer >= 0 && !layer_state_cmp(state, ctrl_tab_layer)) {
	    unregister_code(KC_LCTL);
	    ctrl_tab_layer = -1;
    }
    return state;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KY_SFQT:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KY_SFQT:
            return TAPPING_TERM - 55;
        default:
            return TAPPING_TERM;
    }
}
