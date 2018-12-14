#include <IRremote.h>

int RECV_PIN = 11;
int buzz = 8;
int rele = 4;
int x;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup(){
  pinMode(buzz, OUTPUT);
  pinMode(rele, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    digitalWrite(rele, HIGH);
    for(x=0; x < 50; x++){
      digitalWrite(buzz, HIGH);
      delay(200);
      digitalWrite(buzz, LOW);
      delay(100);
    }
    digitalWrite(rele, LOW);
    
    irrecv.resume();
    
  }
  delay(100);
}