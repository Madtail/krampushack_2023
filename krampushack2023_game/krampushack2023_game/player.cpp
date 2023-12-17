#include "player.h"

#include <iostream>

Player::Player()
{
	position.x = NULL;
	position.y = NULL;
	camera = 0;

	playerArea.w = SCREEN_W;
	playerArea.h = SCREEN_H;
	playerCollider.w = PLAYER_WIDTH;
	playerCollider.h = PLAYER_HEIGHT;
	
	position.x = (SCREEN_W / 2) - PLAYER_WIDTH / 2;
	position.y = (SCREEN_H / 2) - PLAYER_HEIGHT / 2;
	playerArea.x = position.x;
	playerArea.y = position.y;
	playerCollider.x = position.x;
	playerCollider.y = position.y;
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

		if (keyboardState.isKeyActive(ALLEGRO_KEY_W) == false && keyboardState.isKeyActive(ALLEGRO_KEY_S) == false)
		{
			velocity.y = 0;
		}
		if (keyboardState.isKeyActive(ALLEGRO_KEY_A) == false && keyboardState.isKeyActive(ALLEGRO_KEY_D) == false)
		{
			velocity.x = 0;
		}

		camera += velocity;
		//camera += velocity;
		std::cout << "Camera position: " << camera.x << ", " << camera.y << "\n";
		std::cout << "Position: " << position.x << ", " << position.y << "\n";
		std::cout << velocity.x << "," << velocity.y << "\n";
		
		// Position at border
		if (camera.x+SCREEN_W >= BACKGROUND_WIDTH / 2 && velocity.x > 0) {
			position += velocity;
		}
		if (camera.x - SCREEN_W <= -BACKGROUND_WIDTH / 2 && velocity.x < 0) {
			position += velocity;
		}
		if (camera.y + SCREEN_H >= BACKGROUND_HEIGHT / 2 && velocity.y > 0) {
			position += velocity;
		}
		if (camera.y - SCREEN_H <= -BACKGROUND_HEIGHT / 2 && velocity.y < 0) {
			position += velocity;
		}

		// Border
		if (camera.x+SCREEN_W > BACKGROUND_WIDTH / 2) {
			camera.x -= player_vel;
		}
		else if (camera.x-SCREEN_W < -BACKGROUND_WIDTH / 2) {
			camera.x += player_vel;
		}
		if (camera.y+SCREEN_H > BACKGROUND_HEIGHT / 2) {
			camera.y -= player_vel;
		}
		else if (camera.y-SCREEN_H < -BACKGROUND_HEIGHT / 2) {
			camera.y += player_vel;
		}

		if (position.x+PLAYER_WIDTH > SCREEN_W) {
			position.x -= player_vel;
		}
		else if (position.x-PLAYER_WIDTH < -SCREEN_W) {
			position.x += player_vel;
		}
		if (position.y+PLAYER_HEIGHT > SCREEN_H) {
			position.y -= player_vel;
		}
		else if (position.y-PLAYER_HEIGHT < 0) {
			position.y += player_vel;
		}

		playerCollider.x = position.x;
		playerCollider.y = position.y;
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