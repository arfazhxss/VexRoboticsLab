# VEX Robotics Project: RobotC Documentation
## Overview

This repository contains the RobotC programs developed for the **VEX Robotics Project** as part of the **ENGR120 Design II: Vex Robotics** course at the University of Victoria. The project focused on designing and programming a VEX robot capable of performing various tasks, including mechanical, electrical, and sensor-based operations.

---

## Project Details
    ENGR120 Design II : VexRobotics 
    Paisley Kerstens, Aleksia Loewen, Arfaz Hussain
    Spring 2022, University Of Victoria
    

   https://user-images.githubusercontent.com/84450659/237013506-dfff451c-4819-4770-a55f-265a7dff83a3.mp4

---

## Robot Files

### Files
| File                        | Description                                                                                                                                     |
|-----------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------|
| `milestone_one.c`            | Tests basic mechanical functionalities such as forward movement and turning.                                                                    |
| `milestone_one_objplacement.c` | Tests the robot's ability to place objects using a motorized mechanism.                                                                         |
| `m2test1.c`                  | Tests IR sensor-based object detection and stopping logic.                                                                                      |
| `m2test2.c`                  | Enhanced IR detection with blinking LED feedback.                                                                                               |
| `m2test3.c`                  | Integrates sonar sensors and limit switches for obstacle detection and avoidance.                                                                |
| `InfraredSensorTest.c`       | Final test for IR sensors and light source detection with LED feedback.                                                                         |
| `robot.c`                    | Final demonstration code, integrating all mechanical and electrical tests into a single program.                                                 |

---

## Milestone Programs

### 1. `milestone_one.c`: Mechanical Test

**Objective**: Test basic mechanical functionality such as moving forward and turning.

- **Functions**:
  - `moveForward()`: Moves the robot forward for a set duration.
  - `turnRight()`: Rotates the robot to the right.
  
- **Control Logic**: 
  - Press `buttonToMove` to move forward.
  - Press `buttonToTurn` to rotate right.

---

### 2. `milestone_one_objplacement.c`: Object Placement Test

**Objective**: Test object placement capabilities using an upper motor.

- **Functions**:
  - `objectPlacement()`: Activates the motor to place the object.
  - `objectPlacementReverse()`: Reverses the motor to reset the placement mechanism.
  
- **Control Logic**:
  - Press `buttonMain` to place the object.
  - Press `buttonReverse` to reverse the placement mechanism.

---

### 3. `m2test1.c`: Electrical Test 1 - IR Sensor Test

**Objective**: Detect objects using IR sensors and stop the robot when a detected object crosses a specified threshold.

- **Threshold**: `thresholdSensorValue = 1000`

- **Functions**:
  - `Stop()`: Stops the robot.
  - `moveAround()`: Rotates the robot to scan for objects.

- **Control Logic**:
  - The robot moves until an object is detected (sensor value < threshold), at which point it stops and triggers an LED signal.

---

### 4. `m2test2.c`: Electrical Test 2 - Enhanced IR Detection

**Objective**: Enhance object detection using IR sensors and provide visual feedback with LEDs.

- **Functions**:
  - `DistanceDetection()`: Blinks the red LED to indicate detection readiness.
  - `Stop()`: Stops the robot’s movement.
  - `moveAround()`: Rotates the robot.

- **Control Logic**:
  - When an object is detected (sensor value < threshold), the robot stops and blinks the red LED as feedback.

---

### 5. `m2test3.c`: Electrical Test 3 - Sonar and Limit Switch Detection

**Objective**: Use sonar sensors and limit switches for obstacle detection and avoidance.

- **Functions**:
  - `moveTo()`: Moves the robot forward.
  - `moveBack()`: Moves the robot backward when an obstacle is detected.
  - `moveAround()`: Rotates the robot.

- **Control Logic**:
  - The robot approaches a target until it detects an object within 20 cm or triggers a limit switch, causing it to back up and adjust course.

---

### 6. `InfraredSensorTest.c`: Final Signal Test

**Objective**: Test the IR sensors and LED feedback mechanisms for light source detection.

- **Functions**:
  - `firstSignalTest()`: Blinks both red and green LEDs to indicate the start of the detection process.
  - `SourceDetectionSignal()`: Alternates red and green LEDs during object detection.
  - `TargetFixed()`: Turns on the green LED when the target is located.
  - `AllOn()`, `AllOff()`: Turns both LEDs on or off.
  - `moveTo()`, `moveBack()`, `moveAround()`: Controls robot movement based on detected signals.

- **Control Logic**:
  - The robot scans for a light source and moves toward it. Upon detecting an object within 5 cm, it stops, and the green LED signals success.

---

### 7. `robot.c`: Final Demonstration Code

**Objective**: Combine all mechanical and electrical functionalities into a single program for the final demonstration.

- **Features**:
  - Object detection via IR and sonar sensors.
  - Object placement using motor control.
  - Full movement capabilities (forward, backward, turning).
  - LED feedback for visual signaling.
  - Obstacle avoidance using sonar and limit switches.

---

## Installation and Usage

1. **Clone the repository**:
   ```bash
   git clone https://github.com/username/vex-robotics-project.git
2. **Open RobotC**:
   - Launch the RobotC IDE and open the `.c` files from the repository.
  
3. **Load Code onto the VEX Robot**:
   - Compile and download the programs onto the VEX robot.
  
4. **Run the Tests**:
   - Test each milestone individually to verify functionality before running the final demonstration code (`robot.c`).

---

## Hardware and Software Requirements

### Hardware
- VEX EDR Robot Kit
- IR Sensors
- Sonar Sensors
- Limit Switches
- LEDs

### Software
- RobotC IDE (compatible with VEX Robotics kits)
- Git for version control

---

## Final Demonstration

This project demonstrates the integration of mechanical and electrical systems using a VEX robotics platform. The final robot successfully performs tasks such as movement, object detection, and placement, obstacle avoidance, and visual signaling. Each milestone contributed to refining the robot’s functionality and ensured that the project goals were met.

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
```
