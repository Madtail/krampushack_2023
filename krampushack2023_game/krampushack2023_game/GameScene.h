#pragma once
#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <vector>

#include "BaseScene.h"
#include "player.h"

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class GameScene : public BaseScene
{
public:
	GameScene();
	~GameScene();

	bool Update(const InputState& keyboardState, ALLEGRO_EVENT event) override;
	void Draw() override;

	SCENE_TYPE nextScene(SCENE_TYPE type) override;
	SCENE_TYPE GetCurrentScene() override;
	void ResetScene() override;

private:
	std::vector<ALLEGRO_BITMAP*> sprites;
	std::vector<ALLEGRO_FONT*> fonts;

	void setupFilepaths();
	void loadResources();

	Player player;
};

#endif // GAME_SCENE_H