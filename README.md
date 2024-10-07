# Robotic Arm Overview

![Robotic Arm Overview](https://res.cloudinary.com/dk2fdiuvb/image/upload/v1717076078/cards/vjbf82mmubdraujd7ibh.jpg)

## Really? A Robot?

Yeah cool, isn't it? It is a childhood dream, so I thought about using my electronics knowledge to pull it off.  
In this project, I used an **ESP32** to control the robot's movements remotely. The ESP32 is a microcontroller, which is the brains of the operation. It handles Bluetooth communication between the phone app (which I also created) and the robot itself, allowing control from a distance.  
The robot was published along with a research paper at the **International CIIT conference** and presented at Hotel Sirius in Strumica in 2024. You can read more about it below:

---

## How it Was Made

![Components of the Robotic Arm](https://res.cloudinary.com/dk2fdiuvb/image/upload/v1719133218/projects/nl9glkmqbalkikenvthd.png)

### Components

- **1 x Sheet of Plywood**: A sturdy yet lightweight base for the robotic arm.
- **1 x ESPRESSIF ESP32 Devmodule**: The brain of the operation, translating smartphone commands into movements.
- **4 x Servo motors sg90**: These act as the muscles of the robotic arm.
- **1 x Battery Holder (3 cell)**: Provides power for both the servos and ESP32.
- **1 x Stable 5V Power Delivery**: Ensures reliable servo operation using various power sources.
- **(Optional) 1 x 3.7V Rechargeable Li-Ion Battery**: Can be used for recharging purposes.

---

![Robotic Arm in Action](https://res.cloudinary.com/dk2fdiuvb/image/upload/v1719132245/projects/hqkc3jhr40tmju9fou3y.jpg)

## Considerations

The material choice for the frame was important. I didn't have a 3D printer available at the time, so I opted for plywood, which was sturdy, cheap, and readily available.

I chose the **ESP32** because it has more memory than Arduino and a built-in Bluetooth module, allowing for easier communication between the app and the robot.

The servo motors had some issues with current, but I used a lever system to reduce the strain on the motors. In the future, I plan to use metal gear servos for more torque.

---

## The Gripper

The gripper was initially tested with cardboard and later upgraded to plywood. The gripper operates using two servo motors, with wires connected to the servo horns to control the movement.

![Robotic Gripper Design](https://res.cloudinary.com/dk2fdiuvb/image/upload/v1719132243/projects/nmtm8indeu7y29okrywa.jpg)

---

## Movement

The arm moves in three dimensions, with servos controlling horizontal and vertical movements. The plywood pieces were carefully cut, drilled, and connected with screws to act as pivot points, allowing flexible movement.

---

## Mobile App

I experimented with different control methods, including a PS4 controller. Eventually, I built my own app using **MIT App Inventor**, which sends commands via Bluetooth to the ESP32 to control the servos.

---

![Mobile App Interface](https://res.cloudinary.com/dk2fdiuvb/image/upload/v1719182109/projects/qzeply5beq2pbiibvxyy.jpg)

### The Robotic Arm - APP

![ESP32 Connections](https://res.cloudinary.com/dk2fdiuvb/image/upload/v1719182110/projects/fpu3ruybzlay8kytyubh.jpg)

---

## Accomplishments

![CIIT Presentation](https://res.cloudinary.com/dk2fdiuvb/image/upload/v1719131804/projects/fgyednyxugksax54nnym.jpg)

## CIIT 2024

I was invited to present this project at the **International Conference on Informatics and Information Technologies (CIIT)** in 2024.  
I submitted a research paper under the mentorship of **Vlatko Spasev** and presented it at **Hotel Sirius** in **Strumica**. The event featured presentations from various fields, including AI, robotics, and bioinformatics.  
Learn more about the event [here](https://ciit.finki.ukim.mk/).

Download the research paper [here](https://res-console.cloudinary.com/dk2fdiuvb/media_explorer_thumbnails/53a81f1d1d53da4c69ad4102e9da4610/download "Robot_Hand_CIIT_2024.pdf").
