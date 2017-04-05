//TODO: BUTTON CLASS FOR BETTER EFFICIENCY

#include <iostream>
#include "stack.h"
#include "stack.cpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#define SQUARE_SIZE 100

using namespace std;

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *event_queue;

static ALLEGRO_COLOR BLUE;
static ALLEGRO_COLOR WHITE;
static ALLEGRO_COLOR SLATE_GRAY;

int main() {
	
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	
	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
	display = al_create_display(SQUARE_SIZE * 5, SQUARE_SIZE * 8);
	
	event_queue = al_create_event_queue();
	
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	
	BLUE = al_map_rgb(0, 255, 255);
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
	buttons[24] = new Button(1, 3, 1, 1, SQUARE_SIZE, SLATE_GRAY, "y^x"); //Exponents
	
	Operator calc;
	
	while(true) {
		
		for(int i = 0; i <= 24; i++) {
			
			buttons[i]->draw();
			
		}
		
		al_draw_filled_rectangle(0.05 * SQUARE_SIZE, 0.05 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 0.95 * SQUARE_SIZE, WHITE);
		al_draw_filled_rectangle(0.05 * SQUARE_SIZE, SQUARE_SIZE + 0.05 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
					
		al_flip_display();
		
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);
				
		if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
			
			if(event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				
				break;
				
			}
			
		} else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			
			break;
			
		}
		
	}
	
	calc.push(4);
	cout << calc.operate('s');
	
	return 0;
	
}
