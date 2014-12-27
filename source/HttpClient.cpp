#include <iostream>
#include "HttpClient.h"
#include "URL.h"
#include "TCPClient.h"


HttpClient::HttpClient() {
}

HttpClient::HttpClient(Log log){
	_log = log;
}

//This needs to be refactored to go away from command line style
HttpResponse HttpClient::RunRequest(std::string url, std::string type) {

	URL* urlObject = new URL(url);
	TCPClient client;

	std::string message = type + " / HTTP/1.1\nhost: " + urlObject->GetFullURL() + "\n\n";

	std::string result;

	if(urlObject->IsSSL()) {
			_log.Add("Use https for the call");
			result = client.SendOverSSL(urlObject->GetHostName(), urlObject->GetPortNumber(), message);
	} else {
			_log.Add("Use http for the call");
			result = client.Send(urlObject->GetHostName(), urlObject->GetPortNumber(), message);
	}
	
	_log.Add("Request was made, parsing result");
	HttpResponse response(result, urlObject, _log);
	
	_log.Add("Response was parsed sucessfully");

  return response;

}

Log HttpClient::GetFullLog() {
	return _log;
}
