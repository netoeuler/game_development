//Compilation: gcc main.c -o main $(pkg-config --libs allegro-5 allegro_image-5)
//https://github.com/liballeg/allegro_wiki/wiki/Quickstart
//https://liballeg.org/a5docs/trunk/getting_started.html

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#include "common.c"

int main(int argc, char **argv){
	ALLEGRO_DISPLAY *display;
	ALLEGRO_KEYBOARD_STATE kbdstate;
	ALLEGRO_BITMAP *sprite,*scenario;
	ALLEGRO_COLOR c1;

	if (!al_init()) {
		abort_example("Error initialising Allegro.\n");
	}
	if (!al_install_keyboard()) {
    	abort_example("Error installing keyboard.\n");
   	}

	display = al_create_display(640, 480);	
	if (!display) {
	  abort_example("Unable to create display.\n");
	}

	al_init_image_addon();
   	init_platform_specific();

	scenario = al_load_bitmap("scenario.png");
	sprite = al_load_bitmap("p1.png");
	if (!sprite) {
		abort_example("Error loading sprite.\n");
   	}
   	al_convert_mask_to_alpha(sprite, al_map_rgb(255, 0, 255));

   	int p1_x = 50;
   	int p1_y = 50;

	while(!al_key_down(&kbdstate, ALLEGRO_KEY_ESCAPE)){
		al_clear_to_color(al_map_rgb(0, 0, 0));

		al_get_keyboard_state(&kbdstate);
      	if (al_key_down(&kbdstate, ALLEGRO_KEY_RIGHT)) {
      		p1_x += 5;
      	}
      	else if (al_key_down(&kbdstate, ALLEGRO_KEY_LEFT)) {
      		p1_x -= 5;
      	}
      	else if (al_key_down(&kbdstate, ALLEGRO_KEY_UP)) {
      		p1_y -= 5;
      	}
      	else if (al_key_down(&kbdstate, ALLEGRO_KEY_DOWN)) {
      		p1_y += 5;
      	}

      	al_draw_scaled_bitmap(scenario, 0, 0, 469, 184, 0, 0, 900, 300, 0);
      	al_draw_bitmap(sprite, p1_x, p1_y, 0);
      	al_flip_display();
	}

	al_destroy_bitmap(sprite);
	al_destroy_display(display);

	return 0;
} 
