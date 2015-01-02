// Copyright 2014 EmilW

#include <cstdlib>
#include <string>
#include "Log.h"
Log::Log() {
  _printFunction = nullptr;
}

Log::Log(void (*printFunction)(std::string textToPrint)) {
  _printFunction = printFunction;
}

std::string Log::GetFullLogAsText() {
  return _logText;
}

void Log::Add(std::string message) {
  _logText + "\n" + message;
  if (_printFunction != nullptr) {
    _printFunction(message);
  }
}

void Log::Add(std::string prefix, std::string message) {
  Add("[" + prefix + "] " + message);
}
