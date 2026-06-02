#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
typedef int HPDateType;
typedef struct Heap
{
	HPDateType* a;
	int size;
	int capacity;
}HP;
void HPInit(HP* php);
void HPDestroy(HP* php);
void HPPush(HP* php,HPDateType x);
void HPPop(HP* php);
void AdjustUp(HPDateType*a,int child);
void AdjustDown(HPDateType*a,int n,int parent);
HPDateType HPTop(HP* php);
bool HPEmpty(HP* php);
void Swap(HPDateType* p1, HPDateType* p2);
void Heapsort(int* a, int n);