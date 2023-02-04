#include "../headers/LobbyInfoParser.h"

LobbyInfoParser::LobbyInfoParser()
{
    SettingsParser settings("./settings.ini");
    _pathtodota = settings.GetDotaPath();
}

void LobbyInfoParser::Parse()
{
    LobbyInfoParser::_getFileData(_pathtodota);
    size_t start = _data.rfind("DOTA_GAMEMODE_ALL_DRAFT ");
    if (start == std::string::npos)
    {
        perror("rfind()");
    }
    _data.erase(0, start);
    std::cout << _data;
}