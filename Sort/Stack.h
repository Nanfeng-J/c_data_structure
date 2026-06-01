#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int STDateType;
typedef struct stack
{
	STDateType* a;
	int top;
	int capacity;
}ST;
//初始化
void STInit(ST* pt);
//入栈
void STPush(ST* pt,STDateType x);
//出栈
void STPop(ST* pt);
//销毁
void STDestroy(ST* pt);
//取栈顶数据
STDateType STTop(ST* pt);
//判空
bool STEmpty(ST* pt);
//获取数据个数
int STSize(ST* pt);
