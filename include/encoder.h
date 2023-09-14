#ifndef ENCODER_DRIVER_H
#define ENCODER_DRIVER_H

#define LEFT_ENC_PIN_A 18
#define LEFT_ENC_PIN_B 19

#define RIGHT_ENC_PIN_A 20
#define RIGHT_ENC_PIN_B 21

#include <Encoder.h>

Encoder leftEnc(LEFT_ENC_PIN_A, LEFT_ENC_PIN_B);
Encoder rightEnc(RIGHT_ENC_PIN_A, RIGHT_ENC_PIN_B);

#include "commands.h"

long readEncoder(int i) {
  if (i == LEFT)
    return -leftEnc.read();
  else
    return rightEnc.read();
}

void resetEncoder(int i) {
  if (i == LEFT) {
    leftEnc.write(0);
  } else {
    rightEnc.write(0);
  }
}

void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif  // ENCODER_DRIVER_H