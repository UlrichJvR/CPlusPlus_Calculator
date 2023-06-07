#include <iostream>
using namespace std;

void calculatefunc(int numbers[], char operand);

int main() {
  char operand;
  cout << "Enter a operand: ";
  cin >> operand;
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
  bool is_zero = false;
  bool can_continue = true;
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
        is_zero = true;
        break;
      }
      answer = numbers[0] / numbers[1];
      break;
    default:
      cout << "Choose an operand with either (+ , - , * or /)" << endl;
      can_continue = false;
      break;
  }
  if (is_zero) {
    cout << "Cannot divide by zero" << endl;
  } else if (can_continue) {
    cout << numbers[0] << " " << operand << " " << numbers[1] << " = " << answer << endl;
  }
}