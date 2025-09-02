.PHONY:clean all
all:server client
server:server.cc contact.pb.cc
	g++ $^ -o $@ -lpthread
client:client.cc contact.pb.cc
	g++ $^ -o $@ -lpthread
clean:
	rm server client