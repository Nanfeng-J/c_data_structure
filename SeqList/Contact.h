#pragma once
#define NAME_MAX 20
#define GENDER_MAX 20
#define ADDRESS_MAX 20
typedef struct personinfo
{
	char name[NAME_MAX];
	char gender[GENDER_MAX];
	int age;
	char addr[ADDRESS_MAX];
}peoinf;
struct Seqlist;
typedef struct Seqlist Contact;
//通讯录的初始化
void ContactInit(Contact*);
//通讯录的销毁
void ContactDestroy(Contact*);
//通讯录添加数据
void ContactAdd(Contact*);
//通讯录删除数据
void ContactDel(Contact*);
//通讯录修改数据
void ContactModify(Contact*);
//通讯录查找数据
void ContactFind(Contact*);
//通讯录的展示
void ContactShow(Contact*);
