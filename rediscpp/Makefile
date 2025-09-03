main:main.cc
	g++ $^ /usr/local/lib/libredis++.a /usr/lib/x86_64-linux-gnu/libhiredis.a  -o $@ -std=c++17 -lpthread 
.PHONY:clean
clean:
	rm main