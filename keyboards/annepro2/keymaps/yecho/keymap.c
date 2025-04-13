 /* Copyright 2021 OpenAnnePro community
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

enum anne_pro_layers {
    BASE,
    FN1,
    FN2,
};

/*
 * MIDI
 */
//extern MidiDevice midi_device;
// MIDI CC codes for generic on/off switches (80, 81, 82, 83)
// Off: 0-63
// On:  64-127
//#define MIDI_CC_OFF 0
#//define MIDI_CC_ON  127
/* ~MIDI */

enum unicode_names {
    OUML,
    OUMLCAP,
    AUML,
    AUMLCAP,
    UUML,
    UUMLCAP,
    SZ,
    THUMBSUP,
    RAISEHAND,
    BANG,
    IRONY,
    SNEK
};

const uint32_t PROGMEM unicode_map[] = {
    [OUML] = 0x00F6,
    [OUMLCAP] = 0x00D6,
    [AUML] = 0x00E4,
    [AUMLCAP] = 0x00C4,
    [UUML] = 0x00FC,
    [UUMLCAP] = 0x00DC,
    [SZ] = 0x00DF,
    [THUMBSUP] = 0x1F44D, // 👍
    [RAISEHAND] = 0x1F64B, // 🙋
    [BANG]  = 0x203D,  // ‽
    [IRONY] = 0x2E2E,  // ⸮
    [SNEK]  = 0x1F40D, // 🐍
};


// clang-format off
// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer BASE
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | Ctrl    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Caps  |  Alt  |  L1   |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in BASE
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [BASE] = LAYOUT_60_ansi( /* Base */
    KC_ESC,           KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8, KC_9,    KC_0,             KC_MINS,          KC_EQL,        KC_BSPC,
    KC_TAB,           KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I, KC_O,    KC_P,             KC_LBRC,          KC_RBRC,       KC_BSLS,
//  LT(FN1, KC_CAPS), KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K, KC_L,    KC_SCLN,          KC_QUOT,          KC_ENT,
    KC_LCTL,          KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K, KC_L,    KC_SCLN,          KC_QUOT,          KC_ENT,
    KC_LSFT,                   KC_Z,    KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT,           KC_SLSH,          RSFT_T(KC_UP),
    LT(FN2, KC_CAPS), KC_LALT, KC_LGUI,                   KC_SPC,             KC_RALT, LT(FN1, KC_LEFT), LT(FN2, KC_DOWN), RCTL_T(KC_RGHT)
),
  /*
  * Layer FN1
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl    |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Caps  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN1] = LAYOUT_60_ansi( /* FN1 */
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_HOME, KC_END,  _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______,
    _______,          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, _______, _______, _______, KC_INS,  KC_DEL,  _______,
    _______, _______, _______,                            _______,                   _______, _______, MO(FN2), _______
),
  /*
  * Layer FN2
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |  F5 |  F6 | F7 | F8 | MOD | TOG | BRI- | BRI+ |  👍,🙋    |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | MB2 | MUp | MB1 | MWU |  y  |  ü  |  i  |  ö  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl    |  ä  | MLe | MDo | MRi | MWD |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      | MC  | MD  | ME  | MF  | MG  | MA  | MB  | MC1 | MD1 | MSUS |    Shift      |
  * |-----------------------------------------------------------------------------------------+
  * | Caps  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN2] = LAYOUT_60_ansi( /* FN2 */
//    _______, KC_AP2_BT1,        KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4,  _______,       _______, _______,           _______, KC_AP_RGB_MOD,     KC_AP_RGB_TOG, KC_AP_RGB_VAD, KC_AP_RGB_VAI, UP(THUMBSUP, RAISEHAND),
    _______, KC_AP2_BT1,        KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4,  _______,       _______, _______,           _______, KC_AP_RGB_MOD,     UC(SZ),        KC_AP_RGB_VAD, KC_AP_RGB_VAI, UP(THUMBSUP, RAISEHAND),
    _______, _______,           KC_MS_BTN2, KC_MS_UP,   KC_MS_BTN1,  KC_MS_WH_UP,   _______, UP(UUML, UUMLCAP), _______, UP(OUML, OUMLCAP), KC_PSCR,       KC_HOME,       KC_END,        _______,
    _______, UP(AUML, AUMLCAP), KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, _______, _______,           _______, _______,           KC_PGUP,       KC_PGDN,       _______,
    _______,                    MI_C,       MI_D,       MI_E,        MI_F,          MI_G,    MI_A,              MI_B,    MI_C1,             MI_D1,         MI_SUST,       _______,
    _______, _______,           _______,                                            _______,                             _______,           _______,       _______,       _______
 ),
};


/*
 * Custom key processing
 */

#if defined(MIDI_ENABLE)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MI_SUST:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 64, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, 0, 64, MIDI_CC_OFF);
            }
            return true;
        case MI_C:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 36, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, 0, 36, MIDI_CC_OFF);
            }
            return true;
        case MI_D:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 37, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, 0, 37, MIDI_CC_OFF);
            }
            return true;
        case MI_E:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 38, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, 0, 38, MIDI_CC_OFF);
            }
            return true;
        case MI_F:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 39, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, 0, 39, MIDI_CC_OFF);
            }
            return true;
        case MI_G:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 40, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, 0, 40, MIDI_CC_OFF);
            }
            return true;
        case MI_A:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 41, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, 0, 41, MIDI_CC_OFF);
            }
            return true;
        case MI_B:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 42, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, 0, 42, MIDI_CC_OFF);
            }
            return true;
        case MI_C1:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 43, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, 0, 43, MIDI_CC_OFF);
            }
            return true;
        case MI_D1:
            if (record->event.pressed) {
                midi_send_cc(&midi_device, 0, 44, MIDI_CC_ON);
            } else {
                midi_send_cc(&midi_device, 0, 44, MIDI_CC_OFF);
            }
            return true;
    }
    return true;
};
#endif

/* ~Custom key processing */

// clang-format on
