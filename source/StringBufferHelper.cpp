// Copyright 2014 EmilW
#include "source/StringBufferHelper.h"
// #include <string>
using std::string;

StringBufferHelper::StringBufferHelper(std::string buffer) {
    _buffer = buffer;
    _currentPosition = 0;
}

string StringBufferHelper::MoveBufferForward(int newPosition) {
    _currentPosition = newPosition;
    return _buffer.substr(_currentPosition, _buffer.size());
}

string StringBufferHelper::GetRawData() {
    return _buffer;
}

string StringBufferHelper::GetNextSegmentBySeparator(std::string separator) {
    string currentBuffer = _buffer.substr(_currentPosition, _buffer.size());
    int position = currentBuffer.find(separator);

    if (position == string::npos) {
        return "NA";
    }

    string segment = currentBuffer.substr(0, position);
    _currentPosition = _currentPosition + (position + 1);

    return segment;
}
