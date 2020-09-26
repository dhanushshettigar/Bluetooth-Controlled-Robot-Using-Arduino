//--------------------------------------------- < SAMPLE CODE For RC BY DTiLABZ  > ---------------------------------------


//--------------------------------------------- CONECTIONS-->
//--------------------------------------------- RX (ARDUINO) --> TX (HC_05-BLUETOOTH MODULE)
//--------------------------------------------- TX (ARDUINO) --> RX (HC_05-BLUETOOTH MODULE)

//---------------------- PWM PINS  ---------------------- D9 (ARDUINO) --> EN_A (MOTOR DRIVER)
//---------------------- PWM PINS  ---------------------- D10 (ARDUINO) --> EN_B (MOTOR DRIVER)

//--------------------------------------------- D2 (ARDUINO) --> IN-1 (MOTOR DRIVER) --> OUT1 OF MOTOR(+VE)
//--------------------------------------------- D3 (ARDUINO) --> IN-2 (MOTOR DRIVER) --> OUT2 OF MOTOR
//--------------------------------------------- D4 (ARDUINO) --> IN-3 (MOTOR DRIVER) --> OUT3 OF MOTOR(+VE)
//--------------------------------------------- D5 (ARDUINO) --> IN-4 (MOTOR DRIVER) --> OUT4 OF MOTOR

#include <SoftwareSerial.h>

#define Bluetooth_RX_Pin 11      //RX (ARDUINO) --> TX (HC_05-BLUETOOTH MODULE)
#define Bluetooth_TX_Pin 12      //TX (ARDUINO) --> RX (HC_05-BLUETOOTH MODULE)

SoftwareSerial mySerial(Bluetooth_RX_Pin, Bluetooth_TX_Pin); // RX, TX

char Bt_Data;

const int LEFT_ENABLE = 10; // ENABLE PIN DECLARATION
const int RIGHT_ENABLE = 9;

const int MOTOR_SPEED = 150; // ROTATION SPEED

void Set_Speed(int SPEED)
{
  analogWrite(LEFT_ENABLE , SPEED);
  analogWrite(RIGHT_ENABLE , SPEED);
}

void moveForward()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void moveBackward()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void arcRight()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void arcLeft()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void spotRight()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void spotLeft()
{
  Set_Speed(MOTOR_SPEED);
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void Stop()
{
  Set_Speed(0);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}

void setup() {
  // pin declarations
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  mySerial.begin(9600); //----------------BAUD RATE VALUE TO COMMUNICATE WITH HC_05 MODULE
}

void loop()
{
  if (mySerial.available() > 0)
  {
    Bt_Data = mySerial.read();  // BLUETOOTH DATA RECIVED 
    
    if (Bt_Data == 'F')
    {
      moveForward();
    }
    else if (Bt_Data == 'B')
    {
      moveBackward();
    }
    else if (Bt_Data == 'R')
    {
      spotRight();
    }
    else if (Bt_Data == 'L')
    {
      spotLeft();
    }
    else if (Bt_Data == 'G')
    {
      arcRight();
    }
    else if (Bt_Data == 'I')
    {
      arcLeft();
    }
    else if (Bt_Data == 'S')
    {
      Stop();
    }
    else
    {
      Stop();
    }
  }
}
