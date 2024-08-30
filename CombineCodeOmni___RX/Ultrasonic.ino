

void ULTRASONIC() {

  /* SEND TRIGGER PULSE */ 

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

  /* MEASURE THE DURATION OF THE ECHO PULSE */ 

    long duration = pulseIn(ECHO_PIN, HIGH);
    float distance = (duration / 2.0) * 0.0344;

    int colorCase;  /* VARIABLE TO STORE THE CASE RESULT */ 


  if (distance < DISTANCE_THRESHOLD && state == 1) {

    digitalWrite(BUZZER_PIN, 1);  /* TURN ON BUZZER */ 
    color = strip.Color(255, 0, 0);  /* RED */ 
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, color);  /* SET ALL PIXELS TO THE SELECTED COLOR */ 
    }
    strip.show();  /* UPDATE THE STRIP WITH THE NEW COLOR */ 
  } else if (distance >= DISTANCE_THRESHOLD && state == 1) {
    digitalWrite(BUZZER_PIN, LOW);   /* TURN OFF BUZZER */ 

    color = strip.Color(0, 255, 0);  /* GREEN */ 
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, color);  /* SET ALL PIXELS TO THE SELECTED COLOR */ 
    }
    strip.show(); 
  }

}
