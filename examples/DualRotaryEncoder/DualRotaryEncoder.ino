#include "RotaryEncoder.h"
volatile uint8_t flag = false;
volatile uint8_t flag2 = false;
volatile int8_t count;
volatile int8_t count2;

RotaryEncoder myEncoder(9, 10);
RotaryEncoder myEncoder2(11, 12);

void setup() {
  Serial.begin(115200);
  Serial.println("Rotary Encoder Library");
  pinMode(GREEN_LED, OUTPUT);
  myEncoder.begin(encoder_callback);
  myEncoder2.begin(encoder2_callback);
}


void loop() {
  if (flag) {
    flag = false;
    Serial.print("count: ");
    Serial.println(count);
  }
  if (flag2) {
    flag2 = false;
    Serial.print("count2: ");
    Serial.println(count2);
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

void encoder2_callback()
{
  static uint8_t led_state = 0;
  led_state ^= 1;
  digitalWrite(GREEN_LED, led_state);

  uint8_t state = myEncoder2.handle_encoder();
  
  if (state == DIRECTION_NONE)
    return;
  if (state == DIRECTION_CCW)
    count2++;
  else
    count2--;

  flag2 = true;
}
