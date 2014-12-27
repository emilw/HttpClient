#ifndef LOG_H
#define LOG_H

#include <string>

class Log {
public:
  Log();
  Log(void (*printFunction)(std::string textToPrint));
  void Add(std::string message);
  void Add(std::string prefix, std::string message);
  std::string GetFullLogAsText();
private:
  std::string _logText;
  void (*_printFunction)(std::string textToPrint);
};


#endif /* LOG_H */
