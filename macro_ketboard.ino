#include <stdlib.h>
#include <EEPROM.h>
#include "HID-Project.h"
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <splash.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SPITFT.h>
#include <Adafruit_SPITFT_Macros.h>
#include <gfxfont.h>
#include <string.h>
#include <EEPROM.h>

#include "KeyValue.h"

#define OLED_ADDR 0x3C
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET -1     // Reset pin # (or -1 if sharing Arduino reset pin)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


typedef struct KeySettingValue {

  //모드이름
  String name;

  //휠 스위치(Up, Down, Button)
  char wheel_Up_type;  //키 타입
  char wheel_Up_num;   //키 배열번호

  char wheel_Down_type;  //키 타입
  char wheel_Down_num;   //키 배열번호

  char wheel_Push_type;  //키 타입
  char wheel_Push_num;   //키 배열번호


  //0 = Normal_Key, 1 = Sub_Key, 2 = special_Key, 3 = System_Key, 4 = MEDIA_Key
  char Key1_type;  //키 타입
  char Key1_num;   //키 배열번호

  char Key2_type;  //키 타입
  char Key2_num;   //키 배열번호

  char Key3_type;  //키 타입
  char Key3_num;   //키 배열번호

  char Key4_type;  //키 타입
  char Key4_num;   //키 배열번호

  char Key5_type;  //키 타입
  char Key5_num;   //키 배열번호

  char Key6_type;  //키 타입
  char Key6_num;   //키 배열번호

  //키 RGB LED 값
  char Key1_color[3];
  char Key2_color[3];
  char Key3_color[3];
  char Key4_color[3];
  char Key5_color[3];
  char Key6_color[3];

} KeySettingValue;

char KeyValue[6][2];
char wheel_Value[3][2];
char Key_color[6][3];


KeySettingValue KeySceneArray[10];

void setup() {
  Serial.begin(9600);

  Keyboard.begin();
  Mouse.begin();
  Consumer.begin();

  oled_init();

  EEPROM.get(0, KeySceneArray);

  delay(2000);
  Keyboard.write(Normal_Key[(int)KeySceneArray[0].Key1_num]);
  Serial.println((int)KeySceneArray[0].Key1_num);
  delay(5000);
    delay(2000);
  Keyboard.write(Normal_Key[(int)KeySceneArray[0].Key1_num]);
  Serial.println((int)KeySceneArray[0].Key1_num);
  delay(5000);



  wheel_Value[0][0] = 0;  //타입
  wheel_Value[0][1] = 2;

  wheel_Value[1][0] = 0;  //타입
  wheel_Value[1][1] = 2;

  wheel_Value[2][0] = 0;  //타입
  wheel_Value[2][1] = 2;


  KeyValue[0][0] = 0;
  KeyValue[0][1] = 2;
  Key_color[0][0] = 255;
  Key_color[0][1] = 255;
  Key_color[0][2] = 255;

  KeyValue[1][0] = 0;
  KeyValue[1][1] = 17;
  Key_color[1][0] = 255;
  Key_color[1][1] = 255;
  Key_color[1][2] = 255;

  KeyValue[2][0] = 0;
  KeyValue[2][1] = 20;
  Key_color[2][0] = 255;
  Key_color[2][1] = 255;
  Key_color[2][2] = 255;

  KeyValue[3][0] = 0;
  KeyValue[3][1] = 2;
  Key_color[3][0] = 255;
  Key_color[3][1] = 255;
  Key_color[3][2] = 255;

  KeyValue[4][0] = 0;
  KeyValue[4][1] = 17;
  Key_color[4][0] = 255;
  Key_color[4][1] = 255;
  Key_color[4][2] = 255;

  KeyValue[5][0] = 0;
  KeyValue[5][1] = 20;
  Key_color[5][0] = 255;
  Key_color[5][1] = 255;
  Key_color[5][2] = 255;

  set_KeyData(KeySceneArray, 0, "test", KeyValue[0], KeyValue[1], KeyValue[2], KeyValue[3], KeyValue[4], KeyValue[5],
              Key_color[0], Key_color[1], Key_color[2], Key_color[3], Key_color[4], Key_color[5],
              wheel_Value[0], wheel_Value[1], wheel_Value[2]);


EEPROM.put(0, KeySceneArray);

}


