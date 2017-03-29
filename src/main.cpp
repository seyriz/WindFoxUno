#include "Arduino.h"
#include "pin_setting.h"
#include "LowPower.h"

/* TEMP HEADER */
#include "blunoAccessory.h"
#include "U8glib.h"
blunoAccessory myAccessory;
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
#define RIGHT 1
#define UP 2
#define LEFT 3
#define DOWN 4
#define PUSH 5
#define MID 0

float humidity,temperature;                           //Humidity&Temperature

/* PROTOTYPE */
void drawInitPage();
void draw();
void setUpPins();
void clearScreen();
void drawSleep();
void drawWakeUpPage();
void sleepDevice();
void wakeUp();

void setup() {
  setUpPins();
  Serial.begin(115200);
  u8g.setColorIndex(1);             //displayMode : u8g_MODE_BW
  myAccessory.begin();
  u8g.firstPage();
  do {
    drawInitPage();
  } while(u8g.nextPage());

  humidity = myAccessory.readHumidity();
  temperature = myAccessory.readTemperature();

  delay(2000);
}

void loop() {
  int joystick = analogRead(joystickPin);
  Serial.println(joystick);
  // if(joystick < 900) {
    // sleepDevice();
  // }
  u8g.firstPage();
  do{
    draw();
  }
  while(u8g.nextPage());
}

void setUpPins() {
  pinMode(PIN_SLEEP, INPUT_PULLUP);
}

void clearScreen() {
}

void drawSleep() {
  Serial.println("drawSleep");
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(0, 35, "Sleep...");
}

void drawInitPage() {
  Serial.println("drawInitPage");
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(0, 35, "Initilising....");
}

void drawWakeUpPage() {
  Serial.println("drawWakeUpPage");
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(0, 35, "Wake UP!!");
}

void draw () {
  u8g.setFont(u8g_font_unifont);

  u8g.setPrintPos(10, 16);
  do{
    u8g.print("No");
  } while (u8g.nextPage());
}

void sleepDevice() {
  Serial.println("sleepDevice");
  attachInterrupt(joystickPin, wakeUp, FALLING);
  u8g.firstPage();
  do {
    drawSleep();
  } while(u8g.nextPage());
  delay(3000);
  u8g.firstPage();
  do {
    clearScreen();
  } while(u8g.nextPage());
  delay(3000);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}

void wakeUp() {
  Serial.println("wakeUp");
  u8g.firstPage();
  drawWakeUpPage();
}
