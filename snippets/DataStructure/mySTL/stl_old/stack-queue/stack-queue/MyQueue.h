#pragma once
#include "Stack.h"
typedef struct {
	ST pushst;
	ST popst;
}MyQueue;

MyQueue* myQueueCreate();
void myQueuePush(MyQueue* obj, int x);
int myQueuePop(MyQueue* obj);
int myQueuePeek(MyQueue* obj);
bool myQueueEmpty(MyQueue* obj);
void myQueueFree(MyQueue* obj);
