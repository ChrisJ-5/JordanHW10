// File Name: test_all_App.cpp
/* The purpose of this program is to test the functionality of the AnalogIn,
  GPIO, and LED classes. 
  This program does the following:
    It turns on LEDs 1 and 3 for 5 seconds before turning them off
    It flashes LED 2 for 5 seconds before turning it off
    It then reads the analog value from the temperature sensor and prints the
    value to the screen
    It then reads the value of the pushbutton. If the button is pressed, the LED
    will light for 3 seconds before turning off. If the button is not pressed,
    the LED will not light at all.

    Example Invocation: ./test_all_App
*/

#include"AnalogIn.h"
#include"myGpio.h"
#include"LED.h"
#include<iostream>
#include<unistd.h>
using namespace std;

int main() {

  LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };

  leds[1].turnOn();
  leds[3].turnOn();
  sleep(5);
  leds[1].turnOff();
  leds[3].turnOff();

  leds[2].flash("100");
  sleep(5);
  leds[2].turnOff();

  AnalogIn analogInput(0);
  int temp = analogInput.readAdcSample();
  cout << "Analog Value is " << temp << endl;

  // Read P8.16 and print out the value
  MYGPIO inputGpio(46);
  cout << "The value of P8.16 is: " << inputGpio.getValue() << endl;

  if (inputGpio.getValue() == 0) {
    // If pressed, turn on the LED connected to P9.12
    MYGPIO outputGpio(60);  
    outputGpio.setDirection(OUTPUT);
    outputGpio.setValue(HIGH);
    cout << "P9.12 LED turned on!" << endl;
    sleep(3);
    outputGpio.setValue(LOW);
    }
}
