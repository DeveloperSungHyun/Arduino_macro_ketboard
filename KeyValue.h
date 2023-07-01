

KeyboardKeycode Normal_Key[48] = {//키보드 기본키
  KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9,
  KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L, KEY_M, KEY_N, KEY_O, KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T, KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z,
  KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12
};
char Normal_Key_display[48][3] = {//키보드 기본키
"1", "2", "3", "4", "5", "6", "7", "8", "9",
"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
"F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9"
};
char Combination_Key_display[15][20] = {
  "CTRL", "SHIFT", "ALT", "WIN", "CTRL+SHIFT", "CTRL+ALT", "CTRL+WIN", "SHIFT+ALT", "SHIFT+WIN", "ALT+WIN", "CTRL+SHIFT+ALT", "CTRL+SHIFT+WIN", "CTRL+ALT+WIN", "SHIFT+ALT+WIN", "CTRL+SHIFT+ALT+WIN"
};

KeyboardKeycode Sub_Key[18] = {//기능키
  KEY_ESC, KEY_TAB, KEY_BACKSPACE, KEY_ENTER, KEY_LEFT_ALT, KEY_INSERT, KEY_DELETE, KEY_RIGHT_GUI, KEY_CAPS_LOCK, KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_HOME, KEY_END, KEY_PAGE_UP, KEY_PAGE_DOWN
};
char Sub_Key_display[18][15] = {//기능키
  "ESC", "TAB", "BACKSPACE", "ENTER", "LEFT_ALT", "INSERT", "DELETE", "WIN", "CAPS_LOCK", "UP", "DOWN", "LEFT", "RIGHT", "HOME", "END", "PAGE_UP", "PAGE_DOWN"
};

char special_Key[32] = {//특수문자
  33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 96, 123, 124, 125, 126
};

ConsumerKeycode System_Key[3] = {
  CONSUMER_BRIGHTNESS_UP, CONSUMER_BRIGHTNESS_DOWN, CONSUMER_SLEEP
};
char System_Key_display[3][15] = {
  "backlight_Up", "backlight_Down", "SLEEP"
};

ConsumerKeycode MEDIA_Key[6] = {//다음, 이전, 정지재생, 볼륨업, 볼륨다운, 뮤트
  MEDIA_NEXT, MEDIA_PREV, MEDIA_PAUSE, MEDIA_VOLUME_UP, MEDIA_VOLUME_DOWN, MEDIA_VOLUME_MUTE
};
char MEDIA_Key_display[6][12] = {//다음, 이전, 정지재생, 볼륨업, 볼륨다운, 뮤트
  "next", "back", "start/stop", "vol_up", "vol_down", "mute"
};