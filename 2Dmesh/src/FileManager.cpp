#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include "FileManager.h"
#include "Map.h"

using String = std::string;


FileManager::FileManager(String file_Name_Yaml, String file_Name_Pgm)
    : m_File_Name_Yaml(file_Name_Yaml), m_File_Name_Pgm(file_Name_Pgm)
{
    m_My_File.open(file_Name_Yaml);
    std::stringstream strStream;
    strStream << m_My_File.rdbuf();
    this->content_Yaml = strStream.str();
    m_My_File.close();
    m_My_File.open(file_Name_Pgm);
    strStream.str("");
    
    std::getline(m_My_File, this->version);
    std::getline(m_My_File, this->comment);
    std::getline(m_My_File, this->size);
    //std::getline(m_My_File, this->version); 
    //═ caractère ASCII 205
    strStream << m_My_File.rdbuf();
    this->content_Pgm = strStream.str();
}

void FileManager::DisplayFile()
{
    std::cout << this->content_Yaml << std::endl;
    std::cout << this->version << std::endl;
    std::cout << this->comment << std::endl;
    std::cout << this->size << std::endl;
}

Vector2D FileManager::GetMapSize()
{
    String s_Temp_Size = this->size;

    unsigned int x_Size = std::stoi(s_Temp_Size.substr(s_Temp_Size.find(" ")+1));
    s_Temp_Size.erase(s_Temp_Size.find(" "));
    unsigned int y_Size = std::stoi(s_Temp_Size);


    std::cout << x_Size << " " << y_Size << std::endl;
    return Vector2D(x_Size,y_Size); 
}

void FileManager::GetMapFromFile()
{
    std::stringstream strStream;

    Map map(GetMapSize());
}

FileManager::~FileManager()
{
    m_My_File.close();
}