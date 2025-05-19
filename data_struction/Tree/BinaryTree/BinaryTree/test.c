#include "BinTree.h"
#include <stdbool.h>
void test()
{
	BTNode* node1 = BTCreat(1);
	BTNode* node2 = BTCreat(2);
	BTNode* node3 = BTCreat(3);
	BTNode* node4 = BTCreat(4);
	BTNode* node5 = BTCreat(5);
	BTNode* node6 = BTCreat(6);
	BTNode* node7 = BTCreat(7);
	BTNode* node8 = BTCreat(8);
	BTNode* node9 = BTCreat(9);
	BTNode* node10 = BTCreat(10);

	node1->left = node2;
	node1->right = node3;
	node3->left = node6;
	node3->right = node7;
	node2->left = node4;

	//PreOrder(node1);
	//printf("\n");
	//InOrder(node1);
	//printf("\n");
	//PostOrder(node1);
	//printf("\n");
	//printf("%d nodes in total \n", TreeSize(node1));
	//printf("Height: %d \n", TreeHeight(node1));
	//printf("Leaves: %d\n", TreeLeaves(node1));
	//printf("to find: %p\n", node8);
	//printf("find:    %p\n", TreeNodeFind(node1, 8));
	Level_order(node1);
	bool a = Is_Complete_Tree(node1);
	printf("\n%d\n", a);
}
int main()
{
	test();
	return 0;
}
