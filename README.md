# Biomedical Monitoring System (Digital Twin using STM32)

**Full Academic Title:**  
Realtime Emergency Addressing and Improved Time Lagging CNN using Digital Twin Technology for E-Health using STM-32  

---

##  Overview
This project proposes a **real-time biomedical health monitoring system** that integrates **Digital Twin (DT) technology** with **IoT** and **Augmented Vision (AV)** to improve emergency patient treatment in hospital ICUs.

Each patient is assigned a unique **Digital Twin–based Augmented Vision (AV) code**, which provides doctors with a real-time view of the patient’s physiological state.  
The system enables **faster diagnosis, prioritized emergency treatment**, and improved decision-making in critical care environments.

---

##  System Description
When a patient is admitted to the hospital, they are equipped with wearable biomedical sensors that continuously measure:

- Body temperature  
- Respiratory rate  
- Pulse rate  

These signals are processed by the **STM32 microcontroller**, displayed on an **LCD**, and transmitted via an **IoT module (NodeMCU)** to a cloud database.  
Doctors can scan each patient’s **AV code** using an Android application. The **DT Vision Software System** fetches real-time data and visualizes it through 3D models —  
- 🟢 *Green*: Normal condition  
- 🟠 *Orange*: Moderate risk  
- 🔴 *Red*: Critical condition  

This allows the medical team to **prioritize patients based on real-time severity**.

---

##  Block Diagram

### Wearable Sensor Unit
![Block Diagram](Blockdiagram.png)  
*(Example diagram showing STM32, sensors, and IoT interface)*

---

##  Hardware Requirements
1. **STM32 Microcontroller**  
2. **Body Temperature Sensor**  
3. **Respiratory Sensor**  
4. **Pulse Sensor**  
5. **NodeMCU IoT Module**  
6. **Liquid Crystal Display (LCD)**  
7. **Alarm/Buzzer Unit**  
8. **Power Supply Unit**

---

##  Software Requirements
1. **STM32CubeIDE** – for code development and debugging  
2. **Hi-Tech Compiler** – for embedded C compilation  
3. **Embedded C Language** – firmware development  
4. **MATLAB / Simulink (optional)** – for data visualization or algorithm simulation  

---

##  Features
- Real-time biomedical signal acquisition and monitoring  
- IoT-based data upload to cloud for remote access  
- Digital Twin visualization for emergency prioritization  
- Augmented Vision (AV) code–based patient identification  
- Alarm generation for abnormal conditions  
- STM32-based efficient embedded processing  

---

##  Working Principle
1. Sensors collect body parameters and send analog data to STM32.  
2. The microcontroller processes and displays the data locally.  
3. Processed data is transmitted through **UART → NodeMCU → Cloud**.  
4. The hospital’s DT Vision software retrieves this data and displays 3D health visualization.  
5. Doctors can scan the patient’s **AV code** for instant Digital Twin updates.  

---

##  Applications
- ICU emergency patient monitoring  
- Real-time health tracking in hospitals  
- Remote medical diagnostics  
- Predictive healthcare analytics  

---

##  Future Enhancements
- Integration with **machine learning (CNN)** for predictive health analysis  
- Expansion to include **ECG and SpO₂ sensors**  
- Cloud-based analytics dashboard with patient history  
- Wireless BLE communication to reduce latency  

---

##  Developed By
**Sakthivel Balakumar**  
Embedded Systems Enthusiast | Firmware & Hardware Developer  

 bala2001kumar@gmail.com  
 [LinkedIn](https://linkedin.com/in/balakumar-sakthivel-4aba55210) | [GitHub](https://github.com/Bala200166)

---

##  License
This project is an independent personal work created for learning, research, and skill development in embedded systems.  
You are welcome to view and learn from the source code, but please provide credit if you reference or reuse any part of it.  
Commercial use or redistribution without permission is not allowed.

---


