// Copyright 2014 EmilW

#ifndef SOURCE_URL_H_
#define SOURCE_URL_H_

#include <string>

class URL {
 public:
  explicit URL(std::string url);
  std::string GetHostName();
  std::string GetProtocoll();
  std::string GetPortNumber();
  std::string GetFullURL();
  std::string GetRelativePath();
  std::string GetQueryString();
  bool IsSSL();
 private:
  std::string _url;
  std::string _host;
  std::string _protocoll;
  std::string _portNumber;
  std::string _relativePath;
  std::string _queryString;

  const std::string SECUREPROTOCOLPORT = "443";
  const std::string REGULAREPROTOCOLPORT = "80";
  const std::string REGULARPROTOCOL = "http";
  const std::string SECUREPROTOCOL = "https";
};


#endif  // SOURCE_URL_H_
