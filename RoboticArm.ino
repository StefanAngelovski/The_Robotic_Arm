#include "BluetoothSerial.h" 
#include <ESP32Servo.h>

// init Class:
BluetoothSerial ESP_BT; 

// Parameters for Bluetooth interface
int incoming;

byte verticalServoPin = 26;
byte horizontalServoPin = 33;
byte gripperPin = 32;
byte rotationalServoPin = 25;


Servo verticalServo;
Servo horizontalServo;
Servo gripperServo;
Servo rotationalServo;


int i=0; //for rotational
int j=0; //for vertical
int g=180; //for horizontal
bool gripperState = false;
void setup() {
  Serial.begin(9600);
  ESP_BT.begin("Finki - Robotic arm");
  pinMode(verticalServoPin, OUTPUT);
  verticalServo.attach(verticalServoPin);

  pinMode(horizontalServoPin ,OUTPUT);
  horizontalServo.attach(horizontalServoPin);

  pinMode(gripperPin, OUTPUT);
  gripperServo.attach(gripperPin);

  pinMode(rotationalServoPin, OUTPUT);
  rotationalServo.attach(rotationalServoPin);
}

void loop() {
  
  // -------------------- Receive Bluetooth signal ----------------------
  if (ESP_BT.available()) 
  {
    incoming = ESP_BT.read(); //Read what we receive 

    // separate button ID from button value -> button ID is 10, 20, 30, etc, value is 1 or 0
    int button = floor(incoming / 10);
    int value = incoming % 10;
    delay(50);
    switch (button) {
      case 1:  
        Serial.print("Left");
        if(i!=180)rotationalServo.write(i+=10);
        break;
      case 2:  
        Serial.print("Right");
        if(i!=50)rotationalServo.write(i-=10);
        break;
      case 3:  
        Serial.print("Up");
        if(j!=0)verticalServo.write(j-=10);
        break;
      case 4:
        Serial.println("Down");
        if(j!=180)verticalServo.write(j+=10);
        break;
      case 5:
        Serial.println("Gripper");
        if(gripperState == false){
          gripperServo.write(180);
          gripperState = true;
          Serial.println("False");
        }
        else {
          gripperServo.write(160);
          gripperState = false;
          Serial.println("True");
        }
        break;
      case 6:
        Serial.println("Forward");
        horizontalServo.write(g+=10);
        break;
      case 7:
        Serial.println("Backward");
        horizontalServo.write(g-=10);
        break;
    }
  }
}
