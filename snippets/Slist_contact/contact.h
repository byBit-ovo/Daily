#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef struct info
{
	char name[20];
	char phone[12];
	char address[30];
}Person;

typedef Person DataType;
typedef struct list
{
	DataType x;
	struct list* next;
}Slist;

void Init(Slist** pphead);
void Push_back(Slist** pphead);
void Pop_by_name(Slist** pphead);
void Search_people(Slist** pphead);
void Show(Slist** pphead);
void Modify(Slist** pphead);
Slist* Search_by_name(Slist** pphead,char* name);
Slist* Buy_Node(DataType p);
