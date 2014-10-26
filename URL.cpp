
#include "URL.h"
#include <cstdlib>
#include <iostream>

URL::URL(std::string url) {

  _url = url;
  //Get the protocoll end pos
  int protocollPos = url.find("://");

  if(protocollPos == std::string::npos) {
    _protocoll = "http";
    protocollPos = 0;
  } else {
    _protocoll = url.substr(0, protocollPos);
    //Remove the protocoll part from the url
    url = url.substr(protocollPos+3, url.size());
  }

  //Find the hostname ended by / or by : depending on if port is specified or not
  int hostNameEndPos = url.find("/");
  int portEndPos = url.find(":");

  //If the port position do not exists, set default to 80
  if(portEndPos == std::string::npos) {
    std::cout << "port do not exists";
    _portNumber = "80";

    if(hostNameEndPos == std::string::npos) {
      _host = url;
    } else {
      _host = url.substr(0, hostNameEndPos);
    }

  } else {
    std::cout << "port exists\n";
    std::cout << url << "\n";
    //Get the first slash if it exists
    int endPos = hostNameEndPos;
    //If there is nothing more than the hostname e.g. www.google.com, get the last position
    if(hostNameEndPos == std::string::npos) {
      std::cout << "host slash do not exists\n";
      endPos = url.size();
    }

    std::cout << hostNameEndPos << "\n";
    _portNumber = url.substr(portEndPos+1, url.size()-(endPos+1));
    //_host = //url.substr(portEndPos+1, url.size()-endPos);
    _host = url.substr(0, portEndPos);
  }
}

std::string URL::GetHostName() {
  return _host;
}

std::string URL::GetProtocoll() {
  return _protocoll;
}

std::string URL::GetPortNumber() {
  return _portNumber;
}

std::string URL::GetFullURL() {
  return _url;
}
