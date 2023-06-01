#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

struct Vector2D
{
	unsigned int x, y;

	Vector2D();
	Vector2D(int X, int Y);
	unsigned int const multiply();
	
};

class Map
{
private:
	Vector2D size;
	char* m_Map;


public:

	Map(std::ifstream m_My_File, char* map_Ptr);
	Map(const Vector2D map_Size);
	Map(const Vector2D map_size, char* map_Array);
	const Vector2D GetSize();
	char* GetMap();
	void DisplayMap();
	~Map();
};