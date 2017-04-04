#include <iostream>
#include "stack.h"
#include <cmath>
#include <apstring.h>
#include <apstring.cpp>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

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

Button::Button(int xpos, int ypos, int w, int h, int SIZE, ALLEGRO_COLOR c, apstring t) {
	
	x = xpos;
	y = ypos;
	width = w;
	height = h;
	colour = c;
	text = t;
	SQUARE_SIZE = SIZE;
	font = al_load_font("font.ttf", 50, 0);
	
}

void Button::draw() {
	
	al_draw_filled_rectangle(x * SQUARE_SIZE + 0.05 * SQUARE_SIZE, y * SQUARE_SIZE + 0.05 * SQUARE_SIZE, x * SQUARE_SIZE + (width - 1) * SQUARE_SIZE + 0.95 * SQUARE_SIZE, y * SQUARE_SIZE + (height - 1) * SQUARE_SIZE + 0.95 * SQUARE_SIZE, colour);
	al_draw_text(font, al_map_rgb(0, 0, 0), x * SQUARE_SIZE + SQUARE_SIZE / 2 + (width - 1) * SQUARE_SIZE / 2, y * SQUARE_SIZE + 20 + (height - 1) * SQUARE_SIZE / 2, ALLEGRO_ALIGN_CENTRE, text.c_str());
	
}
