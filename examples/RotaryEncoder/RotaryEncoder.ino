#include "RotaryEncoder.h"
volatile uint8_t flag = false;
volatile int8_t count;

RotaryEncoder myEncoder(9, 10);

void setup() {
  Serial.begin(115200);
  Serial.println("RotaryEncoder Library");
  pinMode(GREEN_LED, OUTPUT);
  myEncoder.begin(encoder_callback);
}


void loop() {
  if (flag) {
    flag = false;
    Serial.print("count: ");
    Serial.println(count);
  }
}

void encoder_callback()
{
  static uint8_t led_state = 0;
  led_state ^= 1;
  digitalWrite(GREEN_LED, led_state);

  uint8_t state = myEncoder.handle_encoder();
  
  if (state == DIRECTION_NONE)
    return;
  if (state == DIRECTION_CCW)
    count++;
  else
    count--;

  flag = true;
}
