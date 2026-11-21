# Smart Cleaning Robot

An Arduino-based autonomous cleaning robot that uses ultrasonic sensors for obstacle detection and automatically changes its direction based on the available space.

## Project Overview

The Smart Cleaning Robot is an autonomous robotic vehicle designed to move through an environment while detecting obstacles in its path.

The robot uses three HC-SR04 ultrasonic sensors to measure the distance in front, left, and right directions. An Arduino processes these distance measurements and controls the DC motors through an L298N motor driver.

The robot moves forward when the path is clear. When an obstacle is detected within a specified distance, the robot stops, compares the left and right distances, and turns toward the side with more available space.

## Objective

- Develop an autonomous obstacle-avoiding robot.
- Detect obstacles using ultrasonic sensors.
- Control DC motors using an L298N motor driver.
- Implement basic decision-making using Arduino C++.
- Integrate an ESC and BLDC motor for the cleaning mechanism.

## Components

### Hardware

- Arduino
- 3 × HC-SR04 Ultrasonic Sensors
- L298N Motor Driver
- 2 × DC Motors
- BLDC Motor
- ESC
- IR Sensor
- Battery
- Robot chassis
- Wheels

### Software

- Arduino IDE
- Arduino C++
- Serial Monitor

## Hardware Connections

| Component | Arduino Pin |
|---|---:|
| Front Ultrasonic Trig | D2 |
| Front Ultrasonic Echo | D3 |
| Right Ultrasonic Trig | D4 |
| Right Ultrasonic Echo | D5 |
| Left Ultrasonic Trig | D6 |
| Left Ultrasonic Echo | D7 |
| IR Sensor | D8 |
| L298N IN1 | D9 |
| L298N IN2 | D10 |
| L298N IN3 | D11 |
| L298N IN4 | D12 |
| ESC Signal | D13 |

## Working Principle

The robot continuously measures the distance from three directions:

```text
             Front
           HC-SR04
               |
               ↓
        +---------------+
        |               |
 Left → |     Robot     | ← Right
        |               |
        +---------------+
```

### Navigation Logic

```text
Start
  ↓
Read Front Distance
  ↓
Is Front Distance > 15 cm?
  │
  ├── Yes → Move Forward
  │
  └── No
       ↓
    Stop Robot
       ↓
 Compare Left and Right
       ↓
 Turn toward the side
 with more free space
       ↓
 Continue sensing
```

## Algorithm

1. Initialize ultrasonic sensors, IR sensor, motor driver, Serial communication, and ESC.
2. Measure the distance from the front ultrasonic sensor.
3. Measure the distance from the right ultrasonic sensor.
4. Measure the distance from the left ultrasonic sensor.
5. Display the measured distances on the Serial Monitor.
6. If the front distance is greater than 15 cm, move forward.
7. If the front distance is 15 cm or less, stop the motors.
8. Compare the left and right distances.
9. Turn toward the side with more available space.
10. Continue the process continuously.

## Motor Control

The robot uses four motor-control signals connected to the L298N motor driver.

### Forward

```text
IN1 = HIGH
IN2 = LOW
IN3 = HIGH
IN4 = LOW
```

### Left Turn

```text
IN1 = HIGH
IN2 = LOW
IN3 = LOW
IN4 = HIGH
```

### Right Turn

```text
IN1 = LOW
IN2 = HIGH
IN3 = HIGH
IN4 = LOW
```

### Stop

```text
IN1 = LOW
IN2 = LOW
IN3 = LOW
IN4 = LOW
```

## Features

- Autonomous obstacle detection
- Three-direction distance sensing
- Automatic forward movement
- Automatic left/right direction selection
- DC motor control using L298N
- Serial Monitor distance monitoring
- ESC interface for BLDC motor

## Future Improvements

- Add Bluetooth-based manual control.
- Add a more advanced obstacle-avoidance algorithm.
- Control cleaning motor speed using the ESC.
- Add battery-level monitoring.
- Add Wi-Fi/IoT monitoring using ESP32.
- Improve navigation using additional sensors.
- Add automatic cleaning-path planning.

## Skills Demonstrated

- Arduino C++
- Embedded programming
- GPIO control
- Ultrasonic sensor interfacing
- Motor driver interfacing
- DC motor control
- ESC interfacing
- Sensor-based decision making
- Serial communication
- Hardware debugging

