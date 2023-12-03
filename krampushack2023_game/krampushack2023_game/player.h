#pragma once
#ifndef PLAYER_H
#define PLAYER_H


#include "input.h"


class Player
{
public:
	Player();
	~Player();

	void update(const InputState &keyboardState, ALLEGRO_EVENT event, int playerKeyUp);
	void move();
	void draw(ALLEGRO_BITMAP* playerSprite);

	const int player_vel = 5;

private:
	float posX;
	float posY;

	float velX;
	float velY;

};

#endif // PLAYER_H