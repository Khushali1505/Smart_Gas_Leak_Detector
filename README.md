# Smart Gas Leak Detector using ESP32 & Blynk

A smart IoT-based gas leak detection system built using ESP32, MQ-2 gas sensor, and Blynk.  
The system monitors gas levels in real time, dynamically calibrates thresholds, provides visual and audio alerts, and sends instant notifications to a mobile application over Wi-Fi.

---

## 📌 Project Motivation

The objective of this project was to design a practical safety system suitable for real home environments.  
The focus was on early gas leak detection and remote alerting by combining embedded systems with IoT-based communication.

---

## ⚙️ System Overview

- Real-time gas level monitoring using MQ-2 sensor  
- Dynamic baseline calibration during startup  
- Multi-level alert system (Safe / Warning / Danger)  
- RGB LED and buzzer alerts  
- Instant mobile notifications using Blynk over Wi-Fi  

---

## 🧩 Components Used

- ESP32 Development Board  
- MQ-2 Gas Sensor Module  
- RGB LED (Common Cathode)  
- Piezo Buzzer  
- Breadboard and Jumper Wires  
- USB Cable (Power & Programming)

🔗 DigiKey Component List:  
https://www.digikey.in/en/mylists/list/HZAQGU7QML

---

## 🔌 Circuit Description

- MQ-2 analog output connected to ESP32 ADC pin  
- RGB LED connected to GPIO pins through current-limiting resistors  
- Buzzer connected to GPIO pin for alert generation  
- ESP32 powered via USB  

Circuit images are available in the `circuit/` folder.

---

## 💻 Software Implementation

The ESP32 was programmed using Arduino IDE with ESP32 board support and Blynk libraries.

### Core Logic

- Reading analog gas sensor values  
- Baseline calculation during startup (clean air reference)  
- Dynamic threshold generation  
- Decision logic for safety levels  
- LED and buzzer control  
- Wi-Fi connectivity setup  
- Blynk cloud communication  
- Mobile notification trigger when gas exceeds danger threshold  

---

## 📱 Blynk Dashboard

The Blynk mobile application displays:

- Live gas sensor values  
- System status (Air Safe / Warning / Danger)  
- Threshold reference  

A Blynk event is configured to send push notifications when gas levels exceed the defined danger threshold.

---

## 🧪 Testing & Calibration

- Initial self-calibration performed in clean air  
- Threshold calculated relative to baseline value  
- Tested using controlled exposure to gas/smoke  
- Verified alert accuracy and notification reliability  

---

## 🚀 Future Improvements

- Add protective enclosure for real-world deployment  
- Integrate flame and temperature sensors  
- Implement cloud-based data logging  
- Improve alert logic with adaptive filtering  

---

## 📌 Key Learning Outcomes

- ADC data acquisition using ESP32  
- Sensor calibration techniques  
- Multi-level decision logic implementation  
- GPIO-based alert control  
- IoT integration using Blynk and Wi-Fi communication  
- Real-time remote monitoring system design  
