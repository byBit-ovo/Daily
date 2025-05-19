#include "Binarytree.h"
#include <stack>
#include <list>
int main()
{
	BTNode<int>* root = new BTNode<int>(0);
	BTTree<int> tree(root);
	tree.test();
	return 0;
}