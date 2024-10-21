#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

// Define motor pins
const int motorLeftForward = 22;  // Pin for left motor forward
const int motorLeftBackward = 23; // Pin for left motor backward
const int motorRightForward = 25; // Pin for right motor forward
const int motorRightBackward = 26; // Pin for right motor backward

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Robot"); // Name of the Bluetooth device

  // Set motor pins as outputs
  pinMode(motorLeftForward, OUTPUT);
  pinMode(motorLeftBackward, OUTPUT);
  pinMode(motorRightForward, OUTPUT);
  pinMode(motorRightBackward, OUTPUT);

  Serial.println("Bluetooth Device is Ready to Pair");
}

void loop() {
  if (SerialBT.available()) {
    char command = SerialBT.read(); // Read the incoming command

    // Control the motors based on the command received
    switch (command) {
      case 'F': // Move Forward
        moveForward();
        break;
      case 'B': // Move Backward
        moveBackward();
        break;
      case 'L': // Turn Left
        turnLeft();
        break;
      case 'R': // Turn Right
        turnRight();
        break;
      case 'S': // Stop
        stopMotors();
        break;
      default:
        break;
    }
  }
}

// Function to move forward
void moveForward() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
  Serial.println("Moving Forward");
}

// Function to move backward
void moveBackward() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, HIGH);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, HIGH);
  Serial.println("Moving Backward");
}

// Function to turn left
void turnLeft() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, HIGH);
  digitalWrite(motorRightForward, HIGH);
  digitalWrite(motorRightBackward, LOW);
  Serial.println("Turning Left");
}

// Function to turn right
void turnRight() {
  digitalWrite(motorLeftForward, HIGH);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, HIGH);
  Serial.println("Turning Right");
}

// Function to stop motors
void stopMotors() {
  digitalWrite(motorLeftForward, LOW);
  digitalWrite(motorLeftBackward, LOW);
  digitalWrite(motorRightForward, LOW);
  digitalWrite(motorRightBackward, LOW);
  Serial.println("Motors Stopped");
}
