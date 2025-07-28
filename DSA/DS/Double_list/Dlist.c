#include "Dlist.h"
List* Buy_node(Datatype p)
{
	List* newnode = (List*)malloc(sizeof(List));
	if (newnode == NULL)
	{
		perror("fail!");
		return NULL;
	}
	newnode->data = p;
	newnode->next = newnode->prev = newnode;
	return newnode;
}

List* Init()
{
	List* phead = Buy_node(0);
	return phead;
}

void Push_back(List* phead, Datatype data)
{
	List* newnode = Buy_node(data);
	phead->prev->next = newnode;
	newnode->prev = phead->prev;
	newnode->next = phead;
	phead->prev = newnode;
}
void Print(List* phead)
{
	List* pcur = phead;
	while (pcur != phead->prev)
	{
		printf("%d->",pcur->data);
		pcur = pcur->next;
	}
	printf("%d", pcur->data);
	printf("\n");


}

void Push_front(List* phead, Datatype data)
{
	List* newnode = Buy_node(data);
	phead->next->prev = newnode;
	newnode->next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
}

void Pop_back(List* phead)
{
	assert(phead && phead->next != phead);
	List* waste = phead->prev;
	phead->prev->prev->next = phead;
	phead->prev = phead->prev->prev;
	free(waste);
}
void Pop_front(List* phead)
{
	List* waste = phead->next;
	phead->next = phead->next->next;
	phead->next->next->prev = phead;
	free(waste);
	waste = NULL;
}

List* Find(List* phead, Datatype x)
{
	List* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void Insert_after(List* pos, Datatype x)
{
	List* newnode = Buy_node(x);
	newnode->next = pos->next;
	newnode->prev = pos;
	pos->next->prev = newnode;
	pos->next = newnode;
}

void Eraser(List* pos)
{
	List* waste = pos;
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

void Destroy(List** phead)
{
	List* waste = (*phead)->next;
	List* temp = NULL;
	while (waste != *phead)
	{
		temp = waste->next;
		free(waste);
		waste = temp;
	}
	free(*phead);
	*phead = NULL;

}