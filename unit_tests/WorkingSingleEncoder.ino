// new objective: ENCODERS
int testCount = 0;

#define PIN_A 6
#define PIN_B 5

// 5, 6, B A
// 9, 10, B A

volatile long position = 0;
volatile bool changed = false;

void encoderISR() {
  static uint8_t lastA = 1;

  uint8_t a = digitalRead(PIN_A);
  uint8_t b = digitalRead(PIN_B);

  if (a != lastA) {
    if (a == b) position++;
    else position--;
  }

  lastA = a;
  changed = true;

  /*if (digitalRead(PIN_B)) {
    position--;
  } else {
    position++;
  }
  changed = true;*/
}

void setup(){
  Serial.begin(115200);
	//while (!Serial) delay(1);

  Serial.println("Begin");

  //force pin to be high
  pinMode(PIN_A, INPUT_PULLUP);
  pinMode(PIN_B, INPUT_PULLUP);

  attachInterrupt(
    digitalPinToInterrupt(PIN_A),
    encoderISR,
    CHANGE
  );
}

void loop(){
	/*Serial.print(testCount++);
	Serial.println(" Seconds Past");
	delay(1000);*/

  noInterrupts();
  bool safeChanged = changed;
  long safePosition = position;
  changed = false;
  interrupts();

  //safe way to read
  if (safeChanged){
    Serial.print(safePosition);
    Serial.println(" ticks");
  }

  //now print
  
}