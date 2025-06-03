#include "BadGuy.h"
BadGuy::~BadGuy()
{
	al_destroy_bitmap(image);
}
BadGuy::BadGuy()
{
	image = al_create_bitmap(64, 64);
	if (!image) {
		exit(1);
	}

	al_set_target_bitmap(image);
	al_clear_to_color(al_map_rgb(0, 0, 0));

	x = 0;
	y = 0;

	al_draw_filled_rectangle(25, 10, 39, 54, al_map_rgb(100, 100, 120));
	al_draw_filled_ellipse(32, 32, 32, 16, al_map_rgb(255, 0, 255));
	al_draw_filled_circle(32, 32, 4, al_map_rgb(255, 255, 255));
	al_draw_filled_circle(16, 32, 4, al_map_rgb(120, 255, 255));
	al_draw_filled_circle(48, 32, 4, al_map_rgb(255, 255, 120));
	boundx = al_get_bitmap_width(image) * .75;
	boundy = al_get_bitmap_height(image) * .75;
	live = false;

}
void BadGuy::DrawBadGuy()
{
	if (live)
	{
		al_draw_bitmap(image, x, y, 0);
	}
}
void BadGuy::StartBadGuy(int WIDTH, int HEIGHT)
{
    static BadGuy* allBadGuys[5];
    static int count = 0;
    bool getBadGuyStatus = false;

    //checking to see if a badboy is able to fit within the 5 limit cap
    if (!getBadGuyStatus && count < 5) {
        allBadGuys[count++] = this; //increments array as spots open up
    }

    //handle spawning points
    if (!live && rand() % 100 == 0) { 
        do {
            x = rand() % (WIDTH - boundx); //x and y are used to randomly select locations on the map for the badGuys to spawn
            y = rand() % (HEIGHT - boundy);

            bool valid = true;
            for (int i = 0; i < count && valid; i++) {
                BadGuy* getSpawnedBadGuys = allBadGuys[i];//for all badguys that are live
                //in the if statement im checking the location of where the new badguy can spawn and if his borders and inline with other 
                //badguys borders it will not be a valid location to spawn in 
                if (getSpawnedBadGuys != this && getSpawnedBadGuys->live && x + boundx > getSpawnedBadGuys->x && x < getSpawnedBadGuys->x + getSpawnedBadGuys->boundx &&
                     y + boundy > getSpawnedBadGuys->y && y < getSpawnedBadGuys->y + getSpawnedBadGuys->boundy) {
                    valid = false;
                }
            }
            //after a valid location is found the badguy can be drawn to the screen
            if (valid) {
                live = true;
                break; 
            }
        } while (true); 
    }
}
