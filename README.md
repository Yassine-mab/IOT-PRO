# 🌱 Smart Plant Watering System

An automated plant watering system built with Arduino Uno, simulated in Tinkercad. This project is part of the **Internet of Things (IoT) - S6** module at the Faculté Polydisciplinaire de Ouarzazate.

---

## 📋 Description

The Smart Plant Watering System continuously monitors soil moisture and temperature, then automatically activates a water pump when the soil is too dry. It provides real-time feedback through an LCD display, LED indicators, and a buzzer.

---

## ⚙️ Components

| Component | Quantity | Role |
|---|---|---|
| Arduino Uno R3 | 1 | Main microcontroller |
| Soil Moisture Sensor | 1 | Detects soil humidity |
| TMP36 Temperature Sensor | 1 | Monitors temperature |
| LCD 16x2 I2C (PCF8574) | 1 | Displays status and readings |
| Red LED | 1 | DRY state indicator |
| Yellow LED | 1 | WET state indicator |
| Blue LED | 1 | MEDIUM state indicator |
| 220Ω Resistors | 3 | Current limiting for LEDs |
| Piezo Buzzer | 1 | Audio alert when soil is dry |

---

## 🔌 Wiring

| Component | Pin | Arduino |
|---|---|---|
| Soil Moisture Sensor | SIG | A0 |
| Soil Moisture Sensor | VCC | 5V |
| Soil Moisture Sensor | GND | GND |
| TMP36 | VOUT | A1 |
| TMP36 | POWER | 5V |
| TMP36 | GND | GND |
| LCD I2C | SDA | A4 |
| LCD I2C | SCL | A5 |
| LCD I2C | VCC | 5V |
| LCD I2C | GND | GND |
| Red LED | Anode | Pin 11 (~PWM) |
| Green LED | Anode | Pin 10 (~PWM) |
| Yellow LED | Anode | Pin 9 (~PWM) |
| Buzzer | + | Pin 6 |

---

## 🚦 System States

| State | Moisture Value | LED | Buzzer | Action |
|---|---|---|---|---|
| DRY | < 300 | 🔴 Red | ON | Pump runs 5s, pauses 3s |
| MEDIUM | 300 – 600 | 🟡 Yellow | OFF | Warning displayed |
| WET | ≥ 600 | 🟢 Green | OFF | Pump OFF |

---

## 📺 LCD Display

```
Line 1: M:234  T:28C
Line 2: DRY - Pump ON  Cnt:3
```

- **M** = Soil moisture value (0–1023)
- **T** = Temperature in Celsius
- **Cnt** = Total number of pump activations

---

## 📁 Project Structure

```
smart-plant-watering/
│
├── smart_plant_watering.ino   ← Arduino source code
├── smart_plant_watering.brd   ← Tinkercad circuit diagram
├── report/
│   └── Smart_Plant_Watering_Report.docx
└── README.md
```

---

## 🛠️ Libraries Used

- `LiquidCrystal_I2C` — for the I2C LCD display


---

## 👨‍💻 Authors

- MABCHOUR Yassine

**Supervised by:** Prof. Abdelbasset Boukdir  
**Academic Year:** 2025 – 2026  
**Institution:** Faculté Polydisciplinaire de Ouarzazate
