#pragma once
typedef struct con
{
	char name[20];
	char phone[12];
	char address[50];
}Info;

struct sq;
typedef struct sq Contact;
void Contact_Init(Contact* pcon);//实际初始化的还是顺序表
void Contact_DesTroy(Contact* pcon);

//增加、删除、修改、查找、查看通讯录
void Contact_Add(Contact* pcon);
void Contact_Delet_By_Name(Contact* pcon);
void Contact_Modify(Contact* pcon);
void Contact_Find(Contact* pcon);
void Contact_Show(Contact* pcon);
int Find_By_Name(Contact* pcon,char name[20]);
