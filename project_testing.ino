// For PIR sensors
int pirInputPin = 8;		// choose the input pin (for PIR sensor)
int pirState = LOW;		// we start, assuming no motion detected
int val = 0;			// variable for reading the pin status

// boolean variable to check if the given parking slot is occupied
int isOccupied = 0;

// pin numbers for red and green LEDs
int redLedPin = 7;
int greenLedPin = 6;

// Define pins for ultrasonic sensor and LED
int trigPin = 9;
int echoPin = 10;
int ledPinred = 3;
int ledPingreen = 4;

// for ultrasonic sensor
int isParked = 0;

void setup()  {

  Serial.begin(9600);

  // for PIR sensor
  pinMode(pirInputPin, INPUT);	// declare sensor as input

  // for ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPinred, OUTPUT);
  pinMode(ledPingreen, OUTPUT);

}

void loop() {
  // for PIR sensor

  val = digitalRead(pirInputPin);	// read input value

  if (val == HIGH) {		// check if the input is HIGH
      // digitalWrite (ledPin, HIGH);	// turn LED ON
      if (pirState == LOW) {
	      Serial.println("Motion detected!");	// print on output change
	      pirState = HIGH;
        isOccupied = (isOccupied == 0)? 1:0;
        updateLEDs(isOccupied);
	    }
  }
  else {
      // digitalWrite (ledPin, LOW);	// turn LED OFF
      if (pirState == HIGH) {
	      Serial.println ("Motion ended!");	// print on output change
	      pirState = LOW;
        isOccupied = 0;
        updateLEDs(isOccupied);
	    }
  }

  // for ultrasonic sensor
  sendUltrasonicPulse();
 
  // get ultrasonic sensor reading
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  updateUltrasonicSensorOutput(distance);

  delay(1000);
}

void updateLEDs(int isOccupied1) {
  if (isOccupied1) { // turn off green LED and turn on red LED
    // turn off green LED
    digitalWrite(greenLedPin, LOW);

    // turn on red LED
    digitalWrite(redLedPin, HIGH);
  } else {
    // turn off red LED
    digitalWrite(redLedPin, LOW);

    // turn on green LED
    digitalWrite(greenLedPin, HIGH);
  }

  // for ultrasonic sensor
}

void sendUltrasonicPulse() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

}

void updateUltrasonicSensorOutput(float distance) {

  if (distance < 15 && isParked == 0) {
    Serial.println("Parked.");
    isParked = 1;
    digitalWrite(ledPingreen, LOW);
    digitalWrite(ledPinred, HIGH);
  } else if (distance > 15 && isParked == 1) {
    Serial.println("Parking spot emptied.");
    isParked = 0;
    digitalWrite(ledPinred, LOW);
    digitalWrite(ledPingreen, HIGH);
  }

}