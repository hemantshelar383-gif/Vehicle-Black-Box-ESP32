# Vehicle-Black-Box-ESP32
ESP32-based Vehicle Black Box system for accident detection, GPS tracking, SD card data logging, and automatic GSM emergency alerts.
🚗 ESP32 Vehicle Black Box System
Smart Accident Detection & Vehicle Data Logger
<p align="center"> <img src="https://img.shields.io/badge/ESP32-IoT-blue?style=for-the-badge"> <img src="https://img.shields.io/badge/Embedded-C%2FC%2B%2B-green?style=for-the-badge"> <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge"> </p>
4
📌 About the Project

The ESP32 Vehicle Black Box System is an embedded and IoT-based safety solution that continuously monitors vehicle parameters and records critical data during abnormal conditions such as accidents or sudden impacts.

Inspired by aircraft black boxes, this system helps in:

Accident investigation

Driver behavior analysis

Insurance claim verification

Improving road safety systems

This project is highly relevant for Embedded Systems, IoT, Automotive Electronics, and research-oriented applications.

✨ Features

🚨 Automatic accident detection using IMU

📍 Real-time GPS location tracking

📊 Vehicle motion & acceleration monitoring

🔔 Emergency alert using buzzer

📡 ESP32 Wi-Fi & Bluetooth support

🧠 Reliable data logging for post-accident analysis

🔋 Compact, low-power & cost-effective design

🛠️ Hardware Components
Component	Description
ESP32	Main microcontroller with Wi-Fi & BLE
IMU (MPU6050 / MPU9250)	Acceleration & tilt detection
GPS Module (NEO-6M)	Real-time vehicle location
Buzzer	Emergency alert
OLED / LCD (Optional)	Live data display
Power Supply	5V / Battery
💻 Software & Tools

Arduino IDE

ESP32 Board Package

Embedded C / C++

I2C, IMU & GPS Libraries

⚙️ Working Principle

Sensors continuously monitor vehicle motion

Sudden impact, rollover, or abnormal acceleration is detected

Vehicle speed, orientation & GPS location are recorded

Emergency alert is triggered

Stored data is used for post-accident analysis

📐 System Flow Diagram
IMU + GPS Sensors
        ↓
      ESP32
        ↓
 Accident Detection Logic
        ↓
 Alerts + Data Logging

🚀 Applications

🚗 Vehicle accident investigation

🛣️ Road safety systems

📊 Insurance claim verification

🚚 Fleet management systems

🎓 Academic & research projects

📂 Project Structure
ESP32-Vehicle-Black-Box/
│
├── Code/
│   └── main.ino
├── Circuit_Diagram/
├── Images/
├── Documents/
└── README.md

🔮 Future Enhancements

Cloud data storage (Firebase / AWS)

Mobile application integration

AI-based accident severity prediction

Camera & CAN bus integration

Emergency SMS / call automation

👨‍💻 Author

Hemant Shelar
🎓 Electronics & Telecommunication Engineering
💡 Embedded Systems | IoT | Robotics

🔗 LinkedIn:
https://www.linkedin.com/in/hemant-shelar-l07
