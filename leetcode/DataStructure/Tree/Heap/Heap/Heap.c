#include "Heap.h"
void Swap(HPDatatype* a, HPDatatype* b)
{
	HPDatatype t = *a;
	*a = *b;
	*b = t;
}
void AdjustUp(HPDatatype* p, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (p[parent] > p[child])
		{
			Swap(&p[parent], &p[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void AdjustDown(HPDatatype* a, int parent, int size)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child+1 < size&&a[child] > a[child + 1])
		{
			++child;
		}
		if (a[parent] > a[child])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HPInit(HP* php)
{
	assert(php);
	php->p = NULL;
	php->capacity = php->size = 0;
}
void HPDestroy(HP* php)
{
	assert(php);
	free(php->p);
	php->p = NULL;
}
void HPPush(HP* php, HPDatatype x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int new = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDatatype* tmp = (HPDatatype*)realloc(php->p, new * sizeof(HPDatatype));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->capacity = new;
		php->p = tmp;
	}
	php->p[php->size] = x;
	php->size++;
	AdjustUp(php->p, php->size - 1);
}
void HPPop(HP* php)
{
	assert(php);
	Swap(&php->p[0], &php->p[php->size - 1]);
	php->size--;
	AdjustDown(php->p, 0, php->size);
}
bool HPEmpty(HP* php)
{
	return php->size == 0;
}
HPDatatype Top(HP* php)
{
	assert(php);
	return php->p[0];
}
void HPInitArray(HP* php, HPDatatype* a, int n)
{
	php->p = (HPDatatype*)malloc(sizeof(HPDatatype) * n);
	memcpy(php->p, a, sizeof(HPDatatype) * n);
	php->size = php->capacity = n;
	int i = 1;
	while (i < n)
	{
		AdjustUp(php->p, i++);
	}

}

void HPCreat(HP* php, HPDatatype* a, int size)
{
	php->p = (HPDatatype*)malloc(sizeof(HPDatatype) * size);
	php->capacity = php->size = size;
	assert(php && a);
	memcpy(php->p, a, sizeof(HPDatatype) * size);
	for (int i = (php->size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(php->p, i, size);
	}
}

void HeapSort(HPDatatype* a, int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, i, n);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, 0, end);
		--end;
	}
}

