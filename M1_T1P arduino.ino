// Using Piezo buzzer with a ultrasonic sensor

const int TRIG   = 6; // Arduino pin connected to Sensor's TRIG pin
const int ECHO   = 7; // Arduino pin connected to Sensor's ECHO pin
const int BUZZER = 3; // Arduino pin connected to Piezo Buzzer's pin
const int DISTANCE_THRESHOLD = 50; // centimeters

float duration, distance;

void setup() {
  Serial.begin (9600);         // initializing serial port
  pinMode(TRIG, OUTPUT);   // sets arduino pin to output mode
  pinMode(ECHO, INPUT);    // sets arduino pin to input mode
  pinMode(BUZZER, OUTPUT); // sets arduino pin to output mode
}

void loop() {
  // generating a 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // measuring duration of pulse from ECHO pin
  duration = pulseIn(ECHO, HIGH);
  
  // calculating the distance
  distance = 0.017 * duration;

  if(distance < DISTANCE_THRESHOLD)
    digitalWrite(BUZZER, HIGH); // turn on Buzzer
  else
    digitalWrite(BUZZER, LOW);  // turn off Buzzer

  // prints the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500);
}