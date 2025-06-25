# 📡 433 MHz RF Communication: Raspberry Pi Pico → Arduino Uno
This project demonstrates wireless data transmission using a Raspberry Pi Pico (transmitter) and Arduino Uno (receiver) over low-cost 433 MHz RF modules. Messages are encoded bit-by-bit on the Pico in MicroPython, sent over the air, decoded on the Arduino, and printed to the Serial Monitor.

## 🧰 Hardware Required
- Raspberry Pi Pico (Transmitter)
- Arduino Uno (Receiver)
- 433 MHz RF Transmitter and Receiver modules
- Jumper wires
- Breadboard (optional)
- ~17 cm antenna wires for improved signal range

## 🚀 Getting Started
📤 Transmitter (Raspberry Pi Pico + MicroPython)
- Install MicroPython on Pico
- Download the .uf2 from the MicroPython Pico page
- Hold down BOOTSEL while plugging in the Pico
- Drag the .uf2 file onto the "RPI-RP2" drive
- Upload the Code
- Use Thonny IDE
- Connect the transmitter module’s data pin to GPIO 7
- Load this MicroPython code

📥 Receiver (Arduino Uno)
- Connect RF Receiver
- Data pin to Digital Pin 7
- VCC to 5V, GND to GND
- Upload the Code
const int rfPin = 7;
String message = "";
byte receivedByte = 0;
int bitCount = 0;

# Schematics for wiring:
![image](https://github.com/user-attachments/assets/a64ae5fa-f17e-4ca3-850b-9c7da34f0fd5)

