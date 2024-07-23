void setup () {
  Serial.begin(9600);
}

void loop () {
  static int b = 0;
  Serial.write('A' + (b++ % 63));
  delay(2000);
}
