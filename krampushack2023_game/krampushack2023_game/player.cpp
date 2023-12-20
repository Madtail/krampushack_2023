#include "player.h"

#include <iostream>

Player::Player()
{
	position.x = NULL;
	position.y = NULL;
	camera = 0;
	velocity = 0;

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

bool Player::playerWithinScreen()
{
	bool withinScreen = true;
	// Check that player is within the screen
	if ((position.x + PLAYER_WIDTH) > SCREEN_W) {
		position.x -= velocity.x;
	}
	if ((position.x - PLAYER_WIDTH) < 0) {
		position.x -= velocity.x;
	}
	if ((position.y + PLAYER_HEIGHT) > SCREEN_H) {
		position.y -= velocity.y;
	}
	if ((position.y - PLAYER_HEIGHT) < 0) {
		position.y -= velocity.y;
	}

	return withinScreen;
}

bool Player::updatePlayerPosition()
{
	bool updatePosition = false;
	// Limited player movement
	if (camera.x + SCREEN_W >= BACKGROUND_WIDTH / 2 && velocity.x > 0) {
		updatePosition = true;
	}
	if (camera.x - SCREEN_W <= -BACKGROUND_WIDTH / 2 && velocity.x < 0) {
		updatePosition = true;
	}
	if (camera.y + SCREEN_H >= BACKGROUND_HEIGHT / 2 && velocity.y > 0) {
		updatePosition = true;
	}
	if (camera.y - SCREEN_H <= -BACKGROUND_HEIGHT / 2 && velocity.y < 0) {
		updatePosition = true;
	}

	// Move position to center, Screencenter= (SCREEN_W / 2) - PLAYER_WIDTH / 2, (SCREEN_H / 2) - PLAYER_HEIGHT / 2;
	if (fabsf(((position.x+velocity.x) - ((SCREEN_W / 2) - PLAYER_WIDTH / 2))) < fabsf(((position.x) - ((SCREEN_W / 2) - PLAYER_WIDTH / 2)))
		|| fabsf(((position.y+velocity.y) - ((SCREEN_H / 2) - PLAYER_HEIGHT / 2))) < fabsf(((position.y) - ((SCREEN_H / 2) - PLAYER_HEIGHT / 2))))
	{
		updatePosition = true;
	}

	return updatePosition;
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

		std::cout << "Camera position: " << camera.x << ", " << camera.y << "\n";
		std::cout << "Position: " << position.x << ", " << position.y << "\n";
		std::cout << velocity.x << "," << velocity.y << "\n";

		std::cout << "Distance to center, x: " << fabsf(((position.x) - ((SCREEN_W / 2) - PLAYER_WIDTH / 2))) << " y: "
			<< fabsf(((position.y) - ((SCREEN_H / 2) - PLAYER_HEIGHT / 2))) << "\n";

		if (updatePlayerPosition())
		{
			position += velocity;
		}
		else
		{
			camera += velocity;
		}
		playerWithinScreen();

		// Camera check
		if (camera.x+SCREEN_W > BACKGROUND_WIDTH / 2) {
			camera.x -= velocity.x;
		}
		if (camera.x-SCREEN_W < -BACKGROUND_WIDTH / 2) {
			camera.x -= velocity.x;
		}
		if (camera.y+SCREEN_H > BACKGROUND_HEIGHT / 2) {
			camera.y -= velocity.y;
		}
		if (camera.y-SCREEN_H < -BACKGROUND_HEIGHT / 2) {
			camera.y -= velocity.y;
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