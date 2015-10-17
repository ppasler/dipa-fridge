// record ten values while delayMs 
const int steps = 10;
// log to file every delayMs milliseconds
const int delayMs = 3000;

void setup() {
  Serial.begin(9600);

  Serial.println("#S|SRTLOG|[]#");
  
  startSend();
  // table headers
  Serial.print("A0;A5");
  endSend();
}

int startSend(){
  Serial.print("#S|WRTTMP|[");
}

int endSend(){
  Serial.println("]#");
}

int sendValue(float value, int prec){
  char tmp[10];
  Serial.print(dtostrf(value,1,2,tmp));
  Serial.print(";");
}

void loop() {

  float temperature1 = 0.0;
  float temperature2 = 0.0;

  for(int i = 0; i < steps; i++){
    temperature1 += (5.0 * analogRead(A0) * 100.0) / 1024;
    temperature2  += (5.0 * analogRead(A5) * 100.0) / 1024;
    delay(delayMs / steps);
  }
  startSend();
  sendValue(temperature1/steps, 2);
  sendValue(temperature2/steps, 2);
  endSend();
}
