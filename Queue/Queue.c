#include"Queue.h"
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);

}
//Î²²å
void QueuePush(Queue* pq, QDateType x)
        {
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail!");
		return;
	}
	newnode->next = NULL;
	newnode->val = x;
	if (pq->ptail == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	pq->size++;
}
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->size != 0);
	QNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
	pq->size--;
}
QDateType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}
QDateType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}






