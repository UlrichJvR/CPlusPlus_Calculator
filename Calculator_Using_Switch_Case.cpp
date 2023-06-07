#include <iostream>
using namespace std;

void calculatefunc(int numbers[], char operand);

int main() {
  char operand;
  cout << "Enter a operand: ";
  cin >> operand;
  if (operand != '+' && operand != '-' && operand != '/' && operand != '*') {
    cout << "Choose an operand with either (+ , - , * or /)" << endl;
    return 0;
  }
  int numbers[2] = {};
  for (int i = 0; i < 2; i++){
    cout << "Enter a Number: " << endl;
    cin >> numbers[i];
  }
  calculatefunc(numbers, operand);
  return 0;
}

void calculatefunc(int numbers[], char operand){
  int answer = 0;
  bool is_zero_division = false;
  switch (operand) {
    case '+' :
      answer = numbers[0] + numbers[1];
      break;
    case '-' :
      answer = numbers[0] - numbers[1];
      break;
    case '*' :
      answer = numbers[0] * numbers[1];
      break;
    case '/' :
      if (numbers[1] == 0){
        is_zero_division = true;
        break;
      }
      answer = numbers[0] / numbers[1];
      break;
    default:
      break;
  }
  if (is_zero_division) {
    cout << "Cannot divide by zero" << endl;
  } else {
    cout << numbers[0] << " " << operand << " " << numbers[1] << " = " << answer << endl;
  }
}