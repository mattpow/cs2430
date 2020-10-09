// Matthew Powell
// p2.cpp
// October 6, 2020
//
// Purpose: Execution of test cases to verify functionality and completeness
// of the Stack class.
//
// The file will run through the set of public functions created to assess
// that the functions perform properly. The test cases will also test whether
// the Stack class is able to properly utilize the Copy Constructor,
// the overloaded assignment operator, and the destructor.

#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
	// s1, s3, s4 - Declaration of Stack objects to be used in testing below
	Stack s1;
	Stack s3;
	Stack s4(3);

	cout << "*** Running Stack Tests ***" << endl;

	cout << endl << "Test: Pushing to Stack s1" << endl;
	cout << "--- Pushing value to s1: 5" << endl;
	s1.push(5);
	cout << "--- Pushing value to s1: 10 (non-prime)" << endl;
	s1.push(10);
	cout << "--- Pushing value to s1: 7" << endl;
	s1.push(7);
	cout << "--- Pushing value to s1: 397" << endl;
	s1.push(397);
	cout << "--- Pushing value to s1: 72 (non-prime)" << endl;
	s1.push(72);
	
	cout << endl << "Test: Peeking Stack s1" << endl;
	cout << "--- Peeked value: " << s1.peek() << endl;
	
	cout << endl << "Test: Popping from Stack s1" << endl;
	cout << "--- Popped from s1: " << s1.pop() << endl;
	cout << "--- Popped from s1: " << s1.pop() << endl;
	cout << "--- Peeked value from s1: " << s1.peek() << endl;
	
	cout << endl << "Test: EmptyStack Exception" << endl;
	try {
		cout << "--- Popped from s1: " << s1.pop() << endl;
		cout << "--- Popped from s1: " << endl;
		s1.pop();
	} catch (Stack::EmptyStack e) {
		cout << "\33[31mEncountered an EmptyStack error when popping" << endl
		<< "from s1\33[0m" << endl;
	}
	
	try {
		cout << "--- Peeking from s1: " << endl;
		s1.pop();
	} catch (Stack::EmptyStack e) {
		cout << "\33[31mEncountered an EmptyStack error when peeking" << endl
		<< "from s1\33[0m" << endl;
	}
	
	cout << endl << "Test: empty function on Stack s1" << endl;
	cout << "--- Pushing value to s1: 5" << endl;
	s1.push(5);
	cout << "--- Is empty: " << (s1.empty() ? "true" : "false") << endl;
	cout << "--- Popped from s1: " << s1.pop() << endl;
	cout << "--- Is empty: " << (s1.empty() ? "true" : "false") << endl;
	cout << "--- Pushing value to s1: 10 (non-prime)" << endl;
	s1.push(10);
	cout << "--- isEmpty: " << (s1.empty() ? "true" : "false") << endl;
	
	cout << endl << "Reset: Pushing to Stack s1" << endl;
	cout << "--- Pushing value to s1: 5" << endl;
	s1.push(5);
	cout << "--- Pushing value to s1: 7" << endl;
	s1.push(7);
	cout << "--- Pushing value to s1: 397" << endl;
	s1.push(397);
	
	cout << endl << "Test: Copy Constructor" << endl;
	cout << "--- Creating Stack s2 from Stack s1:" << endl;
	
	Stack s2(s1);
	
	cout << "--- Peeking s1: " << s1.peek() << endl;
	cout << "--- Peeking s2: " << s2.peek() << endl;
	
	cout << endl << "Test: Overloaded Assignment Operator" << endl;
	cout << "--- Creating Stack s3:" << endl;
	cout << "--- Pushing value to s3: 241" << endl;
	s3.push(241);
	cout << "--- Pushing value to s3: 937" << endl;
	s3.push(937);
	cout << "--- Pushing value to s3: 577" << endl;
	s3.push(577);
	cout << "--- Peeking s3: " << s3.peek() << endl;
	
	cout << "--- Assigning s1 to s3" << endl;
	s3 = s1;
	
	cout << "--- Peeking s1: " << s1.peek() << endl;
	cout << "--- Peeking s3: " << s3.peek() << endl;
	
	cout << endl << "Test: Resize Stack" << endl;
	cout << "--- Adding 10 values to Stack s4 (inital size of 3)" << endl;
	s4.push(2);
	s4.push(3);
	s4.push(5);
	s4.push(7);
	s4.push(11);
	s4.push(13);
	s4.push(17);
	s4.push(19);
	s4.push(23);
	s4.push(29);
	cout << "--- Peeking s4: " << s4.peek() << endl;
	
	cout << endl << "Cleaning: " << endl;
	cout << "--- Deleting Stacks" << endl;
	cout << endl << "*** Ending Stack Tests ***";
	return 0;
}