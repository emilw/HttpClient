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
	HttpClient client1("Message");
	std::cout << client1.GetMessage() << "\n";
	std::cout << "Starting...\n";
	if(argc > 1)
	{
		std::string dude;
		dude = argv[1];
		
		std::cout << "Hello " << dude << "\n";
	} else {
		std::cout << "No arguments" << "\n";
	}
	
	std::cout << "Dude" << "\n";
	
	HttpResponse response = client1.RunRequest("www.google.com", "GET");
	
	std::cout << "Response raw-------------------------\n";
	std::cout << response.GetRawResponse() << "\n";
	std::cout << "Version: " << response.GetHttpVersion() << "\n";
	std::cout << "Status code: " << response.GetHttpStatusCode() << "\n";
	std::cout << "Status text: " << response.GetHttpStatusText() << "\n";
	
	std::map<std::string, std::string> headers = response.GetHttpHeaders();
	std::map<std::string, std::string>::iterator it;
	for (it=headers.begin(); it!=headers.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	
	return 0;
}

