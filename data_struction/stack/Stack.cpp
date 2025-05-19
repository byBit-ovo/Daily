#include "stack.h"
void STInit(ST* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
void STDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}
void STPush(ST* ps, Datatype x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int newcap = ps->capacity == 0 ? 10 : ps->capacity * 2;
		Datatype* tmp = (Datatype*)realloc(ps->a,newcap*sizeof(Datatype));
		if (tmp == NULL)
		{
			perror("malloc fail!");
			return;
		}
		ps->a = tmp;
		ps->capacity = newcap;
	}
	ps->a[ps->top] = x;
	ps->top++;

}
Datatype STPop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));
	Datatype top = ps->a[ps->top - 1];
	ps->top--;
	return top;
}
Datatype STPeek(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));
	return ps->a[ps->top - 1];
}
int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
bool STEmpty(ST* ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		return true;
	}
	return false;
}