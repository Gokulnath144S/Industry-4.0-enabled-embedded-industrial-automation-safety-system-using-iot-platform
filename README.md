# Industry-4.0-enabled-embedded-industrial-automation-safety-system-using-iot-platform
An Industry 4.0-based smart automation system integrating an LPC2129 microcontroller with Arduino IoT Cloud for real-time industrial monitoring and remote actuator control.  This project demonstrates a scalable cyber-physical system where industrial devices are controlled via cloud dashboard while temperature data is processed at the edge.

🧠 Project Highlights
✔ Edge-to-Cloud Industrial Automation
✔ Real-Time Temperature Monitoring (SPI ADC)
✔ Bidirectional UART Communication
✔ Cloud-Controlled Actuator Switching
✔ Threshold-Based Intelligent Automation
✔ LCD-Based Live System Feedback

🏗 Architecture Overview
Cloud Dashboard (Arduino IoT Cloud)
↓
ESP IoT Module
↓ UART
LPC21xx (Edge Controller)
↓
Industrial Loads (Fan, Light, Conveyor, Buzzer)
↑
SPI ADC (Temperature Sensor)

⚙ Technical Implementation
Developed Embedded C firmware for LPC21xx.
Implemented SPI-based ADC temperature acquisition.
Designed UART-based communication protocol for device control.
Integrated Arduino IoT Cloud READ_WRITE variables for real-time control.
Implemented threshold-based automation logic for LED status indication.
Designed modular driver interfaces (SPI, UART, LCD).

🔄 Command Protocol
Device	  ON	 OFF
Fan       a	   b
Light	    c	   d
Buzzer  	e    f
Conveyor  g	   h

🛠 Technologies Used
Embedded C
LPC21xx Microcontroller
Arduino IoT Cloud
UART Communication
SPI Communication
IoT Dashboard Integration

📊 Industry 4.0 Concepts Implemented
$Cyber-Physical Systems (CPS)
$Smart Manufacturing
$Edge Computing
$Cloud-Based Remote Control
$Real-Time Monitoring Systems

🚀 Future Scope
$MQTT-based scalable communication
$Data logging & analytics dashboard
$Predictive maintenance integration
$Industrial safety interlock systems
