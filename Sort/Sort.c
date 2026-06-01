#include"Sort.h"
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void Swap(int* p, int* q)
{
	int tmp = *p;
		*p = *q;
		*q = tmp;
}

void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		//[0,end]有序 end+1位置的值插入[0,end]，保持有序
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//+1保证最后一次为直接插入排序   用gap的目的是预排序 使数据接近有序
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}
void BubbleSort(int* a, int n)//O(N^2)
{
	for (int j = 0; j < n - 1; j++)//确定趟数
	{
		int flag = 0;
		for (int i = 1; i < n-j; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}//冒一趟
		if (flag = 0)
			break;
	}
}
void SelectSort(int* a, int n)//时间复杂度O(N^2)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int mini = begin, maxi = begin;
		for (int i = begin + 1; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (begin == maxi)
			maxi = mini;
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}
void QuickSort1(int* a, int left,int right)
{
	//hoare法
	if (left >= right)
		return;
	int keyi = left;
	int begin = left, end = right;
	while (begin < end)
	{
		while (a[end] >= a[keyi] && begin < end)//左边做keyi，右边先走相遇位置一定比keyi小
		{
			end--;
		}
		while (a[begin] <= a[keyi] && begin < end)
		{
			begin++;
		}
		Swap(&a[begin], &a[end]);
	 }
	Swap(&a[keyi], &a[begin]);
	keyi = begin;
	//[0,keyi-1]  keyi  [keyi,end]
	QuickSort1(a, left, keyi - 1);
	QuickSort1(a, keyi+1, right);
}
void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
		return;
	//前后指针
	int keyi = left;

	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		cur++;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	QuickSort2(a, left, keyi - 1);
	QuickSort2(a, keyi+1, right);
}
#include"Stack.h"
int GetMidi(int* a, int left, int right)
{
	int midi = (left + right) / 2;
	// left midi right
	if (a[left] < a[midi])
	{
		if (a[midi] < a[right])
		{
			return midi;
		}
		else if (a[left] < a[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else // a[left] > a[midi]
	{
		if (a[midi] > a[right])
		{
			return midi;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

// hoare
int PartSort1(int* a, int left, int right)
{
	// 三数取中
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);

	int keyi = left;
	int begin = left, end = right;
	while (begin < end)
	{
		// 右边找小
		while (begin < end && a[end] >= a[keyi])
		{
			--end;
		}

		// 左边找大
		while (begin < end && a[begin] <= a[keyi])
		{
			++begin;
		}

		Swap(&a[begin], &a[end]);
	}

	Swap(&a[keyi], &a[begin]);
	return begin;
}

// 前后指针
int PartSort2(int* a, int left, int right)
{
	// 三数取中
	int midi = GetMidi(a, left, right);
	Swap(&a[left], &a[midi]);
	int keyi = left;

	int prev = left;
	int cur = prev + 1;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		cur++;
	}

	Swap(&a[prev], &a[keyi]);
	return prev;
}
void QuickSortNonR(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);

	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);

		int keyi = PartSort2(a, begin, end);
		// [begin, keyi-1] keyi [keyi+1, end]
		if (keyi + 1 < end)
		{
			STPush(&st, end);
			STPush(&st, keyi + 1);
		}

		if (begin < keyi - 1)
		{
			STPush(&st, keyi - 1);
			STPush(&st, begin);
		}
	}

	STDestroy(&st);
}

// 时间复杂度：O(N*logN)
// 空间复杂度：O(N)
void _MergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;
	// 如果[begin, mid][mid+1, end]有序就可以进行归并了
	_MergeSort(a, tmp, begin, mid);
	_MergeSort(a, tmp, mid + 1, end);

	// 归并
	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}

	memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}

	// gap每组归并数据的数据个数
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [begin1, end1][begin2, end2]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			printf("[%d,%d][%d,%d] ", begin1, end1, begin2, end2);

			// 第二组都越界不存在，这一组就不需要归并
			if (begin2 >= n)
				break;

			// 第二的组begin2没越界，end2越界了，需要修正一下，继续归并
			if (end2 >= n)
				end2 = n - 1;

			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}

		printf("\n");

		gap *= 2;
	}
	//计数排序在test.c文件中