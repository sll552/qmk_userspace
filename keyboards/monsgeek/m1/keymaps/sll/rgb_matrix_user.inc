// !!! DO NOT ADD #pragma once !!! //
//#include "rgb_matrix.h" // <---- DO NOT FORGET TO COMMENT

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)

RGB_MATRIX_EFFECT(my_static_pattern) // <---- DO NOT FORGET TO UNCOMMENT, comment is needed for clangd to work properly

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS // <---- DO NOT FORGET TO UNCOMMENT

enum key_led_ids {
    KL_ESCAPE,
    KL_F1,
    KL_F2,
    KL_F3,
    KL_F4,
    KL_F5,
    KL_F6,
    KL_F7,
    KL_F8,
    KL_F9,
    KL_F10,
    KL_F11,
    KL_F12,
    KL_DELETE,
    KL_GRAVE,
    KL_1,
    KL_2,
    KL_3,
    KL_4,
    KL_5,
    KL_6,
    KL_7,
    KL_8,
    KL_9,
    KL_0,
    KL_MINUS,
    KL_EQUAL,
    KL_BACKSPACE,
    KL_HOME,
    KL_TAB,
    KL_Q,
    KL_W,
    KL_E,
    KL_R,
    KL_T,
    KL_Y,
    KL_U,
    KL_I,
    KL_O,
    KL_P,
    KL_LEFT_BRACKET,
    KL_RIGHT_BRACKET,
    KL_BACKSLASH,
    KL_PAGE_UP,
    KL_CAPS_LOCK,
    KL_A,
    KL_S,
    KL_D,
    KL_F,
    KL_G,
    KL_H,
    KL_J,
    KL_K,
    KL_L,
    KL_SEMICOLON,
    KL_QUOTE,
    KL_NONUS_HASH,
    KL_ENTER,
    KL_PAGE_DOWN,
    KL_LEFT_SHIFT,
    KL_NONUS_BACKSLASH,
    KL_Z,
    KL_X,
    KL_C,
    KL_V,
    KL_B,
    KL_N,
    KL_M,
    KL_COMMA,
    KL_DOT,
    KL_SLASH,
    KL_RIGHT_SHIFT,
    KL_UP,
    KL_END,
    KL_LEFT_CTRL,
    KL_LEFT_GUI,
    KL_LEFT_ALT,
    KL_SPACE,
    KL_RIGHT_ALT,
    KL_RIGHT_GUI,
    KL_RIGHT_CTRL,
    KL_LEFT,
    KL_DOWN,
    KL_RIGHT,
    KL_LED_MAX
};

static RGB index_to_rgb(uint8_t led_index) {
    switch (led_index) {
        case KL_F1 ... KL_F12:
            return (RGB){.r = 0, .g = 255, .b = 0}; // Green
        case KL_DELETE:
        case KL_HOME:
        case KL_PAGE_UP:
        case KL_PAGE_DOWN:
        case KL_END:
            return (RGB){.r = 255, .g = 0, .b = 255}; // Magenta
        case KL_ESCAPE:
        case KL_GRAVE:
        case KL_TAB:
        case KL_CAPS_LOCK:
        case KL_LEFT_SHIFT:
        case KL_LEFT_CTRL:
        case KL_LEFT_GUI:
        case KL_LEFT_ALT:
        case KL_SPACE:
        case KL_RIGHT_ALT:
        case KL_RIGHT_GUI:
        case KL_RIGHT_CTRL:
        case KL_RIGHT_SHIFT:
        case KL_ENTER:
        case KL_BACKSPACE:
            return (RGB){.r = 255, .g = 80, .b = 0}; // Orange
        case KL_1 ... KL_0:
        case KL_MINUS:
        case KL_EQUAL:
            return (RGB){.r = 0, .g = 255, .b = 255}; // Cyan
        case KL_Q:
        case KL_W:
        case KL_R:
        case KL_T:
        case KL_Y:
        case KL_U:
        case KL_I:
        case KL_O:
        case KL_P:
        case KL_A:
        case KL_S:
        case KL_D:
        case KL_F:
        case KL_G:
        case KL_H:
        case KL_J:
        case KL_K:
        case KL_L:
        case KL_Z:
        case KL_X:
        case KL_C:
        case KL_V:
        case KL_B:
        case KL_N:
        case KL_M:
        case KL_NONUS_BACKSLASH:
        case KL_COMMA:
        case KL_DOT:
        case KL_SLASH:
        case KL_SEMICOLON:
        case KL_QUOTE:
        case KL_NONUS_HASH:
        case KL_LEFT_BRACKET:
        case KL_RIGHT_BRACKET:
        case KL_BACKSLASH:
            return (RGB){.r = 0, .g = 0, .b = 255}; // Blue
        case KL_UP:
        case KL_DOWN:
        case KL_LEFT:
        case KL_RIGHT:
            return (RGB){.r = 255, .g = 255, .b = 0}; // Yellow
        default:
            return (RGB){.r = 0, .g = 0, .b = 0}; // Black
    }
}

static bool my_static_pattern(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            RGB     rgb;
            if (index >= led_min && index < led_max && index != NO_LED) {
                rgb = index_to_rgb(index);
                rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
            }
        }
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS // <---- DO NOT FORGET TO UNCOMMENT
