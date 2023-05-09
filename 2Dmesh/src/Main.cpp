#include "FileManager.h"
#include "Map.h"
int main()
{
	FileManager f("map_example.yaml");
	std::cout << f.DisplayFile() << std::endl;

	std::cout << "\n saute stp \n" << std::endl;

	Vector2D map_Size = { 2 , 2 };
	Map map(map_Size);

	char* map_ptr = map.GetMap();

	std::cin.get();
	return 0;
}