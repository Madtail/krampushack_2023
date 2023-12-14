#include "player.h"

#include <iostream>

Player::Player()
{
	position.x = (SCREEN_W / 2);
	position.y = (SCREEN_H / 2);
}

Player::~Player()
{

}

void Player::update(const InputState &keyboardState, ALLEGRO_EVENT event, int playerKeyUp)
{
	// Calculate velocity

	if (keyboardState.isKeyActive(ALLEGRO_KEY_W) && event.keyboard.repeat == 0)
	{
		velocity.y = -player_vel;
	}
	if (keyboardState.isKeyActive(ALLEGRO_KEY_S) && event.keyboard.repeat == 0)
	{
		velocity.y = player_vel;
	}
	if (keyboardState.isKeyActive(ALLEGRO_KEY_A) && event.keyboard.repeat == 0)
	{
		velocity.x = -player_vel;
	}
	if (keyboardState.isKeyActive(ALLEGRO_KEY_D) && event.keyboard.repeat == 0)
	{
		velocity.x = player_vel;
	}

	//std::cout << "KEY UP: " << playerKeyUp << "\n";
	/*
		switch (playerKeyUp)
		{
		case ALLEGRO_KEY_W:
			velocity.y = 0;
			break;
		case ALLEGRO_KEY_S:
			//velY -= player_vel;
			velocity.y = 0;
			break;
		case ALLEGRO_KEY_A:
			//velX += player_vel;
			velocity.x = 0;
			break;
		case ALLEGRO_KEY_D:
			//velX -= player_vel;
			velocity.x = 0;
			break;
		}
		*/
		if (keyboardState.isKeyActive(ALLEGRO_KEY_W) == false && keyboardState.isKeyActive(ALLEGRO_KEY_S) == false)
		{
			velocity.y = 0;
		}
		if (keyboardState.isKeyActive(ALLEGRO_KEY_A) == false && keyboardState.isKeyActive(ALLEGRO_KEY_D) == false)
		{
			velocity.x = 0;
		}

		//std::cout << "Velocity: " << velocity.Magnitude() << "\n";
		std::cout << "Position: " << position.x << "," << position.y << "\n";
		position += velocity;
}

void Player::draw(ALLEGRO_BITMAP* playerSprite)
{
	al_draw_bitmap(playerSprite, position.x, position.y, 0);
}

Vector2D Player::getPosition() {
	return position;
}
void Player::setPosition(Vector2D input) {
	position = input;
}
Vector2D Player::getVelocity() {
	return velocity;
}
void Player::setVelocity(Vector2D input) {
	velocity = input;
}