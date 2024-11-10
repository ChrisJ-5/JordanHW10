// File Name: test_analog.cpp
// This is the test application used to test the AnalogIn class.
// This program initializes an object with number 0, calls get number, and then
// reads the analog value. 
// This program takes no command line arguments.
// Example invocation: ./test_analog


#include"AnalogIn.h"
#include<iostream>
using namespace std;

int main() {
  // Initialize object with number = 0
  AnalogIn analogInput(0);
  
  // Call getNumber()
  cout << "Analog input number: " << analogInput.getNumber() << endl;
  
  // Call readAdcSample()
  int temp = analogInput.readAdcSample();
  cout << "Analog Value is " << temp << endl;
  
  return 0;
}
