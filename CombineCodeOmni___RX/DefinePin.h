/* DEFINE PIN PWM AND PIN DIRECTION */

  #define INA_M1 0
  #define INB_M1 1
  #define PWM_M1 3

  #define INA_M2 2
  #define INB_M2 3
  #define PWM_M2 5

  #define INA_M3 4
  #define INB_M3 5
  #define PWM_M3 9

  #define INA_M4 6
  #define INB_M4 7
  #define PWM_M4 10

/* ULTRASONIC & BUZZER */

  /* USE PIN USART PIN 0 AND PIN 1, CLOSE  SERIAL.BIGIN */

  #define TRIG_PIN 0 /* TX PIN */
  #define ECHO_PIN 1 /* RX PIN */
  #define BUZZER_PIN 4
  #define DISTANCE_THRESHOLD 20
  #define DISTANCE_THRESHOLD1 300

  float distance;
  long duration;

/* NEOPICEL RGB PIN 1 */

  #define RGB_PIN 2 /* PIN 2 IN RGB */
  #define NUMPIXELS 34
  #define DELAYVAL 20

  #define COLOR_TIME 1000   /* TIME FOR EACH COLOR 10 SECONDS */ 
  #define BREAK_TIME 1000 
  #define OFF_TIME   1000

  int k =0;
  int i =0;
  int j = 0;
  int state =0;

  unsigned long lastTimeColorChange = 0;
  unsigned long lastTimeUltrasonic = 0;
  bool colorSequenceActive = true;

  int STOP_RGB = 0;
  int colorIndex = 0, colorIndex1 =0 ;         /* TRACKS THE CURRENT CCOLOR BEGIN SHOW */ 
  uint32_t last_time = 0;
  uint32_t color;
  uint32_t color1;
  bool ultrasonicOverride = false;
  bool showingColors = true;     /* INDICATES WHETHER THE STRIP IS IN THE BREAK PERIOD */
  Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800);


/* KINEMATIC EQUATION */

  float M1, M2, M3, M4;
  float vxX, vyY, Omega;

/* I/O FOR MOTOR */

  PCA9557 io1(0x18, &Wire);
  PCA9557 io2(0x19, &Wire);

/* nRF24L01 SETUP */

  RF24 radio(7, 8);                /* CE PIN 7, CSN PIN 8 */
  const byte address[6] = "00007"; /* ADDRESS OF THE TRANSMITTER */

/* STRUCTURE TO HOLD RECEIVER JOYSTICK DATA */

  struct JoystickData {
    int vx;
    int vy;
    int VX;
    int VY;
    uint8_t counter;
  } data;

  unsigned long lastReceiveTime = 0;
  unsigned long currentTime = 0;
  const unsigned long timeout = 10; /* 1 SECOND TIMEOUT */
