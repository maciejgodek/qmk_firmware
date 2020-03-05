#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _BASE 0
#define _RHT 1
#define _LFT 2

// Fillers to make layering more clear

#define ____ KC_TRNS



#define RIGHT OSL(_RHT)
#define LEFT OSL(_LFT)
#define O_RSFT OSM(MOD_RSFT)
#define O_LSFT OSM(MOD_LSFT)
#define O_RALT OSM(MOD_RALT)
#define O_LALT OSM(MOD_LALT)
#define O_LCTL OSM(MOD_LCTL)
#define O_RCTL OSM(MOD_RCTL)
#define O_LGUI OSM(MOD_LGUI)
#define O_RGUI OSM(MOD_RGUI)

#define LW_Z  LWIN_T(KC_Z)
#define LS_X LSFT_T(KC_X)
#define RA_C RALT_T(KC_C)
#define RL_V  LT(_RHT, KC_V)
#define LC_B LCTL_T(KC_B)

#define RC_N RCTL_T(KC_N)
#define LL_M  LT(_LFT, KC_M)
#define RA_COMM RALT_T(KC_COMM)
#define RS_DOT RSFT_T(KC_DOT)
#define RW_SLSH RWIN_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty)
 * ,________________________________--,                             ,________________________________--,
 * |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |
 * |____--+____--+____--+____--+____--|                             |____________-+____--+____--+____--|
 * |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |
 * |____--+____--+____--+____--+____--|                             |____--|____--+____--+____--+____--|
 * |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   '  |
 * |____--+____--+____--+____________-,                             ,____________-+____--+____--+____--,
 *        |  [   |   ]  |                                                         |   -  |   =  |
 *        '____--+____--'____________-'                             '____________-'____--+____--'
 *                      | ESC  |  BS  |                             | SPACE|ENTER |
 *                      |  +   |   +  |                             |  +   |  +   |
 *                      | SHIFT| CTRL |                             | ALT  |SHIFT |
 *                      '____--+____--'                             '____--+____--'
 *                                    '____--+____--' '____--+____--'
 *                                    | TAB  | HOME | | END  | DEL  |   
 *                                    '____--+____--' '____--+____--'
 *                                    | Lower|  ~   | | GUI  | Raise|
 *                                    '____--+____--' '____--+____--'
 */
[_BASE] = LAYOUT( \
  KC_Q, KC_W, KC_E,    KC_R,    KC_T,                                       KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    \
  KC_A, KC_S, KC_D,    KC_F,    KC_G,                                       KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, \
  LW_Z, LS_X, RA_C,    RL_V,    LC_B,                                       RC_N, LL_M,    RA_COMM, RS_DOT, RW_SLSH, \
              KC_ESC,  KC_SPC,                                              KC_ENT, KC_TAB,  \
                               KC_BSPC, KC_DEL, KC_HOME, KC_VOLU,  KC_F6, KC_ESC,
                                        O_LALT, KC_END,  KC_VOLD,  O_LALT),
[_LFT] = LAYOUT( \
  KC_1,     KC_2,   KC_3,   KC_4,    KC_5,                                  KC_6,   KC_7,   KC_8,   KC_9,   KC_0, \
  KC_QUOT,  KC_MINS,KC_GRV, KC_BSLS, KC_PGUP,                               ____,   ____,   ____,   ____,   ____, \
  KC_LEFT,  KC_UP,  KC_DOWN,KC_RGHT, KC_PGDN,                               ____,   ____,   ____,   ____,   ____, \
            ____, ____,                                                     ____, ____,
                                        ____, ____, ____, ____, ____, ____,
                                            ____, ____, ____, ____),
[_RHT] = LAYOUT( \
  KC_1,     KC_2,   KC_3,   KC_4,    KC_5,                                  KC_6,   KC_7,   KC_8,   KC_9,   KC_0, \
  ____,   ____,   ____,   ____,    ____,                                  KC_DLR, KC_LPRN,KC_RPRN,KC_EQL, KC_PLUS, \
  ____,   ____,   ____,   ____,    ____,                                  KC_PERC,KC_LBRC,KC_RBRC,KC_CIRC, ____, \
            ____,   ____,                                                   ____, ____,
                                        ____, ____, ____, ____, ____, ____,
                                            ____, ____, ____, ____)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
