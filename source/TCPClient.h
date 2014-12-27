#include <string>

class TCPClient {
public:
  std::string Send(std::string hostname, std::string portNumber, std::string message);
  std::string SendOverSSL(std::string hostname, std::string portNumber, std::string message);

};
