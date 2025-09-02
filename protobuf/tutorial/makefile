.PHONY:clean all
all:read write
read:read.cc contact.pb.cc
	g++ $^ -o $@ -std=c++11 -lprotobuf 
write:write.cc contact.pb.cc
	g++ $^ -o $@ -std=c++11 -lprotobuf 
clean:
	rm read write