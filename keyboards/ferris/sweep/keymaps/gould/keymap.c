#include QMK_KEYBOARD_H

#define _BASE  0
#define _CURS  1
#define _NUM 2
#define _SYMB  3
#define _FUNL  5
#define _FLASH 6

#define _ KC_NO

#define MY_E MT(MOD_LCTL | MOD_LALT | MOD_LSFT, KC_E)
#define MY_MEH LCTL(LALT(LSFT(KC_NO)))

#define MY_R MT(MOD_LGUI | MOD_LCTL | MOD_LALT | MOD_LSFT, KC_R)
#define MY_HYPR LCTL(LALT(LSFT(LGUI(KC_NO))))

#define MY_U MT(MOD_LGUI | MOD_LCTL | MOD_LALT | MOD_LSFT, KC_U)
#define MY_I MT(MOD_LCTL | MOD_LALT | MOD_LSFT, KC_I)

#define MY_F LSFT_T(KC_F)
#define MY_4 MT(MOD_LSFT, KC_4)
#define MY_F4 MT(MOD_LSFT, KC_F4)

#define MY_J MT(MOD_RSFT, KC_J)
#define MY_7 MT(MOD_RSFT, KC_7)
#define MY_F7 MT(MOD_RSFT, KC_F7)

#define MY_D LCTL_T(KC_D)
#define MY_3 MT(MOD_LCTL, KC_3)
#define MY_F3 MT(MOD_LCTL, KC_F3)

#define MY_K MT(MOD_RCTL, KC_K)
#define MY_8 MT(MOD_RCTL, KC_8)
#define MY_F8 MT(MOD_RCTL, KC_F8)

#define MY_S MT(MOD_LALT, KC_S)
#define MY_2 MT(MOD_LALT, KC_2)
#define MY_F2 MT(MOD_LALT, KC_F2)


#define MY_L MT(MOD_LALT, KC_L)
#define MY_9 MT(MOD_LALT, KC_9)
#define MY_F9 MT(MOD_LALT, KC_F9)

#define MY_A MT(MOD_LGUI, KC_A)
#define MY_1 MT(MOD_LGUI, KC_1)
#define MY_F1 MT(MOD_LGUI, KC_F1)


#define MY_SCLN MT(MOD_RGUI, KC_SCLN)
#define MY_0 MT(MOD_RGUI, KC_0)
#define MY_F10 MT(MOD_RGUI, KC_F10)


#define MY_DEL LT(_FUNL, KC_DEL)
#define MY_SPC LT(_NUM, KC_SPC)
#define MY_RET LT(_CURS, KC_ENTER)
#define MY_BSP LT(_SYMB, KC_BSPC)

#define MY_GRV MT(MOD_LGUI, KC_GRV)

enum custom_keycodes {
    MYARROW = SAFE_RANGE,
    MYBARROW,
    MYDARROW,
    MYBIND,
    MYPIPE,
    MYBPIPE,
    MYAP,
    MYMAP,
    MYDIR
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MYARROW:
        if (record->event.pressed) {
          SEND_STRING("->");
        }
        break;
    case MYBARROW:
        if (record->event.pressed) {
          SEND_STRING("<-");
        }
        break;
    case MYDARROW:
        if (record->event.pressed) {
          SEND_STRING("=>");
        }
        break;
    case MYBIND:
        if (record->event.pressed) {
          SEND_STRING(">>=");
        }
        break;
    case MYPIPE:
        if (record->event.pressed) {
          SEND_STRING("|>");
        }
        break;
    case MYBPIPE:
        if (record->event.pressed) {
          SEND_STRING("<|");
        }
        break;
    case MYAP:
        if (record->event.pressed) {
          SEND_STRING("<*>");
        }
        break;
    case MYMAP:
        if (record->event.pressed) {
          SEND_STRING("<$>");
        }
        break;
    case MYDIR:
        if (record->event.pressed) {
          SEND_STRING(":\\");
        }
        break;

  };
  return true;
}

const uint16_t PROGMEM CV_COMBO[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM COMMAM_COMBO[] = {KC_COMMA, KC_M, COMBO_END};

const uint16_t PROGMEM DF_COMBO[] = {MY_D, MY_F, COMBO_END};

combo_t key_combos[] = {
    COMBO(CV_COMBO, KC_B),
    COMBO(COMMAM_COMBO, KC_N),
    COMBO(DF_COMBO, KC_G),
};


const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R',
                       'L', 'L',     'R', 'R'
    );



