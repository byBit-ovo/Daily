#include "contact.h"
#include "Sqlist.h"
void Contact_Init(Contact* pcon)
{
	Initiate(pcon);
}//实际初始化的还是顺序表
void Contact_DesTroy(Contact* pcon)
{
	Destroy(pcon);
}

//增加、删除、修改、查找、查看通讯录
void Contact_Add(Contact* pcon)
{
	Info info;
	printf("%s\n", "请输入联系人姓名:");
	scanf("%s", info.name);
	printf("%s\n", "请输入联系人电话:");
	scanf("%s", info.phone);
    printf("%s\n", "请输入联系人地址:");
	scanf("%s", info.address);
	Push_back(pcon,info);

}
int Find_By_Name(Contact* pcon,char name[20])
{
	    int i;
		for (i = 0; i < pcon->size; i++)
		{
			if (strcmp(name, pcon->p[i].name) == 0)
			{
				return i;
			}
		}
	
	return -1;
}
void Contact_Delet_By_Name(Contact* pcon)
{
	char name[20];
	printf("请输入要删除的用户姓名：");
	scanf("%s", name);
	int pos = Find_By_Name(pcon, name);
	if (pos < 0)
	{
		printf("该联系人不存在！\n");
		return;
	}
	Eraser(pcon, pos);
	printf("删除成功！\n");
}

void Contact_Modify(Contact* pcon)
{
	printf("请输入要修改的联系人姓名：\n");
	char name[20];
	scanf("%s", name);
	int pos = Find_By_Name(pcon, name);
	if (pos < 0)
	{
		printf("该联系人不存在！\n");
		return;
	}

	printf("请输入修改后的联系人姓名：\n");
	scanf("%s", pcon->p[pos].name);
	printf("请输入修改后的联系人电话：\n");
	scanf("%s", pcon->p[pos].phone);
	printf("请输入修改后的联系人地址：\n");
	scanf("%s", pcon->p[pos].address);

	printf("联系人修改成功！\n");


}
void Contact_Show(Contact* pcon)
{
	printf("Name		Phone		Address\n");
	int i;
	for (i = 0; i < pcon->size; i++)
	{
		printf("%s		%s		%s\n", pcon->p[i].name, pcon->p[i].phone, pcon->p[i].address);
	}
	printf("\n");
}
void Contact_Find(Contact* pcon)
{
	printf("请输入要查找的联系人姓名:\n");
	char name[20];
	scanf("%s", name);
	int pos = Find_By_Name(pcon, name);
	if (pos < 0)
	{
		printf("该联系人不存在！\n");
		return;
	}
	printf("Name		Phone		Address\n");
	printf("%s		%s		%s\n", pcon->p[pos].name, pcon->p[pos].phone, pcon->p[pos].address);

}
