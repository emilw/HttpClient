// Copyright 2014 EmilW

#ifndef SOURCE_TCPCLIENT_H_
#define SOURCE_TCPCLIENT_H_

#include <string>

using std::string;

class TCPClient {
 public:
  string Send(string hostname, string portNumber, string message);
  string SendWin(string hostname, string portNumber, string message);
  string Sendnix(string hostname, string portNumber, string message);
  string SendOverSSL(string hostname, string portNumber, string message);
};

#endif  // SOURCE_TCPCLIENT_H_
