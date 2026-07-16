#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int C1 = A3;
const int C2 = 4;
const int C3 = 5;
const int C4 = 11;
const int C5 = 7;
const int C6 = 12;
const int C7 = A1;
const int C8 = A0;

const int R1 = 10;
const int R2 = A2;
const int R3 = 9;
const int R4 = 13;
const int R5 = 0;
const int R6 = 8;
const int R7 = 1;
const int R8 = 6;

const int BUTTON_PIN = 2;
const int TILT_SWITCH = 3;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int vibrationOutput;
bool gameStarted = false;
int lastButtonReading = HIGH; 
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void clearBoard() {
  // turns all the LEDs off at the start of the game  
  digitalWrite(R1,HIGH);
  digitalWrite(R2,HIGH);  
  digitalWrite(R3,HIGH);
  digitalWrite(R4,HIGH);
  digitalWrite(R5,HIGH);
  digitalWrite(R6,HIGH);
  digitalWrite(R7,HIGH);
  digitalWrite(R8,HIGH);
  digitalWrite(C1,LOW);
  digitalWrite(C2,LOW);
  digitalWrite(C3,LOW); 
  digitalWrite(C4,LOW);
  digitalWrite(C5,LOW);
  digitalWrite(C6,LOW);
  digitalWrite(C7,LOW);
  digitalWrite(C8,LOW);
}

void setup() {
  Wire.begin();

  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3,  OUTPUT);  
  pinMode(R4, OUTPUT);  
  pinMode(R5, OUTPUT); 
  pinMode(R6,  OUTPUT);
  pinMode(R7, OUTPUT);  
  pinMode(R8, OUTPUT);
  pinMode(C1,  OUTPUT);
  pinMode(C2, OUTPUT); 
  pinMode(C3, OUTPUT);
  pinMode(C4,  OUTPUT);
  pinMode(C5, OUTPUT);
  pinMode(C6, OUTPUT);
  pinMode(C7,  OUTPUT);
  pinMode(C8, OUTPUT);

  pinMode(TILT_SWITCH, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Press button to");
  lcd.setCursor(0, 1);
  lcd.print("start game!");

  //clearBoard();
}

void selectRow(int row) {
  if (row==1)  digitalWrite(R1,LOW); else digitalWrite(R1,HIGH);
  if (row==2) digitalWrite(R2,LOW);  else digitalWrite(R2,HIGH);
  if (row==3) digitalWrite(R3,LOW); else digitalWrite(R3,HIGH);
  if (row==4) digitalWrite(R4,LOW); else digitalWrite(R4,HIGH);
  if (row==5)  digitalWrite(R5,LOW); else digitalWrite(R5,HIGH);
  if (row==6) digitalWrite(R6,LOW);  else digitalWrite(R6,HIGH);
  if (row==7) digitalWrite(R7,LOW); else digitalWrite(R7,HIGH);
  if (row==8) digitalWrite(R8,LOW); else digitalWrite(R8,HIGH);
}

void  selectColumn(int column) {
  if (column==1) digitalWrite(C1,HIGH); else digitalWrite(C1,LOW);
  if (column==2) digitalWrite(C2,HIGH); else digitalWrite(C2,LOW);
  if (column==3)  digitalWrite(C3,HIGH); else digitalWrite(C3,LOW);
  if (column==4) digitalWrite(C4,HIGH);  else digitalWrite(C4,LOW);
  if (column==5) digitalWrite(C5,HIGH); else digitalWrite(C5,LOW);
  if (column==6) digitalWrite(C6,HIGH); else digitalWrite(C6,LOW);
  if (column==7)  digitalWrite(C7,HIGH); else digitalWrite(C7,LOW);  
  if (column==8) digitalWrite(C8,HIGH);  else digitalWrite(C8,LOW);
}

void loop() {
  vibrationOutput = digitalRead(TILT_SWITCH);

  if (vibrationOutput < 1022) {
  // I believe the sensor is lower than 1022 if the switch isn't tilting, but it's broken in the editor so there's no way to check
  }

  else {
    // tilting logic
  }

  delay(100);

  int buttonReading = digitalRead(BUTTON_PIN);

  if (buttonReading != lastButtonReading) {
    lastDebounceTime = millis();   // input changed, reset timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    static int buttonState = HIGH;
    if (buttonReading != buttonState) {
      buttonState = buttonReading;
      if (buttonState == LOW) {   // a press pulls the pin LOW
        gameStarted = true;
      }
    }
  }
  lastButtonReading = buttonReading;

  if (gameStarted == true) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Score: 0");
    lcd.setCursor(0, 1);
    lcd.print("High Score: 0");

    for (int i=1;i<9;i++)  {
      for (int j=1;j<9;j++) {
        clearBoard();
        selectRow(i);
        selectColumn(j);  
        delay(100);
      }
    }
  }
}