#pragma once
#include "ConsoleUtils.h"
#include "Map.h"
#include <stdlib.h>
#include <time.h>

class Enemy
{
private:
	COORD spawn;
	COORD position;
	COORD direction;
	char character = 'A';
	ConsoleUtils::CONSOLE_COLOR foreground = ConsoleUtils::CONSOLE_COLOR::DARK_RED;
	ConsoleUtils::CONSOLE_COLOR background = ConsoleUtils::CONSOLE_COLOR::DARK_BLUE;
	void RandomDirection();

public:
	enum ENEMY_STATE {ENEMY_NONE,ENEMY_KILLED,ENEMY_DEAD};
	Enemy();
	Enemy(COORD _spawn);
	void Draw();
	void Update(Map* _map);
};


