void setup() {
  Serial.begin(9600);
  const int arysz = 6;
  int ary[arysz] = {4, 32, 6, 2, -1, 5};
  int wantedval = -1;
  int wantedpos;
  for (int i = 0; i < arysz; i++) {
    if (wantedval == ary[i]) {
      wantedpos = i;
      break;
    }
  }
Serial.println(wantedpos);
}

void loop() {

}

