// Copyright 2014 EmilW

#include "source/URL.h"
// #include <cstdlib>

using std::string;

URL::URL(std::string url) {
  _url = url;
  // Get the protocoll end pos
  int protocollPos = url.find("://");

  if (protocollPos == std::string::npos) {
    _protocoll = REGULARPROTOCOL;
    protocollPos = 0;
  } else {
    _protocoll = url.substr(0, protocollPos);
    // Remove the protocoll part from the url
    url = url.substr(protocollPos+3, url.size());
  }

  /* Find the hostname ended by / or by : depending on if
  port is specified or not */

  int hostNameEndPos = url.find("/");
  int portEndPos = url.find(":");

  int queryStringStartPos = url.find("?");

  // If the port position do not exists, set default to 80
  if (portEndPos == std::string::npos) {
    if (this->GetProtocoll() == SECUREPROTOCOL) {
      _portNumber = SECUREPROTOCOLPORT;
    } else {
      _portNumber = REGULAREPROTOCOLPORT;
    }
  } else {
    /* If there is nothing more than the hostname e.g. www.google.com,
    get the last position
    */
    if (hostNameEndPos == string::npos) {
      hostNameEndPos = url.size();
    }
    // If there is a port specified, e.g. www.google.com:80/subfolder
    _portNumber = url.substr(portEndPos+1, hostNameEndPos-(portEndPos+1));
    _host = url.substr(0, portEndPos);
  }

  // If the host was not set by due to that the port was not specified
  if (_host == "") {
    if (hostNameEndPos == string::npos) {
      _host = url;
    } else {
      _host = url.substr(0, hostNameEndPos);
    }
  }

  // Set the relative part of the URL
  if (hostNameEndPos != string::npos) {
    _relativePath = url.substr(hostNameEndPos, url.size()-hostNameEndPos);
  }

  // Set the query string part of the URL
  if (queryStringStartPos != string::npos) {
      _queryString = url.substr(queryStringStartPos,
                                url.size()-queryStringStartPos);
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

std::string URL::GetRelativePath() {
  return _relativePath;
}

std::string URL::GetQueryString() {
  return _queryString;
}

bool URL::IsSSL() {
  if (this->GetProtocoll() == SECUREPROTOCOL)
    return true;
  else
    return false;
}
