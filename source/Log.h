// Copyright 2014 EmilW

#ifndef SOURCE_LOG_H_
#define SOURCE_LOG_H_
#include <string>

class Log {
 public:
  Log();
  explicit Log(void (*printFunction)(std::string textToPrint));
  void Add(std::string message);
  void Add(std::string prefix, std::string message);
  std::string GetFullLogAsText();
 private:
  std::string _logText;
  void (*_printFunction)(std::string textToPrint);
};


#endif  // SOURCE_LOG_H_
