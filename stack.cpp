#include <iostream>
#include "stack.h"
#include <cmath>

using namespace std;

//Initialize stack, top
Stack::Stack() {
	
	for(int i = 0; i < 20; i++) {
		
		stack[i] = 0;
		
	}
	
	top = -1;
	
}

//Return top of stack and deincrement top
float Stack::pop() {

	return stack[top--];
	
}

//Increment top and push n to top
void Stack::push(float n) {
	
	stack[++top] = n;
	
}

//Main operations
float Operator::operate(char op) {
	
	float a;
	
	switch(op) {
		
		case '+': if (top > 0) {
				      return pop() + pop();
				  } else cout << "Not enough data in stack to add!" << endl;
				  break;
				  
		case '-': if (top > 0) {
					  a = pop();
				      return pop() - a;
				  } else cout << "Not enough data in stack to subtract!" << endl;
				  break; 
				  
		case '*': if (top > 0) {
				      return pop() * pop();
				  } else cout << "Not enough data in stack to multiply!" << endl;
				  break;
				  
		case '/': if (top > 0) {
			  		  a = pop();
					  if(a != 0) {
					  
					      return pop() / a;
					  
					  } else {
					  	
					      cout << "DIVIDE BY 0 ERROR" << endl;
					  	
					  }
				  }
				  else cout << "Not enough data in stack to divide!" << endl;
				  break;
				  
		case '^': if (!isEmpty()) {
				      return pow(pop(), pop());
				  } else cout << "Stack is empty!";
				  break;
				  
		case 'r': if (!isEmpty()) {
				      return 1 / pop();
				  } else cout << "Stack is empty!";
				  break;
				  
		case 's': if (!isEmpty()) {
				      return pow(pop(), 0.5);
				  } else cout << "Stack is empty!";
				  break;
	}
	
}
