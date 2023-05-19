#include "FileManager.h"
#include "Map.h"

int main()
{
	FileManager f("map_example.yaml", "robotarium.pgm");
	
	Vector2D map_Size = f.GetMapSize();
	Map map(map_Size);

	char* map_ptr = map.GetMap();
	f.GetMapFromFile();
	f.DisplayFile();

	/*
	std::ifstream infile("robotarium.pgm");
	std::stringstream ss;
	std::string inputline = "";

	std::getline(infile, inputline);
	std::cout << inputline;
	*/

	std::cin.get();
	return 0;
}