all: client

client: main.o HttpClient.o HttpResponse.o StringBufferHelper.o URL.o
	g++ main.o HttpClient.o HttpResponse.o StringBufferHelper.o URL.o -o client

main.o: main.cpp
	g++ -c main.cpp

HttpClient.o: HttpClient.cpp HttpClient.h
	g++ -c HttpClient.cpp HttpClient.h

HttpResponse.o: HttpResponse.cpp HttpResponse.h
	g++ -c HttpResponse.cpp HttpResponse.h

StringBufferHelper.o: StringBufferHelper.cpp StringBufferHelper.h
	g++ -c StringBufferHelper.cpp StringBufferHelper.h

URL.o: URL.cpp URL.h
	g++ -c URL.cpp URL.h

#hello.o: hello.cpp
#    g++ -c hello.cpp

clean:
	rm -rf *o client
