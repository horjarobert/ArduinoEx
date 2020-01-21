#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//constant variables
#define joyStickButton 7
#define joyStickPinY A0
#define joyStickPinX A1

//define joyStick keys
#define JOYSTICK_UP       B00000001 //DEC 1
#define JOYSTICK_DOWN     B00000010 //DEC 2
#define JOYSTICK_LEFT     B00000100 //DEC 4
#define JOYSTICK_RIGHT    B00001000 //DEC 8

LiquidCrystal_I2C lcdMoveIT(0x27, 20, 4); //lcd object

int joyBtnState, joyBtnLastState; //joyStick button states

int moveIT = 0; //move the character +- 1 space

//custom characters
byte coolFace[] = {
  B00000,
  B00000,
  B11011,
  B11011,
  B00000,
  B10001,
  B01110,
  B00100
};

byte doorChar[] = {
  B11111,
  B10001,
  B10001,
  B10001,
  B10011,
  B10001,
  B10001,
  B11111
};

byte okChar[] = {
  B01110,
  B01010,
  B01110,
  B00000,
  B00000,
  B01010,
  B01100,
  B01010
};

void setup() {
  //lcdMoveIT
  lcdMoveIT.init();
  lcdMoveIT.setBacklight(HIGH);

  //joystick
  pinMode(joyStickButton, INPUT);
  digitalWrite(joyStickButton, HIGH);

  joyBtnLastState = digitalRead(joyStickButton);

  Serial.begin(9600);
}

void loop() {
  //joystick states
  unsigned char joystick = 0;
  static unsigned char oldJoystick = 0;

  int pinX = analogRead(joyStickPinX);
  int pinY = analogRead(joyStickPinY);

  //custom characters
  lcdMoveIT.createChar(0, doorChar);
  lcdMoveIT.createChar(1, okChar);
  lcdMoveIT.createChar(2, coolFace);

  //set the custom character
  lcdMoveIT.setCursor(0, 0);
  lcdMoveIT.print(char(0));

  lcdMoveIT.setCursor(15, 0);
  lcdMoveIT.print(char(1));

  //joystick UP | DOWN | RIGHT | LEFT
  if (pinY >= 550) { //UP
    joystick = joystick | JOYSTICK_UP ;
  }
  else if (pinY <= 450) { //DOWN
    joystick = joystick | JOYSTICK_DOWN ;
  }
  else if (pinX >= 550) { //RIGHT
    joystick = joystick | JOYSTICK_RIGHT;
  }
  else if (pinX <= 450) { //LEFT
    joystick = joystick | JOYSTICK_LEFT;
  }

  //menu interactions
  if ((joystick == JOYSTICK_UP) && (oldJoystick == 0))
  {
    Serial.println("Joystick up");
  }
  else if ((joystick == JOYSTICK_DOWN) && (oldJoystick == 0))
  {
    Serial.println("Joystick down");
  }
  else if ((joystick == JOYSTICK_LEFT) && (oldJoystick == 0))
  {
    Serial.println("Joystick left");
    
    moveIT -= 1;
    
    if (moveIT >= 1) {
      lcdMoveIT.clear();

      lcdMoveIT.setCursor(moveIT, 0);
      lcdMoveIT.print(char(2));

    }
    else if (moveIT < 1) {
      lcdMoveIT.setCursor(3, 1);
      lcdMoveIT.print("Game over?");
      moveIT = 0; //stopped at 0
    }
  }
  else if ((joystick == JOYSTICK_RIGHT) && (oldJoystick == 0))
  {
    moveIT += 1;
    
    Serial.println("Joystick right");
    
    if (moveIT >= 1 && moveIT < 15) {
      lcdMoveIT.clear();

      lcdMoveIT.setCursor(moveIT, 0);
      lcdMoveIT.print(char(2));
    }
    else if (moveIT >= 15) {
      lcdMoveIT.setCursor(3, 1);
      lcdMoveIT.print("Congrats!");
      moveIT = 15; //stopped at 15
    }
  }
  
  oldJoystick = joystick;

  if (moveIT == 4) {
    lcdMoveIT.setCursor(2, 1);
    lcdMoveIT.print("Nice! Go on!");
  }
  else if (moveIT == 8) {
    lcdMoveIT.setCursor(3, 1);
    lcdMoveIT.print("To the WIN!");
  }
  
  //press on joystick button
  joyBtnState = digitalRead(joyStickButton);

  if ((joyBtnState == LOW) && (joyBtnLastState == HIGH))
  {
    Serial.println("Button pressed");
  }
  else if ((joyBtnState == HIGH) && (joyBtnLastState == LOW))
  {
    Serial.println("Button released");
  }

  joyBtnLastState = joyBtnState;
}
