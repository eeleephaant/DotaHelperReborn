#include "../headers/DBManager.h"

DBManager::DBManager(char *path)
{
    this->_path = path;
}

bool DBManager::Find(char *predicate)
{
    std::string line;
    std::ifstream _dbase = _openfile_read();

    while (getline(_dbase, line))
    {
        _temp_dbase += line + "\n";
    }

    size_t result = _temp_dbase.find(predicate);
    if (result == std::string::npos)
    {
        _dbase.close();
        return false;
    }
    _dbase.close();
    return true;
}

bool DBManager::Write(std::string str)
{
    if (Find((char *)str.c_str()))
    {
        std::cout << "\nDuplicate!";
        return false;
    }
    std::ofstream _dbase;
    _dbase.open(_path, std::ios::app);
    if (!_dbase.is_open())
    {
        perror("fstream: open()");
        _dbase.close();
        return false;
    }

    std::string line = _line_base + str;
    _dbase << line;
    _dbase.close();
    return true;
}

bool DBManager::Remove(std::string SteamID)
{
    std::string line;
    std::ifstream _dbase = _openfile_read();
    while (getline(_dbase, line))
    {
        _temp_dbase += line + "\n";
    }

    size_t result = _temp_dbase.find(SteamID);
    if (result == std::string::npos)
    {
        _dbase.close();
        return false;
    }
    size_t right, left;
    while (_temp_dbase[result] != '[')
    {
        result--;
    }
    printf("%d\n", result);
    right = result;
    while (_temp_dbase[result] != ']')
    {
        result++;
    }
    printf("%d\n", result);
    left = result;
    _temp_dbase.erase(right, left);
    _dbase.close();
    std::ofstream _dbasee;
    _dbasee.open(_path);
    _dbasee << _temp_dbase;

    return true;
}

bool DBManager::Modify(std::string key, PlayerData datatoreplace, std::string replace)
{
    //     std::regex nickname("[[](\\w+)");
    //     std::regex accid("[[]\\w+[,]\\s([1-9]+)");
    //     std::regex steamid("[[]\\w+[,]\\s[1-9]+[,]\\s([7656]\\d+)");
    //     std::regex steamid2("[[]\\w+[,]\\s[1-9]+[,]\\s[7656]\\d+[,]\\s([STEAM_]\\w+[:]\\w+[:]\\w+)");
    //     std::regex reason("");

    //     std::ifstream _db;
    //     std::string line;
    //     std::string temp[];
    //     _db.open("./URoD.csv");
    //     int counter = 0;
    //     while (getline(line, _db))
    //     {
    //         temp[counter] = line;
    //         counter++;
    //     }
    //     _db.close();
    //     std::cmatch c;
    //     if (datatoreplace == PlayerData::Nickname)
    //     {
    //         for (std::string x : temp)
    //         {
    //             std::regex_match(x, nickname, c);
    //             if (c[1].str() != "")
    //             {
    //                 std::regex_replace(x, )
    //             }

    //         }
    //         Write(std::regex_replace(_temp_dbase, nickname, replace));
    //         return 1;
    //     }
    //     if (datatoreplace == PlayerData::AccountID)
    //     {
    //         return 1;
    //     }
    //     if (datatoreplace == PlayerData::Reason)
    //     {
    //         return 1;
    //     }
    //     if (datatoreplace == PlayerData::Sender)
    //     {
    //         return 1;
    //     }
    //     if (datatoreplace == PlayerData::SteamID)
    //     {
    //         return 1;
    //     }
    //     if (datatoreplace == PlayerData::SteamID2)
    //     {
    //         return 1;
    //     }
    //     return 0;
}

size_t DBManager::_find_string_endpos(std::string key)
{
    std::string line;
    std::ifstream _dbase = _openfile_read();

    while (getline(_dbase, line))
    {
        _temp_dbase += line + "\n";
    }

    size_t result = _temp_dbase.find(key);
    if (result == std::string::npos)
    {
        _dbase.close();
        std::cout << "Not founded!\n";
        return 0;
    }
    while (_temp_dbase[result] != ']')
    {
        result--;
    }
    _dbase.close();
    return result;
}

size_t DBManager::_find_string_startpos(std::string key)
{
    std::ifstream _dbase = _openfile_read();
    std::string line;
    while (getline(_dbase, line))
    {
        _temp_dbase += line + "\n";
    }

    size_t result = _temp_dbase.find(key);
    if (result == std::string::npos)
    {
        _dbase.close();
        std::cout << "Not founded!\n";
        return 0;
    }
    while (_temp_dbase[result] != '[')
    {
        result--;
    }
    _dbase.close();
    return result;
}

std::ifstream DBManager::_openfile_read()
{
    std::ifstream file;
    file.open(_path);
    if (!file.is_open())
    {
        perror("fstream: open()");
        exit(0);
    }
    return file;
}