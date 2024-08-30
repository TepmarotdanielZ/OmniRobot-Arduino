

void showRGBSequence() {
  if (millis() - lastTimeColorChange >= COLOR_TIME) {  /* SHOW EACH COLOR FOR 10 SECONDS */ 
    lastTimeColorChange = millis();                    /* RESET THE TIMER */ 
    displayColor();

    if (colorIndex == 4) {  /* IF INDEX REACHES 6, STOP THE RGB SHOW */ 
      turnOffRGB();         /* TURN OFF ALL RGBs */ 
      state = 1;
    }
  }
}

void displayColor() {
  if (colorIndex == 0) {
    color = strip.Color(255, 0, 0);  /* RED */ 
    colorIndex = 1;
  } else if (colorIndex == 1) {
    color = strip.Color(0, 255, 0);  /* GREEN */ 
    colorIndex = 2;
  } else if (colorIndex == 2) {
    color = strip.Color(0, 0, 255);  /* BLUE */ 
    colorIndex = 3;
  } else if (colorIndex == 3) {
    color = strip.Color(0, 0, 0);     /* OFF */ 
    colorIndex = 4;
  } 
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);  /* SET ALL PIXELS TO THE SELECTED COLOR */ 
  }
  strip.show();  /* UPDATE THE STRIP WITH THE NEW COLOR */ 
}

void turnOffRGB() {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, 0);  /* TURN OFF ALL PIXELS */ 
  }
  strip.show();  /* UPDATE THE STRIP TO TURN OFF ALL LEDs */ 
}

