Smart Gas Leak Detector using ESP32 & Blynk

A smart IoT-based gas leak detection system built using ESP32, MQ-2 gas sensor, and Blynk.
The system monitors gas levels in real time, dynamically calibrates thresholds, provides visual and audio alerts, and sends instant notifications to a mobile application over Wi-Fi.

📌 Project Motivation

I wanted to build a small but practical safety project that could be used in a real home environment.
This project focuses on early gas leak detection and remote alerting, combining embedded systems with IoT-based communication.

⚙️ System Overview

Real-time gas level monitoring using MQ-2 sensor
Dynamic baseline calibration in clean air
Multi-level alert system (Safe / Warning / Danger)
RGB LED and buzzer alerts
Instant mobile notifications using Blynk over Wi-Fi

🧩 Components Used

ESP32 Development Board
MQ-2 Gas Sensor Module
RGB LED (Common Cathode)
Piezo Buzzer
Breadboard and Jumper Wires
USB Cable (Power & Programming)

🔗 DigiKey Component List:
https://www.digikey.in/en/mylists/list/HZAQGU7QML

🔌 Circuit Description

MQ-2 analog output connected to ESP32 ADC pin
RGB LED connected via current-limiting resistors to GPIO pins
Buzzer connected to GPIO pin for alert generation
ESP32 powered via USB
Circuit images are available in the circuit/ folder.

💻 Software Implementation

The ESP32 is programmed using Arduino IDE with ESP32 board support and Blynk libraries.

Core logic includes:
Reading analog sensor values
Baseline calculation during startup
Dynamic threshold generation
Decision logic for safety levels
LED and buzzer control
Wi-Fi and Blynk cloud communication
Mobile notification trigger on gas detection

📱 Blynk Dashboard

The Blynk app displays:
Live gas sensor values
System status (Air Safe / Warning / Danger)
Threshold reference
A Blynk event is configured to send notifications when gas levels exceed the danger threshold.

🧪 Testing & Calibration

Initial self-calibration performed in clean air
Threshold set relative to baseline value
Tested using controlled exposure to gas/smoke
Verified alert accuracy and notification reliability
 
