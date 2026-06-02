#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"
#include"Seqlist.h"
//初始化
void ContactInit(Contact* con)
{
	SeqInit(con);
}
//销毁
void ContactDestroy(Contact* con)
{
	SeqDestroy(con);
}
//增加通讯录数据
void ContactAdd(Contact* con)
{
	peoinf s;
	printf("请输入姓名：");
	scanf("%s", s.name);
	printf("请输入性别：");
	scanf("%s", s.gender);
	printf("请输入年龄：");
	scanf("%d", &s.age);
	printf("请输入地址：");
	scanf("%s", s.addr);
  //使用尾插
	SeqPushBack(con, s);
}
int Findbyname(Contact* con, char* name)
{
	for (int i = 0; i < con->arr[i].name; i++)
	{
		if (strcmpy(con->arr[i].name, name) == 0)
			return i;
	}
	return -1;
}
void ContactDel(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要删除的联系人姓名");
	scanf("%s", name);
	int find = Findbyname(con, name);
	if (find < 0)
	{
		printf("要删除的联系人不存在");
	}
	//联系人信息存在
	SeqErase(con, find);
	printf("删除成功！\n");
}
void ContactShow(Contact* con)
{
	printf("%s", "%s", "%s", "%s", "姓名", "性别", "年龄", "地址");
	for (int i = 0; i < con->size; i++)
	{
		printf("6%s", "6%s", "6%d", "6%s",
			con->arr[i].name,
			con->arr[i].gender,
			con->arr[i].age,
			con->arr[i].addr
		);
	}
}
void ContactModify(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入要修改的联系人姓名");
	scanf("%s", name);
	int find = Findbyname(con, name);
	if (find < 0)
	{
		printf("要修改的联系人不存在");
	}
	printf("请输入新的姓名");
	scanf("%s", con->arr[find].name);
	//其他数据类似修改 代码不再写
}
//查找
void ContactFind(Contact* con)
{
	char name[NAME_MAX];
	printf("请输入查找的联系人姓名");
	scanf("%s", name);
	int find = Findbyname(con, name);
	if (find < 0)
	{
		printf("要查找的联系人不存在");
	}
	printf("%s", "%s", "%s", "%s", "姓名", "性别", "年龄", "地址");
		printf("6%s", "6%s", "6%d", "6%s",
			con->arr[find].name,
			con->arr[find].gender,
			con->arr[find].age,
			con->arr[find].addr
		);
}