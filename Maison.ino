#include <IRremote.hpp>

const int DIN_RECEPTEUR_INFRAROUGE = 11;

IRrecv IR(DIN_RECEPTEUR_INFRAROUGE);
const int LED1= 6;
const int LED2= 7; 
char AN_PHOTORESISTANCE = A0;
const int LED3 = 8;
int analogPin =0;
int analogValue = 0;
void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
  //IR.blink13(true);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

}

void loop() {
  if (IR.decode()) {
    if (IR.decodedIRData.decodedRawData == 0xF30CFF00) {
      digitalWrite(LED1, HIGH); // Allumer la lampe
      Serial.println("Touche1");
    }
    if (IR.decodedIRData.decodedRawData == 0xE718FF00) {
      digitalWrite(LED1, LOW); // Éteindre la lampe
      Serial.println("Touche2");
    }
      if (IR.decodedIRData.decodedRawData == 0xA15EFF00) {
      digitalWrite(LED2, HIGH); // Allumer la lampe
      Serial.println("Touche3");
    }
    if (IR.decodedIRData.decodedRawData == 0xF708FF00) {
      digitalWrite(LED2, LOW); // Éteindre la lampe
      Serial.println("Touche4");
    }
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    delay(500);
    IR.resume();
  }
analogValue = analogRead(analogPin);
 Serial.println(analogValue);
 if(analogValue>90){
   digitalWrite(LED3,LOW);

 }
  else{
  digitalWrite(LED3,HIGH);
   
  }

}
