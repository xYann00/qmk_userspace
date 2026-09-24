#include QMK_KEYBOARD_H
#include "keymap_czech_qwerty.h"

enum layers { US, CZ, LEFT_US, LEFT_CZ, RIGHT_US, RIGHT_CZ, SETTINGS, WINDOWS };
enum custom_keycodes { KY_OLED = SAFE_RANGE, MC_CTLT };

static bool ctrl_tab_active = false;
static bool left_ctrl_held = false;

#ifdef OLED_ENABLE
static bool status_oled_enabled = true;
#endif

#define KY_LEFT MO(LEFT_US)
#define KY_RIGHT MO(RIGHT_US)
#define KY_TERM LCTL(KC_F13)
#define KY_WPST LGUI(KC_V)
#define WS_PREV LGUI(LCTL(KC_LEFT))
#define WS_NEXT LGUI(LCTL(KC_RGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [US] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    WS_PREV, WS_NEXT,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                 KC_LGUI, KC_LALT, KY_LEFT, KC_SPC,  KC_ENT,    KY_RIGHT,KC_RCTL, KC_RALT),

    [CZ] = LAYOUT(
        KC_ESC,  CQ_PLUS, CQ_ECAR, CQ_SCAR, CQ_CCAR, CQ_RCAR,                     CQ_ZCAR, CQ_YACU, CQ_AACU, CQ_IACU, CQ_EACU, CQ_ACUT,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    CQ_URNG, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    WS_PREV, WS_NEXT,   KC_N,    KC_M,    KC_COMM, KC_DOT,  CQ_MINS, KC_RSFT,
                                 KC_LGUI, KC_LALT, KY_LEFT, KC_SPC,  KC_ENT,    KY_RIGHT,KC_RCTL, KC_RALT),

    [LEFT_US] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   KC_EQL,
        MC_CTLT, KY_TERM, KC_END,  KC_UP,   KC_HOME, KC_PGUP,                     KC_BSLS, KC_PIPE, KC_LBRC, KC_RBRC, KC_PLUS, _______,
        _______, KY_WPST, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                     KC_ASTR, KC_COLN, KC_LPRN, KC_RPRN, KC_EQL,  KC_DQUO,
        _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_DEL,  WS_PREV, WS_NEXT,   KC_CIRC, KC_UNDS, KC_LCBR, KC_RCBR, KC_MINS, _______,
                                 _______, _______, _______, _______, _______,  _______, _______, KC_APP),

    [LEFT_CZ] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_P0,   CQ_EQL,
        MC_CTLT, KY_TERM, KC_END,  KC_UP,   KC_HOME, KC_PGUP,                     CQ_BSLS, CQ_PIPE, CQ_LBRC, CQ_RBRC, CQ_PLUS, _______,
        _______, KY_WPST, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                     CQ_ASTR, CQ_COLN, CQ_LPRN, CQ_RPRN, CQ_EQL,  CQ_DQUO,
        _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_DEL,  WS_PREV, WS_NEXT,   CQ_CIRC, CQ_UNDS, CQ_LCBR, CQ_RCBR, CQ_MINS, _______,
                                 _______, _______, _______, _______, _______,  _______, _______, KC_APP),

    [RIGHT_US] = LAYOUT(
        _______, KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_INS,
        _______, KC_GRV,  KC_TILD, KC_P7,   KC_P8,   KC_P9,                       KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_RCTL, _______,
        _______, KC_EXLM, KC_AT,   KC_P4,   KC_P5,   KC_P6,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_LBRC,
        _______, KC_HASH, KC_P0,   KC_P1,   KC_P2,   KC_P3,   WS_PREV, WS_NEXT,   KC_F11,  KC_F12,  _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,  _______, _______, _______),

    [RIGHT_CZ] = LAYOUT(
        _______, KC_P1,   KC_P2,   KC_P3,   KC_P4,   KC_P5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_INS,
        _______, CQ_GRV,  CQ_TILD, KC_P7,   KC_P8,   KC_P9,                       KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_RCTL, _______,
        _______, CQ_EXLM, CQ_AT,   KC_P4,   KC_P5,   KC_P6,                       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  CQ_UACU,
        _______, CQ_HASH, KC_P0,   KC_P1,   KC_P2,   KC_P3,   WS_PREV, WS_NEXT,   KC_F11,  KC_F12,  _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,  _______, _______, _______),

    [SETTINGS] = LAYOUT(
        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_CAPS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,   PDF(US), KC_NO,   KY_OLED, KC_NO,   KC_NO,
        _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, KC_NO,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        _______, KC_NO,   KC_NO,   PDF(CZ), KC_NO,   KC_NO,   WS_PREV, WS_NEXT,   KC_NUM,  KC_MPRV, KC_MNXT, KC_NO,   KC_NO,   _______,
                                 _______, _______, _______, _______, _______,  _______, _______, _______),

    [WINDOWS] = LAYOUT(
        KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TAB,  KC_NO,   KC_END,  KC_UP,   KC_HOME, KC_NO,                       KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,                       KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO,
        KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   WS_PREV, WS_NEXT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,
                                 KC_NO,   KC_LALT, KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO),
    // clang-format on
};

