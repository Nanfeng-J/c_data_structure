#include"SList.h"
node* SLTBuyNode(SLTDataType x)
{
	node* newnode = malloc(sizeof(SLTDataType));
	if (newnode == NULL)
	{
		perror("malloc fail!");
	    return 1;
	}
	//空间开辟成功了
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
//链表的打印
void SLTPrint(node* phead)
{
	node* p = phead;
	while (p)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}
//尾插
void SLTPushBack(node** pphead, SLTDataType x)
{
	assert(pphead);
	node* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		node* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		//找到尾节点了
		ptail->next = newnode;
	}
}
//头插
void SLTPushFront(node** pphead, SLTDataType x)
{
	assert(pphead);
	node* newnode = SLTBuyNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}
node* SLTFind(node* phead, SLTDataType x)
{
	assert(phead);
	node* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
void SLTInsert(node** pphead, node* pos, SLTDataType x)
{
	assert(*pphead && pos&&pphead);
	if (pos==*pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		node* newnode = SLTBuyNode(x);
		node* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		//找到指定节点的前一个节点了
		newnode->next = pos;
		prev->next = newnode;
	}
}
void SLTInsertAfter(node* pos, SLTDataType x)
{
	assert(pos);
	node* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SLTErase(node** pphead, node* pos)
{
	assert(pphead && *pphead &&pos);
	if (pos == *pphead)
	{
		node* pcur = (*pphead)->next;
		free(*pphead);
		*pphead = pcur;//实际上就是头删的代码
	}
	else
	{
		node* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}
void SLTEraseAfter(node* pos)
{
	assert(pos&&pos->next);
	node* paft = pos->next->next;
	free(pos->next);
	pos->next = paft;
}
void SLTDestroy(node** pphead)//重点
{
	assert(pphead&&*pphead);
	node* pcur = *pphead;
	while (pcur)
	{
		node* next =pcur->next;
		free(pcur);
		pcur = next;
	}
	*pphead = NULL;
}






