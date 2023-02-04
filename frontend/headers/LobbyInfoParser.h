#include "../headers/Parser.h"
#include "SettingsParser.h"
#include <stdio.h>

class LobbyInfoParser : Parser
{
private:
    std::string _pathtodota;
public:
    //std::string SteamID3[];
    LobbyInfoParser();
    void Parse();

};




