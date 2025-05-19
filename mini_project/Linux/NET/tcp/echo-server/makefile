.PHONY:all
all:server-tcp client-tcp

server-tcp:TcpServer.cpp 
	g++ $^ -o $@ -std=c++17 -lpthread

client-tcp:TcpClient.cpp
	g++ $^ -o $@ -std=c++17 -lpthread

.PHONY:clean
clean:
	rm -f server-tcp client-tcp
	