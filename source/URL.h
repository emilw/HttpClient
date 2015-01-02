// Copyright 2014 EmilW

#ifndef URL_H
#define URL_H

#include <string>

class URL {
public:
  URL(std::string url);
  std::string GetHostName();
  std::string GetProtocoll();
  std::string GetPortNumber();
  std::string GetFullURL();
  bool IsSSL();
private:
  std::string _url;
  std::string _host;
  std::string _protocoll;
  std::string _portNumber;
};


#endif /* URL_H */
