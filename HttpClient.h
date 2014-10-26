#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <string>
#include "HttpResponse.h"

class HttpClient
{
	public:
		HttpClient(std::string message);
		std::string GetMessage();
		HttpResponse RunRequest(std::string url, std::string type);
		std::string GetHostName(std::string url);
		int GetPort(std::string url);
	private:
		std::string _message;
};

#endif /* HTTPCLIENT_H */