void loop() {
  delay(2000);
  Keyboard.write(special_Key[(int)KeySceneArray[0].Key1_num]);
  Serial.println((int)KeySceneArray[0].Key1_num);
  delay(5000);
}

//================================================================================
void set_KeyData(KeySettingValue* KeySceneArray, char lint_num, String name, char* KeyValue1, char* KeyValue2, char* KeyValue3, char* KeyValue4, char* KeyValue5, char* KeyValue6,
                 char* Key1_color, char* Key2_color, char* Key3_color, char* Key4_color, char* Key5_color, char* Key6_color,
                 char* wheel_Up_Value, char* wheel_Down_Value, char* wheel_Push_Value) {
  KeySceneArray[lint_num].name = name;

  KeySceneArray[lint_num].Key1_type = KeyValue1[0];
  KeySceneArray[lint_num].Key1_num = KeyValue1[1];
  KeySceneArray[lint_num].Key1_color[0] = Key1_color[0];
  KeySceneArray[lint_num].Key1_color[1] = Key1_color[1];
  KeySceneArray[lint_num].Key1_color[2] = Key1_color[2];

  KeySceneArray[lint_num].Key2_type = KeyValue2[0];
  KeySceneArray[lint_num].Key2_num = KeyValue2[1];
  KeySceneArray[lint_num].Key2_color[0] = Key2_color[0];
  KeySceneArray[lint_num].Key2_color[1] = Key2_color[1];
  KeySceneArray[lint_num].Key2_color[2] = Key2_color[2];

  KeySceneArray[lint_num].Key3_type = KeyValue3[0];
  KeySceneArray[lint_num].Key3_num = KeyValue3[1];
  KeySceneArray[lint_num].Key3_color[0] = Key3_color[0];
  KeySceneArray[lint_num].Key3_color[1] = Key3_color[1];
  KeySceneArray[lint_num].Key3_color[2] = Key3_color[2];

  KeySceneArray[lint_num].Key4_type = KeyValue4[0];
  KeySceneArray[lint_num].Key4_num = KeyValue4[1];
  KeySceneArray[lint_num].Key4_color[0] = Key4_color[0];
  KeySceneArray[lint_num].Key4_color[1] = Key4_color[1];
  KeySceneArray[lint_num].Key4_color[2] = Key4_color[2];

  KeySceneArray[lint_num].Key5_type = KeyValue5[0];
  KeySceneArray[lint_num].Key5_num = KeyValue5[1];
  KeySceneArray[lint_num].Key5_color[0] = Key5_color[0];
  KeySceneArray[lint_num].Key5_color[1] = Key5_color[1];
  KeySceneArray[lint_num].Key5_color[2] = Key5_color[2];

  KeySceneArray[lint_num].Key6_type = KeyValue6[0];
  KeySceneArray[lint_num].Key6_num = KeyValue6[1];
  KeySceneArray[lint_num].Key6_color[0] = Key6_color[0];
  KeySceneArray[lint_num].Key6_color[1] = Key6_color[1];
  KeySceneArray[lint_num].Key6_color[2] = Key6_color[2];

  KeySceneArray[lint_num].wheel_Up_type = wheel_Up_Value[0];
  KeySceneArray[lint_num].wheel_Up_num = wheel_Up_Value[1];

  KeySceneArray[lint_num].wheel_Down_type = wheel_Down_Value[0];
  KeySceneArray[lint_num].wheel_Down_num = wheel_Down_Value[1];

  KeySceneArray[lint_num].wheel_Push_type = wheel_Push_Value[0];
  KeySceneArray[lint_num].wheel_Push_num = wheel_Push_Value[1];
}

void oled_init() {
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.drawPixel(10, 10, SSD1306_WHITE);
  display.clearDisplay();

  display.setTextSize(1);               // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Draw white text
  display.setCursor(0, 0);              // Start at top-left corner
  display.cp437(true);                  // Use full 256 char 'Code Page 437' font
}
