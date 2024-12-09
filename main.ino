//Code by CZ, AI generated sections marked with comment
//Github copilot and chatGPT used to debug multiple times
#include "findWeights.h"
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <vector>

#define NUMPIXELS 4
#define COLOR_SENSOR_ADDR 0x48
#define I2C_SDA 11
#define I2C_SCL 12

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, 13, NEO_GRB + NEO_KHZ800);

struct RGB {
  float r, g, b;
};

const int ButtonPin = 14;
const int Motor1 = 10;
const int Motor2 = 9;
const int MotorButton = 8;

int lastButtonValue = HIGH;
int lastMotorValue = HIGH;

volatile float recv_value[3];
RGB colors[NUMPIXELS];
RGB recordedColors[NUMPIXELS];
int currentLight = 0;
bool waitingForPress = true;
bool secondLayerActive = false;

unsigned long buttonPressStart = 0;
bool isLongPress = false;

float weights[3];

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println("0");
  Wire.begin(I2C_SDA, I2C_SCL);
  ping();
  pixels.begin();
  pinMode(ButtonPin, INPUT);
  pinMode(MotorButton, INPUT);
  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  Serial.println("1");
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
    delay(200);
  }
  Serial.println("2");
  delay(500);
  pixels.clear();
  pixels.show();
  Serial.println("3");
}

void loop() {
  handleButtonPress();
  motorControl();
  if (!secondLayerActive && waitingForPress) {
    blinkCurrentLight();
  } else if (secondLayerActive) {
    displayWeight();
  }
}

void motorControl(){
  int buttonValue = digitalRead(MotorButton); 
  if (buttonValue == LOW && lastMotorValue == HIGH) {
    Serial.println("Move");
    digitalWrite(Motor1, HIGH);
    digitalWrite(Motor2, LOW);
    delay(1000);
    digitalWrite(Motor1, LOW);
    digitalWrite(Motor2, HIGH);
    delay(1000);
    digitalWrite(Motor1, LOW);
    digitalWrite(Motor2, LOW);
  }

  lastMotorValue = buttonValue;

}

void ping(void) {
  char sensors_status;
  while (sensors_status != 0x66) {
    Wire.beginTransmission(COLOR_SENSOR_ADDR);
    Wire.write(0xAA);
    Wire.endTransmission(0);
    Wire.requestFrom(COLOR_SENSOR_ADDR, 1, 1);
    sensors_status = Wire.read();
  }
}

void capture_color() {
  Wire.requestFrom(COLOR_SENSOR_ADDR, 3, 1);
  for (unsigned int i = 0; i < 3; ++i) {
    recv_value[i] = Wire.read();

  }
  RGB newColor = {recv_value[0], recv_value[1], recv_value[2]};
  
  colors[currentLight] = newColor;
  recordedColors[currentLight] = newColor;
}

void calculateWeightsFromRecordedColors() {
  std::vector<float> rgb1 = {recordedColors[0].r, recordedColors[0].g, recordedColors[0].b};
  std::vector<float> rgb2 = {recordedColors[1].r, recordedColors[1].g, recordedColors[1].b};
  std::vector<float> rgb3 = {recordedColors[2].r, recordedColors[2].g, recordedColors[2].b};
  std::vector<float> rgb_target = {recordedColors[3].r, recordedColors[3].g, recordedColors[3].b};

  std::vector<float> w = findWeights(rgb1, rgb2, rgb3, rgb_target);
  weights[0] = w[0];
  weights[1] = w[1];
  weights[2] = w[2];

  Serial.println(weights[0]);
  Serial.println(weights[1]);
  Serial.println(weights[2]);

}

void displayWeight() {
  static unsigned long previousMillis = 0;
  const unsigned long interval = 20;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    if (weights[0]>= -0.2 && weights[1]>= -0.2 && weights[2]>= -0.2 &&
      weights[0]<= 1.2 && weights[1]<= 1.2 && weights[2]<= 1.2 
    ){
      firstDigit();
      dot_1();
      int scaledValue = (int)(weights[currentLight] * 100);
      // Serial.println(scaledValue);
      secondDigit((scaledValue / 10) % 10);
      thridDigit(scaledValue % 10);
    } else {
      for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));
      pixels.show();
      delay(200);
      }
      ESP.restart();
    }
  }
}

void handleButtonPress() {
  int buttonValue = digitalRead(ButtonPin);

  if (buttonValue == LOW) {
    if (lastButtonValue == HIGH) {
      buttonPressStart = millis();
    }
    if (millis() - buttonPressStart > 1000) {
      isLongPress = true;
    }
  } else if (buttonValue == HIGH && lastButtonValue == LOW) {
    if (isLongPress) {
      handleLongPress();
    } else {
      handleShortPress();
    }
    isLongPress = false;
  }

  lastButtonValue = buttonValue;
}

void handleShortPress() {
  if (!secondLayerActive) {
    if (waitingForPress) {
      capture_color();
      pixels.setPixelColor(currentLight, pixels.Color(colors[currentLight].r,colors[currentLight].g,colors[currentLight].b));

      Serial.print("R: ");
      Serial.print(colors[currentLight].r);
      Serial.print(", G: ");
      Serial.print(colors[currentLight].g);
      Serial.print(", B: ");
      Serial.println(colors[currentLight].b);


      pixels.show();
      recordedColors[currentLight] = colors[currentLight];
      waitingForPress = false;
      delay(500);
      moveToNextLight();
    } else if (currentLight == NUMPIXELS - 1) {
      calculateWeightsFromRecordedColors();
      secondLayerActive = true;
      currentLight = 0;
      waitingForPress = true;
      dimAllExcept(currentLight);
      displayWeight();
    }
  } else {
    currentLight = (currentLight + 1) % 3;
    dimAllExcept(currentLight);
    displayWeight();
  }
}

void handleLongPress() {
  if (!secondLayerActive) {
    if (currentLight == NUMPIXELS - 1) {
      waitingForPress = true;
    } else if (currentLight > 0) {
      currentLight--;
      waitingForPress = true;
    }
    pixels.setPixelColor(currentLight, pixels.Color(colors[currentLight].r,colors[currentLight].g,colors[currentLight].b));
    pixels.show();
  }
}

void moveToNextLight() {
  if (currentLight < NUMPIXELS - 1) {
    currentLight++;
    waitingForPress = true;
  } else {
    waitingForPress = false;
  }
}

void blinkCurrentLight() {
  static unsigned long lastBlink = 0;
  static bool isOn = false;

  if (millis() - lastBlink > 500) {
    lastBlink = millis();
    isOn = !isOn;
    if (isOn) {
      pixels.setPixelColor(currentLight, pixels.Color(255, 255, 255));
    } else {
      pixels.setPixelColor(currentLight, 0);
    }
    pixels.show();
  }
}

void dimAllExcept(int activeLight) {
  for (int i = 0; i < NUMPIXELS; i++) {
    if (i == activeLight) {
      pixels.setPixelColor(i, pixels.Color(colors[i].r,colors[i].g,colors[i].b));
    } else {
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
  }
  pixels.show();
}












