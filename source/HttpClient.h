#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <string>
#include "HttpResponse.h"
#include "Log.h"

class HttpClient
{
	public:
		HttpClient();
		HttpClient(Log log);
		HttpResponse RunRequest(std::string url, std::string type);
		Log GetFullLog();
	private:
		Log _log;
};

#endif /* HTTPCLIENT_H */
