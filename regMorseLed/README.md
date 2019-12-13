# Morse code - led blinking
***

### Circuit
***
- Arduino board; 1 potentiometer; 1 led; wires...     
- Connect the potentiometer output to A0 (analog pin 0 in Arduino; don't forget GNG to GND and VCC/+ to 5V); led + to D2 (digital pin 2 in Arduino; don't forget to put a resistance to led - pin, I have a resistance of 1K);      
- Copy the code into your Arduino sketch.    

### Purpose
***
- Learn new things;   
- Improve electronic/programming skills;   
- Implement Morse code into an electronic project;
- Make something useful.

### How it works?
***
- If you have the circuit correctly installed, and the code in your Arduino sketch, now open Serial Monitor, and every step from your potentiometer will be interpreted as a number, but every number (from 1 to 26) in the code has a case (representing the english alphabet...). Now, if you put the potentiometer at state 1, it will appear on Serial Monitor: 'Current letter: A . _ ', and your led will blink the point at 300ms ratio, dash at 1000ms, and pause at 500ms. You can play with your potentiometer, in Serial Monitor you'll see the letter, together with Morse code for that letter... and the led in front of you will blink automatically (in a loop) the properly Morse code for that letter...
