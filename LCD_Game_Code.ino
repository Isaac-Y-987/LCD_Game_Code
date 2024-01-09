#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 6, 7, 8, 9);
int currentX = 0; //This is the current x position of the joystick
int currentY = 0; //This is the current x position of the joystick
int cursorX = 0; //This is the current x position of the character
int cursorY = 0; //This is the current x position of the character
const int switchPin = 12;
const int xPin = A0;
const int yPin = A1;
void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  lcd.print("Move the X with joystick");
  delay(1000);
  lcd.clear();
  lcd.setCursor(cursorX, cursorY);
  lcd.print("X");
}

void loop() {
  // put your main code here, to run repeatedly:
  int currentx = analogRead(xPin);
  int currenty = analogRead(yPin);
  if (currentX < 400) {
    if (cursorX > 0) {
      cursorX -= 1;
    }
  }
  if (currentX > 600) {
    if (cursorX < 15) {
      cursorX += 1;
    }
  }
  if (currentY < 400) {
    if (cursorY > 0) {
      cursorY -= 1;
    }
  }
  if (currentY > 600) {
    if (cursorY < 1) {
      cursorY += 1;
    }
  }

  if (digitalRead(switchPin) == LOW) {
    int cursorX = 0;
    int cursorY = 0;
  }
  lcd.clear();
  lcd.setCursor(cursorX, cursorY);
  lcd.print("X");
  delay(100);
}
