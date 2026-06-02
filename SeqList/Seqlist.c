#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"
#include<assert.h>
//初始化
void SeqInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//销毁
void SeqDestroy(SL*ps)
{
	if (ps->arr)
	{
		free(ps->arr);
	}
	ps->size =ps->capacity = 0;
}
//检查空间是否够用
void SeqCheckCapacity(SL*ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc");
			return 1;
		}
		//开辟空间成功
		ps->arr = tmp;
		ps->capacity = ps->capacity = newcapacity;
	}
}
//尾插
void SeqPushBack(SL* ps,SLDataType x)
{
	assert(ps);
	SeqCheckCapacity(ps);
	ps->arr[ps->size++]=x;  
}
//头插
void SeqPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SeqCheckCapacity(ps);
	for (int i = ps->size-1; i>=0; i--)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[0] = x;
	ps -> size++;
}
//尾删
void SeqPopBack(SL*ps)
{
	assert(ps);
	assert(ps->size);//顺序表不能为空
	ps->size--;
}
//头删
void SeqPopFront(SL* ps)
{
	for (int i = 0; i<=ps->size-2; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
//打印数组内容
//void SeqPrint(SL* ps)
//{
//	for (int i = 0; i <= ps->size - 1; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	printf("\n");
//}
//任意位置插入
void SeqInsert(SL* ps,int pos,SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SeqCheckCapacity(ps);
	for (int i = ps->size; i>=pos+1;i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}
//任意位置删除
void SeqErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	for (int i = pos; i<=ps->size-2; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
//顺序表的查找
//int SeqFind(SL* ps)
//{
//	int a = 0;
//	printf("请输入要查找的数据：");
//	scanf("%d", &a);
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->arr[i] == a)
//		{
//			return i;
//		}
//	}
//	return -1;
//}

