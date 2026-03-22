#include "Stack.h"
void STInit(ST* ps)
{
	assert(ps);
	ps->p = NULL;
	ps->capacity = ps->top = 0;
}
void STDestroy(ST* ps)
{
	assert(ps);
	free(ps->p);
	ps->p = NULL;
}
void STPush(ST* ps,STDatatype x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		size_t new = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDatatype* temp = (STDatatype*)realloc(ps->p,sizeof(STDatatype) * new);
		if (temp == NULL)
		{
			perror("malloc fail");
			return;
		}
		ps->p = temp;
		ps->capacity = new;
	}
	ps->p[ps->top] = x;
	ps->top++;
}
void STPop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));
	ps->top--;
}
STDatatype STTop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));
	return ps->p[ps->top - 1];
}
size_t STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool STEmpty(ST* ps)
{
	return ps->top == 0;
}