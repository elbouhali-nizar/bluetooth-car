#include <SoftwareSerial.h>

#define M1_PIN1 2

#define M1_PIN2 4

#define M1_VEL_PIN 3

#define M2_PIN1 6

#define M2_PIN2 7

#define M2_VEL_PIN 5

#define white 10

#define green 12

#define red 13

#define bip 11

SoftwareSerial HC06(9,8);

int val1=150;

int val2=150;

char t=' ';

float dist;

void L298N_Motor_Control_Robot(int pin1, int pin2, int velpin, bool mover, int vel)

{

digitalWrite(pin1, mover);

digitalWrite(pin2, !mover);

analogWrite (velpin, vel);

}

float getDistance(int trig,int echo)

{

pinMode(trig,OUTPUT);

digitalWrite(trig,LOW);

delayMicroseconds(2);

digitalWrite(trig,HIGH);

delayMicroseconds(10);

digitalWrite(trig,LOW);

pinMode(echo, INPUT);

return pulseIn(echo,HIGH,30000)/58.0;

}

void setup()

{

Serial.begin(115200);

HC06.begin(9600);

pinMode(white, OUTPUT);

pinMode(green, OUTPUT);

pinMode(red, OUTPUT);

pinMode(bip, OUTPUT);

pinMode(M1_PIN1, OUTPUT);

pinMode(M1_PIN2, OUTPUT);

pinMode(M1_VEL_PIN, OUTPUT);

pinMode(M2_PIN1, OUTPUT);

pinMode(M2_PIN2, OUTPUT);

pinMode(M2_VEL_PIN, OUTPUT);

}

void loop()

{

dist = getDistance(14,15);

if(HC06.available())

{

t = HC06.read();

}

if(t=='e')

{

digitalWrite(red,HIGH);

delay(600);

digitalWrite(red,LOW);

delay(600);

L298N_Motor_Control_Robot(M1_PIN1, M1_PIN2, M1_VEL_PIN, 0, 0);

L298N_Motor_Control_Robot(M2_PIN1, M2_PIN2, M2_VEL_PIN, 0, 0);

}

if(t=='a')

{

if (dist>=9.0)

{

digitalWrite(red,HIGH);

delay(500);

digitalWrite(red,LOW);

delay(200);

L298N_Motor_Control_Robot(M1_PIN1, M1_PIN2, M1_VEL_PIN, 0, 0);

L298N_Motor_Control_Robot(M2_PIN1, M2_PIN2, M2_VEL_PIN, 0, 0);

digitalWrite(red,HIGH);

delay(500);

digitalWrite(red,LOW);

delay(200);

digitalWrite(red,HIGH);

delay(500);

digitalWrite(red,LOW);

} else

{

digitalWrite(green,HIGH);

delay(400);

digitalWrite(green,LOW);

delay(400);

digitalWrite(green,HIGH);

delay(400);

digitalWrite(green,LOW);

L298N_Motor_Control_Robot(M1_PIN1, M1_PIN2, M1_VEL_PIN, 1, val1);

L298N_Motor_Control_Robot(M2_PIN1, M2_PIN2, M2_VEL_PIN, 1, val2);

}

}

if(t=='b')

{digitalWrite(white,HIGH);

delay(400);

digitalWrite(white,LOW);

delay(400);

digitalWrite(white,HIGH);

delay(400);

digitalWrite(white,LOW);

digitalWrite(bip,1);

delay(100);

digitalWrite(bip,0);

delay(100);

digitalWrite(bip,1);

delay(100);

digitalWrite(bip,0);

delay(100);

digitalWrite(bip,1);

delay(100);

digitalWrite(bip,0);

delay(100);

digitalWrite(bip,1);

delay(100);

digitalWrite(bip,0);

delay(100);

digitalWrite(bip,1);

delay(100);

digitalWrite(bip,0);

digitalWrite(bip,1);

delay(100);

digitalWrite(bip,0);

delay(100);

L298N_Motor_Control_Robot(M1_PIN1, M1_PIN2, M1_VEL_PIN, 0, val1);

L298N_Motor_Control_Robot(M2_PIN1, M2_PIN2, M2_VEL_PIN, 0, val2);

}

if(t=='c')

{

L298N_Motor_Control_Robot(M1_PIN1, M1_PIN2, M1_VEL_PIN, 1, val1);

delay(300);

L298N_Motor_Control_Robot(M2_PIN1, M2_PIN2, M2_VEL_PIN, 0, val2);

delay(300);

}

if(t=='d')

{

L298N_Motor_Control_Robot(M1_PIN1, M1_PIN2, M1_VEL_PIN, 0, val1);

delay(300);

L298N_Motor_Control_Robot(M2_PIN1, M2_PIN2, M2_VEL_PIN, 1, val2);

delay(300);

}

if(t=='i')

{

val1=val1+20;

t=' ';

}

if(t=='j')

{

val1=val1-20;

t=' ';

}

if(t=='k')

{

val2=val2+20;

t=' ';

}

if(t=='l')

{

val2=val2-20;

t=' ';

}

delay(100);

}
