#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "FileManager.h"
#include "Map.h"

using String = std::string;

FileManager::FileManager(String file_Name)
    : m_File_Name(file_Name)
{
    m_myfile.open(file_Name);
}

String FileManager::DisplayFile()
{
    std::stringstream strStream;
    strStream << m_myfile.rdbuf();
    String content = strStream.str();
    return content;
}

FileManager::~FileManager()
{
    m_myfile.close();
}