#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <apstring.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

class Stack {
	
	protected:
		float stack[20]; //Holds the data fro the calculator
		int top; //Index of the top of the stack
	public:
		Stack(); //Constructor
		float pop(); //Get value on top of stack
		void push(float n); //Put value at the top of the stack
		bool isEmpty() { return top < 0; } //Check if stack is empty
		int getTop() { return top; } //Find index of top of stack
		float getTopData() { return stack[top]; }
		~Stack() { std::cout << std::endl << "Stack Destroyed" << std::endl; } //Deconstructor
	
};

class Operator : public Stack {
	
	public:
		float operate(char op); //Perform operation on stack
		void clear(); //Clear stack
	
};

class Button {
	
	private:
		int x, y, width, height, SQUARE_SIZE;
		ALLEGRO_COLOR colour;
		ALLEGRO_FONT *font;
		apstring text;
	public:
		Button(int xpos, int ypos, int w, int h, int SIZE, ALLEGRO_COLOR c, apstring t);
		void draw();
		int getX() {return x;}
		int getY() {return y;}
		int getW() {return width;}
		int getH() {return height;}
		apstring getText() {return text;}
		ALLEGRO_FONT *getFont() { return font; }
		~Button() {};
	
};
#endif
