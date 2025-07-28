#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
typedef int HPDatatype;
typedef struct heap
{
	HPDatatype* p;
	int size;
	int capacity;
}HP;
void HPInitArray(HP* php,HPDatatype* a, int n);
void HPInit(HP* php);
void HPDestroy(HP* php);
void HPPush(HP* php,HPDatatype x);
void HPPop(HP* php);
bool HPEmpty(HP* php);
HPDatatype Top(HP* php);
void HPCreat(HP* php, HPDatatype* a, int size);
void HeapSort(HPDatatype* a, int n);
