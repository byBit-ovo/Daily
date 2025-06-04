#include <unistd.h>
#include <iostream>
#include <cstdio>
int main(){
	execl("/bin/ls","ls","-l","-a",nullptr);
	std::cout<<"hello world"<<std::endl;
	return 0;
}
