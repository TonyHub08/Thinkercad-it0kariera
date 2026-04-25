#include <LiquidCrystal.h>

// LCD pins: RS=7, E=8, D4=9, D5=10, D6=11, D7=12
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const int pirPin = 2;
const int ledPin = 13;
const int piezoPin = 5;

int lastState = LOW;

// simple “cartoon-style” melody
int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};

void playMelody() {
  for (int i = 0; i < 8; i++) {
    tone(piezoPin, melody[i]);
  }
}

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(piezoPin, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("BACHKA!");

  delay(2000);
  lcd.clear();
}

void loop() {
  int state = digitalRead(pirPin);
  delay(50); // stability for PIR

  if (state != lastState) {

    if (state == HIGH) {
      digitalWrite(ledPin, HIGH);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("MOVE BITCH!");

      playMelody();
    }
    else {
      digitalWrite(ledPin, LOW);
      noTone(piezoPin);

      lcd.clear();
      lcd.setCursor(0, 0);
    }

    lastState = state;
  }
}