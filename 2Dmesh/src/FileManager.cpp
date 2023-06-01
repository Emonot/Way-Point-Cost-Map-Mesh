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
    
    this->mapStream << m_My_File.rdbuf();
    this->content_Yaml = this->mapStream.str();
    m_My_File.close();
    m_My_File.open(file_Name_Pgm);
    this->mapStream.str("");
    
    std::getline(m_My_File, this->version);
    std::getline(m_My_File, this->comment);
    std::getline(m_My_File, this->size);
    //std::getline(m_My_File, this->version); 
    //═ caractère ASCII 205
    this->mapStream << m_My_File.rdbuf();
    this->content_Pgm = this->mapStream.str();
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

Map FileManager::GetMapFromFile()
{
    Vector2D mapLenghtWidth = GetMapSize();
    int mapSize = mapLenghtWidth.multiply();
    char* map_Array = new char[mapSize];
    unsigned int n_oc = 0;
    unsigned int n_ff = 0;
    unsigned int n_un = 0;
    for (int i = 0; i < mapSize; i++)
    {
        unsigned char pixelValue;
        this->mapStream >> pixelValue;
        map_Array[i] = static_cast<int>(pixelValue);
    }
    for (int i = 0; i < mapSize; i++)
    {
        //-51 doit correspondre à unkown
        //-2 zone libre
        //0 zone occupé je pense
        switch (map_Array[i]) {
            case -51:
                map_Array[i] = UNKNOWN;
                n_un++;
                break;
            case -2:
                map_Array[i] = FREE;
                n_ff++;
                break;
            case 0: 
                map_Array[i] = OCCUPIED;
                n_oc++;
                break;
     }
    }
    std::cout << "unknown : " << n_un << " free : " << n_ff << " occupied : " << n_oc << std::endl;
    return Map(mapLenghtWidth, map_Array);
}

FileManager::~FileManager()
{
    m_My_File.close();
}