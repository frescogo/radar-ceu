static char msg[23] = {
  0x88,
  'a', 'b', 'c', 'd', 'e', 'f',
  'g',
  //0b010000?0,         // inb=1, out=0
  0b01000000,           // inb=1, out=0
  //?, ?, ?, ?,         // 100 10 1 0.1
  0, 0, 0, 0,
  'h', 'i', 'j', 'k',
  'l', 'm', 'n', 'o', 'p', 'q'
};

void setup () {
  Serial.begin(9600);
}

void loop () {
  static int i = 0;
  Serial.write(msg[i]);
  i = (i+1) % 23;
  //delay(2000);
}
