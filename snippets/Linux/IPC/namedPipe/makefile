.PHONY:all
all:server client

server:server.cpp
	g++ $^ -o $@
client:client.cpp
	g++ $^ -o $@

.PHONY:clean
clean:
	rm -f server client