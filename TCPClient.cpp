#include <iostream>
#include <cstring>      // Needed for memset
#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
#include <unistd.h>
#include "TCPClient.h"


std::string TCPClient::Send(std::string hostname, std::string portNumber, std::string message) {

  //To be used to make it platform independent
  #ifdef __linux__
  std::cout << "In Linux\n"
  #elif _WIN32
  std::cout << "In Windows\n";
  #elif __APPLE__
  std::cout << "Mac Os X\n";
  #else
  std::cout << "Unknown system \n";
  #endif

  //TCP client
   int status;
    struct addrinfo host_info;       // The struct that getaddrinfo() fills up with data.
    struct addrinfo *host_info_list; // Pointer to the to the linked list of host_info's.

    // The MAN page of getaddrinfo() states "All  the other fields in the structure pointed
    // to by hints must contain either 0 or a null pointer, as appropriate." When a struct
    // is created in c++, it will be given a block of memory. This memory is not nessesary
    // empty. Therefor we use the memset function to make sure all fields are NULL.
    memset(&host_info, 0, sizeof host_info);

    host_info.ai_family = AF_UNSPEC;     // IP version not specified. Can be both.
    host_info.ai_socktype = SOCK_STREAM; // Use SOCK_STREAM for TCP or SOCK_DGRAM for UDP.

    // Now fill up the linked list of host_info structs with google's address information.
    //status = getaddrinfo("www.google.com", "80", &host_info, &host_info_list);
    status = getaddrinfo(hostname.c_str(), portNumber.c_str(), &host_info, &host_info_list);
    // getaddrinfo returns 0 on succes, or some other value when an error occured.
    // (translated into human readable text by the gai_gai_strerror function).
    if (status != 0) {
      //std::cout << "getaddrinfo error" << gai_strerror(status) ;
      return std::string("ERROR: Hostname could not be resolved");
    }


    //std::cout << "Creating a socket..."  << std::endl;
    int socketfd ; // The socket descripter
    socketfd = socket(host_info_list->ai_family, host_info_list->ai_socktype,
                      host_info_list->ai_protocol);
    if (socketfd == -1) {
      return std::string("ERROR: Could not open socket");
    }

    status = connect(socketfd, host_info_list->ai_addr, host_info_list->ai_addrlen);
    if (status == -1) {
      return std::string("ERROR: Could not connect");
    }

    std::string msg = message;
    int len;
    ssize_t bytes_sent;
    len = strlen(msg.c_str());
    bytes_sent = send(socketfd, msg.c_str(), len, 0);

    ssize_t bytes_recieved;
    char incomming_data_buffer[1000];
    bytes_recieved = recv(socketfd, incomming_data_buffer,1000, 0);
    // If no data arrives, the program will just wait here until some data arrives.
    if (bytes_recieved == 0) {
      return std::string("ERROR: Host shut down");
    }
    if (bytes_recieved == -1) {
      return std::string("ERROR: Error when recieving");
    }
    incomming_data_buffer[bytes_recieved] = '\0' ;

    freeaddrinfo(host_info_list);

    close(socketfd);

    std::string raw(incomming_data_buffer);
    return raw;
}
