INTRODUCTION
====

We are the members of team Supernova. We are a part of the Robotronics Club of Ahmedabad dedicated to supporting and nurturing the growth of future innovators and leaders. We have a well-equipped engineering room supported by experienced teachers and mentors. With strong focus on STEM education, allowing us to push the boundaries of robotic innovation. Together having different skillsets, we have been able to put together this robot for the WRO competition.

## ABOUT THE TEAM

[Kreneal Shah - Grade 12]
 As the teams most experienced member, Kreneal brings strong leadership and extensive experience in robotics he has been fascinated with robots since a young age. He has competed in several WRO’s. He has created and patented the Robomarine an underwater ROV.

[Dhvanil Shah - Grade 10]
 Dhvanil is the hardware and Creo expert, responsible for designing and executing the chassis and circuitry of the bot. With prior involvement and victories in STEM competitions he ensures that the robot is efficient and easy to use. He brings lively spirit, bringing the machine to life. 

[Nisheel Patel - Grade 9] 
 Nisheel may be the youngest, but brings fresh ideas and enthusiasm. Specializing in electronics and sensor integration, he manages the teams GitHub repository. He too has participated in various robotics competitions, emerging victorious , bringing about the team spirit.


ENGINEERING PROCESSES
====
## Processes and Electricals

In this project, the ESP32 microcontroller will make up the central processing part of your control system. The sensor inputs are kept in mind along with the controlling of the motors that drive your robot. The ESP32 is a highly capable microcontroller that is assigned work to collect information from the three VL53L0X Time-of-Flight (ToF) sensors, mounted on the sides and front parts of the robot. There are laser sensors that are installed on the front, left, and right sides of the chassis. Such sensors provide the robot with the fundamental distance measurements since they emit a laser pulse and calculate the time taken before the light bounces back. From this data, the robot determines the distance, hence it keeps detecting objects in real-time. I2C bus is used for connecting the sensors to ESP32. Separate addresses have been assigned to each sensor to avoid conflictions during data retrieval from the sensors. The ESP32 processes the returned data from the sensors and makes critical decisions regarding the robot’s movements, based on the nearness of detected obstacles. If the microcontroller detects any object within a particular range, it can give commands to the motors, steering left or right and thus continue navigation without collision.

Concerning movement, the robot's motor driver control is essential for governing motion through a TB6612 motor driver. The ESP32 sends PWM signals to the motor driver to control speed and direction of the motors. The ESP32 can modulate the cycle of the PWM signals precisely to measure the speed at which the motors rotate to move forward, reverse, or make turns. The motor driver is  efficient enough to handle the current and voltage supplied by the motors' demands to ensure smooth performance. A 7.4V lithium-ion battery supplies adequate power to the motor driver, motors, and other parts. This battery is strong enough to supply the motors with the required voltage-to-function in a way that eliminates power failures, thus offering a steady power supply towards the ESP32 and the rest of the system. It is made in a way that the lifespan is sufficient for robots to operate for certain periods without having to recharge the battery.

We have used the Raspberry Pi 4 which brings a lot of brainpowers to the robot the higher processing tasks that go beyond simple motion and obstacle detection. In essence, the Raspberry Pi acts as the brain of the robot- dealing with complex decision making at higher levels, most especially in terms of image processing and complex navigation. It is connected to the PiCamera2, which captures live video as well as live images from the robot's surroundings. This camera is essential in enabling the robot to function by giving it the capability of achieving many tasks such as object recognition, visual tracking. The Raspberry Pi further processes the images using libraries such as OpenCV for functions that includes detection of objects, paths, or lines drawn on the ground. After processing the visual data, it communicates the instructions meant for navigation to ESP32 through serial communication.  This system allows the robot to have intelligent responses to its environment rather than mere response to sensor data.

