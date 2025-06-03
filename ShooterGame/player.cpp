#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"
#include <iostream>
 

player::~player()
{
	//al_destroy_bitmap(image);
	for (int i = 0; i < 4; i++)
	{
		al_destroy_bitmap(image[i]);
	}
}
player::player(int HEIGHT)
{
	dir = 0;

	for (int i = 0;i < 4; i++)
	{
		 
	image[i] = al_create_bitmap(64, 64);
	al_set_target_bitmap(image[i]);
	x = 20;
	y = HEIGHT / 2;

	speed = 10;
	boundx = al_get_bitmap_width(image[i]);
	boundy = al_get_bitmap_height(image[i]);

		al_set_target_bitmap(image[i]);
		al_clear_to_color(al_map_rgb(0, 0, 0));

		int x = 15;
		int y = 15;
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_filled_rectangle(0, 25, 64, 39, al_map_rgb(75, 75, 75));
		al_draw_filled_rectangle(25, 0, 39, 64, al_map_rgb(50, 50, 50));
		al_draw_circle(32, 32, 8, al_map_rgb(0, 0, 0), 5);
		al_draw_line(0, 32, 64, 32, al_map_rgb(255, 100, 255), 2);
		al_draw_line(32, 0, 32, 64, al_map_rgb(255, 100, 255), 2);
		al_draw_circle(32, 32, 16, al_map_rgb(200, 200, 200), 5);
		 
		switch (i)
		{
		case 0: //Up
			al_draw_filled_triangle(22, 22, 42, 22, 32, 12, al_map_rgb(255, 0, 0));
			break;
		case 1: //Right
			al_draw_filled_triangle(42, 22, 42, 42, 52, 32, al_map_rgb(255, 0, 0));
			break;
		case 2: //Down
			al_draw_filled_triangle(22, 42, 42, 42,32, 52, al_map_rgb(255, 0, 0));
			break;
		case 3: //Left
			al_draw_filled_triangle(22, 22, 22, 42, 12, 32, al_map_rgb(255, 0, 0));
			break;
		}
	}
}

int player::getDirection()//similar to lab 6 arrow.cp im passing direction around to use in CollidePlayer
{
	return dir;
}
void player::DrawPlayer()
{
	al_draw_bitmap(image[getDirection()], getX(), getY(), 0);
}
void player::CollidePlayer(BadGuy BadGuys[], int cSize, int priorX, int priorY)
{
		for (int j = 0; j < cSize; j++)//recycled the same logic from Collideweapon in weapon.cpp 
		{
			if (BadGuys[j].getLive())
			{
				if (x > (BadGuys[j].getX() - BadGuys[j].getBoundX()) &&
					x < (BadGuys[j].getX() + BadGuys[j].getBoundX()) &&
					y >(BadGuys[j].getY() - BadGuys[j].getBoundY()) &&
					y < (BadGuys[j].getY() + BadGuys[j].getBoundY()))
				{
					x = priorX;//passed back from main this allows the player to stay at their "prior" really current location once their cordinates match a bad guys
					y = priorY;
				}
			}
		}
}
void player::MoveUp()
{
	dir = 0;
	y -= speed;
	if (y < 0)
		y = 0;
}
void player::MoveDown(int HEIGHT)
{
	dir = 2;
	y += speed;
	if (y > HEIGHT - boundy)
		y = HEIGHT - boundy;
}
void player::MoveLeft()
{
	dir = 3;
	x -= speed;
	if (x < 0)
		x = 0;
}
void player::MoveRight(int WIDTH)
{
	dir = 1;
	x += speed;
	if (x > WIDTH - boundx)
		x = WIDTH - boundx;
}