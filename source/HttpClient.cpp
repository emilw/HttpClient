#include <iostream>
#include "HttpClient.h"
#include "URL.h"
#include "TCPClient.h"


HttpClient::HttpClient() {
}

//This needs to be refactored to go away from command line style
HttpResponse HttpClient::RunRequest(std::string url, std::string type) {

	URL urlObject(url);
	TCPClient client;

	std::string message = type + " / HTTP/1.1\nhost: " + urlObject.GetFullURL() + "\n\n";

	std::string result;

	if(urlObject.GetProtocoll() == "https") {
			result = client.SendOverSSL(urlObject.GetHostName(), urlObject.GetPortNumber(), message);
	} else {
			result = client.Send(urlObject.GetHostName(), urlObject.GetPortNumber(), message);
	}


	HttpResponse response(result, urlObject);

  return response;

}
