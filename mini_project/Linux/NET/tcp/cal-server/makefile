.PHONY:all
all:server-tcp client-tcp

server-tcp:TcpServer.cpp 
	g++ $^ -o $@ -std=c++17 -lpthread -ljsoncpp

client-tcp:TcpClient.cpp
	g++ $^ -o $@ -std=c++17 -lpthread -ljsoncpp

.PHONY:clean
clean:
	rm -f server-tcp client-tcp
	