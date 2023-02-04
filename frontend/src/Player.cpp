#include "../headers/Player.h"

void Player::addPlayerInfo(std::string nickname,
                      std::string accountID,
                      std::string steamID,
                      std::string steamID2,
                      std::string reason,
                      std::string sender)
{
  this->_accountID = accountID;
  this->_latestNickname = nickname;
  this->_reason = reason;
  this->_sender = sender;
  this->_steamID2 = steamID2;
  this->_steamID = steamID;
}

std::string Player::getCSVstring()
{
  return "[" + _latestNickname + ", " + _reason + ", " + _steamID + ", " +
         _steamID2 + ", " + _sender + "]";
}