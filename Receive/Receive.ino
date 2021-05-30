const int input = 0;
int value = 0;

int background = 350; // Background light level
int offset = 20;

void setup() {
    pinMode(input, INPUT);

    Serial.begin(57600);
}

void loop() {
    Serial.println(readLight());
    delay(10);
}

int readLight(){
    return analogRead(input) <= background - offset;
}
