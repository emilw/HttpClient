// Copyright 2014 EmilW

#include "source/Log.h"
#include <cstdlib>
#include <string>

using std::string;

Log::Log() {
  _printFunction = nullptr;
}

Log::Log(void (*printFunction)(string textToPrint)) {
  _printFunction = printFunction;
}

string Log::GetFullLogAsText() {
  return _logText;
}

void Log::Add(string message) {
  _logText + "\n" + message;
  if (_printFunction != nullptr) {
    _printFunction(message);
  }
}

void Log::Add(string prefix, string message) {
  Add("[" + prefix + "] " + message);
}
