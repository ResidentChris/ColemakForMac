#include QMK_KEYBOARD_H

#define _COLEMAK 0
#define _SYMBOL 1
#define _NUMBER 2

#define CTLENT MT(MOD_LCTL, KC_ENT)
#define SHIFTandENTER S(KC_ENT)

#define LOCK TD(TAPDANCE_LOCK)
#define CAPS TD(TAPDANCE_CAPS)

#define KC_COLEMAK DF(_COLEMAK)
#define KC_SYM MO(_SYMBOL)
#define KC_NUMS MO(_NUMBER)
#define KC_COLEM DF(_COLEMAK)

#define MC_ALL LCTL(KC_UP)
#define MC_APP LCTL(KC_DOWN)
#define COMPLETE C(KC_SPC)
#define CONTEXT A(KC_ENT)
#define FIND SGUI(KC_F)
#define VSMENU SGUI(KC_P)
#define TEST SGUI(KC_T)
#define RENAME S(KC_F6)
#define USAGES A(KC_F7)
#define FORMAT LAG(KC_L)
#define HINT G(KC_P)
#define SNIP SGUI(KC_5)

#define PRT_WIN A(KC_PSCR)

#define MC_FILL HYPR(KC_F)
#define MC_LEFT HYPR(KC_LEFT)
#define MC_RGHT HYPR(KC_RGHT)

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
};

enum {
  TAPDANCE_LOCK,
  TAPDANCE_CAPS,
};

tap_dance_action_t tap_dance_actions[] = {
  [TAPDANCE_LOCK] = ACTION_TAP_DANCE_DOUBLE(_______, RCG(KC_Q)),
  [TAPDANCE_CAPS] = ACTION_TAP_DANCE_DOUBLE(_______, KC_CAPS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     MC_APP  ,COMPLETE,CONTEXT ,FIND    ,VSMENU  ,TEST                               ,MC_LEFT ,USAGES  ,MC_FILL ,MC_RGHT ,HINT    ,MC_ALL
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B                               ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_BSPC
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,KC_ESC  ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G                               ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_QUOT
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    ,KC_LBRC ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,KC_EQL           ,KC_MINS ,KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RBRC
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   ,KC_LGUI ,CTLENT  ,KC_LSFT                   ,KC_SPC  ,KC_NUMS ,KC_SYM
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYMBOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______                            ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,KC_BRIU ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5                              ,KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_VOLU
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC                            ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_MUTE
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    ,KC_BRID ,KC_LGUI ,KC_LALT ,KC_LSFT ,KC_LCTL ,KC_F11  ,KC_PLUS          ,_______ ,KC_F12  ,KC_RCTL ,KC_RSFT ,KC_RALT ,KC_RGUI ,KC_VOLD
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   ,_______ ,OS_LALT ,SHIFTandENTER             ,_______ ,_______ ,_______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUMBER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,RENAME  ,_______ ,FORMAT  ,_______ ,SNIP                               ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5                               ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_DEL
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,LOCK    ,_______ ,KC_HOME ,KC_PGUP ,KC_PGDN ,KC_END                             ,KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RGHT ,KC_GRV  ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    ,CAPS    ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_PLUS          ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_BSLS ,_______
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   ,_______ ,_______ ,_______                   ,_______ ,_______ ,_______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

/*
  [_] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______                            ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                            ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,_______ ,_______ ,_______ ,_______ ,_______                            ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______          ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   ,_______ ,_______ ,_______                   ,_______ ,_______ ,_______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
 */
};

const rgblight_segment_t PROGMEM colemak_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_OFF}
);

const rgblight_segment_t PROGMEM number_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_BLUE}
);
const rgblight_segment_t PROGMEM symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_YELLOW}
);
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 12, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    colemak_layer,
    symbol_layer,
    number_layer,
    capslock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(4, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_COLEMAK, layer_state_cmp(state, _COLEMAK));
    rgblight_set_layer_state(_SYMBOL, layer_state_cmp(state, _SYMBOL));
    rgblight_set_layer_state(_NUMBER, layer_state_cmp(state, _NUMBER));
    return state;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return 200;
    }
}
