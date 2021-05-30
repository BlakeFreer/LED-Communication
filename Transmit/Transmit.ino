// Author: Blake Freer
// May 30, 2021

const int ledPin = 8; // Digital output pin of LED

// Communication settings
/* Note
 * The actual bitspeed is determined by the period, not the baud directly.
 * Therefore a baud = 200 and baud = 170 will actually be the same speed, since
 * they produce produce a period of 5 milliseconds (due to integer division)
 */
const int baud = 50; // Bits per second
long period;  // Milliseconds between bits

void setup() {
    pinMode(ledPin, OUTPUT);
    period = 1000 / baud;
}

String message = "Sending data with an LED!!\n";

void loop() {
    // Send the message and wait a second before repeating
    sendWord(message);
    delay(1000);
}

void sendWord(String string){
    // Send a string of characters
    for(int i = 0; i < string.length(); i++){
        sendChar(string.charAt(i));
    }
}

void sendChar(char data){
    emit(0); // Set line low to signal start of character
    delay(period);
    
    for(int i = 0; i < 8; i++){
        // Emit the 8 bits, LSB first
        emit(data % 2);
        delay(period);
        data = data / 2;
    }
    emit(1); // Return line to high
    delay(period); 
}

void emit(int _bit){
    // Shorthand for digitalWrite...
    digitalWrite(ledPin, _bit);
}
