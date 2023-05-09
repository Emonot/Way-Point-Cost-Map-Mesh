#include <iostream>
#include "Map.h"

Map::Map(const Vector2D map_Size)
{
	this->size = map_Size;
	this->m_Map = new char[map_Size.x * map_Size.y] ;
	for (int i = 0; i < (map_Size.x*map_Size.y); i++)
	{
		m_Map[i] = 0;
	}
}

char* Map::GetMap()
{
	return this->m_Map;
}

Map::~Map()
{
	delete[] m_Map;
}


