// Copyright 2014 EmilW

#include <string>
#include "StringBufferHelper.h"



StringBufferHelper::StringBufferHelper(std::string buffer) {
	_buffer = buffer;
	_currentPosition = 0;
}
std::string StringBufferHelper::MoveBufferForward(int newPosition){
	_currentPosition = newPosition;
	return _buffer.substr(_currentPosition, _buffer.size());
}

std::string StringBufferHelper::GetRawData() {
	return _buffer;

}

std::string StringBufferHelper::GetNextSegmentBySeparator(std::string separator) {
	
	std::string currentBuffer = _buffer.substr(_currentPosition, _buffer.size());
	
	int position = currentBuffer.find(separator);
	
	if(position == std::string::npos) {
		return "NA";
	}
	
	std::string segment = currentBuffer.substr(0, position);
	 
	_currentPosition = _currentPosition + (position + 1);
	
	return segment;
}
