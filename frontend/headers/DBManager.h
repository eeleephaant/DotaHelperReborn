#pragma once

#include "Player.h"
#include <fstream>
#include <iostream>
#include <regex>
#include <stdio.h>

class DBManager
{
private:
    std::string _temp_dbase;
    const std::string _line_base = "\n";
    char *_path;
    size_t _find_string_startpos(std::string key);
    size_t _find_string_endpos(std::string key);
    std::ifstream _openfile_read();

public:
    DBManager(char *path);
    bool Find(char *predicate);
    bool Write(std::string string);
    bool Remove(std::string SteamID);
    bool Modify(std::string key, PlayerData typetomodify, std::string replace);
};