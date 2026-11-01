#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/Org_01.h>
#include <SimpleEncoder.h>
#include <Timer.h>

//OLED setup
const int ScreenWidth = 128;
const int ScreenHeight = 32;
Adafruit_SSD1306 display(ScreenWidth, ScreenHeight, &Wire, -1);

//Button setup
const int SW1 = 3;
const int SW2 = 4;

//Rotary encoder setup
const int ENC_A = 20;
const int ENC_B = 10;
const int ButtonPin = 8;
long DialValue;
long MinDial = 0;
long MaxDial = 99;
SimpleEncoder encoder(ButtonPin, ENC_A, ENC_B, DialValue, MinDial, MaxDial, 1);

//LED setup
const int LEDR = 5;
const int LEDG = 21;

//Logic Setup
bool TimerActive = false;
bool TimerPaused = false;
bool SW1State = false;
bool SW2State = false;
bool SW1PrevState = true;
bool SW2PrevState = true;
long SetMinutes = 0;
long SetHours = 0;
unsigned long SW1LastDebounceTime = 0;
unsigned long SW1DebounceDelay = 200;
unsigned long SW2LastDebounceTime = 0;
unsigned long SW2DebounceDelay = 200;
unsigned long TimerMinutes = 0;
unsigned long TimerHours = 0;
unsigned long TimerSeconds = 0;
unsigned long PrevSeconds = 0;
Timer Timer;

//Config
bool DoTitle = true;
bool ShowSeconds = true;

void setup() {
  Serial.begin(9600);

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);

  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);

  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("Screen not found");
    while (true) {
    }
  }

  Serial.println("Screen started succesfully");

  if (DoTitle == true) {
    display.clearDisplay();
    //Title
    display.setTextColor(1);
    display.setTextWrap(false);
    display.setCursor(2, 2);
    display.print("Mini Study Timer");
    //Name
    display.setFont(&Org_01);
    display.setCursor(2, 29);
    display.print("Balint Koch");
    display.display();
    delay(1000);
  }
  
  drawTimer(0, 0, 0);
  digitalWrite(LEDR, HIGH);
}

void loop() {

  SW1State = digitalRead(SW1);
  SW2State = digitalRead(SW2);

  if (SW1State == LOW && SW1PrevState == HIGH) {
    if ((millis() - SW1LastDebounceTime) > SW1DebounceDelay) {

      if (!TimerActive && !TimerPaused) {

      Serial.println("Timer Started");
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDG, HIGH);
      TimerActive = true;
      Timer.start();

    } else if (TimerActive) {

      Timer.pause();
      TimerActive = false;
      TimerPaused = true;
      digitalWrite(LEDR, HIGH);
      digitalWrite(LEDG, LOW);
      Serial.println("Timer paused");

    } else if (TimerPaused) {

      Timer.resume();
      TimerPaused = false;
      TimerActive = true;
      digitalWrite(LEDR, LOW);
      digitalWrite(LEDG, HIGH);
      Serial.println("Timer resumed");
    }
    SW1LastDebounceTime = millis();
    }
  }
  SW1PrevState = SW1State;
  
  if (SW2State == LOW && SW2PrevState == HIGH) {
    if ((millis() - SW2LastDebounceTime) > SW2DebounceDelay) {

      if (TimerActive || TimerPaused) {
        Timer.stop();
        TimerPaused = false;
        TimerActive = false;
        drawTimer(0, 0, 0);
        digitalWrite(LEDR, HIGH);
        digitalWrite(LEDG, LOW);
        Serial.println("Timer Reset");
      }
      SW2LastDebounceTime = millis();
    }
  }
  SW2PrevState = SW2State;

  if (TimerActive) { 

    TimerSeconds = (Timer.read() / 1000) % 60;
    TimerMinutes = (Timer.read() / 60000) % 60;
    TimerHours = Timer.read() / 3600000;
  }

  
  if (TimerSeconds != PrevSeconds) {

    PrevSeconds = TimerSeconds;
    drawTimer(TimerHours, TimerMinutes, TimerSeconds);
    Serial.print("Current seconds: ");
    Serial.println(TimerSeconds);
  }
}

void drawTimer(unsigned long Hours, unsigned long Minutes, unsigned long Seconds) {
  display.clearDisplay();
  // Hours
  display.setTextColor(1);
  display.setTextSize(2);
  display.setTextWrap(false);
  display.setCursor(37, 9);
  display.print(Hours);
  // Minutes
  display.setCursor(69, 9);
  display.print(Minutes);
  // ":"
  display.setCursor(59, 9);
  display.print(":");
   // Seconds
  if (ShowSeconds) {
   display.setTextSize(1);
   display.setCursor(93, 16);
   display.print(Seconds);
  }
  display.display();
}
