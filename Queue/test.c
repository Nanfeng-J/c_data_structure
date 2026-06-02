#include"Queue.h"
int main()
{
	Queue s;
	QueueInit(&s);
	QueuePush(&s, 1);
	QueuePush(&s, 2);
	QueuePush(&s, 3);
 	QueuePush(&s, 4);
	QueuePop(&s);

	return 0;
}