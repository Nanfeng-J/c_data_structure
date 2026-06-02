#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SLTNode
{
	SLTDataType data;
	struct SLTNode* next;
}node;
//新节点的创建
node* SLTBuyNode(SLTDataType x);
//链表的打印
void SLTPrint(node* phead);
//链表的尾插
void SLTPushBack(node** pphead, SLTDataType x);
//链表的头插
void SLTPushFront(node** pphead, SLTDataType x);
//查找
node* SLTFind(node* phead, SLTDataType x);
//在指定位置之前插入数据
void SLTInsert(node** pphead, node* pos, SLTDataType x);
//在指定位置之后插入数据
void SLTInsertAfter(node* pos, SLTDataType x);
//删除pos节点
void SLTErase(node** pphead, node* pos);
//删除pos之后的节点
void SLTEraseAfter(node* pos);
//销毁链表
void SLTDestroy(node**pphead);
