#include <iostream>
#include "Map.h"
#include "FileManager.h"

Vector2D::Vector2D(): x(0),y(0) {};
Vector2D::Vector2D(int X, int Y) : x(X), y(Y) {}
unsigned int const Vector2D::multiply() { return x * y; }

Map::Map(std::ifstream m_My_File, char* map_Ptr)
	: m_Map(map_Ptr) {}

Map::Map(const Vector2D map_Size)
{
	this->size = map_Size;
	this->m_Map = new char[map_Size.x * map_Size.y] ;
	for (int i = 0; i < (map_Size.x*map_Size.y); i++)
	{
		m_Map[i] = 0;
	}
}

char* Map::GetMap(){ return this->m_Map; }
const Vector2D Map::GetSize() { return this->size;  }

Map::~Map(){delete[] m_Map;}


