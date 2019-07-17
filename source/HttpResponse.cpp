// Copyright 2014 EmilW
#include "source/HttpResponse.h"
#include <string>
#include <utility>
#include <map>

using std::string;

HttpResponse::HttpResponse(string responseData, URL* originalURL,
                            Log log) {
  _log = log;
  _requestURL = originalURL;
  _log.Add("HttpResponse", "Starting parsing");

  if (responseData.substr(0, 5) == "ERROR") {
    _httpStatusCode = "999";
    _httpStatusText = responseData.substr(5, responseData.size()-5);
    _log.Add("Client handled error occured");
  } else {
    _pRawBuffer = new StringBufferHelper(responseData);
    parseHttpResponseData();
    _log.Add("HttpResponse", "Parsing of response went ok");
  }
}

URL* HttpResponse::GetRequestURL() {
  return _requestURL;
}

string HttpResponse::moveBufferForward(string buffer, int newPosition) {
  return buffer.substr(newPosition+1, buffer.size());
}

void HttpResponse::parseHttpResponseData() {
  parseHttpEnvelope();
  parseHttpHeaders();
}

void HttpResponse::parseHttpEnvelope() {
  _httpVersion = _pRawBuffer->GetNextSegmentBySeparator(" ");
  _httpStatusCode = _pRawBuffer->GetNextSegmentBySeparator(" ");
  _httpStatusText = _pRawBuffer->GetNextSegmentBySeparator("\n");
}

void HttpResponse::parseHttpHeaders() {
  string key, value;

  while (true) {
    key = _pRawBuffer->GetNextSegmentBySeparator(": ");
    if (key == "NA")
      break;
    value = _pRawBuffer->GetNextSegmentBySeparator("\n");
    _headerMap.insert(std::pair<string, string>(key, value));
  }
}

string HttpResponse::GetHttpVersion() {
  return _httpVersion;
}

string HttpResponse::GetHttpStatusCode() {
  return _httpStatusCode;
}

string HttpResponse::GetHttpStatusText() {
  return _httpStatusText;
}

std::map<string, string> HttpResponse::GetHttpHeaders() {
  return _headerMap;
}

string HttpResponse::GetRawResponse() {
  if (_pRawBuffer != nullptr)
    return _pRawBuffer->GetRawData();
  return "";
}
