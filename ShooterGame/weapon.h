#ifndef WEAPONH
#define WEAPONH
#include "BadGuy.h"
#include "player.h"
class weapon
{
public:
	weapon();
	~weapon();
	void Drawweapon();
	void Fireweapon(player& Player, int directionOfFreedom);
	void Updateweapon(int WIDTH, int HEIGHT);//added to allow n s
	void Collideweapon(BadGuy BadGuys[], int cSize);
private:
	int dir;
	int x;
	int y;
	int boundx;
	int boundy;
	bool live;
	int speed;
	float angle;
	ALLEGRO_BITMAP* image;
};
#endif
