#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

int moisturePin = A0;
int tempPin     = A1;
int redLED      = 11;
int yellowLED   = 10;
int blueLED     = 9;
int buzzer      = 6;

int moistureValue = 0;
int dryThreshold  = 300;
int wetThreshold  = 600;
int pumpCount     = 0;
bool wasPumping   = false;

float readTemperature() {
  int raw = analogRead(tempPin);
  float voltage = raw * 5.0 / 1024.0;
  float temp = (voltage - 0.5) * 100.0;
  return temp;
}

void allLEDsOff() {
  digitalWrite(redLED,    LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(blueLED,   LOW);
}

void setup() {
  pinMode(redLED,    OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(blueLED,   OUTPUT);
  pinMode(buzzer,    OUTPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Plant Watering");
  lcd.setCursor(0, 1);
  lcd.print("System Ready!");
  delay(2000);
  lcd.clear();
}

void loop() {
  moistureValue = analogRead(moisturePin);
  float temp    = readTemperature();

  Serial.print("Moisture: ");
  Serial.print(moistureValue);
  Serial.print(" | Temp: ");
  Serial.print(temp);
  Serial.print("C | Pump count: ");
  Serial.println(pumpCount);

  lcd.setCursor(0, 0);
  lcd.print("M:");
  lcd.print(moistureValue);
  lcd.print(" T:");
  lcd.print((int)temp);
  lcd.print("C   ");

  if (moistureValue < dryThreshold) {

    if (!wasPumping) {
      pumpCount++;
      wasPumping = true;
    }

    // DRY → Red ON
    allLEDsOff();
    digitalWrite(redLED, HIGH);
    tone(buzzer, 1000);

    lcd.setCursor(0, 1);
    lcd.print("DRY Cnt:");
    lcd.print(pumpCount);
    lcd.print("        ");

    Serial.println("Status: DRY - Pump ON");
    delay(5000);

    allLEDsOff();
    noTone(buzzer);
    lcd.setCursor(0, 1);
    lcd.print("Pump paused...  ");
    delay(3000);

  } else if (moistureValue < wetThreshold) {

    wasPumping = false;

    // MEDIUM → Blue ON (swapped)
    allLEDsOff();
    digitalWrite(blueLED, HIGH);
    noTone(buzzer);

    lcd.setCursor(0, 1);
    lcd.print("MEDIUM-Warning  ");

    Serial.println("Status: MEDIUM - Warning");
    delay(1000);

  } else {

    wasPumping = false;

    // WET → Yellow ON (swapped)
    allLEDsOff();
    digitalWrite(yellowLED, HIGH);
    noTone(buzzer);

    lcd.setCursor(0, 1);
    lcd.print("WET  Cnt:");
    lcd.print(pumpCount);
    lcd.print("     ");

    Serial.println("Status: WET - Pump OFF");
    delay(1000);
  }
}