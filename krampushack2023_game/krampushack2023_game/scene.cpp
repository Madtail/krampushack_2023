#pragma once
#include "scene.h"

Scene::Scene(SCENE_TYPE type) 
{
	current_scene = type;
	camera.camera_x = 0;
	camera.camera_y = 0;
}

Scene::~Scene() 
{
	
}

bool Scene::Update(ALLEGRO_EVENT event, int playerKeyUp)
{
	bool keepRunning{ true };
	
	switch (current_scene)
	{
		case SCENE_TYPE::MENU:

			break;
		
		case SCENE_TYPE::GAME:
			gameScene.Update(input, event, playerKeyUp);
			break;

		case SCENE_TYPE::QUIT:

			break;
		default:
			// Draw an error
			break;
	}

	return keepRunning;
}

void Scene::Draw()
{

	switch (current_scene)
	{
	case SCENE_TYPE::MENU:
		menuScene.Draw();
		break;
	case SCENE_TYPE::GAME:
		gameScene.Draw();
		break;
	case SCENE_TYPE::QUIT:
		break;
	default:
		break;
	}
}