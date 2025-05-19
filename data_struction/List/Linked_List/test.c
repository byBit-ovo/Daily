#include "Link_List.h"

int main()
{
	Node* plist = NULL;
	Push_back(&plist, 1);
	Push_back(&plist, 2);
	Push_back(&plist, 3);
	Push_back(&plist, 4);
	Print_List(plist);
	Print_List(reverse(plist));
	return 0;
}