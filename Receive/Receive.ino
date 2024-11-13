// Author: Blake Freer
// May 30, 2021

const int photoPin = 0; // Analog input pin of photoresistor

// Communication Settings
const int baud = 50;    // Bits per second
long period; // Milliseconds between bits

// Light settings (may need calibration)
int backgroundLightLevel = 350; // Background light level
int threshold = 150;     // Required change in light-level to constitute a "1" signal

void setup() {
    pinMode(photoPin, INPUT);
    period = 1000 / baud;
    
    Serial.begin(57600);
}

void loop() {
    // Wait for a bit to be sent then print it to Serial monitor
    while(readLight()){
        // Wait while line is HIGH
    }
    Serial.print(readChar());    
}

char readChar(){
    delay(period * 1.5); // Wait into the first actual bit
    
    int charValue = 0;  // The value being sent across
    int power = 1;      // The current binary power multiplier
    
    for(int i = 0; i < 8; i++){
        // Read in 8 bits, LSB first, and add to the charValue
        charValue += readLight() * power;
        power *= 2;
        delay(period);
    }
    return charValue;
}

int readLight() {
    // Returns 1 if the LED is on (low light level) and 0 if off (high light level)
    return analogRead(photoPin) <= backgroundLightLevel - threshold;
}
