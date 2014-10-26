#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <string>
#include <map>
#include "StringBufferHelper.h"

class HttpResponse {

public:
	HttpResponse(std::string responseData);
	std::string GetHttpStatusCode();
	std::string GetHttpStatusText();
	std::string GetRawResponse();
	std::string GetHttpVersion();
	std::map<std::string, std::string> GetHttpHeaders();
private:
	std::string moveBufferForward(std::string buffer, int newPosition);
	void parseHttpResponseData();
	void parseHttpEnvelope();
	void parseHttpHeaders();
	StringBufferHelper* _pRawBuffer;
	std::string _httpStatusCode;
	std::string _httpStatusText;
	std::string _httpVersion;
	std::map<std::string, std::string> _headerMap;
};

#endif /* HTTPRESPONSE_H */
