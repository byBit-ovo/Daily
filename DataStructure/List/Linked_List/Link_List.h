#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int DataType;
typedef struct link
{
	DataType data;
	struct link* next;
}Node;

void Push_back(Node** phead, DataType x);
void Push_front(Node** phead, DataType x);
void Print_List(Node* phead);
void Delet_Tail(Node** phead);
void Delet_head(Node** phead);
void Insert_front(Node** pphead, Node* pos, DataType x);
void Insert_after(Node* pos, DataType x);
void Eraser_node(Node** pphead, Node* pos);
void Delet_After(Node* pos);
void Destroy_List(Node* phead);
Node* Buy_Node(DataType x);
Node* Find_Node(Node** pphead, DataType x);
Node* reverse(Node* phead);

