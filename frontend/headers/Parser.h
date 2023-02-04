#pragma once

#include <fstream>
#include <regex>
#include <string>

class Parser
{
private:
public:
    std::string _data;
    void _getFileData(std::string path);
};
