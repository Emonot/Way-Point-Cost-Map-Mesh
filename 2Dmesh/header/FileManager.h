#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using String = std::string;

class FileManager
{
protected:
	String m_File_Name;
	std::ifstream m_myfile;

public:
	FileManager(String file_Name);
	~FileManager();
	String DisplayFile();
};