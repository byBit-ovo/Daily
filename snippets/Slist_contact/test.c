#include "contact.h"
void menu()
{
	printf("1. 添加联系人\n");
	printf("2. 删除联系人\n");
	printf("3. 查找联系人\n");
	printf("4. 修改联系人\n");
	printf("5. 通讯录\n");
	printf("6.退出\n");
}
int main()
{
	Slist* list;
	Init(&list);
	int input;
	do
	{
		menu();
		scanf("%d", &input);
        switch (input)
		{
		case 1:
			Push_back(&list);
			break;
		case 2:
			Pop_by_name(&list);
			break;
		case 5:
			Show(&list);
			break;
		case 3:
			Search_people(&list);
			break;
		case 6:
			break;
		case 4:
			Modify(&list);
			break;
		}
	} while (input != 6);
	return 0;
}