#pragma once
#include "scene.h"

Scene::Scene(SCENE_TYPE type) 
{
	current_scene = type;
}

Scene::~Scene() 
{
	
}

bool Scene::Update(ALLEGRO_EVENT event)
{
	bool keepRunning{ true };
	
	switch (current_scene)
	{
		case SCENE_TYPE::MENU:

			break;
		
		case SCENE_TYPE::GAME:
			gameScene.Update(input, event);
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