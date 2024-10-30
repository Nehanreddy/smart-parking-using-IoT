IoT-based smart parking system

Team members:
Jitheesh V J
Kanuru Yamini Krishna
Loka Nehan Reddy

This project is an IoT-based smart parking system. The system uses ultrasonic sensors and infrared sensors to detect if a given parking slot is occupied and shows the output using LEDs.

Components used:

1. Arduino Uno microcontroller board
2. USB cable
3. Ultrasonic sensor
4. Infrared (IR) sensor
5. LEDs (red and green)
6. Jumper wires (as required)

The infrared sensor is connected to pin 8. The red and green LEDs that indicate the output of the IR sensor are connected to pins 7 and 6 of the Arduino board respectively.
The trig and echo pins of the ultrasonic sensor are connected to pins 9 and 10 or the Arduino board respectively. The red and green LEDs that indicate the outputs of the 
ultrasonic sensor are connected to pins 3 and 4 of the Arduino board respectively. Serial communication with the computer is established at a baud rate of 9600 bits per second.
Every second, the outputs of both the IR and ultrasonic sensors are checked and they are reflected in their LEDs. If the distance detected by the ultrasonic sensor is lesser than 15 cm,
then the car is parked in the parking slot--the respective red LED glows and the serial monitor shows "Parked". In the opposite case, the green LED glows and the serial monitor shows 
"Parking slot empty". Similarly when the IR sensor detects motion the green LED glows, and when it does not detect motion the red LED glows. The serial monitor outputs the state of
motion detection at that instant. This activity is periodically done every second.