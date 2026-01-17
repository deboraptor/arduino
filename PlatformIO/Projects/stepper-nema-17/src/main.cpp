/*
  doc : https://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html

  Controlling two steppers with the AccelStepper library

    by Dejan, https://howtomechatronics.com
*/

#include <AccelStepper.h>

// Define the stepper motor and the pins that is connected to
AccelStepper stepper1(1, 2, 5); // (toujours 1, stepPin, dirPin)

void setup() {
  stepper1.setEnablePin(8); // port EN -> enable the motor driver (if applicable)
  stepper1.enableOutputs(); // Active le driver (EN = LOW si inversé)

  stepper1.setMaxSpeed(1000); // pas/s
  stepper1.setAcceleration(500); // pas/s^2
  stepper1.setCurrentPosition(0); // réinitialise la position actuelle à 0

  stepper1.move(800); // 1 tour = 800 steps 
}

void loop() {
  stepper1.run();
  
  // Quand le mouvement en cours est fini, on relance un nouveau tour
  if (stepper1.distanceToGo() == 0) {
    stepper1.move(800);
  }
}

// stepper1.stop();
// stepper1.run(); 
// stepper1.runToPosition(); // Moves the motor to target position w/ acceleration/ deceleration and it blocks until is in position