#include "Dlist.h"
int main()
{
	List* phead = Init();
	Push_front(phead, 3);
	Push_front(phead, 4);
	Push_front(phead, 2);//85243
	Push_front(phead, 5);
	Push_front(phead, 8);
	Print(phead);
	Print(phead->prev);
	Destroy(&phead);
	return 0;
}