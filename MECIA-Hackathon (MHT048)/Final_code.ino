#include <SoftwareSerial.h>
#include <Servo.h>

Servo servo_1;
Serial servo_2;
int servo_variable = 0;

String value;
#define en_a 2
#define input_1 3
#define input_2 4

/* Create object named bt of the class SoftwareSerial */
SoftwareSerial bt(0, 1); /* (Rx,Tx) */

void setup() {
  servo_1.attach(3);
  servo_2.attach(6);
  pinMode(en_a, OUTPUT);
  pinMode(input_1, OUTPUT);
  pinMode(input_2, OUTPUT);
  bt.begin(9600);      /* Define baud rate for software serial communication */
  Serial.begin(38400); /* Define baud rate for serial communication */
}

void motor_a() {
  digitalWrite(input_1, HIGH);
  digitalWrite(input_2, LOW);

  analogWrite(en_a, 130);
}

void stop() {
  digitalWrite(input_2, LOW);
  digitalWrite(input_1, LOW);
}
void servo_lid_up() {
  for (servo_variable = 0; servo_variable < 90; servo_variable++) {
    servo1.write(i);
    servo2.write(90 - servo_variable);
    delay(10);
  }
}
void servo_lid_dowm()
{
  for (servo_variable = 90; servo_variable > 0; servo_variable--) {
    servo1.write(servo_variable;
    servo2.write(90 - servo_variable);
    delay(10);
  }
}
void loop() {
  if (bt.available()) {
    value = bt.readString();
    if (value == "1") {
      motor_a();
    }
    if (value == "0") {
      stop();
    }
    if (value == "00")
    {
      servo_lid_up();
    }
    if (value == "11")
    {
      servo_lid_dowm();
    }
  }
}