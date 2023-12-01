#pragma once
#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "BaseScene.h"

class GameScene : public BaseScene
{
public:
	GameScene();
	~GameScene();

	bool Update(const InputState& state) override;
	void Draw() override;

	SCENE_TYPE nextScene(SCENE_TYPE type) override;

private:


};

#endif // GAME_SCENE_H