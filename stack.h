#ifndef STACK_H
#define STACK_H
#include <iostream>

class Stack {
	
	protected:
		float stack[20]; //Holds the data fro the calculator
		int top; //Index of the top of the stack
	public:
		Stack(); //Constructor
		float pop(); //Get value on top of stack
		void push(float n); //Put value at the top of the stack
		bool isEmpty() { return top < 0; } //Check if stack is empty
		int getTop() {return top; } //Find index of top of stack
		~Stack() { std::cout << std::endl << "Stack Destroyed" << std::endl; } //Deconstructor
	
};

class Operator : public Stack {
	
	public:
		float operate(char op); //Perform operation on stack
	
};

#endif
