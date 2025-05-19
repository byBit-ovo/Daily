#include "string.h"
void test1()
{
    char s1[20] = "abcdrtdyf";
    char s2[] = "abefg";
    printf("%d\n", my_strlen(s1));
    printf("%d\n", my_strlen(s2));
    printf("%d\n",my_strcmp(s1,s2));
    printf("%d\n", my_strlen(s1));
    printf("%d\n", my_strlen(s2));
    my_strcat(s1,s2);
    printf("%s\n",s1);
}

void test2(){
    char arr[8] = "abcdefg";
    char arr2[]="";
    const char* p = my_strstr(arr,arr2);
    printf("%s\n",p);
}
void test3(){
    char arr1[]="abcdefghi";
    my_memmove(arr1+3,arr1+1,5);
    printf("%s\n",arr1);
}
void test4(){
    char arr[10]="hello xun";
    memset(arr,-1,10);
    printf("%s\n",arr);
}
void test5(){
    const char* str = "-294vgdfsg7";
    int ret = my_atoi(str);
    printf("%d\n",ret);
}
typedef struct sude{
    double c;
    char d;
    int a;
}stu;
typedef struct sde{
    char a;
    stu r;
    double c;
}su;
void test6(){
    su a;
    printf("%ld\n",sizeof(a));
}
int main(){
    // test5();
    test6();
    return 0;
}