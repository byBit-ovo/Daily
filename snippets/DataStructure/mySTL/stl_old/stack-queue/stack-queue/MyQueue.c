#include "MyQueue.h"
MyQueue* myQueueCreate()
{
	MyQueue* qu = (MyQueue*)malloc(sizeof(MyQueue));
	STInit(&qu->pushst);
	STInit(&qu->popst);
	return qu;
}
bool myQueueEmpty(MyQueue* obj)
{
	return STEmpty(&obj->popst) && STEmpty(&obj->pushst);
}
void myQueuePush(MyQueue* obj, int x)
{
	STPush(&obj->pushst, x);
}
int myQueuePop(MyQueue* obj)
{
	int top = myQueuePeek(obj);
	STPop(&obj->popst);
	return top;
}
int myQueuePeek(MyQueue* obj)
{
	if (STEmpty(&obj->popst))
	{
		while (!STEmpty(&obj->pushst))
		{
			int top = STTop(&obj->pushst);
			STPush(&obj->popst, top);
			STPop(&obj->pushst);
		}
	}
	return STTop(&obj->popst);
}

void myQueueFree(MyQueue* obj)
{
	STDestroy(&obj->popst);
	STDestroy(&obj->pushst);
	free(obj);
}