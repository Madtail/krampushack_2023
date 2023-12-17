#pragma once
#ifndef GLOBALS_H
#define GLOBALS_H

constexpr double FPS{ 60 };

extern int SCREEN_W;
extern int SCREEN_H;

extern int PLAYER_WIDTH;
extern int PLAYER_HEIGHT;

extern int BACKGROUND_WIDTH;
extern int BACKGROUND_HEIGHT;

typedef struct {
	int x, y, w, h;
} Rect;

extern bool collide(Rect rect1, Rect rect2);

#endif // !GLOBALS_H
