#include "../headers/SettingsParser.h"

std::regex path("path = (.+[\\//]dota 2 beta)");

SettingsParser::SettingsParser(std::string path) 
{
    SettingsParser::_getFileData(path);
}

std::string SettingsParser::GetDotaPath()
{
    std::smatch c;
    std::regex_search(_data, c, path);
    if (c[1].str() == "") {
        std::cout << "Check ur settings file\n";
        exit(-1);
    }
    return c[1].str();
}