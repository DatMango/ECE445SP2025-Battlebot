# Ant-weight Battlebot - Scooper

# Group members
- Yuxuan Nan(yuxuann2)
- Justin Leong (jyleong2)
- Zilong Jiang(zjian4)

# Problem
The issue at hand is an Ant-weight, 3D Printed Battlebot Competition in which each team wants to win. There are certain constraints of the Battlebots’ design in order to be eligible and win. To win the competition, the goal of a battlebot is to outlast or destroy the opponent team’s battlebot. Different teams will have different designs, meaning a battlebot designed for winning must take into account as many factors to withstand and outlast the competition.

# Solution
We decided upon developing a 3D Printed Bluetooth-controlled battle bot powered by an STM32 microcontroller. The Battlebot communicates with a PC via a Bluetooth module, enabling wireless command and control. It is equipped with two DC motors driven by H-bridge circuits for precise movement and a ramp-shaped weapon system for engaging in battles. The STM32 manages motor control using GPIO and PWM, while the weapon system utilizes GPIO or I2C protocols for activation. The bot integrates real-time communication, robust motor control, and weapon functionality, offering an engaging and functional design. My goal is to create a responsive and competitive robot for dynamic competitions.

# Solution Components

## DriveTrain
The drivetrain of our battlebot will utilize two DC motors with high torque to power two of our rear wheels making this a rear wheel drive robot. We have decided upon a brand of motor that will output 0.58kgf.cm of torque as well as have a max of 200 RPM in rotational speed. The rear wheels will consist of high-friction wheels that allow for lots of traction to handle the speed. Additionally, we will combine this with an omni-directional front wheel to allow for easy directional movement if the weight capacity allows it. Furthermore, we will combine this with an H-bridge circuit to allow control, stability, and power for the battlebot.

## Weapon and Chassis
The weapon and chassis are required to be 3D printed according to the list of approved plastic types. Ideally if possible, we would like to use ABS plastic as this would be the best in terms of weight and durability but have opted for PLA+ plastic as it is easier to print designs. PLA+ plastic also offers decent strength and isn’t as brittle as the other provided plastics. For weapon design, we will be creating a Skid Bucket type weapon that can potentially be moved up and down using pneumatics to attack other battlebots (both for ramming and slamming other battlebots). In terms of chassis, we have decided to use two motors for rear wheel drive box-ish battlebot as well as an omni-directional front wheel to make steering easy.

## Power system
In the power system module, this includes regulators and converters to different electronics, the battery, and a monitor for the battery with a switch/relay. For the battery, we have decided upon a 12V NiMh battery as this can supply consistent and reliable power. We will also include a short circuit detection that will turn off the battery for safe practice.

## Control system
The control system will be powered by an STM32 microcontroller, which will manage motor control and wireless communication. Using a Bluetooth module, the bot will communicate with a PC, enabling real-time control with minimal latency. The STM32 will leverage GPIO and PWM to provide precise speed and directional control for the motors, ensuring responsiveness and accuracy during battles.

# Criterion For Success:

Our battlebot would be considered successful if we can control the battlebot via Bluetooth relatively well. This would include having both motors work separately for steering as well as being able to make each motor have different amounts of throttle inputted. Additionally, we would like our weapon to work well enough to be considered functional during a match.

