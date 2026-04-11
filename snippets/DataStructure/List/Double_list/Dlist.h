#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int Datatype;
typedef struct list
{
	Datatype data;
	struct list* prev;
	struct list* next;
}List;

List* Init();
void Push_back(List* phead, Datatype data);
void Print(List* phead);
void Delet(List* phead);
void Push_front(List* phead, Datatype data);
void Pop_back(List* phead);
void Pop_front(List* phead);
List* Find(List* phead, Datatype x);
void Insert_after(List* pos, Datatype x);
void Eraser_after(List* pos);
void Destroy(List** phead);