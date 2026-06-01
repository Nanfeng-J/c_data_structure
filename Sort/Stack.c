#include"Stack.h"
//初始化
void STInit(ST* pt)
{
	assert(pt);
	pt->a = NULL;
	pt->top = 0;
	pt->capacity = 0;
}
//销毁
void STDestroy(ST* pt)
{
	assert(pt);
	free(pt->a);
	pt->a = NULL;
	pt->top = pt->capacity = 0;
}
//入栈
void STPush(ST* pt,STDateType x)
{
	assert(pt);
	if (pt->top == pt->capacity)
	{
		int newcapacity =pt->capacity==0?4:pt->capacity*2;
		STDateType* tmp = (STDateType*)realloc(pt->a, newcapacity * sizeof(STDateType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			return;
		}
		pt->a = tmp;
		pt->capacity = newcapacity;
	}
	pt->a[pt->top] = x;
	pt->top++;
}
//出栈
void STPop(ST* pt)
{
	assert(pt);
	assert(pt->top>0);
	pt->top--;
}
//取栈顶数据
STDateType STTop(ST* pt)
{
	assert(pt);
	assert(pt->top>0);
	return pt->a[pt->top - 1];
}
//判空
bool STEmpty(ST* pt)
{
	assert(pt);
	if (pt->top==0)
	{
		return true;
	}
	return false;
}
//获取数据个数
int STSize(ST* pt)
{
	assert(pt);
	return pt->top;
}