#include "../headers/GSIHandler.h"

void GSIHandler::Init()
{
  int connection_socket = socket(AF_UNIX, SOCK_STREAM, 0);
  if (connection_socket == -1)
  {
    perror("socket");
    exit(EXIT_FAILURE);
  }
  int len = sizeof(struct sockaddr) + 6;
  if (connect(connection_socket, (struct sockaddr *)&address, len) < 0)
  {
    perror("connect");
    exit(1);
  }

  for (;;)
  {
    ret = read(connection_socket, buffer, 1024);
    if (ret == -1)
    {
      perror("read");
      exit(EXIT_FAILURE);
    }
    printf("\n%s", buffer);
    fflush(NULL);
    ParseData();
  }

  close(connection_socket);
  exit(EXIT_SUCCESS);
}

void GSIHandler::ParseData()
{
  if (buffer[0] == 't')
  {
    std::regex time("t:(\\d+)");
    std::cmatch m;
    std::regex_match(buffer, m, time);
    maptime = "";
    maptime = m[1].str();
  }
  if (buffer[0] == 'h' && buffer[1] == 'n')
  {
    std::regex time("hn:(.+)");
    std::cmatch m;
    std::regex_match(buffer, m, time);

    heroname = m[1].str();
    std::cout << heroname;
  }
}