#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <iostream>
#include <string>

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

	bool Update(ALLEGRO_EVENT event, int playerKeyUp);
	void Draw();

	InputState input;
	
	struct Camera
	{
		float camera_x;
		float camera_y;
	};
	Camera camera;

private:
	SCENE_TYPE current_scene;
	// List scene types here as objects
	MenuScene menuScene;
	GameScene gameScene;
};

#endif // SCENE_H