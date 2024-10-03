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




