/*****************************************************************************
 *	Name: Justin Paoli                                                       *
 *	Course: ICS4U                                                            *  
 *	Date: April 6, 2017                                                      * 
 *	                                                                         * 
 *	Purpose: Reverse Polish Notation Calculator                              *
 *	                                                                         *
 *	Usage: Use like a normal calulator GUI - Enter a number then enter it    *
 *  onto the top on the stack, then perform an operation on it               *
 *	                                                                         *
 *	Revision History: Made stack class, then added GUI, then added           *
 *	functionality to the GUI                                                 *
 *	                                                                         *  
 *****************************************************************************/

#include <iostream>
#include "stack.h"
#include "stack.cpp"
#include <cstdio>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define SQUARE_SIZE 100

using namespace std;

//Declarations
ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *event_queue;

static ALLEGRO_COLOR WHITE;
static ALLEGRO_COLOR SLATE_GRAY;

int main() {
	
	//Allegro inits
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_mouse();
	
	//Create display and event queue
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	display = al_create_display(SQUARE_SIZE * 5, SQUARE_SIZE * 8);
	event_queue = al_create_event_queue();
	
	//Register event sources
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_mouse_event_source());
	
	//Colour constants
	WHITE = al_map_rgb(255, 255, 255);
	SLATE_GRAY = al_map_rgb(112, 138, 144);
	
	//Buttons
	Button *buttons[25];
	buttons[0] = new Button(0, 7, 1, 1, SQUARE_SIZE, WHITE, "0"); //0
	buttons[1] = new Button(0, 6, 1, 1, SQUARE_SIZE, WHITE, "1"); //1
	buttons[2] = new Button(1, 6, 1, 1, SQUARE_SIZE, WHITE, "2"); //2
	buttons[3] = new Button(2, 6, 1, 1, SQUARE_SIZE, WHITE, "3"); //3
	buttons[4] = new Button(0, 5, 1, 1, SQUARE_SIZE, WHITE, "4"); //4
	buttons[5] = new Button(1, 5, 1, 1, SQUARE_SIZE, WHITE, "5"); //5
	buttons[6] = new Button(2, 5, 1, 1, SQUARE_SIZE, WHITE, "6"); //6
	buttons[7] = new Button(0, 4, 1, 1, SQUARE_SIZE, WHITE, "7"); //7
	buttons[8] = new Button(1, 4, 1, 1, SQUARE_SIZE, WHITE, "8"); //8
	buttons[9] = new Button(2, 4, 1, 1, SQUARE_SIZE, WHITE, "9"); //9
	buttons[10] = new Button(2, 7, 1, 1, SQUARE_SIZE, WHITE, "+/-"); //Negate
	buttons[11] = new Button(1, 7, 1, 1, SQUARE_SIZE, WHITE, "."); //Decimal
	buttons[12] = new Button(3, 4, 1, 1, SQUARE_SIZE, SLATE_GRAY, "+"); //Plus
	buttons[13] = new Button(3, 3, 1, 1, SQUARE_SIZE, SLATE_GRAY, "-"); //Minus
	buttons[14] = new Button(3, 5, 1, 1, SQUARE_SIZE, SLATE_GRAY, "X"); //Times
	buttons[15] = new Button(2, 3, 1, 1, SQUARE_SIZE, SLATE_GRAY, "/"); //Divide
	buttons[16] = new Button(3, 6, 1, 2, SQUARE_SIZE, SLATE_GRAY, "ENT"); //Enter
	buttons[17] = new Button(3, 2, 1, 1, SQUARE_SIZE, SLATE_GRAY, "1/x"); //Reciprocal
	buttons[18] = new Button(0, 3, 1, 1, SQUARE_SIZE, SLATE_GRAY, "SQRT"); //Square Root
	buttons[19] = new Button(4, 4, 1, 2, SQUARE_SIZE, SLATE_GRAY, "C"); //Clear
	buttons[20] = new Button(4, 6, 1, 2, SQUARE_SIZE, SLATE_GRAY, "AC"); //All Clear
	buttons[21] = new Button(0, 2, 1, 1, SQUARE_SIZE, SLATE_GRAY, "sin"); //Sine
	buttons[22] = new Button(1, 2, 1, 1, SQUARE_SIZE, SLATE_GRAY, "cos"); //Cosine
	buttons[23] = new Button(2, 2, 1, 1, SQUARE_SIZE, SLATE_GRAY, "tan"); //Tangent
	buttons[24] = new Button(1, 3, 1, 1, SQUARE_SIZE, SLATE_GRAY, "POW"); //Exponents
	buttons[25] = new Button(4, 2, 1, 2, SQUARE_SIZE, SLATE_GRAY, "EXIT"); //exit
	
	Operator calc;
	float input;
	apstring num1("");
	char num2[50];
	
	while(true) {
		
		//Draw display
		input = atof(num1.c_str());
		
		for(int i = 0; i <= 25; i++) {
			
			buttons[i]->draw();
			
		}
		
		al_draw_filled_rectangle(0.05 * SQUARE_SIZE, 0.05 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, 0.95 * SQUARE_SIZE, WHITE);
		al_draw_filled_rectangle(0.05 * SQUARE_SIZE, SQUARE_SIZE + 0.05 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
				
		if(calc.getTop() < 0) {
			
			sprintf(num2, "%f", 0.0);
			
		} else {
			
			sprintf(num2, "%f", calc.getTopData());
			
		}
		
		al_draw_text(buttons[0]->getFont(), al_map_rgb(0, 0, 0), 4 * SQUARE_SIZE + 0.90 * SQUARE_SIZE, SQUARE_SIZE / 2 + 0.95 * SQUARE_SIZE, ALLEGRO_ALIGN_RIGHT, num1.c_str());
		al_draw_text(buttons[0]->getFont(), al_map_rgb(0, 0, 0), 4 * SQUARE_SIZE + 0.90 * SQUARE_SIZE, SQUARE_SIZE / 2, ALLEGRO_ALIGN_RIGHT, num2);
					
		al_flip_display();
		
		//Wait for an event
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
			
		//If its the ESC key exit		
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				
				break;
				
			}
		
		//If its the red X button exit
		} else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			
			break;
		
		//If they left click somewhere	
		} else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			
			if(event.mouse.button == 1) {
					
				//Find which button it is then do the action for that button				
				for(int i = 0; i <= 25; i++) {
					
					if(event.mouse.x >= buttons[i]->getX() * SQUARE_SIZE && event.mouse.x <= buttons[i]->getX() * SQUARE_SIZE + buttons[i]->getW() * SQUARE_SIZE && event.mouse.y >= buttons[i]->getY() * SQUARE_SIZE && event.mouse.y <= buttons[i]->getY() * SQUARE_SIZE + buttons[i]->getH() * SQUARE_SIZE) {
													
						if(i >= 0 && i <= 9) {
						
							num1 += buttons[i]->getText();
								
						} else if(i == 10) {
							
							if(num1[0] == '-') {
								
								int i;
								
								for(i = 0; i < num1.length() - 1; i++) {
									
									num1[i] = num1[i + 1];
									
								}
								
								num1[i] = '\0';
								
							} else {
							
								num1 = "-" + num1;
							
							}
							
						} else if(i == 11) {
							
							num1 += ".";
							
						} else if(i >= 12 && i <= 15) {
							
							calc.push(input);
							input = 0;
							num1 = "";
							
							calc.operate(buttons[i]->getText()[0]);
							
						} else if(i == 16) {
							
							calc.push(input);
							input = 0;
							num1 = ""; 
							
						} else if(i == 17) {
							
							calc.push(input);
							input = 0;
							num1 = "";
							calc.operate('r');
							
						} else if(i == 18) {
							
							calc.push(input);
							input = 0;
							num1 = "";
							calc.operate('s');
							
						} else if(i == 19) {
							
							input = 0;
							num1 = "";
							
						} else if(i == 20) {
						
							input = 0;
							num1 = "";
							calc.clear();
						
						}else if(i >= 21 && i <= 23) {
							
							calc.push(input);
							input = 0;
							num1 = "";
							calc.operate(i + 28);
						
						} else if(i == 24) {
							
							calc.push(input);
							input = 0;
							num1 = "";
							calc.operate('^');
							
						} else if(i == 25) {
							
							return 0;
							
						}
						
					}
					
				}
				
			}
			
		}
		
	}
	
	return 0;
	
}
