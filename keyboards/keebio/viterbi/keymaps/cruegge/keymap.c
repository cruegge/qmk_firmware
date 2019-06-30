#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum layers {
  _BASE, _SYM, _NUM, _NAV
};

enum custom_keycodes {
  KC_SYM = SAFE_RANGE, KC_NUM, KC_NAV
};

#define KC_____ KC_TRNS
#define KC_GTAB LCMD_T(KC_TAB)
#define KC_CESC LCTL_T(KC_ESC)
#define KC_CENT LCTL_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT_kc(
    ____, ____, ____, ____, ____, ____, ____, /**/ ____, ____, ____, ____, ____, ____, ____,
    GTAB, Q   , W   , E   , R   , T   , ____, /**/ ____, Y   , U   , I   , O   , P   , RCMD,
    CESC, A   , S   , D   , F   , G   , ____, /**/ ____, H   , J   , K   , L   , BSPC, CENT,
    LSFT, Z   , X   , C   , V   , B   , ____, /**/ ____, N   , M   , COMM, DOT , SLSH, RSFT,
    ____, ____, ____, ____, LALT, SYM , SPC , /**/ SPC , NAV , RALT, ____, ____, ____, ____
  ),

  [_SYM] = LAYOUT_kc(
    ____, ____, ____, ____, ____, ____, ____, /**/ ____, ____, ____, ____, ____, ____, ____,
    ____, 1   , 2   , 3   , 4   , 5   , ____, /**/ ____, 6   , 7   , 8   , 9   , 0   , ____,
    ____, GRV , EQL , QUOT, MINS, ____, ____, /**/ ____, BSLS, LBRC, RBRC, SCLN, ____, ____,
    ____, ____, ____, ____, ____, ____, ____, /**/ ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____, /**/ ____, ____, ____, ____, ____, ____, ____
  ),

  [_NAV] = LAYOUT_kc(
    ____, ____, ____, ____, ____, ____, ____, /**/ ____, ____, ____, ____, ____, ____, ____,
    ____, F1  , F2  , F3  , F4  , F5  , ____, /**/ ____, HOME, PGDN, PGUP, END , DEL , ____,
    ____, F6  , F7  , F8  , F9  , F10 , ____, /**/ ____, LEFT, DOWN, UP  , RGHT, ____, ____,
    ____, F11 , F12 , PSCR, APP , PAUS, ____, /**/ ____, INS , ENT , TAB , ESC , ____, ____,
    ____, ____, ____, ____, ____, ____, ____, /**/ ____, ____, ____, ____, ____, ____, ____
  ),

};

void set_layer(bool on, int layer) {
  if (on) layer_on(layer);
  else layer_off(layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_SYM:
      set_layer(record->event.pressed, _SYM);
      return false;
    case KC_NAV:
      set_layer(record->event.pressed, _NAV);
      return false;
  }
  return true;
}
