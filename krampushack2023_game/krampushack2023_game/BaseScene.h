#pragma once
#ifndef BASE_SCENE_H
#define BASE_SCENE_H

#include "input.h"

#include <vector>

enum class SCENE_TYPE {
	NEW_SCENE,
	MENU,
	GAME,
	QUIT
};

class BaseScene
{
public:
	BaseScene();
	//virtual ~BaseScene();

	// Returns true when a scene change is triggered.
	virtual bool Update(const InputState& state, ALLEGRO_EVENT event) = 0;
	virtual void Draw() = 0;

	// Function to change scene depending on conditions
	virtual SCENE_TYPE nextScene(SCENE_TYPE type) = 0;
	virtual SCENE_TYPE GetCurrentScene() = 0;
	virtual void ResetScene() = 0;

protected:
	SCENE_TYPE type;

	std::vector<const char*> image_resources;
	std::vector<const char*> font_resources;
	std::vector<const char*> audio_resources;
};

#endif // BASE_SCENE_H