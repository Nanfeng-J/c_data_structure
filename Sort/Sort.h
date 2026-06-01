#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void PrintArray(int* a, int n);
void Swap(int* p, int* q);
//插入排序(时间复杂度:O(N^2))  最好情况O(N)  稳定
void InsertSort(int* a, int n);
//希尔排序：冒泡排序的延伸  时间复杂度O（N^1.3） 不稳定
void ShellSort(int* a, int n);
//冒泡排序（稳定）
void BubbleSort(int* a, int n);
//选择排序(不稳定)
void SelectSort(int* a, int n);
//快速排序(不稳定)            O(NlogN)            O(logN)
void QuickSort1(int* a,int left,int right);
void QuickSort2(int* a, int left, int right);
void QuickSortNonR(int* a, int left, int right);

//归并排序(稳定)  时间复杂度：O（NlogN） 空间复杂度O（N）
void MergeSort(int* a, int n);
//计数排序
void CountSort(int* a, int n);