// Matthew Powell
// lab1.cpp

#include <iostream>

using namespace std;

const int SIZE = 8;


int max(int numbers[SIZE]) {
  int max = 0;
  for (int i = 0; i < SIZE; i++) {
    if (numbers[i] > max) {
      max = numbers[i];
    }
  }
  return max;
}

int main() {
  bool playAgain = true;
  static int numbers[SIZE];
  int index = 0;

  cout << "Welcome!" << endl;

  while (playAgain) {
    index = 0;
    while (index < SIZE) {
      cout << "Please add an EVEN number between 10 and 100: ";
      cin >> numbers[index];
      if (numbers[index] % 2 == 0 && numbers[index] > 9 &&
          numbers[index] < 101) {
        index++;
      } else {
        cout
          << "Only even numbers between 10 and 100 are allowed. "
          << "Try again."
          << endl;
      }
    }

    for (int i = 0; i < SIZE; i++) {
      cout << "Index: " << i << " | Value: " << numbers[i] << endl;
    }
    cout << "Maximum value: " << max(numbers) << endl << endl;

    char response;
    cout << "Do you want to go again? (y/n): ";
    cin >> response;
    if (response == 'n') {
      playAgain = false;
    }
  }
  cout << endl << "End of Lab1 Pgm" << endl;
  return 0;
}
