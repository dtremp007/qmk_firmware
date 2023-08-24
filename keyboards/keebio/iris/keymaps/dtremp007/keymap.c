#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            XXXXXXX, KC_1,   KC_2,    KC_3,     KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           QK_GRAVE_ESCAPE, KC_Q, KC_W, KC_F, KC_P, KC_G,                                          KC_J, KC_L, KC_U, KC_Y, KC_SCLN, XXXXXXX,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_CAPS_LOCK, LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_D,         KC_H, RSFT_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_O), KC_QUOT,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           KC_LGUI, LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, TG(_RAISE),                          TG(_LOWER),  KC_K, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), XXXXXXX,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                        KC_SPC, LT(_RAISE, KC_BSPC), LT(_ADJUST, KC_TAB),        KC_ENT, LT(_LOWER, KC_SPC), QK_ESCAPE
        //                                    └────────┴────────┴────────┘         └────────┴────────┴────────┘
        ),

    [_LOWER] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
           _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                               KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_1, KC_2, KC_3, KC_4, KC_5,                                           KC_6, KC_7, KC_8, KC_9, KC_0, KC_DOT,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_DLR, KC_PLUS, KC_LPRN, KC_RPRN, KC_AT,                               KC_PIPE, KC_MINS, KC_EQL, KC_UNDS, KC_ASTR, KC_BSLS,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_EXLM, KC_HASH, KC_LCBR, KC_RCBR, KC_GRAVE, _______,           _______, KC_AMPR, KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, _______,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, _______, KC_SPC,                    _______, _______, _______
        //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_RAISE] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
           QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                               KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, KC_P4,   KC_P5,   KC_P9, KC_PLUS,                           KC_DOWN, KC_RGHT, KC_MPLY, KC_VOLD, KC_VOLU, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LEFT_CTRL, LALT_T(KC_P1), LGUI_T(KC_P2), LSFT_T(KC_P3), KC_MINS,          KC_LEFT, KC_MINS, KC_EQL, _______, _______, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            _______, KC_P0, KC_P8, KC_P6, KC_P7, KC_PDOT, _______,              _______, KC_UP, KC_LBRC, KC_RBRC, _______, _______, _______,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                             _______, _______, _______,                  _______, MO(_ADJUST), _______
        //                                 └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_ADJUST] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
          _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, KC_COMM, KC_DOWN, KC_DOT, _______,                             _______, _______, _______, _______, _______, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, KC_LEFT, KC_ENT, LSFT_T(KC_RGHT), _______,                       _______, KC_O, KC_SCLN, KC_QUOT, _______, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, KC_UP, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        _______, _______, _______,                   _______, _______, _______
        //                              └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        )
};

/**
 * Define lighting layers.
 *
 * Iris rev6a uses WS2812 RGB Matrix lighting.
 * The RGB Matrix lighting option has already been enabled in ../../rev6a/config.h
 * You'll need to add #define SPLIT_LAYER_STATE_ENABLE to config.h if you
 * will be customizing the LED's per key.
 *
 * Here's how to customize the colors per layer and per key:
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md#direct-operation-iddirect-operation
 *
 * If you start getting real weird with it, your likely to exceed the firmware limit of 28672.
 * You may need to selectively disable some effects:
 * https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgb_matrix.md#rgb-matrix-effects-idrgb-matrix-effects
 *
 * There are 68 Leds. Printed on the board itself, the led numbers are 1-68.
 * For color addressing, use 0-67 as the index number.
 * rgb_matrix_set_color(index, r, g, b)
 *
 * Here's an LED number guide:
 * FRONT
 * Left Hand                    Right Hand
 * |00|01|02|03|04|05|          |39|38|37|36|35|34|
 * |11|10|09|08|07|06|          |40|41|42|43|44|45|
 * |12|13|14|15|16|17|          |51|50|49|48|47|46|
 * |23|22|21|20|19|18|27|    |61|52|53|54|55|56|57|
 *             |24|25|26|    |60|59|58|
 * REVERSE
 * Right Hand                   Left Hand
 * |65|--|--|66|--|67|          |33|--|32|--|--|31|
 * |--|--|--|--|--|--|          |--|--|--|--|--|--|
 * |--|--|--|--|--|--|          |--|--|--|--|--|--|
 * |64|--|--|63|--|--|--|    |--|--|--|29|--|--|30|
 *             |--|62|--|    |--|28|--|
 */
// void rgb_matrix_indicators_user(void) {
//   if (IS_LAYER_ON(0)) {
//     rgb_matrix_set_color(1,255,0,0);
//   }
//   else if (IS_LAYER_ON(4)) {
//     rgb_matrix_set_color(2,255,0,0);
//   }
//   else if (IS_LAYER_ON(5)) {
//     rgb_matrix_set_color(3,255,0,0);
//   }
//   else if (IS_LAYER_ON(6)) {
//     rgb_matrix_set_color(4,255,0,0);
//   } else {
//       rgb_matrix_disable();
//   }
//
// }



bool encoder_update_user(uint8_t index, bool clockwise) {
    if (get_highest_layer(layer_state | default_layer_state) > 0) {
        if (index == 1) {
            if (clockwise) {
                tap_code(KC_DOWN);
            } else {
                tap_code(KC_UP);
            }
        }
    } else {
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (index == 1) {
            if (clockwise) {
                tap_code(KC_TAB);
            } else {
                tap_code16(S(KC_TAB));
            }
        }
    }
    return false;
}
