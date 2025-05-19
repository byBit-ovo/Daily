.PHONY:all
all:server-udp client-udp

server-udp:udpServer.cpp 
	g++ $^ -o $@ -std=c++17 -lpthread

client-udp:udpClient.cpp
	g++ $^ -o $@ -std=c++17 -lpthread

.PHONY:clean
clean:
	rm -f server-udp client-udp
	