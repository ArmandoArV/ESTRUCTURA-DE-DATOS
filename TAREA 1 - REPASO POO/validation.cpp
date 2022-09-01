//Add header

#include <iostream>
#include <sstream>

#include "validation.h"

using namespace std;

int validation(int input,int lower,int top){
while (!(cin >> input) || input>top || input<lower) {
    cout << "Invalid input. Please try again." << "\n";
    cin.clear(); 
		cin.ignore(123, '\n'); 
  }
  return input;
}

double validationDouble(double input,double lower,double top){
  while (!(cin >> input) || input>top || input<lower) {
    cout << "Invalid input. Please try again." << "\n";
    cin.clear();
		cin.ignore(123, '\n');
  }
  return input;
}
