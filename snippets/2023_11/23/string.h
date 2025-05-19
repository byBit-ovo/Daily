#include <assert.h>
#include <string.h>
#include <stdio.h>
int my_strlen(const char* s){
    const char* p = s;
    while(*p!='\0'){
        ++p;
    }
    return p-s;
}

char* my_strcpy(char* dest,const char* src){
    if(dest==NULL||src==NULL) return dest;
    char* head = dest;
    while((*dest++ = *src++)){
       ;
    }
    return head;
}

int my_strcmp(const char* s1,const char* s2){
    assert(s1&&s2);
    while(*s1==*s2){
        if(*s1=='\0') return 0;
        ++s1;
        ++s2;
    }
    return *s1-*s2;
}

void my_strcat(char* dest,const char* src){
    assert(dest && src);
    while(*dest!='\0'){
        ++dest;
    }
    while(*dest++=*src++){
        ;
    }
}

const char* my_strstr(const char* s1,const char* s2){
    if(s2==NULL) return s1;
    assert(s1);
    while(*s1!='\0'){
        const char* tmp1 = s1;
        const char* tmp2 = s2;
        while(*tmp1++==*tmp2++){
            if(*tmp2=='\0'){
                return s1;
            }
        }
        ++s1;
    }
    return NULL;
}

void my_memmove(void *dest, void *src, int num)
{
    assert(dest && src);
    if (dest < src)
    {
        //->
        for (int i = 0; i < num; ++i)
        {
            *((char *)dest + i) = *((char *)src + i);
        }
    }
    else
    {
        //<-
        while (num--)
        {
            *((char *)dest + num) = *((char *)src + num);
        }
    }
}

void my_memset(void* ptr,int value,int num){
    assert(ptr);
    char* p = (char*)ptr;
    while(num--){
        p[num] = (char)value;
    }
}

int my_atoi(const char* str){
    assert(str!=NULL);
    int ret = 0;
    int sign = 1;
    if(*str=='-'){
        sign=-1;
        ++str;
    }
    else if(*str=='+'){
        ++str;
    }
    while(*str!='\0' && *str>='0' &&*str<='9'){
        ret = ret*10+*str-'0';
        ++str;
    }
    if(sign==-1)
    ret = -ret;
    return ret;
}