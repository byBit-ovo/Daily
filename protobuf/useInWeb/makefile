.PHONY:clean all
all:server client
server:server.cc contact.pb.cc 
	g++ $^ -o $@ -lpthread -lprotobuf
client:client.cc contact.pb.cc
	g++ $^ -o $@ -lpthread  -lprotobuf
clean:
	rm server client