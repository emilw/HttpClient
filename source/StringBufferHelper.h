// Copyright 2014 EmilW

#ifndef STRINGBUFFERHELPER_H
#define STRINGBUFFERHELPER_H

#include <string>

class StringBufferHelper {
	
public:
	StringBufferHelper(std::string buffer);
	std::string MoveBufferForward(int newPosition);
	std::string GetRawData();
	std::string GetNextSegmentBySeparator(std::string separator);
private:
	std::string _buffer;
	int _currentPosition;
};


#endif /* STRINGBUFFERHELPER_H */
