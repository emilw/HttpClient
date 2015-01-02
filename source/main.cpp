// Copyright 2014 EmilW

#include <map>
#include <iostream>
#include <string>
#include "HttpClient.h"

void printOut(std::string message) {
  std::cout << "CPrint: " << message << "\n";
}

int main(int argc, char **argv) {
  std::string adress;
  if (argc > 1) {
    adress = argv[1];
  } else {
    std::cout << "No URL adress provided" << "\n";
    return -1;
  }

  Log log(printOut);
  HttpClient client(log);

  try {
    HttpResponse response = client.RunRequest(adress, "GET");
    printOut("Client was called, ok!");
    URL* urlObject = response.GetRequestURL();

    if (urlObject == nullptr) {
      std::cout << "The URL is dead";
    }

    printOut("Request information-------------------");
    printOut("Full URL: " + urlObject->GetFullURL());
    printOut("Protocoll: " + urlObject->GetProtocoll());
    printOut("Host name: " + urlObject->GetHostName());
    printOut("Port number: " + urlObject->GetPortNumber());

    printOut("Basic information---------------------");
    printOut("Version: " + response.GetHttpVersion());
    printOut("Status code: " + response.GetHttpStatusCode());
    printOut("Status text: " + response.GetHttpStatusText());

    printOut("Header information---------------------");
    std::map<std::string, std::string> headers = response.GetHttpHeaders();
    std::map<std::string, std::string>::iterator it;
    for (it=headers.begin(); it != headers.end(); ++it) {
      printOut(it->first + ": " + it->second);
    }
    printOut("Raw response-------------------------");
    printOut(response.GetRawResponse());
  } catch (int e) {
      printOut("An unhandled exception occured");
  }
  return 0;
}
