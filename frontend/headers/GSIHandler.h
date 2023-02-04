#pragma once

#include <iostream>
#include <netinet/in.h>
#include <regex>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

class GSIHandler
{
private:
  int server_fd, new_socket, valread;
  int connection_socket;
  struct sockaddr_un address = {AF_UNIX, "/home/dotagsi123"};
  int ret;
  int result;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  void ParseData();

public:
  void Init();
  std::string maptime = "";
  std::string heroname = "";
};