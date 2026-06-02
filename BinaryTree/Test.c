#include"Heap.h"
void test01()
{
	/*HP s1;
	HPInit(&s1);*/
	int a[] = { 4,5,3,7,8,9,2,3,8,9 };
	/*for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		HPPush(&s1, arr[i]);
	}*/
	Heapsort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
}
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyNode(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}

	node->data = x;
	node->left = NULL;
	node->right = NULL;

	return node;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(6);


	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->right = node7;

	return node1;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
void BackOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("N");
		return NULL;
	}                       //递归小结：把大问题转化为一个个小问题，每个小问题的执行步骤相同
                             //递归上面的代码解决最小子问题（即递归到最后如何返回或结束）           
	BackOrder(root->left);
	BackOrder(root->right);
	printf(root->data);
}

int fun(int n)
{
	if (n == 0)
		return 0;

	return fun(n - 1) + n;
}

// 错误示范
//int TreeSize(BTNode* root)
//{
//	static int size = 0;
//	if (root == NULL)
//		return 0;
//	else
//		++size;
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//}

//int size = 0;
//int TreeSize(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	else
//		++size;
//
//	TreeSize(root->left);
//	TreeSize(root->right);
//
//	return size;
//}

//void TreeSize(BTNode* root, int* psize)
//{
//	if (root == NULL)
//		return 0;
//	else
//		++(*psize);
//
//	TreeSize(root->left, psize);
//	TreeSize(root->right, psize);
//}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 :
		TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return TreeLeafSize(root->left)
		+ TreeLeafSize(root->right);
}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);

	return leftHeight > rightHeight ?
		leftHeight + 1 : rightHeight + 1;
}

// 有效率问题
//int TreeHeight(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//
//	return TreeHeight(root->left) > TreeHeight(root->right) ?
//		TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
//}

//int fmax(int x, int y)
//{
//	return x > y ? x : y;
//}

//int TreeHeight(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//
//	return fmax(TreeHeight(root->left), TreeHeight(root->right)) + 1;
//}
//二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)
{ 
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;
	BTNode* ret2 = TreeFind(root->left, x);
	if (ret2)
		return ret2;
	return NULL;
}
int main()
{
	BTNode* root = CreatBinaryTree();
	PrevOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");

	//printf("%d\n", fun(10000));

	/*int size = 0;
	TreeSize(root, &size);
	printf("TreeSize:%d\n",size);

	size = 0;
	TreeSize(root, &size);
	printf("TreeSize:%d\n", size);*/

	printf("TreeSize:%d\n", TreeSize(root));
	printf("TreeLeafSize:%d\n", TreeLeafSize(root));
	printf("TreeHeight:%d\n", TreeHeight(root));

	return 0;
}
