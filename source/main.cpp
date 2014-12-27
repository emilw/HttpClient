/*
 * main.cpp
 *
 * Copyright 2014 Emil <emil@emil-desktop>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include <iostream>
#include <string>


#include "HttpClient.h"

//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>

//using std;

void printOut(std::string message){
		std::cout << "CPrint: " << message << "\n";
}

int main(int argc, char **argv)
{
	std::string adress;
	if(argc > 1)
	{
		//std::string dude;
		adress = argv[1];

		//std::cout << "Hello " << dude << "\n";

	} else {
		std::cout << "No URL adress provided" << "\n";
		return -1;
	}

	Log log(printOut);
	HttpClient client(log);

	try
	{
	HttpResponse response = client.RunRequest(adress, "GET");
	printOut("Client was called, ok!");
	
	URL* urlObject = response.GetRequestURL();
	
	if(urlObject == nullptr) {
		std::cout << "The URL is dead";
	}
	
	printOut("Request information-------------------");
	printOut("Full URL" + urlObject->GetFullURL());
	/*std::cout << "Full URL: " << urlObject->GetFullURL() << "\n";
	std::cout << "Protocoll: " << urlObject->GetProtocoll() << "\n";
	std::cout << "Host name: " << urlObject->GetHostName() << "\n";
	std::cout << "Port number: " << urlObject->GetPortNumber() << "\n";*/

	std::cout << "Basic information---------------------" << "\n";

	std::cout << "Version: " << response.GetHttpVersion() << "\n";
	std::cout << "Status code: " << response.GetHttpStatusCode() << "\n";
	std::cout << "Status text: " << response.GetHttpStatusText() << "\n";

	std::cout << "Header information---------------------" << "\n";
	std::map<std::string, std::string> headers = response.GetHttpHeaders();
	std::map<std::string, std::string>::iterator it;
	for (it=headers.begin(); it!=headers.end(); ++it)
		std::cout << it->first << ": " << it->second << '\n';

	std::cout << "Raw response-------------------------\n";
	std::cout << response.GetRawResponse() << "\n";
	} catch(int e) {
		
		std::cout << "Output 1\n";
	}

	return 0;
}
