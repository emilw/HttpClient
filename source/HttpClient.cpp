// Copyright 2014 EmilW

#include "source/HttpClient.h"
#include "source/URL.h"
#include "source/TCPClient.h"

using std::string;

HttpClient::HttpClient() {
}

HttpClient::HttpClient(Log log) {
  _log = log;
}

// This needs to be refactored to go away from command line style
HttpResponse HttpClient::RunRequest(string url, string type) {
  URL* urlObject = new URL(url);
  TCPClient client;
  string message, result;
  message = type + " " + urlObject->GetRelativePath() + " HTTP/1.1\r\n" \
            + "Host: " + urlObject->GetHostName() + "\r\n" \
            + "\r\n";

  _log.Add("Making call with hostname: " + urlObject->GetHostName());
  _log.Add("Port number: " + urlObject->GetPortNumber());
  _log.Add("Message: \n" + message);

  if (urlObject->IsSSL()) {
    _log.Add("Use https for the call");
    result = client.SendOverSSL(urlObject->GetHostName(),
                                urlObject->GetPortNumber(), message);
  } else {
    _log.Add("Use http for the call");
    result = client.Send(urlObject->GetHostName(),
                         urlObject->GetPortNumber(), message);
  }
  _log.Add("Request was made, parsing result");
  HttpResponse response(result, urlObject, _log);
  _log.Add("Response was parsed sucessfully");
  return response;
}

Log HttpClient::GetFullLog() {
  return _log;
}
