// Copyright 2014 EmilW

#include <string>

class TCPClient {
public:
  std::string Send(std::string hostname, std::string portNumber, std::string message);
  std::string SendWin(std::string hostname, std::string portNumber, std::string message);
  std::string Sendnix(std::string hostname, std::string portNumber, std::string message);
  std::string SendOverSSL(std::string hostname, std::string portNumber, std::string message);

};
