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
  if (( (((char)key) >= '0') && (((char)key) <= '9') ) || ( (((char)key) >= 'A') && (((char)key) <= 'Z') ) || ( (((char)key) >= 'a') && (((char)key) <= 'z') ) || (((char)key) == '-') || (((char)key) == '*') ) {
    // Serial.print((char)key);
    Barcode +=(char)key;
    Serial.print(Barcode);
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
  //pinMode(16, OUTPUT);
  //pinMode(17, INPUT);
  //pinMode(28, OUTPUT);
  //digitalWrite(28, HIGH);
  delay(1000);
  Serial.begin(9600);
  Serial.println("Start");
  // Serial.print("Barcode :\t");
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
String stringKey;
void loop()
{
  Usb.Task();

  //  if (digitalRead(17) == LOW) {
  //
  //    digitalWrite(16, HIGH);
  //
  //  }
  //  else {
  //    digitalWrite(16, LOW);
  //  }


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
