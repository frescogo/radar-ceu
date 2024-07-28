static char msg[23] = {
  0x88,
  'a', 'b', 'c', 'd', 'e', 'f',
  'g',
  //0b010000?0,         // inb=1, out=0
  0b01000010,           // inb=1, out=0
  //?, ?, ?, ?,         // 100 10 1 0.1
  '0', '5', '5', '0',
  'h', 'i', 'j', 'k',
  'l', 'm', 'n', 'o', 'p', 'q'
};

void setup () {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop () {
  delay(500);
  if (random(0,2) == 0) {
    msg[8]  = (random(0,2) == 0) ? 0b01000010 : 0b01000000;
    msg[10] = random('0', '9');
    msg[11] = random('0', '9');
    for (int i=0; i<23; i++) {
      Serial.write(msg[i]);
    }
  }
}
