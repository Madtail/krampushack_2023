#include "player.h"

#include <iostream>

Player::Player()
{
	velX = 0;
	velY = 0;

	posX = 400;
	posY = 300;
}

Player::~Player()
{

}

void Player::move()
{
	
}

void Player::update(const InputState &keyboardState, ALLEGRO_EVENT event, int playerKeyUp)
{
	// Calculate velocity
	// TODO: Diagonal movement

	if (keyboardState.isKeyActive(ALLEGRO_KEY_W) && event.keyboard.repeat == 0)
	{
		velY -= player_vel;
	}
	if (keyboardState.isKeyActive(ALLEGRO_KEY_S) && event.keyboard.repeat == 0)
	{
		velY += player_vel;
	}
	if (keyboardState.isKeyActive(ALLEGRO_KEY_A) && event.keyboard.repeat == 0)
	{
		velX -= player_vel;
	}
	if (keyboardState.isKeyActive(ALLEGRO_KEY_D) && event.keyboard.repeat == 0)
	{
		velX += player_vel;
	}
	
		switch (playerKeyUp)
		{
		case ALLEGRO_KEY_W:
			velY += player_vel;
			break;
		case ALLEGRO_KEY_S:
			velY -= player_vel;
			break;
		case ALLEGRO_KEY_A:
			velX += player_vel;
			break;
		case ALLEGRO_KEY_D:
			velX -= player_vel;
			break;
		}
	
		std::cout << "VelX: " << velX << std::endl;
		std::cout << "VelY: " << velY << std::endl;

		if (velX > player_vel && velX != 0) {
			velX = player_vel;
		}
		else if (velX < player_vel && velX != 0)
		{
			velX = -player_vel;
		}

		if (velY > player_vel && velY != 0) {
			velY = player_vel;
		}
		else if (velY < player_vel && velY != 0)
		{
			velY = -player_vel;
		}

		posX += velX;
		posY += velY;
}

void Player::draw(ALLEGRO_BITMAP* playerSprite)
{
	al_draw_bitmap(playerSprite, posX, posY, 0);
}