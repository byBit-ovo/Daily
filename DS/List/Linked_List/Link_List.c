#include "Link_List.h"

Node* Buy_Node(DataType x)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = x;
	node->next = NULL;
	return node;
}

void Push_back(Node** pphead, DataType x)
{
	assert(pphead);
	Node* newnode = Buy_Node(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
		return;
	}

	Node* temp = *pphead;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	//temp已经指向尾节点
	temp->next = newnode;

}

void Push_front(Node** pphead, DataType x)
{
	assert(pphead);
	Node* newnode = Buy_Node(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void Delet_Tail(Node** pphead)
{
	assert(pphead && *pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	Node* pcur = *pphead;
	Node* pre = NULL;
	while (pcur->next != NULL)
	{
		pre = pcur;
		pcur = pcur->next;
	}
	free(pcur);
	pcur = NULL;
	pre->next = NULL;
}

void Delet_head(Node** pphead)
{
	assert(pphead && *pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
		return;
	}
	Node* freenode = *pphead;
	*pphead = (*pphead)->next;
	free(freenode);
}


void Print_List(Node* phead)
{
	while (phead != NULL)
	{
		printf("%d->", phead->data);
		phead = phead->next;
	}
	printf("NULL\n");
}

Node* Find_Node(Node** pphead, DataType x)
{
	Node* pcur = *pphead;
	while (pcur != NULL)
	{
		if (x == pcur->data)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	perror("不存在");
	return NULL;
}

void Insert_front(Node** pphead, Node* pos, DataType x)
{
	assert(pphead);
	Node* newnode = Buy_Node(x);
	Node* pcur = *pphead;
	if (*pphead == pos)
	{
		Push_front(pphead, x);
		return;
	}
	while (pcur->next != pos)
		pcur = pcur->next;
	newnode->next = pos;
	pcur->next = newnode;

}

void Insert_after(Node* pos, DataType x)
{
	Node* newnode = Buy_Node(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void Eraser_node(Node** pphead, Node* pos)
{
	Node* pcur = *pphead;
	if (*pphead == pos)
	{
		Delet_head(pphead);
		return;
	}
	while (pcur->next != pos)
		pcur = pcur->next;
	pcur->next = pos->next;
	free(pos);
	pos = NULL;

}

void Delet_After(Node* pos)
{
	Node* freenode = pos->next;
	pos->next = pos->next->next;
	free(freenode);
	freenode = NULL;
}

void Destroy_List(Node* phead)
{
	Node* pcur = phead;
	Node* next = phead;
	while (next != NULL)
	{
		next = next->next;
		free(pcur);
		pcur = next;
	}

}

//Node* reverse(Node* phead)
//{
//	Node* prev = NULL;
//	Node* next = phead->next;
//	Node* cur = phead;
//	while (cur != NULL)
//	{
//		cur->next = prev;
//		prev = cur;
//		cur = next;
//		if(cur != NULL)
//		next = cur->next;
//	}
//	return prev;
//}

Node* reverse(Node* phead)
{
	Node* prev = NULL;
	Node* pcur = phead;
	Node* next = pcur->next;
	while (pcur != NULL)
	{
		pcur->next = prev;
		prev = pcur;
		pcur = next;
		if(pcur != NULL)
		next = pcur->next;
	}
	return prev;
}


