#include "Enemy.h"

void Enemy::RandomDirection()
{

	direction = { 0,0 };
	int random = rand() % 4;

	switch (random)
	{
	case 0:
		direction.X = 1;
		break;
	case 1:
		direction.X = -1;
		break;
	case 2:
		direction.Y = 1;
		break;
	case 3:
		direction.Y = -1;
		break;

	}

}

Enemy::Enemy()
{

	position = { 0,0 };
	direction = { 0,0 };

}

Enemy::Enemy(COORD _spawn)
{

	position = _spawn;
	direction = { 0,0 };

}

void Enemy::Draw()
{

	ConsoleUtils::Console_SetPos(position);
	ConsoleUtils::Console_SetColor(foreground, background);
	std::cout << character;
}

void Enemy::Update(Map* _map)
{

	RandomDirection();
	COORD newPosition = position;
	newPosition.X += direction.X;
	newPosition.Y += direction.Y;

	/*if (newPosition.X < 0)
	{
		newPosition.X = pacman_map.Width - 1;
	}
	newPosition.X %= pacman_map.Width;
	if (newPosition.Y < 0)
	{
		newPosition.Y = pacman_map.Height - 1;
	}
	newPosition.Y %= pacman_map.Height;*/

	switch (_map->GetTile(newPosition.X, newPosition.Y))
	{
	case Map::MAP_TILES::MAP_WALL:
		newPosition = position;
		break;
	}

	position = newPosition;




}
