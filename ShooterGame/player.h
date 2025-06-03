#ifndef PLAYERH
#define PLAYERH
#include "BadGuy.h"
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
class BadGuy;
class player
{
public:
	player(int HEIGHT);
	~player();
	int getDirection();//added from lab6 
	void DrawPlayer();
	void MoveUp();
	void MoveDown(int HEIGHT );
	void MoveLeft( );
	void MoveRight(int WIDTH );
	void CollidePlayer(BadGuy BadGuys[], int cSize, int oldX, int oldY);//reused from weapons
	int getBoundX() { return boundx; }
	int getBoundY() { return boundy; }
	int getX() { return x; }
	int getY() { return y; }
private:
	int x;
	int y;
	int speed;
	int boundx;
	int boundy;
	int dir; //lab6
	ALLEGRO_BITMAP* image[4];
};
#endif