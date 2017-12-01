#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX.
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
#include <hid.h>
#include <hiduniversal.h>
#include <avr/pgmspace.h>
#include <Usb.h>
#include <usbhub.h>
#include <avr/pgmspace.h>
#include <hidboot.h>
USB     Usb;
USBHub  Hub1(&Usb);
USBHub  Hub2(&Usb);
USBHub  Hub3(&Usb);
USBHub  Hub4(&Usb);
HIDUniversal    Hid1(&Usb);
HIDUniversal    Hid2(&Usb);
HIDUniversal    Hid3(&Usb);
HIDUniversal    Hid4(&Usb);

HIDBoot<HID_PROTOCOL_KEYBOARD>    Keyboard(&Usb);
void TX(char Tx) {
  BTserial.write(Tx);
}

void TX(String Tx) {

  int i = 0;
  // while (Tx[i] != '\0') {
  BTserial.write(Tx[i]);
  i++;
  // }
}

class KbdRptParser : public KeyboardReportParser
{
    void PrintKey(uint8_t mod, uint8_t key);

  protected:
    virtual void OnKeyDown  (uint8_t mod, uint8_t key);
    virtual void OnKeyPressed(uint8_t key);
};

void KbdRptParser::OnKeyDown(uint8_t mod, uint8_t key)
{
  uint8_t c = OemToAscii(mod, key);

  if (c)
    OnKeyPressed(c);
}

/* what to do when symbol arrives */
void KbdRptParser::OnKeyPressed(uint8_t key)
{
  static uint32_t next_time = 0;      //watchdog
  static uint8_t current_cursor = 0;  //tracks current cursor position

  //Serial.println((char)key );
  //Char_toString((char)key);
  /*
    if ( (((char)key) >= '0') && (((char)key) <= '9') ) {
        Serial.print("ASCII: ");
      Serial.println((char)key);
    }
  */
  //Serial.print("Barcode: ");
  // static uint8_t count = 0;
  String Barcode = "";
  if (( (((char)key) >= '0') && (((char)key) <= '9') ) || ( (((char)key) >= 'A') && (((char)key) <= 'Z') ) || ( (((char)key) >= 'a') && (((char)key) <= 'z') ) || (((char)key) == '-') || (((char)key) == '*') || ( (char)key == '\0')) {
    // Serial.print((char)key);
    Barcode += (char)key;
    Serial.print(Barcode);
    TX(Barcode);
  } else {
    Serial.println();
    // Serial.print("Barcode :\t");
  }

};
KbdRptParser Prs;
int randomData0, randomData1;
unsigned long timePrevious;

void setup()
{
  // start th serial communication with the host computer
  Serial.begin(9600);
  Serial.println("Arduino with HC-05 is ready ");

  // start communication with the HC-05 using 38400
  BTserial.begin(38400);
  //Serial.println("BTserial started at 38400");
  Serial.print("Plase Enter  Barcode  or ScanBarcode: ");
  Serial.print(">");
  if (Usb.Init() == -1) {
    Serial.println("OSC did not start.");
  }

  delay( 200 );
  Hid1.SetReportParser(0, (HIDReportParser*)&Prs);
  Hid2.SetReportParser(0, (HIDReportParser*)&Prs);
  Hid3.SetReportParser(0, (HIDReportParser*)&Prs);
  Hid4.SetReportParser(0, (HIDReportParser*)&Prs);
  delay( 200 );


}

String Massenger = "";
String stringKey;

void Char_toString(char key) {

  if (key >= 32) {
    stringKey = stringKey + String(key);
  }
  else {
    Serial.println(stringKey);
    stringKey = "";

  }
}
void loop()
{
  Usb.Task();
  if (Serial.available() > 0) {
    Massenger = Serial.readString();
    TX(Massenger);
    Serial.println();
  }


}
