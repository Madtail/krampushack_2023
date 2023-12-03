#include "player.h"

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
	posX += velX;
	posY += velY;
}

void Player::update(const InputState &keyboardState, ALLEGRO_EVENT event)
{
	// Calculate velocity

	if (keyboardState.isKeyActive(ALLEGRO_KEY_W))
	{
		velY -= player_vel;
	}
	else if (keyboardState.isKeyActive(ALLEGRO_KEY_S))
	{
		velY += player_vel;
	}
	else if (keyboardState.isKeyActive(ALLEGRO_KEY_A))
	{
		velX -= player_vel;
	}
	else if (keyboardState.isKeyActive(ALLEGRO_KEY_D))
	{
		velX += player_vel;
	}


	if (event.type == ALLEGRO_EVENT_KEY_UP)
	{
		// If a key is released
		if (keyboardState.isKeyActive(ALLEGRO_KEY_W))
		{
			velY += player_vel;
		}
		else if (keyboardState.isKeyActive(ALLEGRO_KEY_S))
		{
			velY -= player_vel;
		}
		else if (keyboardState.isKeyActive(ALLEGRO_KEY_A))
		{
			velX += player_vel;
		}
		else if (keyboardState.isKeyActive(ALLEGRO_KEY_D))
		{
			velX -= player_vel;
		}
	}
}

void Player::draw(ALLEGRO_BITMAP* playerSprite)
{
	al_draw_bitmap(playerSprite, posX, posY, 0);
}