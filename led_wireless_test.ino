#include <FastLED.h>
#define LED_PIN   12
#define COLOR_ORDER   GRB
#define CHIPSET   WS2812B 
#define NUM_LEDS 20
CRGB leds[NUM_LEDS];

const int btn1 = 8; // d0  
const int btn2 = 7; // d1
const int btn3 = 6; // d2
const int btn4 = 5; // d3
// variables will change:
int buttonState1 = 0;  // variable for reading the pushbutton status
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
void setup() { 
 FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);

  
  // initialize the pushbuttons pin as an input:
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);  
}
void loop() {
  // led section start
// FastLED.showColor(CRGB::Red);
// delay(1000);
// FastLED.showColor(CRGB::Blue);
// delay(1000);
  // led section end
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(btn1);
  buttonState2 = digitalRead(btn2);
  buttonState3 = digitalRead(btn3);
  buttonState4 = digitalRead(btn4);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {
    // turn LED on:
    FastLED.showColor(CRGB::Green);
    delay(500);    
    FastLED.showColor(CRGB::Red);
  }  
  // else {
  //   // turn LED off:
  //   FastLED.showColor(CRGB::Black);
  
  if(buttonState2 == HIGH) {
    // turn LED on:
    FastLED.showColor(CRGB::Yellow);
    delay(500);
    FastLED.showColor(CRGB::White);
    delay(500);
  }
  // else {
  //   // turn LED off:
  //   FastLED.showColor(CRGB::Black);
  
  if(buttonState3 == HIGH) {
    // turn LED on:
    FastLED.showColor(CRGB::Black);
    delay(500);
    FastLED.showColor(CRGB::Red);
  } 
  // else {
  //   // turn LED off:
  //   FastLED.showColor(CRGB::Black);
  
  
  if (buttonState4 == HIGH) {
    // turn LED on:
    FastLED.showColor(CRGB::Green);
    delay(500);
    FastLED.showColor(CRGB::White);
    delay(500);
    FastLED.showColor(CRGB::Red);
    delay(500);
  } 
  // else {
  //   // turn LED off:
  //   FastLED.showColor(CRGB::Black);
  
}
