#include "GameScene.h"

GameScene::GameScene()
{
	start = true;
	setupFilepaths();
	loadResources();
}

GameScene::~GameScene()
{
	for (auto& sprite : sprites) {
		al_destroy_bitmap(sprite);
	}

	for (auto& font : fonts) {
		al_destroy_font(font);
	}
}

bool GameScene::Update(const InputState& keyboard_state, ALLEGRO_EVENT event, int playerKeyUp)
{
	// return true when the right key has been pressed otherwise false

	player.update(keyboard_state, event, playerKeyUp);

	// temporary
	return true;
}

void GameScene::Draw()
{

	// Send sprites to player draw function
	al_draw_bitmap(sprites[1], ((SCREEN_W/2)-BACKGROUND_WIDTH/2) - player.camera.x, ((SCREEN_H / 2) - BACKGROUND_HEIGHT / 2) - player.camera.y, 0);
	player.draw(sprites[0]);
}

SCENE_TYPE GameScene::nextScene(SCENE_TYPE type)
{
	return SCENE_TYPE::MENU;
}

SCENE_TYPE GameScene::GetCurrentScene()
{
	return SCENE_TYPE::GAME;
}

void GameScene::ResetScene()
{

}

void GameScene::setupFilepaths()
{
	// player sprite 1
	image_resources.push_back("../data/player1.png");
	image_resources.push_back("../data/background2.png");
}

void GameScene::loadResources()
{
	for (const char* file : image_resources)
	{
		sprites.push_back(al_load_bitmap(file));
	}
	
	int fontsize{ 12 };
	for (const char* file : font_resources)
	{
		fonts.push_back(al_load_font(file, fontsize, NULL));
	}
}