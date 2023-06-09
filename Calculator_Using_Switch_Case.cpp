#include <iostream>
#include <stdlib.h>
using namespace std;

// Functions declarations
void calculatefunc(double numbers[], char operand);
void startCalculator();
void restartCalculator();

// variable declarations
bool doCalculation = true;

// main function
int main() {
  system("Clear"); // user "CLS" for windows
  cout << "Calculator startup \n\n" << endl;
  while (doCalculation)
  {
    startCalculator();
  }
  return 0;
}

void startCalculator(){
  char operation;
  cout << "Enter a mathematical operator: " << endl;
  cin >> operation;
  if (operation != '+' && operation != '-' && operation != '/' && operation != '*') {
    cout << "Choose an operator with either (+ , - , * or /)" << endl;
    return;
  }
  double operands[2] = {};
  for (int i = 0; i < 2; i++){
    string another = "a";
    if (i == 1){
      another = "another";
    }
    cout << "Enter " << another << " Number: " << endl;
    cin >> operands[i];
  }
  calculatefunc(operands, operation);
  restartCalculator();
}

void calculatefunc(double numbers[], char operand){
  double result = 0;
  bool is_zero_division = false;
  switch (operand) {
    case '+' :
      result = numbers[0] + numbers[1];
      break;
    case '-' :
      result = numbers[0] - numbers[1];
      break;
    case '*' :
      result = numbers[0] * numbers[1];
      break;
    case '/' :
      if (numbers[1] == 0){
        is_zero_division = true;
        break;
      }
      result = numbers[0] / numbers[1];
      break;
    default:
      break;
  }
  if (is_zero_division) {
    cout << "Cannot divide by zero" << endl;
  } else {
    cout << "----------------------" << endl;
    cout << numbers[0] << " " << operand << " " << numbers[1] << " = " << result << endl;
    cout << "----------------------" << endl;
  }
}

void restartCalculator(){
  cout << "Do you want to perform another calculation? (y/n)" << endl;

  char choice;
  cin >> choice;

  if (choice != 'y' && choice != 'n'){
    cout << choice << " is not a recognized command" << endl;
  }

  if (choice == 'n'){
    doCalculation = false;
  }
}