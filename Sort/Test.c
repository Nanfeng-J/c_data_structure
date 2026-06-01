#include"Sort.h"
int main()
{
	int a[] = { 2,4,6,4,1,7,9 };
	/*InsertSort(a, sizeof(a) / sizeof(int));*/
	//BubbleSort(a, 7);   
	QuickSort2(a, 0, 6);
	PrintArray(a, sizeof(a) / sizeof(int));
	return 0;
}
// 时间复杂度:O(N+range)
// 只适合整数/适合范围集中
// 空间范围度：O(range)
void CountSort(int* a, int n)
{
	int min = a[0], max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];

		if (a[i] > max)
			max = a[i];
	}

	int range = max - min + 1;
	//printf("%d\n", range);

	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		perror("calloc fail");
		return;
	}

	// 统计次数
	for (int i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}

	// 排序
	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (count[i]--)
		{
			a[j++] = i + min;
		}
	}

	free(count);
}