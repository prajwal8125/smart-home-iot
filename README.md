# 🏠 Smart Home IoT System

A Smart Home Automation System built using **ESP8266 NodeMCU**, **Firebase Realtime Database**, and an **Android application**. This project enables users to remotely control home appliances over the internet while also supporting manual physical switch control.

---____

# 📱 Features

- 🔌 Control up to 4 electrical appliances
- 📲 Android application for remote access
- ☁️ Firebase Realtime Database integration
- 📡 Real-time synchronization
- 🔄 Physical switches and mobile app work together
- 🌐 Control appliances from anywhere with internet access
- ⚡ Low-cost and energy-efficient solution

---

# 🚀 Technologies Used

| Category | Technology |
|-----------|------------|
| Mobile App | Java, Android Studio |
| Backend | Firebase Realtime Database |
| Hardware | ESP8266 NodeMCU |
| IDE | Arduino IDE |
| Communication | Wi-Fi |
| Version Control | Git & GitHub |

---

# 🔧 Hardware Components

- ESP8266 NodeMCU
- 4-Channel Relay Module
- Extension Board
- 4 Electrical Appliances (Bulbs/Fan)
- Physical Switches
- Jumper Wires
- Power Supply

---

# 📸 Project Screenshots

## Android Application

(Add Screenshot Here)

---

## Firebase Realtime Database

(Add Screenshot Here)

---

## Complete Hardware Setup

![Complete Setup](media/photos/final_setup.jpg)

---

## ESP8266 Wiring

![ESP8266 Wiring](media/photos/esp8266_wiring.jpg)

---

## Relay Module

![Relay Module](media/photos/relay_module.jpg)

---

# 🎥 Demo Video

Watch the project in action:

(Add YouTube or GitHub Video Link)

---

# 🏗️ System Architecture

```

Android App
│
│ Wi-Fi
▼
Firebase Realtime Database
│
│ Real-time Sync
▼
ESP8266 NodeMCU
│
│ GPIO Pins
▼
4-Channel Relay Module
│
▼
Home Appliances

```

---

# ⚙️ Working Process

1. User opens the Android application.
2. User toggles a switch.
3. App updates Firebase Realtime Database.
4. ESP8266 continuously listens for Firebase changes.
5. Relay module turns the appliance ON/OFF.
6. Manual switches also update appliance state.

---

# 📂 Project Structure

```

SmartHome-IoT/
│
├── Android-App/
│ ├── app/
│ └── ...
│
├── ESP8266-Code/
│ └── SmartHomeController.ino
│
├── media/
│ ├── photos/
│ └── videos/
│
├── diagram/
│ └── connection_diagram.png
│
├── README.md
└── LICENSE

```

---

# 🔥 Firebase Database Structure

```

Relay1 : "ON"
Relay2 : "OFF"
Relay3 : "OFF"
Relay4 : "ON"

```

---

# 🛠️ Installation Guide

## ESP8266

- Install Arduino IDE
- Install ESP8266 Board Package
- Install FirebaseESP8266 Library
- Open SmartHomeController.ino
- Add Wi-Fi credentials
- Add Firebase credentials
- Upload code

---

## Android App

- Open project in Android Studio
- Add google-services.json
- Sync Gradle
- Run the application

---

## Firebase

- Create Firebase Project
- Enable Realtime Database
- Create four nodes

```

Relay1
Relay2
Relay3
Relay4

```

---

# 💡 Future Improvements

- Voice Assistant Integration
- Google Assistant Support
- Alexa Integration
- Dark Mode
- Energy Consumption Monitoring
- Device Scheduling
- User Authentication
- Multiple Home Support

---

# 🎯 Learning Outcomes

Through this project I learned:

- Android Development
- Firebase Realtime Database
- ESP8266 Programming
- IoT System Design
- Hardware–Software Integration
- Real-time Cloud Communication
- Git & GitHub

---

# 👨‍💻 Developer

**Prajwal**

B.Tech Artificial Intelligence & Machine Learning

India

GitHub:  
https://github.com/prajwal8125   


hii india

---

# ⭐ If you found this project helpful

Please consider giving this repository a ⭐ on GitHub.
