#pragma once
#ifndef MENU_SCENE_H
#define MENU_SCENE_H

#include "BaseScene.h"

class MenuScene : public BaseScene
{
public:
	MenuScene();
	~MenuScene();

	bool Update(const InputState& keyboardState, ALLEGRO_EVENT event) override;
	void Draw() override;

	SCENE_TYPE nextScene(SCENE_TYPE type) override;
	SCENE_TYPE GetCurrentScene() override;
	void ResetScene() override;

private:


};

#endif // MENU_SCENE_H