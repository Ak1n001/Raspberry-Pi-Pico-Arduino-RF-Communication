const int rfPin = 7;
String message = "";
byte receivedByte = 0;
int bitCount = 0;

void setup() {
  Serial.begin(9600);
  pinMode(rfPin, INPUT);
}

void loop() {
  while (bitCount < 8) {
    while (digitalRead(rfPin) == 0);
    unsigned long start = micros();
    while (digitalRead(rfPin) == 1);
    unsigned long duration = micros() - start;

    if (duration > 400 && duration < 700) {
      receivedByte = (receivedByte << 1) | 1;
      bitCount++;
    } else if (duration > 100 && duration < 350) {
      receivedByte = (receivedByte << 1);
      bitCount++;
    } else {
      receivedByte = 0;
      bitCount = 0;
    }
  }

  char c = (char)receivedByte;
  if (c == '\n') {
    Serial.println(message);  // Print full message
    message = "";             // Reset buffer
  } else {
    message += c;
  }

  bitCount = 0;
  receivedByte = 0;
}