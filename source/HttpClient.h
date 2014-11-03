#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <string>
#include "HttpResponse.h"

class HttpClient
{
	public:
		HttpClient();
		HttpResponse RunRequest(std::string url, std::string type);
	private:
};

#endif /* HTTPCLIENT_H */
