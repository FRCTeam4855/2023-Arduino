#include <Adafruit_NeoPixel.h>

// Define the buttons and pin location
#define BUTTON_PIN_2 4
#define BUTTON_PIN_3 5
#define BUTTON_PIN_4 6
#define BUTTON_PIN_5 7

#define PIXEL_PIN 12  // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 122  // Number of LEDs in the Neopixel

// Parameter 1 = number of pixels in strip,  neopixel stick has 8
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_RGB     Pixels are wired for RGB bitstream
//   NEO_GRB     Pixels are wired for GRB bitstream, correct for neopixel stick
//   NEO_KHZ400  400 KHz bitstream (e.g. FLORA pixels)
//   NEO_KHZ800  800 KHz bitstream (e.g. High Density LED strip), correct for neopixel stick
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

// State variables and initial condition
int currentButton = 0;
unsigned long currentTime = 0;


int showType = 0;
int oneColorWipeSpeed = 40;
int twoColorWipeSpeed = 80;   // Delay in pixel color wipe, bigger == slower
int oneColorChaseSpeed = 200;
int twoColorChaseSpeed = 200;  // Delay in theater chase
int flashTime = 2000;     //ms duration for flash animation


void setup() {
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);
  pinMode(BUTTON_PIN_3, INPUT_PULLUP);
  pinMode(BUTTON_PIN_4, INPUT_PULLUP);
  pinMode(BUTTON_PIN_5, INPUT_PULLUP);

  strip1.begin();
  strip1.show();  // Initialize all pixels to 'off'
}
void loop() {
  // Get current button state.
  if (digitalRead(BUTTON_PIN_2) == HIGH && currentButton != 2) {
    strip1.clear();
    currentButton = 2;
    currentTime = millis();
  }

  if (digitalRead(BUTTON_PIN_3) == HIGH && currentButton != 3) {
    strip1.clear();
    currentButton = 3;
    currentTime = millis();
  }

  if (digitalRead(BUTTON_PIN_4) == HIGH && currentButton != 4) {
    strip1.clear();
    currentButton = 4;
    currentTime = millis();
  }

  if (digitalRead(BUTTON_PIN_5) == HIGH && currentButton != 5) {
    strip1.clear();
    currentButton = 5;
    currentTime = millis();
  }

  // Check if button 2 state changed (button press).
  if (currentButton == 2) {
    if (currentTime + flashTime <= millis()) {
      twoColorChase(strip1.Color(0, 128, 0), strip1.Color(0, 0, 128));
    } else {
      oneColorChase(strip1.Color(0, 128, 0));  // Green
    }
  }
  // Check if button 3 state changed (button press).
  if (currentButton == 3) {
    if (currentTime + flashTime <= millis()) {
      oneColorWipe(strip1.Color(0, 0, 128));
    } else {
      oneColorChase(strip1.Color(0, 0, 128));  // Blue
    }
  }
  // Check if button 4 state changed (button press).
  if (currentButton == 4) {
    if (currentTime + flashTime <= millis()) {
      oneColorWipe(strip1.Color(200, 0, 0));
    } else {
      oneColorChase(strip1.Color(200, 0, 0));  // Red
    }
  }
  // Check if button 5 state changed (button press).
  if (currentButton == 5) {
    if (currentTime + flashTime <= millis()) {
      twoColorWipe(strip1.Color(40, 0, 40), strip1.Color(150, 100, 0));  // Purple and gold
    } else {
      twoColorChase(strip1.Color(40, 0, 40), strip1.Color(150, 100, 0));
    }
  }
}


// Fill the dots one after the other with a color
void oneColorWipe(uint32_t c) {
  for (uint16_t i = 0; i < strip1.numPixels(); i++) {
    strip1.setPixelColor(i, c);
    strip1.show();
    delay(oneColorWipeSpeed);
  }
}

// Fill the dots one after the other with a TWO colors
void twoColorWipe(uint32_t c1, uint32_t c2) {
  for (int i = 0; i < strip1.numPixels(); i = i + 2) {
    strip1.setPixelColor(i, c1);
    strip1.setPixelColor(i + 1, c2);
    strip1.show();
    delay(twoColorWipeSpeed);
  }
}

//Theatre-style crawling lights with one color
void oneColorChase(uint32_t c) {
  for (int j = 0; j < 10; j++) {  //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < strip1.numPixels(); i = i + 3) {
        strip1.setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip1.show();

      delay(oneColorChaseSpeed);

      for (int i = 0; i < strip1.numPixels(); i = i + 3) {
        strip1.setPixelColor(i + q, 0);  //turn every third pixel off
      }
    }
  }
}

// Theatre-style crawling lights with TWO colors
void twoColorChase(uint32_t c1, uint32_t c2) {
  for (int j = 0; j < 10; j++) {  //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < strip1.numPixels(); i = i + 3) {
        strip1.setPixelColor(i + q, c1);  //turn every third pixel to color 1
      }
      strip1.show();

      delay(twoColorChaseSpeed);

      for (int i = 0; i < strip1.numPixels(); i = i + 3) {
        strip1.setPixelColor(i + q, c2);  //turn every third pixel to color 2
      }
    }
  }
}

