// Torodial CVT Motor code
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), countUp, RISING);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(3), countUp2, RISING);
}

volatile int count = 0;
volatile int count2 = 0;

void loop() {
  Serial.print("count;");
  Serial.print(count);
  Serial.print(";count2;");
  Serial.println(count2);
}

void countUp(){
  count++;
}
void countUp2(){
  count2++;
}
