#include "MenuScene.h"

MenuScene::MenuScene()
{

}

MenuScene::~MenuScene()
{

}

bool MenuScene::Update(const InputState& state, ALLEGRO_EVENT event, int playerKeyUp)
{
	// return true when the right key has been pressed otherwise false

	// temporary
	return true;
}

void MenuScene::Draw()
{

}

SCENE_TYPE MenuScene::nextScene(SCENE_TYPE type)
{
	return SCENE_TYPE::GAME;
}

SCENE_TYPE MenuScene::GetCurrentScene()
{
	return SCENE_TYPE::MENU;
}

void MenuScene::ResetScene()
{

}