#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int	QDateType;
typedef struct QNode
{
	QDateType val;
	struct QNode* next;
}QNode;
typedef struct Queue
{
	QNode* phead;
    QNode* ptail;
	int size;
}Queue;
//队列的初始化与销毁
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
//队尾插入
void QueuePush(Queue* pq, QDateType x);
//队头删除
void QueuePop(Queue* pq);
//队头和队尾数据
QDateType QueueFront(Queue* pq);
QDateType QueueBack(Queue* pq);
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);
