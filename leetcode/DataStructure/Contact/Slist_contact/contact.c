#include "contact.h"
void Init(Slist** pphead)//让指针指向一块有效的空间
{
	assert(pphead && *pphead);
	*pphead = (Slist*)malloc(sizeof(Slist));
	(*pphead)->next = *pphead;
}
Slist* Buy_Node(DataType p)
{
	Slist* newnode = (Slist*)malloc(sizeof(Slist));
	if (newnode == NULL)
	{
		perror("malloc fail!");
		exit(-1);
	}
	newnode->x = p;
	newnode->next = NULL;
	return newnode;
}

void Push_back(Slist** pphead)
{
	Person person;
	printf("name:\n");
	scanf("%s", person.name);
	printf("phone:\n");
	scanf("%s", person.phone);
	printf("address:\n");
	scanf("%s", person.address);
	Slist* newnode = Buy_Node(person);
	Slist* pcur = *pphead;
	if (pcur->next == pcur)
	{
		pcur->next = newnode;
		return;
	}
	pcur = pcur->next;
	while (pcur->next)
	{
		pcur = pcur->next;
	}
	pcur->next = newnode;
}
void Pop_by_name(Slist** pphead)
{
	Slist* pcur = *pphead;
	Slist* prev = NULL;
	char name[20];
	printf("Please input name to delet:\n");
	scanf("%s", name);
	Slist* node = Search_by_name(pphead, name);
	if (node == NULL)
	{
		perror("不存在！");
			return;
	}

	while (pcur != node)
	{
		prev = pcur;
		pcur = pcur->next;
	}
	prev->next = pcur->next;
	free(pcur);
	pcur = NULL;
}
void Show(Slist** pphead)
{
	assert(pphead && *pphead);
	Slist* pcur = *pphead;
	if (pcur == pcur->next || pcur->next == NULL)
	{
		printf("It's empty!\n");
		return;
	}
	pcur = pcur->next;
	printf("name		phone		address\n");
	while (pcur)
	{
		printf("%s		%s		%s\n", pcur->x.name, pcur->x.phone, pcur->x.address);
		pcur = pcur->next;
	}
}
Slist* Search_by_name(Slist** pphead, char* name)
{
	Slist* pcur = *pphead;
	while (pcur)
	{
		if (strcmp(name, pcur->x.name) == 0)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
void Search_people(Slist** pphead)
{
	printf("name:\n");
	char name[20];
	scanf("%s", name);
	Slist* pcur = *pphead;
	while (pcur)
	{
		if(strcmp(pcur->x.name,name) == 0)
		{
			printf("name		phone		address\n");
			printf("%s		%s		%s\n", pcur->x.name, pcur->x.phone, pcur->x.address);
			return;
		}
		pcur = pcur->next;
	}
	perror("不存在");
}
void Modify(Slist** pphead)
{
	Person person;
	Slist* pcur = *pphead;
	char name[20];
	printf("name:\n");
	scanf("%s",name);
	Slist* node = Search_by_name(pphead, name);
	if (node == NULL)
	{
		perror("不存在");
		return;
	}
	printf("name_after:\n");
	scanf("%s", person.name);
	printf("phone_after:\n");
	scanf("%s", person.phone);
	printf("address_after:\n");
	scanf("%s", person.address);
	node->x = person;
}
