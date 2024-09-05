
# Animatronic-Hand-using-Arduino-UNO
This project uses the Arduino Uno R3 version of the microcontroller. It is integrated with Flex Sensors along with a piezo buzzer with different musical Key-tones

This project simulates an animatronic hand using Tinkercad. The hand is equipped with flex sensors that detect bending movements, and a piezo buzzer that produces different sounds based on the sensor inputs.

**Project Overview**
The animatronic hand is designed to replicate the movements of a human hand. It uses flex sensors to measure the degree of bending in each finger. When a sensor is stressed (i.e., when a finger bends), it sends a signal to the Arduino controller. The controller then triggers the piezo buzzer to emit a specific sound corresponding to the stressed sensor, creating an interactive response.

**Components Used**
Arduino UNO: Microcontroller to manage sensor inputs and output signals.
Flex Sensors: Sensors attached to the fingers of the hand to detect bending.
Piezo Buzzer: Generates different tones based on the input from the flex sensors.
Resistors: Used for current regulation with the flex sensors.
Jumper Wires: For making electrical connections.
Breadboard: To connect all components in a test setup.


**How It Works**
Flex Sensors: Each finger of the animatronic hand has a flex sensor attached. When a finger is bent, the corresponding flex sensor changes its resistance.
Arduino UNO: Reads the input from the flex sensors and processes it.
Piezo Buzzer: Depending on the resistance value from the stressed flex sensor, the Arduino UNO triggers the piezo buzzer to produce a different tone.


![Screenshot 2024-09-05 212023](https://github.com/user-attachments/assets/4d6831f6-3ca8-4437-9e86-fc6ddd6d0125)



