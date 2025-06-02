.PHONY:all
all:reader1 reader2 writer

reader1:reader1.cpp
	g++ $^ -o $@
reader2:reader2.cpp
	g++ $^ -o $@
writer:writer.cpp
	g++ $^ -o $@

.PHONY:clean
clean:
	rm -f reader1 reader2 writer