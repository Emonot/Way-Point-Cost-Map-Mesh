#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct Vector2D
{
	unsigned int x, y;
};

class Map
{
private:
	char* m_Map;
	Vector2D size;

public:

	Map(const Vector2D map_Size);
	char* GetMap();
	~Map();
};