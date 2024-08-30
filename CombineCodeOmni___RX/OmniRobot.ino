void OmniRobot() {

  /* MOTOR 1 */

  if (M1 > 0 && M1 <= 255) {
    io1.digitalWrite(INA_M1, 0);
    io1.digitalWrite(INB_M1, 1);
    analogWrite(PWM_M1, M1);
  }
  if (M1 == 0) {
    io1.digitalWrite(INA_M1, 0);
    io1.digitalWrite(INB_M1, 0);
  }
  if (M1 < 0 && M1 >= -255) {
    io1.digitalWrite(INA_M1, 1);
    io1.digitalWrite(INB_M1, 0);
    analogWrite(PWM_M1, (-1) * M1);
  }

  /* MOTOR 2 */

  if (M2 > 0 && M2 <= 255) {
    io1.digitalWrite(INA_M2, 0);
    io1.digitalWrite(INB_M2, 1);
    analogWrite(PWM_M2, M2);
  }
  if (M2 == 0) {
    io1.digitalWrite(INA_M2, 0);
    io1.digitalWrite(INB_M2, 0);
  }
  if (M2 < 0 && M2 >= -255) {
    io1.digitalWrite(INA_M2,1);
    io1.digitalWrite(INB_M2, 0);
    analogWrite(PWM_M2, (-1) * M2);
  }

  /* MOTOR 3 */

  if (M3 > 0 && M3 <= 255) {
    io1.digitalWrite(INA_M3, 0);
    io1.digitalWrite(INB_M3, 1);
    analogWrite(PWM_M3, M3);
  }
  if (M3 == 0) {
    io1.digitalWrite(INA_M3, 0);
    io1.digitalWrite(INB_M3, 0);
  }
  if (M3 < 0 && M3 >= -255) {
    io1.digitalWrite(INA_M3, 1);
    io1.digitalWrite(INB_M3, 0);
    analogWrite(PWM_M3, (-1) * M3);
  }

  /* MOTOR 4 */

  if (M4 > 0 && M4 <= 255) {
    io1.digitalWrite(INA_M4, 0);
    io1.digitalWrite(INB_M4, 1);
    analogWrite(PWM_M4, M4);
  }
  if (M4 == 0) {
    io1.digitalWrite(INA_M4, 0);
    io1.digitalWrite(INB_M4, 0);
  }
  if (M4 < 0 && M4 >= -255) {
    io1.digitalWrite(INA_M4, 1);
    io1.digitalWrite(INB_M4, 0);
    analogWrite(PWM_M4, (-1) * M4);
  }

}
