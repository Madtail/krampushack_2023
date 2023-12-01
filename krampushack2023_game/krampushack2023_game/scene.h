#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "input.h"
#include "scene_types.h"
// This is the scene director or manager, "scenemain"

class Scene
{
public:
	Scene(SCENE_TYPE type);
	~Scene();

	bool Update();
	void Draw();

	InputState input;

private:
	SCENE_TYPE current_scene;
	// List scene types here as objects

};

#endif // SCENE_H