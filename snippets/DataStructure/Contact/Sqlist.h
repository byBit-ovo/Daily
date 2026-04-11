#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "contact.h"
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS 1
typedef Info DataType;
typedef struct sq
{
	DataType* p;
	int size;
	int capacity;
}SL;

void Initiate(SL* ps);
void Check(SL* ps);
void Push_back(SL* ps, DataType m);
void Push_front(SL* ps, DataType m);
void Delet_back(SL* ps);
void Delet_front(SL* ps);
void Insert(SL* ps, DataType m,int pos);
void Eraser(SL* ps, int pos);
void Destroy(SL* ps);
void Print(SL* ps);

