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

// Tap Dance Declarations
enum {
    TD_SPACE_SFT
};

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_SPACE_SFT] = ACTION_TAP_DANCE_DOUBLE(KC_SPC, KC_LSFT)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
            KC_GRAVE, KC_1,   KC_2,    KC_3,     KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           KC_ESCAPE, KC_Q, KC_W, KC_F, KC_P, KC_G,                                          KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_PGUP,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      CW_TOGG, LCTL_T(KC_A), LALT_T(KC_R), LGUI_T(KC_S), LSFT_T(KC_T), KC_D,         KC_H, RSFT_T(KC_N), RGUI_T(KC_E), RALT_T(KC_I), RCTL_T(KC_O), KC_QUOT,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           LCTL(KC_B), LSFT_T(KC_Z), KC_X, KC_C, KC_V, KC_B, KC_LCTL,             TG(_LOWER),  KC_K, KC_M, KC_COMM, KC_DOT, RSFT_T(KC_SLSH), KC_PGDN,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                         QK_LEADER, LT(_RAISE, KC_BSPC), LT(_ADJUST, KC_TAB),        KC_ENT, LT(_LOWER, KC_SPC), KC_RSFT
        //                                    └────────┴────────┴────────┘         └────────┴────────┴────────┘
        ),

    [_LOWER] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
           _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                               KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_GRAVE, KC_TILDE, KC_LBRC, KC_RBRC, S(KC_7),                        KC_CIRC, KC_PIPE, S(KC_3), S(KC_8), _______, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_EXLM, S(KC_SCLN), KC_LPRN, KC_RPRN, KC_DLR,                       KC_AT, KC_MINUS, KC_EQUAL, KC_UNDS, KC_SEMICOLON, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
           _______, KC_PERC, KC_QUES, KC_LCBR, KC_RCBR, KC_BSLS, _______,           _______, KC_SLASH, KC_PLUS, S(KC_COMM), S(KC_DOT), S(KC_QUOT), _______,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                          _______, _______, KC_SPC,                    _______, _______, _______
        //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_RAISE] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
           QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                               KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
           _______, _______, KC_P7,   KC_P8,   KC_P9, KC_PLUS,                           KC_DOWN, KC_RGHT, KC_MPLY, KC_VOLD, KC_VOLU, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, KC_LEFT_CTRL, LALT_T(KC_P4), LGUI_T(KC_P5), LSFT_T(KC_P6), KC_MINS,          KC_LEFT, KC_MINS, KC_EQL, _______, _______, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
            _______, KC_P0, KC_P1, KC_P2, KC_P3, KC_PDOT, _______,              _______, KC_UP, KC_LBRC, KC_RBRC, _______, _______, _______,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                             _______, _______, _______,                  _______, MO(_ADJUST), _______
        //                                 └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        ),

    [_ADJUST] = LAYOUT(
        //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
          _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
          _______, _______, KC_COMM, KC_DOWN, KC_DOT, _______,                             _______, KC_F7, KC_F8, KC_F9, KC_F12, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, KC_LEFT, KC_ENT, LSFT_T(KC_RGHT), _______,                       _______, KC_F4, KC_F5, KC_F6, KC_F11, _______,
        //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______, _______, _______, KC_UP, _______, _______, _______,             _______, _______, KC_F1, KC_F2, KC_F3, KC_F10, _______,
        //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                        _______, _______, _______,                   _______, _______, _______
        //                              └────────┴────────┴────────┘                 └────────┴────────┴────────┘
        )
};


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


// Leader Sequences
void leader_end_user(void) {
    // Email shortcut
    if (leader_sequence_one_key(KC_D)) {
        SEND_STRING("ddrempti@gmail.com");
    }
    // Assignment operator
    else if (leader_sequence_one_key(KC_E)) {
        SEND_STRING(" = ");
    }
    // PHP variable assignment
    else if (leader_sequence_one_key(KC_4)) {
        SEND_STRING("$ = ;" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    }
    // Arrow operator
    else if (leader_sequence_one_key(KC_EQUAL)) {
        SEND_STRING("=>");
    }
    // Code block delimiter, shift enter twice, and then go back up
    else if (leader_sequence_one_key(KC_Q)) {
        SEND_STRING("```" SS_DOWN(X_LSFT) SS_TAP(X_ENT) SS_UP(X_LSFT) SS_DOWN(X_LSFT) SS_TAP(X_ENT) SS_UP(X_LSFT) "```" SS_TAP(X_UP));
    }
    // JavaScript 'let' declaration
    else if (leader_sequence_two_keys(KC_L, KC_E)) {
        SEND_STRING("let  =" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    }
    // JavaScript 'const' declaration
    else if (leader_sequence_two_keys(KC_C, KC_E)) {
        SEND_STRING("const  =" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    }
    // Send testing password
    else if (leader_sequence_one_key(KC_1)) {
        SEND_STRING("12345678");
    }

    // Send testing password 2
    else if (leader_sequence_one_key(KC_2)) {
        SEND_STRING("1800auther");
    }

    // Send `pn dev` command and hit enter
    else if (leader_sequence_one_key(KC_P)) {
        SEND_STRING("pn dev" SS_TAP(X_ENT));
    }

    // Git add + commit + push, leaving cursor inside commit message quotes
    else if (leader_sequence_two_keys(KC_G, KC_P)) {
        SEND_STRING("git add . && git commit -m \"\" && git push"
                    SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT)
                    SS_TAP(X_LEFT));
    }

    // Git add + commit, leaving cursor inside commit message quotes
    else if (leader_sequence_one_key(KC_G)) {
        SEND_STRING("git add . && git commit -m \"\"" SS_TAP(X_LEFT));
    }

    // Jump to end of line and enter a ,
    else if (leader_sequence_one_key(KC_COMM)) {
        // TODO
    }
}
