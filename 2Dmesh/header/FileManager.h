#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <Map.h>
using String = std::string;

class FileManager
{
protected:
	String m_File_Name_Yaml;
	String m_File_Name_Pgm;
	std::ifstream m_My_File;
	String content_Yaml;
	String version;
	String size;
	String comment;
	String content_Pgm;

public:
	FileManager(String file_Name, String file_Name_Pgm);
	~FileManager();
	void DisplayFile();
	Vector2D GetMapSize();
	void GetMapFromFile();
};