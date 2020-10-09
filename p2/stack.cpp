// Matthew Powell
// p2.cpp
// October 6, 2020
//
// Purpose: Function logic for the Stack object
	
#include "stack.h"

Stack::Stack(int size)
{
	if (size < 3) {
		size = 50;
	}
	max = size;
	list = new int[max];
	top = 0;
}

Stack::Stack(const Stack& copy)
{
	max = copy.max;
	list = new int[max];
	top = copy.top;
	
	for (int i = 0; i < top; i++) {
		list[i] = copy.list[i];
	}
}

Stack& Stack::operator=(const Stack& rhs)
{
	if (this != &rhs) {
		delete [] list;
		max = rhs.max;
		list = new int[max];
		top = rhs.top;
		for (int i = 0; i < top; i++) {
			list[i] = rhs.list[i];
		}
	}
	return *this;
}

Stack::~Stack()
{
	delete [] list;
}

void Stack::push(int value)
{
	if (isFull()) {
		resize();
	}
	if (isPrime(value)) {
		list[top] = value;
		top++;	
	}
}

int Stack::pop()
{
	if (empty()) {
		throw EmptyStack();
	} else {
		top--;
		return list[top];
	}
}

int Stack::peek()
{
  if (empty()) {
		throw EmptyStack();
	} else {
		return list[top - 1];
	}
}

bool Stack::empty() const
{
	return top == 0;
} 

bool Stack::isFull() const
{
	return top == max;
}

bool Stack::isPrime(int num) const
{
	bool prime = true;
	if (num > 1) {
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				prime = false;
			}
		}
	} else {
		prime = false;
	}
	return prime;
}

void Stack::resize()
{
	int* tmp;
	int larger = static_cast<int> (max * 1.5);
	tmp = new int[larger];
	for (int i = 0; i < top; i++) {
		tmp[i] = list[i];
	}
	delete [] list;
	list = tmp;
	max = larger;
}