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

int main(int argc, char **argv)
{
	//std::cout << client1.GetMessage() << "\n";
	//std::cout << "Starting...\n";

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

	HttpClient client;

	HttpResponse response = client.RunRequest(adress, "GET");

	URL urlObject = response.GetRequestURL();

	std::cout << "Request information-------------------" << "\n";
	std::cout << "Full URL: " << urlObject.GetFullURL() << "\n";
	std::cout << "Protocoll: " << urlObject.GetProtocoll() << "\n";
	std::cout << "Host name: " << urlObject.GetHostName() << "\n";
	std::cout << "Port number: " << urlObject.GetPortNumber() << "\n";

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

	return 0;
}
