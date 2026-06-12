# Smart Home IoT System

## Overview
4-relay smart home controller using ESP8266,
Firebase Realtime Database and Android app.

---

## Hardware Photos

### Complete Setup
![Complete Setup](media/photos/final_setup.jpg)

### ESP8266 Wiring
![ESP8266 Wiring](media/photos/esp8266_wiring.jpg)

### Relay Module Connection
![Relay Module](media/photos/relay_module.jpg)

### Extension Board
![Extension Board](media/photos/extension_board.jpg)

---

## Demo Video

### Phone controlling fan
https://github.com/YOUR_USERNAME/smart-home-iot/
raw/main/media/videos/demo_phone_control.mp4

---

## Connection Diagram
![Connection Diagram](diagram/connection_diagram.png)

---

## Features
- Control 4 appliances from Android app
- Physical switches work independently
- Staircase logic
- Firebase realtime sync

## Hardware Used
- ESP8266 NodeMCU
- 4 Channel Relay Module
- Extension board with 4 switches
- Android phone

## Tech Stack
| Part | Technology |
|---|---|
| Microcontroller | ESP8266 NodeMCU |
| Cloud | Firebase Realtime DB |
| Mobile App | Android Java |
| Protocol | WiFi |

## Circuit Connection
![Diagram](diagram/connection_diagram.png)

## How to Setup

### ESP8266
1. Install Arduino IDE
2. Install ESP8266 board
3. Install FirebaseESP8266 by Mobizt
4. Open arduino/smart_home.ino
5. Fill WiFi and Firebase credentials
6. Upload to ESP8266

### Android App
1. Open android/ in Android Studio
2. Add your google-services.json
3. Build and run

### Firebase
1. Create Firebase project
2. Enable Realtime Database
3. Create nodes:
   relay1 / relay2 / relay3 / relay4

## Project by
Your Name
College Name
Date: June 2026