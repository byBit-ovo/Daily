#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
typedef int STDatatype;
typedef struct stack
{
	STDatatype* p;
	int top;
	int capacity;
}ST;
void STInit(ST* ps);
void STDestroy(ST* ps);
void STPush(ST* ps, STDatatype x);
void STPop(ST* ps);
STDatatype STTop(ST* ps);
size_t STSize(ST* ps);
bool STEmpty(ST* ps);
