#ifndef DISABLE_RGB_MATRIX_ALPHAS_MODS
RGB_MATRIX_EFFECT(ALPHAS_MODS)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// alphas = color1, mods = color2
bool ALPHAS_MODS(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);


//Original
//   HSV hsv = { rgb_matrix_config.hue, rgb_matrix_config.sat, rgb_matrix_config.val };
//   RGB rgb1 = hsv_to_rgb(hsv);
//   hsv.h += rgb_matrix_config.speed;
//   RGB rgb2 = hsv_to_rgb(hsv);

//Modified
//0-255 for hsv
  HSV hsv = { 128, 255, 255};
  RGB rgb1 = hsv_to_rgb(hsv);
  hsv.h += ((0.6*hsv.h) + (rgb_matrix_config.speed - 8)) + rgb_matrix_config.speed;
  RGB rgb2 = hsv_to_rgb(hsv);


  for (uint8_t i = led_min; i < led_max; i++) {
    RGB_MATRIX_TEST_LED_FLAGS();
    if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_MODIFIER)) {
      rgb_matrix_set_color(i, rgb2.r, rgb2.g, rgb2.b);
    } else {
      rgb_matrix_set_color(i, rgb1.r, rgb1.g, rgb1.b);
    }
  }
  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif // DISABLE_RGB_MATRIX_ALPHAS_MODS
