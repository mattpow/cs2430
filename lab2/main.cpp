#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
  int number = 0;
  int* numPtr = &number;

  cout << "Welcome to Lab 2" << endl << endl;
  cout << "Please enter a number below:" << endl;
  cin >> number;

  cout << number << endl;
  cout << numPtr << endl << endl;

  number = 100;
  cout << number << endl;
  cout << numPtr;
  return 0;
}
