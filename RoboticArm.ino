#include "BluetoothSerial.h"
#include <ESP32Servo.h>
#include <Constants.h>

// init Class:
BluetoothSerial ESP_BT;

// Parameters for Bluetooth interface
int incoming;

// pins for servos
byte VERTICAL_SERVO_PIN   = 26;
byte HORIZONTAL_SERVO_PIN = 33;
byte GRIPPER_PIN          = 32;
byte ROTATIONAL_SERVO_PIN = 25;

// Servo objects
Servo verticalServo;
Servo horizontalServo;
Servo gripperServo;
Servo rotationalServo;

// values for servos
int  rotationalValue = ZERO_ROTATIONAL_SERVO;
int  verticalValue   = MIN_VERTICAL_SERVO;
int  horizontalValue = MAX_HORIZONTAL_SERVO;
bool gripperState    = false;

void setup()
{
  // setup
  Serial.begin(SERIAL_SPEED);
  ESP_BT.begin(TITLE);

  // pin handling
  pinMode(VERTICAL_SERVO_PIN, OUTPUT);
  verticalServo.attach(VERTICAL_SERVO_PIN);

  pinMode(HORIZONTAL_SERVO_PIN, OUTPUT);
  horizontalServo.attach(HORIZONTAL_SERVO_PIN);

  pinMode(GRIPPER_PIN, OUTPUT);
  gripperServo.attach(GRIPPER_PIN);

  pinMode(ROTATIONAL_SERVO_PIN, OUTPUT);
  rotationalServo.attach(ROTATIONAL_SERVO_PIN);
}

void loop()
{
  // -------------------- Receive Bluetooth signal ----------------------
  if (ESP_BT.available())
  {
    incoming = ESP_BT.read(); // Read what we receive

    // separate button ID from button value -> button ID is 10, 20, 30, etc, value is 1 or 0
    int button = floor(incoming / BUTTON_ID);
    int value  = incoming % BUTTON_ID;
    delay(50);

    switch (button)
    {
    case LEFT:
      Serial.print("Left");
      if (rotationalValue != MAX_ROTATIONAL_SERVO)
      {
        rotationalServo.write(rotationalValue += ROTATIONAL_STEP);
      }
      break;
    case RIGHT:
      Serial.print("Right");
      if (rotationalValue != ZERO_ROTATIONAL_SERVO)
      {
          rotationalServo.write(rotationalValue -= ROTATIONAL_STEP);
      }
      break;
    case UP:
      Serial.print("Up");
      if (verticalValue != MIN_VERTICAL_SERVO)
      {
        verticalServo.write(verticalValue -= VERTICAL_STEP);
      }
      break;
    case DOWN:
      Serial.println("Down");
      if (verticalValue != MAX_VERTICAL_SERVO)
      {
        verticalServo.write(verticalValue += VERTICAL_STEP);
      }
      break;
    case GRIPPER:
      Serial.println("Gripper");
      if (gripperState == false)
      {
        gripperServo.write(MAX_GRIPPER_SERVO);
        gripperState = true;
        Serial.println(FALSE);
      }
      else
      {
        gripperServo.write(MIN_GRIPPER_SERVO);
        gripperState = false;
        Serial.println(TRUE);
      }
      break;
    case FORWARD:
      Serial.println("Forward");
      horizontalServo.write(horizontalValue += HORIZONTAL_STEP);
      break;
    case BACKWARD:
      Serial.println("Backward");
      horizontalServo.write(horizontalValue -= HORIZONTAL_STEP);
      break;
    }
  }
}
