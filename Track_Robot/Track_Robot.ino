#include <SoftwareSerial.h>
#include "Position.h"

SoftwareSerial CarSerial(12, 13); // RX, TX

void setup() {
  Serial.begin(9600);
  CarSerial.begin(38400);
  Serial.println("Hello, world?");
  pinMode(lmotorf, OUTPUT);
  pinMode(rmotorf, OUTPUT);
  pinMode(lmotorb, OUTPUT);
  pinMode(rmotorb, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  //  pinMode(9, INPUT);
  //  pinMode(10, INPUT);
  pinMode(lmotor, OUTPUT);
  pinMode(rmotor, OUTPUT);

}

void loop() {


   bool lsensor = digitalRead(10);
   bool rsensor = digitalRead(9);
  // bool Switch = digitalRead(8);


  if (CarSerial.available()) {
    // key = "";
    key += ((char)CarSerial.read());
    // Serial.print(key);
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
  //Serial.println(BC);

  // จากจุด Scan ไปจุดส่งของ-วางของใส่รถแล้ว
  if (digitalRead(8) == 0 && Count == 0) {
    Serial.println("Transport");
    Serial.println(Count);
    //both sensors on white
    // go forward
    digitalWrite(lmotorf, HIGH);
    digitalWrite(rmotorf, HIGH);
    analogWrite(lmotor, 100);
    digitalWrite(lmotorb, LOW);
    digitalWrite(rmotorb, LOW);
    analogWrite(rmotor, 100);
    delay(1000);
  }

  if ( key == "X" ) {
    
  }
/*
  if ( key == "Y" ) {
    Serial.println(Count);

    Serial.println("Go to Location Y");
    // ถึง y  แต่ยังไม่หยิบของออก
    //    if (Switch == 0 && Count == 2) {
    //
    //    }

    // ถึง y  และหยิบของออกแล้ว
    if (Switch == 1 && Count == 2) {
      //both sensors on white
      // go forward
      digitalWrite(lmotorf, HIGH);
      digitalWrite(rmotorf, HIGH);
      analogWrite(lmotor, 100);
      digitalWrite(lmotorb, LOW);
      digitalWrite(rmotorb, LOW);
      analogWrite(rmotor, 100);
      delay(500);

    }

    key = "";
  }

  if ( key == "Z" ) {
    Serial.println(Count);
    Serial.println("Go to Location Z");

    //    // ถึง z  แต่ยังไม่หยิบของออก
    //    if (Switch == 0 && Count == 3) {
    //    }

    // ถึง z  และหยิบของออกแล้ว
    if (Switch == 1 && Count == 3) {
      //both sensors on white
      // go forward
      digitalWrite(lmotorf, HIGH);
      digitalWrite(rmotorf, HIGH);
      analogWrite(lmotor, 100);
      digitalWrite(lmotorb, LOW);
      digitalWrite(rmotorb, LOW);
      analogWrite(rmotor, 100);
      delay(500);
    }
    key = "";
  }




  // จุดพักรถ
  if (Switch == 1 && Count == 4) {
    Serial.println(Count);
    Serial.println("Stop");
  }

  // จากจุดพักรถมาจุด Scan
  if (Switch == 1 && Count == 5) {
    Serial.println(Count);
    Serial.println("Start");
    Count = 0;

  }
*/
  if ((lsensor == HIGH) && (rsensor == HIGH))
  {
    //both sensors on white
    // go forward
    digitalWrite(lmotorf, HIGH);
    digitalWrite(rmotorf, HIGH);
    analogWrite(lmotor, 100);
    digitalWrite(lmotorb, LOW);
    digitalWrite(rmotorb, LOW);
    analogWrite(rmotor, 100);
    //    if ((lsensor == LOW) && (rsensor == LOW))
    //  {
    //    //both sensors on white
    //    // go forward
    //    Count++;
    //    if(Count >= 4){
    //      Stop();
    //    }
    //  }
  }
  else if ((lsensor == HIGH) && (rsensor == LOW))
  {
    //right sensor on black line
    // turn right
    digitalWrite(lmotorf, HIGH);
    digitalWrite(rmotorf, LOW);
    analogWrite(lmotor, 100);
    digitalWrite(lmotorb, LOW);
    digitalWrite(rmotorb, HIGH);
    analogWrite(rmotor, 100);
  }
  else if ((lsensor == LOW) && (rsensor == HIGH))
  {
    //left sensor on black line
    // turn left
    digitalWrite(lmotorf, LOW);
    digitalWrite(rmotorf, HIGH);
    analogWrite(lmotor, 100);
    digitalWrite(lmotorb, HIGH);
    digitalWrite(rmotorb, LOW);
    analogWrite(rmotor, 100);
  }
  else if ((lsensor == LOW) && (rsensor == LOW)) {
    //Stop
    digitalWrite(lmotorf, LOW);
    digitalWrite(rmotorf, 0);
    analogWrite(lmotor, 0);
    digitalWrite(lmotorb, 0);
    digitalWrite(rmotorb, LOW);
    analogWrite(rmotor, 0);
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
