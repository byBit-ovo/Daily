#include "cycle_queue.h"
MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* ps = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	ps->p = (Datatype*)malloc(sizeof(Datatype) * (k + 1));//多开一个空间解决假溢出问题
	ps->front = ps->rear = 0;
	ps->k = k;
}
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	obj->p[obj->rear] = value;
	obj->rear++;
	obj->rear %= obj->k + 1;
	return true;
}
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	obj->front++;
	obj->front %= obj->k + 1;
	return true;
}
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}

	return obj->p[obj->front];
}
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->p[(obj->rear - 1 + (1 + obj->k)) % (obj->k + 1)];
}
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->front == obj->rear;
}
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->rear + 1) % (obj->k + 1) == obj->front;
}
void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->p);
	free(obj);
}