// Keep normal apostrophe/double-quote behavior in Czech without a tap/hold key.
// Trigger-down only prevents a late Shift press from generating another quote.
#define QUOTE_OPTIONS (ko_option_activation_trigger_down | ko_option_no_reregister_trigger)
const key_override_t cz_quote = ko_make_with_layers_negmods_and_options(
    0, KC_QUOT, CQ_QUOT, 1UL << CZ, MOD_MASK_SHIFT | MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI, QUOTE_OPTIONS);
const key_override_t cz_double_quote = ko_make_with_layers_negmods_and_options(
    MOD_MASK_SHIFT, KC_QUOT, CQ_DQUO, 1UL << CZ, MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI, QUOTE_OPTIONS);
const key_override_t *key_overrides[] = {&cz_double_quote, &cz_quote};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Keep the physical Ctrl independent of the Ctrl held by the tab switcher.
    if (keycode == KC_LCTL) {
        left_ctrl_held = record->event.pressed;
        if (ctrl_tab_active) {
            return false;
        }
    }
    if (keycode == MC_CTLT) {
        if (record->event.pressed) {
            ctrl_tab_active = true;
            register_code(KC_LCTL);
            register_code(KC_TAB);
        } else {
            unregister_code(KC_TAB);
        }
        return false;
    }
#ifdef OLED_ENABLE
    if (keycode == KY_OLED) {
        if (record->event.pressed) {
            status_oled_enabled = !status_oled_enabled;
        }
        return false;
    }
#endif
    // Leave Alt shortcuts unchanged until an actual Alt+Tab starts switching.
    if (keycode == KC_TAB && record->event.pressed && (get_mods() & MOD_BIT(KC_LALT))) {
        layer_on(WINDOWS);
    } else if ((keycode == KC_LALT && !record->event.pressed) || (keycode == KC_ESC && record->event.pressed)) {
        layer_off(WINDOWS);
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (ctrl_tab_active && !(state & (1UL << LEFT_US))) {
        ctrl_tab_active = false;
        if (!left_ctrl_held) {
            unregister_code(KC_LCTL);
        }
    }
    // Keep the held US layers underneath their Czech overlays so releasing
    // either thumb always removes its overlay, regardless of release order.
    state &= ~((1UL << LEFT_CZ) | (1UL << RIGHT_CZ));
    if (default_layer_state & (1UL << CZ)) {
        if (state & (1UL << LEFT_US)) {
            state |= 1UL << LEFT_CZ;
        }
        if (state & (1UL << RIGHT_US)) {
            state |= 1UL << RIGHT_CZ;
        }
    }
    return update_tri_layer_state(state, LEFT_US, RIGHT_US, SETTINGS);
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_left() ? rotation : OLED_ROTATION_180;
}

bool oled_task_user(void) {
    if (!is_keyboard_master() || !status_oled_enabled ||
        (last_input_activity_elapsed() >= STATUS_OLED_TIMEOUT && last_led_activity_elapsed() >= STATUS_OLED_TIMEOUT)) {
        // Flush pending pixels before powering off; the driver's later render
        // would otherwise wake the display again, including on the unused half.
        oled_render_dirty(true);
        oled_off();
        return false;
    }

    oled_on();
    oled_set_cursor(0, 0);
    oled_write_P(PSTR("Keyboard: "), false);
    oled_write_P(default_layer_state & (1UL << CZ) ? PSTR("CZ") : PSTR("US"), false);
    oled_set_cursor(0, 2);
    oled_write_P(PSTR("Num Lock: "), false);
    oled_write_P(host_keyboard_led_state().num_lock ? PSTR("ON ") : PSTR("OFF"), false);
    return false;
}
#endif
