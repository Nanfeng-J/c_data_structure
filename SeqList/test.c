#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"
#include<stdio.h>
#include<assert.h>
void test01()
{
	/*SL s1;*/
	/*SeqInit(&s1);
	SeqPushBack(&s1,1);
	SeqPushBack(&s1, 2);
	SeqPushBack(&s1, 3);
	SeqPushBack(&s1, 4);
	SeqPrint(&s1);
	SeqInsert(&s1, 3, 9);
	SeqErase(&s1, 3);
	//int ret=SeqFind(&s1);
	printf("%d", ret);*/
	/*SeqPushFront(&s1, 9);
	SeqPushFront(&s1, 8);
	SeqPrint(&s1);
	SeqPopBack(&s1);*/

	/*SeqPrint(&s1);*/

	/*SeqPopFront(&s1);
	SeqPrint(&s1);*/

}
void test02()
{
	Contact s1;
	ContactInit(&s1);
	ContactAdd(&s1);
	ContactShow(&s1);
	

}

int main()
{   
	/*test01();*/
	/*test02();*/
	return 0;
}		
