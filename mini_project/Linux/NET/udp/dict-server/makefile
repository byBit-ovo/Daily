.PHONY:all
all:server-udp client-udp

server-udp:udpServer.cpp
	g++ $^ -o $@ -std=c++17

client-udp:udpClient.cpp
	g++ $^ -o $@ -std=c++17

.PHONY:clean
clean:
	rm -f server-udp client-udp
	