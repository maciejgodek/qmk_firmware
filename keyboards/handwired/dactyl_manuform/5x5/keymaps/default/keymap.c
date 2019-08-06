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
  KC_Z, KC_X, KC_C,    KC_V,    KC_B,                                       KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, \
              O_RALT,  O_LSFT,                                              O_RSFT, O_RALT,  \
                               RIGHT, KC_SPC, O_LALT, O_RCTL,  KC_ENT, LEFT,
                                      KC_BSPC,O_LGUI, KC_TAB, KC_ESC),
[_LFT] = LAYOUT( \
  KC_1,     KC_2,   KC_3,   KC_4,    KC_5,                                  ____,   ____,   ____,   ____,   ____, \
  KC_QUOT,  KC_MINS,KC_GRV, KC_BSLS, KC_PGUP,                               ____,   ____,   ____,   ____,   ____, \
  KC_LEFT,  KC_UP,  KC_DOWN,KC_RGHT, KC_PGDN,                               ____,   ____,   ____,   ____,   ____, \
            ____, ____,                                                         O_RGUI, O_RCTL,
                                        ____, ____, ____, ____, ____, ____,
                                            ____, ____, ____, ____),
[_RHT] = LAYOUT( \
  ____,     ____,   ____,   ____,    ____,                                  KC_6,   KC_7,   KC_8,   KC_9,   KC_0, \
  ____,     ____,   ____,   ____,    ____,                                  KC_DLR, KC_LPRN,KC_RPRN,KC_EQL, KC_PLUS, \
  ____,     ____,   ____,   ____,    ____,                                  KC_PERC,KC_LBRC,KC_RBRC,KC_CIRC, ____, \
            O_LCTL,  O_LGUI,                                                   ____, ____,
                                        ____, ____, ____, ____, ____, ____,
                                            ____, ____, ____, ____)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
