#include "SQlist.h"
void Initiate(SL* ps)
{
	ps->size = ps->capacity = 0;
	ps->p = NULL;
}
void Check(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int new = ps->capacity == 0 ? 100 : ps->capacity * 2;
		DataType* temp = (DataType*)realloc(ps->p, new * sizeof(DataType));
		if (temp != NULL)
		{
			ps->p = temp;
			ps->capacity = new;
		}
		else
		{
			perror("realloc fail!");
			exit(-1);
		}
	}
}
void Push_back(SL* ps, DataType m)
{
	assert(ps != NULL);
	Check(ps);
	ps->p[ps->size++] = m;
}
void Push_front(SL* ps, DataType m)
{
	assert(ps != NULL);
	Check(ps);
	int i;
	for (i = ps->size; i > 0; i--)// ps->p[ps->size] = ps->p[ps->size -1]
	{                             // ps->p[1] = ps->p[0];
		ps->p[i] = ps->p[i - 1];
	}

	ps->p[0] = m;
	ps->size++;
}
void Delet_back(SL* ps)
{
	assert(ps && ps->size >= 0);
	ps->size--;
}
void Delet_front(SL* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size - 1; i++)
	{
		ps->p[i] = ps->p[i + 1];//ps->p[0] =ps->p[1]
		                        //ps->p[ps->size-2] = ps->p[ps->size-1]
	}

	ps->size--;
}
void Insert(SL* ps, DataType m, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	Check(ps);
	int i;
	for (i = ps->size; i > pos; i--)
	{
		ps->p[i] = ps->p[i - 1];//ps->p[ps->size] = ps->p[ps->size-1];
	}
	//ps->p[pos+1] = ps->p[pos];
	ps->p[pos] = m;
	ps->size++;
}
void Eraser(SL* ps, int pos)
{
	assert(ps);
	int i = pos;
	for (i = pos; i < ps->size - 1; i++)
	{
		ps->p[i] = ps->p[i + 1];
	}
	ps->size--;
}

void Destroy(SL* ps)
{
	assert(ps);
	free(ps->p);
	ps->p = NULL;
}

//void Print(SL* ps) {
//	for (int i = 0; i < ps->size; i++)
//	{
//		printf("%d ", ps->p[i]);
//	}
//	printf("\n");
//}
