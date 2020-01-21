# MoveIT - move the character to the finish (ok) line
***

### Circuit
***
- Arduino board; 1 LCD with I2C communication bus; joystick;    
- Connect the joystick: SW (switch button) to digital 7, joystick pinY to analog A0, joystick pinX to analog A1, GND to GND (in Arduino board), VCC to 5V (in Arduino board); the LCD  with I2C: SCL to SCL, SDA to SDA, GND to GND, VCC to 5V (all of these with Arduino board...);         
- Copy the code into your Arduino sketch.    

### Purpose
***
- Improve my skills;    
- Make a little game (for fun).

### How it works?
***
- If everything is OK (with your circuit and the Arduino sketch), compile it; now you'll see a door at char 0, and an OK sign at char 15. Turn right with the joystick, now you'll see a cool face, that face must finish the game; step by step move to right until it will appear a message 'Congrats!' on second row. That's it... you can play with joystick (left/right) to move the cool face from the ALFA to OMEGA. Have fun and don't forget to learn something useful from this little project! 
