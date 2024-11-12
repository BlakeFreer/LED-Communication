// Author: Blake Freer
// May 30, 2021

/* Instructions
 *  Set up the photoresistor and LED. Keep the LED off
 *  Run this file on the photoresistor Arduino
 *  Open Serial Monitor and set baud to 57600
 *  Determine the stable value of the photoresistor under ambient conditions
 *  In Receive.ino, set backgroundLightLevel to this value
 */

int photoPin = 0;

int lightValue = 0;

void setup() {
    Serial.begin(57600);
}

void loop() {

    // Read the light value from the photoresistor
    lightValue = analogRead(photoPin);
    // Print the value to the screen
    Serial.println(lightValue);

    delay(10);

}