The PiCamera2 module used is especially designed for the Raspberry Pi and supports advanced imaging and video captures. Mounted to the front of the robot, it gives a view of its surroundings and captures frames that the Raspberry Pi can analyse for tasks such as identifying objects or following lines. This operation of real-time processing enables the robot to adapt to dynamic environments, allowing it to make decisions between visual data and sensor data. The Raspberry Pi draws its power from its own power system, which should be taken from the output of a voltage regulator attached to the lithium-ion battery. This way, the robot should not draw too much power from the battery and ensures a stable power supply for the Pi and other peripherals on the robot.

All these components are securely mounted on the robot's chassis, the design of which balances functionality and balance. The chassis provides a robust foundation for the motors, sensors, battery, and electronics, providing each part with ample support and protection when in use. There are sensors placed along the sides of the robot for sufficient detection of obstacles surrounding the robot, while the PiCamera2 provides an unobstructed view for visual data. The mounting arrangement of the electronics has been done without any interference to each other, thus making smooth communication between the ESP32 and the Raspberry Pi and the rest of the electronics.

The system integrations allow this robot to independently operate by way of combining real-time sensor data handled by the ESP32 and the Raspberry Pi's image processing capabilities. This would signify that the lower-level tasks like speed control and direction of motors are taken care of by ESP32, while at the same time, the Raspberry Pi will be able to carry out high-level decision making, like processing visual data through the PiCamera2 to detect objects . It will enable the robot to dynamically respond to sensor and visual input, changing behaviour to navigate through complex environments by being able to communicate between Raspberry Pi and ESP32. Together, these components provide a highly efficient and autonomous operating system for the robot, capable of conducting high-level tasks in real-time.

It will make it a strong and flexible robot which is able to perform complex actions of various types through this hardware control and high-level processing. Such kinds of robots can very well change and adapt to its surroundings, wether it is navigating an obstacle course, or detecting objects crossing its pathway. In all aspects, the design ensures the smooth functioning of all components leads maximum efficiency and functionality for smooth and self-directed running.

ELECTRICAL COMPONENTS
====
•	EV3 Chassis

•	ESP32

•	Raspberry Pi4

•	Vl53l1x (ToF) Sensor

•	TB6612FNG Motor Driver

•	7.4V Battery

•	Raspberry Pi Camera V2

## EV3 Chassis
The EV3 chassis is a modular and sturdy framework designed primarily for use in robotics projects. It is part of the LEGO Mindstorms series, which allows for versatile construction and easy reconfiguration. The chassis can be fitted with multiple components, such as motors and sensors, to suit specific tasks. Its lightweight yet robust design makes it an ideal base for mobile robots, providing both stability and flexibility. The ability to easily attach or detach parts allows for quick modifications, which is particularly useful during testing and development phases.

## VL53L1X Distance Sensors
The VL53L1X is a time-of-flight laser-ranging sensor that measures the distance between the sensor and an object. Unlike traditional infrared sensors, the VL53L1X uses laser pulses to measure distances with high accuracy over a long range, even in low-light conditions. This sensor is crucial for wall-following, as it can sense distances up to 4 meters. It provides reliable distance data to the robot’s controller, allowing for smooth navigation and precise adjustments in tight spaces. Additionally, its compact size makes it easy to integrate into small or complex designs without taking up much space. 

## Raspberry Pi 4
The Raspberry Pi 4 is a powerful and versatile single-board computer (SBC) that serves as the brain of our robot. It is equipped with a quad-core ARM Cortex-A72 processor, 4 GB of RAM, and multiple USB and GPIO ports, making it capable of handling complex tasks such as image processing, sensor fusion, and motor control. In your robot, the Raspberry Pi 4 processes the data from the VL53L1X sensors and the Raspberry Pi Camera V2, making real-time decisions about movement and obstacle avoidance. Its ability to run full-fledged operating systems like Raspberry Pi OS allows for easy programming and integration of various libraries for computer vision and robotics applications.

## Raspberry Pi Camera V2
The Raspberry Pi Camera V2 is a high-resolution camera module that provides the robot with the ability to see and interpret its surroundings. Featuring an 8-megapixel sensor, it captures high-quality images that the Raspberry Pi can use for color detection and object recognition. In our setup, the camera is crucial for detecting red and green obstacles, which guide the robot’s turns. The camera supports video capture at 1080p, allowing for real-time image processing and analysis. Its compact design ensures that it can be easily mounted on the robot without adding significant weight or bulk.

