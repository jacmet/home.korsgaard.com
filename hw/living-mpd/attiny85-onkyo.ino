/*
  Control Onkyo TX-SR307 from Attiny85
  Turn on/change to DVD input on ext reset (PB5 to gnd)
  Onkyo control code from https://github.com/docbender/Onkyo-RI

  Supported RI commands on TX-SR307:
  0x20: CD input
  0x2f: Power on + CD input
  0x120: DVD input
  0x12f: Power on + DVD input
  0x170: Dock input
  0x17f: Power on + Dock input
  0x2b0: Dimmer high
  0x2b1: Dimmer mid
  0x2b2: Dimmer low
*/

/* connect PB0 to tip of RI jack / GND to sleeve */
#define ONKYO_PIN 0


void onkyoWriteHeader()
{
  digitalWrite(ONKYO_PIN,HIGH);
  delayMicroseconds(3000);
  digitalWrite(ONKYO_PIN,LOW);
  delayMicroseconds(1000);
}

void onkyoWriteBit(bool level)
{
  digitalWrite(ONKYO_PIN,HIGH);
  delayMicroseconds(1000);
  digitalWrite(ONKYO_PIN,LOW);

  if(level)
    delayMicroseconds(2000);
  else
    delayMicroseconds(1000);
}

void onkyoWriteFooter()
{
  digitalWrite(ONKYO_PIN,HIGH);
  delayMicroseconds(1000);
  digitalWrite(ONKYO_PIN,LOW);
  delay(20);
}

void onkyoSend(int command)
{
  onkyoWriteHeader();

  for(int i=0;i<12;i++)
  {
    bool level = command & 0x800;
    command <<= 1;
    onkyoWriteBit(level);
  }

  onkyoWriteFooter();
}


void setup() {
  /* ensure micronucleus (built with ENTRY_POWER_ON entry mode)
   * doesn't wait for USB communication on external reset */
  MCUSR = 0;

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(ONKYO_PIN, OUTPUT);
  digitalWrite(ONKYO_PIN, LOW);

  digitalWrite(LED_BUILTIN, HIGH);
  onkyoSend(0x120); /* change to DVD */
  onkyoSend(0x12f); /* power on + change to DVD */
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  delay(1000);
}
