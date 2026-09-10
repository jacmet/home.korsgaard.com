/*
trivial serial protocol for relay control. Understands the following commands:
- relay-on
- relay-off
- relay-state
*/

#define RELAY_PIN       12
#define MAX_CMDLENGTH   16

char buf[MAX_CMDLENGTH + 1];
int state = 0;


void set_pin(int state)
{
  if (state != -1) {
    digitalWrite(LED_BUILTIN, state);
    digitalWrite(RELAY_PIN, state);
  }
 
  if (digitalRead(LED_BUILTIN))
    Serial.println("on");
  else
    Serial.println("off");  
}

void handle_cmd(const char *cmd)
{
  if (!strcmp(cmd, "relay-on")) {
    set_pin(1);
  } else if (!strcmp(cmd, "relay-off")) {
    set_pin(0);
  } else if (!strcmp(cmd, "relay-state")) {
    set_pin(-1);
  } else {
    Serial.println("?");
  }  
}

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

//  set_pin(1);
}


void loop() {
  if (Serial.available()) {
    char c = Serial.read();
  
    if (state == -1) {
        if (c == '\n')
          state = 0;
    } else {
      if (c != '\r' && c != '\n' && state < MAX_CMDLENGTH) {
        buf[state++] = c;
      } else {
        buf[state] = '\0';
        handle_cmd(buf);
        state = -1;
      }
    }
  }
}