## 7.4 V Battery
The 7.4 V rechargeable battery is the primary power source for the robot, providing energy to the motors, sensors, and computing components. This type of battery is commonly used in robotics due to its balance between power output and portability. In your robot, the 7.4 V battery ensures stable operation throughout the competition, powering not only the Raspberry Pi and sensor systems but also the motors responsible for movement and steering. With a robust capacity, the battery can sustain the robot for extended periods, reducing the need for frequent recharging.

## ESP32
The ESP32 driver board is a general-purpose motor driver that acts as an interface between the Raspberry Pi and the motors. It ensures that signals from the Raspberry Pi are correctly interpreted to control the motors' speed and direction. The ESP32 microcontroller on the board is known for its Wi-Fi and Bluetooth capabilities, although in this setup, it primarily serves to manage communication between the robot's sensors, motors, and control systems. The board also offers PWM (Pulse Width Modulation) control, which allows for smooth acceleration and deceleration of the motors, providing the robot with precise movement control. Additionally, the ESP32’s low power consumption ensures that the robot can run efficiently without draining the battery too quickly.

MOBILITY MANAGEMENT:
====

Due to the unreliability of our initial 3D-printed design, we transitioned to a more robust and customizable approach by utilizing Lego components. The Lego Technic chassis provided an ideal foundation due to its flexibility and durability, allowing us to fine-tune our robot’s design based on evolving requirements.
                                                                            
## Core Design
The core of the robot’s movement is driven by an EV3 motor connected to a system of gears and a differential. This setup ensures smooth and controlled turns, crucial for maintaining stability during sharp maneuvers. The differential plays a key role in preventing tire slipping when the robot navigates tight turns, allowing for precise and consistent movements. We implemented a two-gear system to prioritize speed over torque, as the robot is required to traverse at least fourteen meters within a short period. The gearing ratio was chosen specifically to enhance speed without compromising stability, based on the demands of the competition.

## Sensor Placement and Functionality
The robot is equipped with two VL53L1X laser sensors, placed at the front of the chassis to handle the wall-following aspect of the task. This strategic placement allows the robot to make sharp turns as soon as the sensors detect a wall, ensuring quick and efficient navigation. Additionally, a third VL53L1X sensor is mounted at the front to measure the distance from the wall directly ahead, further improving precision when navigating along straight paths. The Raspberry Pi Camera V2 adds another layer of sensing by detecting obstacles marked in red or green, enhancing the robot's ability to identify and avoid objects effectively.

## Steering Mechanism
The steering mechanism is controlled by a servo motor, which allows for real-time adjustments to the robot’s direction. This motor is connected to the front axle, enabling smooth and responsive steering. The servo motor’s accuracy ensures that the robot maintains its intended course, especially during sharp turns or when avoiding obstacles.

## Power Supply
The entire system is powered by a 7.4V battery, providing sufficient energy to sustain the robot’s operations for approximately 60 minutes. This battery life ensures that the robot can complete multiple rounds of the challenge without needing frequent recharging, offering reliable performance throughout the competition.

## Assembly Instructions:
Chassis Construction: Build any Lego Technic chassis as per your choice. Ensure that the beams are aligned to offer a sturdy base for mounting motors and sensors.
Motor Mounting: Attach the EV3 motor to the chassis (You will have to modify the cable).
Gear Assembly: Connect the two gears to the EV3 motor to achieve the 1:1 speed-to-torque ratio. Attach the differential to the front axle for smoother turning.
Sensor Installation: Mount the two VL53L1X sensors at the front of the chassis, ensuring they are angled appropriately for accurate wall detection. The third sensor should be placed facing forward to monitor the distance to walls.
Camera and Servo Installation: Attach the Raspberry Pi Camera V2 to the front of the robot for obstacle detection. Install the servo motor to control the front axle for steering..


