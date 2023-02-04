#include "../headers/Parser.h"

void Parser::_getFileData(std::string path)
{
    std::ifstream _temp;
    _temp.open(path);
    if (!_temp.is_open())
    {
        perror("ifstream.open() error");
        return;
    }
    std::string line;
    while (getline(_temp, line))
    {
        _data = line + "\n";
    }
    return;
}