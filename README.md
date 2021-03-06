# Introduction To Robotics (2021 - 2022)

Introduction to Robotics laboratory homeworks, taken in the 3rd year at the Faculty of Mathematics and Computer Science, University of Bucharest. We will discuss and learn about robotics using Arduino Uno. 

# Homework 1 - Light up a RGB led

## Components

* RGB led
* wires and 3 resistors
* 3 potentiometers

## Task

Use a separate potentiometer in controlling each of the color of the RGB led (Red,Green and Blue).  The control must be done with digital electronics(you must read the value of the potentiometer with Arduino, and write a mapped value to each of the pins connected to the led).

## Setup Pictures

![setup_image_1](./Homework1/setup_pictures/setup_image1.jpg)
![setup_image_2](./Homework1/setup_pictures/setup_image2.jpg)

## Youtube Demo

https://www.youtube.com/watch?v=BxD2xCbVAZc

# Homework 2 - Traffic Lights

## Components

* 5 LEDs
* 1 button
* 1 buzzer
* wires and 3 resistors

## Task

Building the traffic lights for a crosswalk. You will use 2 LEDs to represent the traffic lights for people (red and green) and 3 LEDs to represent the traffic lights for cars (red, yellow and green). See the states it needs to go through. The system has the following states:

1. State 1 (default, reinstated after state 4 ends): green light for cars, red light for people, no sounds. Duration: indefinite, changed bypressing the button.
2. State 2 (initiated by counting down 10 seconds after a button press): the light should be yellow for cars, red for people and no sounds. Duration: 3 seconds.
3. State 3 (iniated after state 2 ends): red for cars, green for people and a beeping sound from the buzzer at a constant interval. Duration: 10 seconds.
4. State 4 (initiated after state 3 ends): red for cars, blinking green for people and a beeping sound from the buzzer, at a constant interval, faster than the beeping in state 3.

## Setup Pictures

![setup_image_2](./Homework2/setup_pictures/h2setup_picture2.jpg)

## Youtube Demo

https://www.youtube.com/watch?v=YbOIRNmDqcI

# Homework 3 - EMF Detector

## Components

* 7-segment display
* 1 buzzer
* wires and resitors

## Task

Should detect EMF (check body and near outlets). It should print the value on the 7-segment display and should make a sound based on the intensity.

## Setup Pictures

![setup_image_1](./Homework3/setup_pictures/setup_image1.jpg)

## Youtube Demo

https://www.youtube.com/watch?v=06nDbn-i898

# Homework 4 - 4 digits 7-segment display number increment

## Components

* 4 digit 7-segment display
* 1 joystick
* 1 shift register
* wires and resitors

## Task

First  state:   you  can  use  a  joystick  axis  to  cycle  through  the  4 digits; using the other axis does nothing.  A blinking decimal point shows the current digit position.  When pressing the button ,  you  lock  in  on  the  selected  digit  and  enter  the second state.  In this state, the decimal point stays always on, no longer blinking and you can no longer use the axis to cycle through the 4 digits. Instead, using the other axis, you can increment on decrement the number on the current digit.  Pressing the button again returns you to the previous state.  For bonus, save the last value in eeprom and load it when starting arduino.  Also, keep in mind that when changing the number, you must increment it for each joystick movement - it should not work continuosly increment if you keep the joystick in one position.

## Setup Pictures

![setup_image1](./Homework4/setup_pictures/setup_image1.jpg)

## Youtube Demo

https://www.youtube.com/watch?v=SFksSZss9WE

