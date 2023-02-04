#include <fstream>
#include <regex>
#include <iostream>
#include "../headers/Parser.h"

class SettingsParser : Parser
{
private:
    std::string _temp;
public:
    SettingsParser(std::string path);
    std::string GetDotaPath();
};