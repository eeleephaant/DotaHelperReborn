#pragma once

#include <regex>
#include <string>

enum PlayerData
{
  Nickname,
  AccountID,
  SteamID,
  SteamID2,
  Reason,
  Sender
};

class Player
{
private:
  std::string _latestNickname = "LatestNickname";
  std::string _accountID = "AccountID";
  std::string _steamID = "SteamID";
  std::string _steamID2 = "SteamID2";
  std::string _reason = "Default reason";
  std::string _sender = "Default sender";

public:
  void addPlayerInfo(std::string nickname, std::string accountID, std::string steamID,
                     std::string steamID2, std::string reason, std::string sender);
  std::string getCSVstring();
};