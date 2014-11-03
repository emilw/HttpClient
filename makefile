#Define variables
CXX	:= g++
CXXFLAGS := -g

OBJECTFOLDER := objects
#SOURCEFOLDER := source

#OBJECTS := main.cpp.o HttpClient.cpp.o HttpResponse.cpp.o StringBufferHelper.cpp.o URL.cpp.o TCPClient.cpp.o
NEWSOURCE := main.cpp HttpClient.cpp HttpResponse.cpp StringBufferHelper.cpp URL.cpp TCPClient.cpp
OBJECTS := $(NEWSOURCE:.cpp=.o)
OBJECTSWITHPATH := $(addprefix objects/, $(OBJECTS))
DUDE := $(addprefix buddy/, nisse pisse)

#OBJBUILDPATH = $(OBJECT: path/, )

all: client

#client: $(OBJECTS)
#	$(CXX) objects/$(OBJECTS) -o client

#VPATH = src:objects

client: $(OBJECTS)
	$(CXX) $(OBJECTSWITHPATH) -o bin/client

#client: %.o
#	$(CXX) $< -o client

%.o: source/%.cpp
	$(CXX) -c $< -o objects/$@

#main.cpp.o: main.cpp
#	$(CXX) -c main.cpp

#HttpClient.o: HttpClient.cpp HttpClient.h
#	$(CXX) -c HttpClient.cpp HttpClient.h

#HttpResponse.o: HttpResponse.cpp HttpResponse.h
#	$(CXX) -c HttpResponse.cpp HttpResponse.h

#StringBufferHelper.o: StringBufferHelper.cpp StringBufferHelper.h
#	$(CXX) -c StringBufferHelper.cpp StringBufferHelper.h

#TCPClient.o: TCPClient.cpp TCPClient.h
#	$(CXX) -c $<



#hello.o: hello.cpp
#    g++ -c hello.cpp

clean:
	rm -rf objects/*.o
	rm -rf bin/client
