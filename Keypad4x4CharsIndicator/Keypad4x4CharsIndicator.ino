#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


byte rowPins[ROWS] = {9, 8, 7, 6}; //Rows 0 to 3
byte colPins[COLS] = {5, 4, 3, 2}; //Columns 0 to 3

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
int LED_NUMBER = 12;
int LED_LETTER = 11;
int BUZZER_PIN = 10;
int delayValue = 1000; //1second default delay
int charIndex = 0;
char chars[] = "";
boolean state = false;
void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_NUMBER, OUTPUT);
  pinMode(LED_LETTER, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY) {
    Serial.print(key);
    switch (key) {
      case '#':
        lightUp();
        state = true;
        charIndex = 0;
        delayValue = 1000;
        clearValue();
        delay(2000);
        break;
      case '*':
        lightDown();
        state = false;
        charIndex = 0;
        clearValue();
        break;
      default:
        if (isDigit(key)) {
          chars[charIndex] =  key;
          charIndex++;
          charTypeIndicator(true);
        } else {
          delayValue = (int)chars;
          digitalWrite(LED_LETTER, HIGH);
          charTypeIndicator(false);
        }
        break;
    }
  } else {
    if (state == true) {
      lightUp();
      delay(delayValue);
      lightDown();
      delay(delayValue);
    } else {
      lightDown();
    }
  }

  digitalWrite(LED_NUMBER, LOW);
  digitalWrite(LED_LETTER, LOW);
  digitalWrite(BUZZER_PIN, LOW);
}

void lightUp() {
  //digitalWrite(BUZZER_PIN,HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
}

void lightDown() {
  digitalWrite(LED_BUILTIN, LOW);
  //digitalWrite(BUZZER_PIN,LOW);
}

void charTypeIndicator(boolean isDigitType) {
  digitalWrite(BUZZER_PIN, HIGH);
  if (isDigitType) {
    digitalWrite(LED_NUMBER, HIGH);
    digitalWrite(LED_LETTER, LOW);
    delay(50);
  } else {
    digitalWrite(LED_NUMBER, LOW);
    digitalWrite(LED_LETTER, HIGH);
    delay(100);
  }
  digitalWrite(BUZZER_PIN, LOW);
}

void clearValue() {
  memset(chars, 0, sizeof(chars));
}

