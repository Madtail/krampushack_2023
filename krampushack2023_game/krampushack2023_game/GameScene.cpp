#include "GameScene.h"

GameScene::GameScene()
{
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

bool GameScene::Update(const InputState& keyboard_state, ALLEGRO_EVENT event)
{
	// return true when the right key has been pressed otherwise false

	player.update(keyboard_state, event);
	player.move();

	// temporary
	return true;
}

void GameScene::Draw()
{
	// Send sprites to player draw function
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
	image_resources.push_back("../data/scary_gnome_crab1.png");
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