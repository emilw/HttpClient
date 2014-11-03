
#include "URL.h"
#include <cstdlib>

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
    if(this->GetProtocoll() == "https") {
      _portNumber = "443";
    } else {
      _portNumber = "80";
    }

    if(hostNameEndPos == std::string::npos) {
      _host = url;
    } else {
      _host = url.substr(0, hostNameEndPos);
    }

  } else {
    //Get the first slash if it exists
    int endPos = hostNameEndPos;
    //If there is nothing more than the hostname e.g. www.google.com, get the last position
    if(hostNameEndPos == std::string::npos) {
      endPos = url.size();
    }

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