// Chordal Hold Logic
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
  switch(tap_hold_keycode) {
    case MY_D:
    case MY_F:
      return true;

    default:
      break;
  }

  return get_chordal_hold_default(tap_hold_record, other_record);
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  
/* Base
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  T   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |      |      |  Meh |  Hpr |      |           |      |  Hpr |  Meh |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  G   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |
 * | Super|  Alt | Ctrl |Shift |      |           |      | Shift| Ctrl | Alt  | Super|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  B   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | BckSp|      |    |      | Del  |      |
 *                  |      | SYMB | RET  |    |Space | FUNL |      |
 *                  `-------------| CURS |    |NUM   |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_BASE] = LAYOUT( \
  KC_Q,    KC_W,    MY_E,    MY_R,    KC_T,         KC_Y,    MY_U,    MY_I,    KC_O,    KC_P,    \
  MY_A,    MY_S,    MY_D,    MY_F,    KC_G,         KC_H,    MY_J,    MY_K,    MY_L,    MY_SCLN, \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \

                             MY_BSP,  MY_RET,       MY_SPC,   MY_DEL \
),

/* CURS
 * ,----------------------------------.           ,----------------------------------.
 * |      |      | Meh  |  Hypr|      |           | Ins  | Home |  Up  | End  |  "   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  `   |      |      |      |      |           |      |      |      |      |      |
 * |Super |  Alt | Ctrl |Shift |      |           |WCaps |  <-  | Down |  ->  |  '   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |  :\  | PgUp | Contx|PgDown|  \   |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    | Tab  |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_CURS] = LAYOUT( \
  _,      _,  MY_MEH, MY_HYPR, _,            KC_INS,   KC_HOME,  KC_UP,           KC_END,    KC_DQUO, \
  MY_GRV, KC_LALT, KC_LCTL, KC_LSFT, _,            CW_TOGG,  KC_LEFT,  KC_DOWN,         KC_RIGHT,  KC_QUOTE, \
  _,       _,       _,       _,       _,            MYDIR,    KC_PGUP,  KC_APPLICATION,  KC_PGDN,   KC_BSLS, \
                             _,       _,            KC_TAB,    _ \
),

/*
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  !   |  @   |   #  |  $   |  %   |           |      |   -  |  =   |  +   |  *   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  1   |  2   |  3   |  4   |  5   |           |  6   |   7  |   8  |   9  |  0   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  ^   |  &   |      |      |      |           |      |      |  ,   |   .  |  /   |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | BckSp|      |    |      |      |      |
 *                  `-------------|CoTab |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_NUM] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    _,       KC_MINS,   KC_EQL,  KC_PPLS,  KC_ASTR,      \
  MY_1,    MY_2,    MY_3,    MY_4,    KC_5,       KC_6,    MY_7,      MY_8,     MY_9,     MY_0,   \
  KC_CIRC, KC_AMPR, _,       _,          _,       _,       _      ,   KC_COMM,  KC_DOT,   KC_SLSH,      \
                       KC_BSPC,  S(KC_TAB),       _,       _ \
),
/* FUNL
 *
 * ,----------------------------------.           ,----------------------------------.
 * |  F11 |  F12 |  F12 |  F14 |  F15 |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  F16 |  F17 |  F18 |  F19 | F20  |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      | BCSP | ESC  |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_FUNL] = LAYOUT( \
  KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,    _,       _,       _,       _,          _,   \
  MY_F1,   MY_F2,   MY_F3,   MY_F4,   KC_F5,     KC_F6,   MY_F7,   MY_F8,   MY_F9,   MY_F10, \
  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,    _,       _,       _,       _,       _,      \
                         KC_BSPC,     KC_ESC,    _,       _ \
),

/* 
 *
 * ,----------------------------------.           ,----------------------------------.
 * |_FLASH|      |      |      |      |           |   |  |  _   |  *   |  ~   |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  <   |  {   |  [   |   (  |      |           |      |  )   |   ]  |  }   |  >   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | <$>  |      |      |  <-  |  <|  |           |  |>  |  ->  |  =>  |  >>= | <*>  |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      | DEL  |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_SYMB] = LAYOUT( \
  MO(_FLASH),        _,        _,        _,        _,      KC_PIPE,  KC_UNDS,   KC_ASTR,   KC_TILD,      _,   \
  KC_LT,       KC_LCBR,  KC_LBRC,  KC_LPRN,        _,            _,  KC_RPRN,   KC_RBRC,   KC_RCBR,  KC_GT,   \
  MYMAP,             _,        _, MYBARROW,  MYBPIPE,       MYPIPE,  MYARROW,  MYDARROW,    MYBIND,   MYAP,   \
                                   _,         _,             _,        KC_DEL \
),
/* FLASH
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |Boot  |      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *                  ,--------------------.    ,------,-------------.
 *                  |      |      |      |    |      |      |      |
 *                  `-------------|      |    |      |------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_FLASH] = LAYOUT( \
  _,       _,       _,       _,       _,          _,       _,       _,     _,     _,        \
  _,       _,       _,       _,       _,          _,       _,       _,     _,     _,        \
  QK_BOOT, _,       _,       _,       _,          _,       _,       _,     _,     _,   \
                             _,       _,          _,       _ \
)
};
