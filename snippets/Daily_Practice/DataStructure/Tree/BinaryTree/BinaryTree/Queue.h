#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "BinTree.h"
typedef BTNode* QDatatype;
typedef struct queue
{
	QDatatype data;
	struct queue* next;
}Qnode;

typedef struct que
{
	Qnode* phead;
	Qnode* ptail;
	int size;
}Queue;

void InitQueue(Queue* pq);
void DestroyQueue(Queue* pq);
void QueuePush(Queue* pq, QDatatype x);
void QueuePop(Queue* pq);
QDatatype QueueFront(Queue* pq);
QDatatype QueueBack(Queue* pq);
bool QueueEm(Queue* pq);
int QueueSize(Queue* pq);

