#include "Queue.h"
void InitQueue(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
void DestroyQueue(Queue* pq)
{
	assert(pq);
	Qnode* pcur = pq->phead;
	Qnode* next = NULL;
	while (pcur)
	{
		next = pcur->next;
		free(pcur);
		pcur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
void QueuePush(Queue* pq, QDatatype x)
{
	Qnode* newnode = (Qnode*)malloc(sizeof(Qnode));
	if (newnode == NULL)
	{
		perror("malloc fali!");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->phead == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	if (pq->ptail == pq->phead)
	{
		free(pq->phead);
		pq->ptail = pq->phead = NULL;
		pq->size--;
		return;
	}
	Qnode* newhead = pq->phead->next;
	free(pq->phead);
	pq->phead = newhead;
	pq->size--;
}
QDatatype QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->data;
}
QDatatype QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->data;
}
bool QueueEm(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
