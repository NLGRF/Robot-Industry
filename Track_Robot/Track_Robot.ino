#include <SoftwareSerial.h>

SoftwareSerial CarSerial(12, 13); // RX, TX

#define lmotorf 3
#define lmotorb 4
#define rmotorf 5
#define rmotorb 6

//HIGH white
//LOW black
#define lmotor 2
#define rmotor 7
void setup() {
  Serial.begin(9600);
  CarSerial.begin(38400);
  Serial.println("Hello, world?");
  pinMode(lmotorf, OUTPUT);
  pinMode(rmotorf, OUTPUT);
  pinMode(lmotorb, OUTPUT);
  pinMode(rmotorb, OUTPUT);
  pinMode(8, INPUT);
  pinMode(11, INPUT);
  pinMode(lmotor, OUTPUT);
  pinMode(rmotor, OUTPUT);

}
String stringKey;
String key;
void loop() {

   
  if (CarSerial.available()) {
   // key = "";
    key += ((char)CarSerial.read());
    
/*    String Barcode = "";
    if (( (((char)key) >= '0') && (((char)key) <= '9') ) || ( (((char)key) >= 'A') && (((char)key) <= 'Z') ) || ( (((char)key) >= 'a') && (((char)key) <= 'z') ) || (((char)key) == '-') || (((char)key) == '*') ) {
      // Serial.print((char)key);
      Barcode += (char)key;
      Serial.print(Barcode);

    } else if ( (char)key == '\0') {
      Serial.println();

    } */
    //Serial.println();
  }

  /*  if (Serial.available()) {
      CarSerial.println(Serial.read());
    }
  */

//  String BC = key;
  // Serial.println(BC);
 if ( key == "8851021962745" ) {
  Serial.println("Go to Location A");
  key ="";
 }

  bool lsensor = digitalRead(8);
  bool rsensor = digitalRead(11);
  if ((lsensor == HIGH) && (rsensor == HIGH))
  {
    //both sensors on white
    // go forward
    digitalWrite(lmotorf, HIGH);
    digitalWrite(rmotorf, HIGH);
    analogWrite(lmotor, 255);
    digitalWrite(lmotorb, LOW);
    digitalWrite(rmotorb, LOW);
    analogWrite(rmotor, 255);
  }
  else if ((lsensor == HIGH) && (rsensor == LOW))
  {
    //right sensor on black line
    // turn right
    digitalWrite(lmotorf, HIGH);
    digitalWrite(rmotorf, LOW);
    analogWrite(lmotor, 255);
    digitalWrite(lmotorb, LOW);
    digitalWrite(rmotorb, HIGH);
    analogWrite(rmotor, 255);
  }
  else if ((lsensor == LOW) && (rsensor == HIGH))
  {
    //left sensor on black line
    // turn left
    digitalWrite(lmotorf, LOW);
    digitalWrite(rmotorf, HIGH);
    analogWrite(lmotor, 255);
    digitalWrite(lmotorb, HIGH);
    digitalWrite(rmotorb, LOW);
    analogWrite(rmotor, 255);
  }
  else
  {
    digitalWrite(lmotorf, LOW);
    digitalWrite(rmotorf, LOW);
    analogWrite(lmotor, 255);
    digitalWrite(lmotorb, LOW);
    digitalWrite(rmotorb, LOW);
    analogWrite(rmotor, 255);
  }
}

void Char_toString(char key) {

  if (key >= 32) {
    stringKey = stringKey + String(key);
  }
  else {
    Serial.println(stringKey);
    stringKey = "";

  }
}
