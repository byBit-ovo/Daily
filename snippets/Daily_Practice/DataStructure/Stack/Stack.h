#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
typedef int Datatype;
typedef struct stack
{
	Datatype* a;
	int top;
	int capacity;
}ST;

void STInit(ST* ps);
void STDestroy(ST* ps);
void STPush(ST* ps, Datatype x);
Datatype STPop(ST* ps);
Datatype STPeek(ST* ps);
int STSize(ST* ps);
bool STEmpty(ST* ps);
