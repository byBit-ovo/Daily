#include <stdio.h>
#include <unistd.h>

int main(){
	int a = fork();
	int b = 1;
	if(a==0){
	printf("%d\n",a);
	printf("%p\n",&b);
	b=2;
	printf("%d\n",b);
	}
	else{
	printf("%d\n",a);
	printf("%p\n",&b);
	b=3;
	printf("%d\n",b);
	}
	return 0;
}

