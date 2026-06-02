#include"Heap.h"
void HPInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void HPDestroy(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;
}
void Swap(HPDateType* p1, HPDateType* p2)
{
	HPDateType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//向上调整
void AdjustUp(HPDateType*a,int child)
{
	//建小堆
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void HPPush(HP* php,HPDateType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDateType* tmp = (HPDateType*)realloc(php->a, newcapacity * sizeof(HPDateType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			return;
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size - 1);
}
//向下调整
void AdjustDown(HPDateType*a,int n,int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HPPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}
HPDateType HPTop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}
bool HPEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
void Heapsort(int* a, int n)
{
	//降序 建小堆
	/*for (int i = 1; i < n; i++)
	{
		AdjustUp(a, i);
	}*/
	for (int i = (n - 1 - 1) / 2; i >=0; i--)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}