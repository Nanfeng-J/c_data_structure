#pragma once
#include<stdio.h>
#include<stdlib.h>
#include"Contact.h"
//typedef int SLDataType;
typedef peoinf SLDataType;
typedef struct Seqlist
{
	SLDataType*arr;
	int size;
	int capacity;
}SL;
//顺序表的初始化
void SeqInit(SL*);
//检查空间是否够用
void SeqCheckCapacity(SL*);
//顺序表的销毁
void SeqDestroy(SL*);
//顺序表的尾插
void SeqPushBack(SL*,SLDataType);
//顺序表的头插
void SeqPushFront(SL*,SLDataType);
//顺序表的尾删
void SeqPopBack(SL*);
//顺序表中数组的打印
void SeqPrint(SL*);
//顺序表中任意位置数据的插入
void SeqInsert(SL*,int,SLDataType);
//顺序表中任意位置数据的删除
void SeqErase(SL*,int);
//顺序表的查找
int SeqFind(SL*);

