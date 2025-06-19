#include "Sqlist.h"
void menu()
{
	printf("********************************\n");
	printf("***1.增加联系人  2.删除联系人***\n");
	printf("***3.查找联系人  4.修改联系人***\n");
	printf("***5.展示通讯录  6.退出通讯录***\n");
	printf("********************************\n");
	printf("请选择：\n");

}
int main()
{
	int op;
	Contact contact;
	Contact_Init(&contact);
	do
	{
		menu();
		scanf("%d", &op);
		switch (op)
		{
		case 1:
			Contact_Add(&contact);
			break;
		case 2:
			Contact_Delet_By_Name(&contact);
			break;
		case 3:
			Contact_Find(&contact);
			break;
		case 4:
			Contact_Modify(&contact);
			break;
		case 5:
			Contact_Show(&contact);
			break;
		default:
			printf("输入错误！\n");
			break;
		case 6:
			break;
		}
	} while (op != 6);

}
