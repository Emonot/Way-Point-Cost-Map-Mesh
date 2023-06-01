#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Map.h"
using String = std::string;
enum CELL_STATUS { OCCUPIED, FREE, UNKNOWN };

class FileManager
{
protected:
	String m_File_Name_Yaml;
	String m_File_Name_Pgm;

	std::ifstream m_My_File;
	std::stringstream mapStream;

	String content_Yaml;
	String content_Pgm;
	String version;
	String size;
	String comment;

public:
	FileManager(String file_Name, String file_Name_Pgm);
	~FileManager();
	void DisplayFile();
	Vector2D GetMapSize();
	Map GetMapFromFile();
};