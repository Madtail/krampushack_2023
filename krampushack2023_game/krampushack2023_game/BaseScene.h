#pragma once
#ifndef BASE_SCENE_H
#define BASE_SCENE_H

#include "input.h"

enum class SCENE_TYPE {
	MENU,
	GAME,
	QUIT
};

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();

	// Returns true when a scene change is triggered.
	virtual bool Update(const InputState& state);
	virtual void Draw();

	// Function to change scene depending on conditions
	virtual SCENE_TYPE nextScene(SCENE_TYPE type);

protected:
	SCENE_TYPE type;
};

#endif // BASE_SCENE_H