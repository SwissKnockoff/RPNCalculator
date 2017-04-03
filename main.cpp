//TODO: BUTTON CLASS FOR BETTER EFFICIENCY

#include <iostream>
#include "stack.h"
#include "stack.cpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

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
	al_install_keyboard();
	
	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
	display = al_create_display(SQUARE_SIZE * 5, SQUARE_SIZE * 8);
	
	event_queue = al_create_event_queue();
	
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	
	BLUE = al_map_rgb(0, 255, 255);
	WHITE = al_map_rgb(255, 255, 255);
	SLATE_GRAY = al_map_rgb(112, 138, 144);
	
	Operator calc;
	
	while(true) {
		
		al_draw_filled_rectangle(0.05 * SQUARE_SIZE, 7 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 0.95 * SQUARE_SIZE, 7 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
		al_draw_filled_rectangle(0.05 * SQUARE_SIZE, 6 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 0.95 * SQUARE_SIZE, 6 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
		al_draw_filled_rectangle(0.05 * SQUARE_SIZE, 5 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 0.95 * SQUARE_SIZE, 5 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
		al_draw_filled_rectangle(0.05 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 0.95 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
		al_draw_filled_rectangle(SQUARE_SIZE + 0.05 * SQUARE_SIZE, 7 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, SQUARE_SIZE + 0.95 * SQUARE_SIZE, 7 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
		al_draw_filled_rectangle(SQUARE_SIZE + 0.05 * SQUARE_SIZE, 6 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, SQUARE_SIZE + 0.95 * SQUARE_SIZE, 6 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
		al_draw_filled_rectangle(SQUARE_SIZE + 0.05 * SQUARE_SIZE, 5 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, SQUARE_SIZE + 0.95 * SQUARE_SIZE, 5 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
		al_draw_filled_rectangle(SQUARE_SIZE + 0.05 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, SQUARE_SIZE + 0.95 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
		al_draw_filled_rectangle(2 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 7 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 2 *  SQUARE_SIZE + 0.95 * SQUARE_SIZE, 7 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
		al_draw_filled_rectangle(2 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 6 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 2 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, 6 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
		al_draw_filled_rectangle(2 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 5 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 2 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, 5 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
		al_draw_filled_rectangle(2 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 2 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, WHITE);
		
		al_draw_filled_rectangle(3 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 6 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 3 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, 7 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, SLATE_GRAY);
		al_draw_filled_rectangle(4 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 6 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, 7 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, SLATE_GRAY);
		al_draw_filled_rectangle(4 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, 5 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, SLATE_GRAY);
		al_draw_filled_rectangle(3 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 3 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, 4 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, SLATE_GRAY);
		al_draw_filled_rectangle(3 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 5 * SQUARE_SIZE + 0.05 * SQUARE_SIZE, 3 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, 5 * SQUARE_SIZE + 0.95 * SQUARE_SIZE, SLATE_GRAY);
									
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
