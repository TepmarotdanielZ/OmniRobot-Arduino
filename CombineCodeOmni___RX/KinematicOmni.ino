
/* MAPPING JOYSTICK TO 8BIT */

  void MappingOmnirobot() {
    vxX = map(data.vx, 255, 0, -255, 255);
    vyY = map(data.vy, 0, 254, -255, 255);
    Omega = map(data.VY, 0, 254, -255, 255);
  }

/* KINEMATIC EQUATION */

  void KinematicOmnirobot() {
    /*
      M1 = (vxX*0.5) - (vyY*0.5) - (Omega*0.5);
      M2 = (vxX*0.5) + (vyY*0.5) + (Omega*0.5);
      M3 = (vxX*0.5) - (vyY*0.5) + (Omega*0.5);
      M4 = (vxX*0.5) + (vyY*0.5) - (Omega*0.5);
    */

    M1 = (vxX*1) - (vyY*1) - (Omega*1);
    M2 = (vxX*1) + (vyY*1) + (Omega*1);
    M3 = (vxX*1) - (vyY*1) + (Omega*1);
    M4 = (vxX*1) + (vyY*1) - (Omega*1);

  }

/* SPEED MOTOR */

  void SPEED() {
    if (M1 < -255) M1 = -255;
    if (M1 > 255) M1 = 255;

    if (M2 < -255) M2 = -255;
    if (M2 > 255) M2 = 255;

    if (M3 < -255) M3 = -255;
    if (M3 > 255) M3 = 255;

    if (M4 < -255) M4 = -255;
    if (M4 > 255) M4 = 255;
  }