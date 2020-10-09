// Matthew Powell
// p2.cpp
// October 6, 2020
//
// Purpose: class definition of the Stack object
	
class Stack {
	public:
		class EmptyStack{};
		
		explicit Stack(int size = 50);
		
		Stack(const Stack &copy);
		
		~Stack();
		
		Stack& operator = (const Stack &rhs);
		
		// Adds integer to the top of the Stack
		void push(int value);
		
		// Returns and removes value from the top of the Stack
		int pop();
		
		// Returns value from the top of the Stack
		int peek();
		
		// Determines whether Stack is empty.
		bool empty() const;
				
	private:
		// contains the values in the Stack
		int* list;
		
		// tracks the current size of the Stack
		int top;
		
		// the maximum size of the stack before needing to be resized
		int max;
		
		// Determines if the Stack needs to be resized to fit more values
		bool isFull() const;
		
		// Determines if the number being pushed to the Stack is a prime number
		bool isPrime(int num) const;
		
		// Increases the size of the Stack by 50%
		void resize();
};