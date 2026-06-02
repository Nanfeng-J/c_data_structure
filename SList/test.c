#include"SList.h"
void test01()
{
	node* s1=NULL;
	SLTPushBack(&s1,1);
	SLTPushBack(&s1,2);
	SLTPushBack(&s1,3);
	SLTPushBack(&s1,4);
	/*SLTPrint(s1);*/
	SLTPushFront(&s1, 5);
	/*SLTPrint(s1);*/
	node*p=SLTFind(s1,2);
	/*SLTInsert(&s1,p,6);
	SLTPrint(s1);*/
	SLTInsertAfter(p, 9);
	SLTPrint(s1);
	/*SLTErase(&s1,p)*//*;*/
	SLTEraseAfter(p);
	SLTPrint(s1);

}
int main()

{
	test01();
	return 0;
}