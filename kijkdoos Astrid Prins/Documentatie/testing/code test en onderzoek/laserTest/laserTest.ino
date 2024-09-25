#define laser 6

int LDR_In = A0;
int lichtHoeveelheid;

int LED_PIN0 = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(laser, OUTPUT);
  digitalWrite(laser, HIGH);
  pinMode(LED_PIN0, OUTPUT);
}

void loop() {
  lichtHoeveelheid = analogRead(LDR_In);
  Serial.println(lichtHoeveelheid);

  if(lichtHoeveelheid > 300){
    digitalWrite(LED_PIN0, HIGH);
    Serial.println("laser connected");
  }
  else{
    digitalWrite(LED_PIN0, LOW);
    Serial.println("laser disconnected");
  }
}
