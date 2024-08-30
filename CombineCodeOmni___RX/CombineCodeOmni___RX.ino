
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <PCA9557.h>
#include <Adafruit_NeoPixel.h>
#include "DefinePin.h"

/* RESET DATA WHEN DISCONNECT REMOTE CONTROL */

void resetData() {
  data.vx = 128;
  data.vy = 128;
  data.VX = 128;
  data.VY = 128;
}

void setup() {

  /* BIGIN nRF24L0 */

  radio.begin();

  /* BIGIN DRIVER MOTOR */

  Wire.begin();

  /* SERIAL PRINT */

  //  Serial.begin(9600);

  /*  nRF24L0 */

    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_LOW);
    radio.startListening();

  /* ULTRASONIC & BUZZER */

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);

  /* NEOPICEL */

    strip.begin();

  /* PCA DRIVER MOTOR */

    io1.pinMode(INA_M1, OUTPUT);
    io1.pinMode(INB_M1, OUTPUT);
    pinMode(PWM_M1, OUTPUT);

    io1.pinMode(INA_M2, OUTPUT);
    io1.pinMode(INB_M2, OUTPUT);
    pinMode(PWM_M2, OUTPUT);

    io1.pinMode(INA_M3, OUTPUT);
    io1.pinMode(INB_M3, OUTPUT);
    pinMode(PWM_M3, OUTPUT);

    io1.pinMode(INA_M4, OUTPUT);
    io1.pinMode(INB_M4, OUTPUT);
    pinMode(PWM_M4, OUTPUT);

}

void loop() {

  /* DATA RECEIVER */

  if (radio.available()) {
    lastReceiveTime = millis();
    radio.read(&data, sizeof(data));

    /* SERIAL PRINT */

    if (data.counter != 0) {
      Serial.print("Counterr: ");
      Serial.print(data.counter);
      Serial.print(" | Joystick vx: ");
      Serial.print(data.vx);
      Serial.print(" | Joystick vy: ");
      Serial.print(data.vy);
      Serial.print(" | Joystick VX: ");
      Serial.print(data.VX);
      Serial.print(" | Joystick VY: ");
      Serial.println(data.VY);
    }
  } else {
    currentTime = millis();
    if (currentTime - lastReceiveTime > timeout) {
      resetData();
      Serial.println("DATA RESET DUE TO TIMEOUT");
    }
  }

  /* RESET DATA WHEN DISCONNECT REMOTE CONTROL */
  if (data.counter != 0) {
    MappingOmnirobot();
    KinematicOmnirobot();
    SPEED();
    OmniRobot();
  }
  showRGBSequence();
  ULTRASONIC();
}
