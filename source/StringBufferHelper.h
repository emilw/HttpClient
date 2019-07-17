// Copyright 2014 EmilW

#ifndef SOURCE_STRINGBUFFERHELPER_H_
#define SOURCE_STRINGBUFFERHELPER_H_

#include <string>
using std::string;

class StringBufferHelper {
 public:
    explicit StringBufferHelper(string buffer);
    string MoveBufferForward(int newPosition);
    string GetRawData();
    string GetNextSegmentBySeparator(string separator);
 private:
    string _buffer;
    int _currentPosition;
};


#endif  // SOURCE_STRINGBUFFERHELPER_H_
