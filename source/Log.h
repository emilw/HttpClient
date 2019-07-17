// Copyright 2014 EmilW

#ifndef SOURCE_LOG_H_
#define SOURCE_LOG_H_
#include <string>

using std::string;

class Log {
 public:
  Log();
  explicit Log(void (*printFunction)(string textToPrint));
  void Add(string message);
  void Add(string prefix, string message);
  string GetFullLogAsText();
 private:
  string _logText;
  void (*_printFunction)(string textToPrint);
};


#endif  // SOURCE_LOG_H_
