#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "input.h"
#include "Vector2D.h"

class Player
{
public:
	Player();
	~Player();

	void update(const InputState &keyboardState, ALLEGRO_EVENT event, int playerKeyUp);
	void draw(ALLEGRO_BITMAP* playerSprite);

	// Get and set player position
	Vector2D getPosition();
	void setPosition(Vector2D input);
	Vector2D getVelocity();
	void setVelocity(Vector2D input);

	const int player_vel = 5;

	/*
	struct Camera
	{
		float camera_x;
		float camera_y;
	};
	Camera camera;
	*/
	Vector2D camera;

	Rect playerArea;
	Rect playerCollider;

private:
	
	Vector2D position;
	Vector2D velocity;

};

#endif // PLAYER_H