#include "Setting.h"

byte Count = 0;

// Position X

void pX() {


  Serial.println(Count);
  Serial.println("Go to Location X");
  if ( Count == 0 ) {
    Count++;
  }
  Serial.println(Count);
  /*
    // ถึง x  แต่ยังไม่หยิบของออก
    while (Switch == 0 && Count == 1) {

    }
  */

  // ถึง x  และหยิบของออกแล้ว
  if (digitalRead(8) == 0 && Count == 1) {
    Serial.println("X");
    //both sensors on white
    // go forward
    digitalWrite(lmotorf, 0);
    digitalWrite(rmotorf, 0);
    analogWrite(lmotor, 100);
    digitalWrite(lmotorb, LOW);
    digitalWrite(rmotorb, LOW);
    analogWrite(rmotor, 100);
    delay(500);
    //       Count++;
    //       Serial.println(Count);
  }
  /*
      while (Switch == 0 && Count == 2){
        Serial.println("Test");
      }
  */
  while (digitalRead(8) == 1 && Count == 1) {
    Serial.println("Go  X to Stop");
    //both sensors on white
    // go forward
    digitalWrite(lmotorf, 1);
    digitalWrite(rmotorf, 1);
    analogWrite(lmotor, 100);
    digitalWrite(lmotorb, LOW);
    digitalWrite(rmotorb, LOW);
    analogWrite(rmotor, 100);
    delay(500);
    //       Count++;
    //       Serial.println(Count);
    key = "";
    Count++;
    break;
  }
  // Count++;
  Serial.println(Count);
  // key = "";
  // Count = 0;

}

void toStop() {
  while ((digitalRead(10) == LOW) && (digitalRead(9) == LOW)) {
    //Stop
    digitalWrite(lmotorf, LOW);
    digitalWrite(rmotorf, 0);
    analogWrite(lmotor, 0);
    digitalWrite(lmotorb, 0);
    digitalWrite(rmotorb, LOW);
    analogWrite(rmotor, 0);
    Count++;
    break;
  }

  if (digitalRead(8) == 1 && Count == 2) {
    digitalWrite(lmotorf, 1);
    digitalWrite(rmotorf, 1);
    analogWrite(lmotor, 100);
    digitalWrite(lmotorb, LOW);
    digitalWrite(rmotorb, LOW);
    analogWrite(rmotor, 100);
    delay(500);
  }
  
    if (digitalRead(8) == 1 && Count == 3) {
    digitalWrite(lmotorf, 1);
    digitalWrite(rmotorf, 1);
    analogWrite(lmotor, 100);
    digitalWrite(lmotorb, LOW);
    digitalWrite(rmotorb, LOW);
    analogWrite(rmotor, 100);
    delay(500);
  }
  
    if (digitalRead(8) == 1 && Count == 4) {
    digitalWrite(lmotorf, 1);
    digitalWrite(rmotorf, 1);
    analogWrite(lmotor, 100);
    digitalWrite(lmotorb, LOW);
    digitalWrite(rmotorb, LOW);
    analogWrite(rmotor, 100);
    delay(500);
  }
  
}

