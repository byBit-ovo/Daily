#include "BinTree.h"
#include "Queue.h"
BTNode* BTCreat(BTDatatype val)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
		return node;
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}
void PreOrder(BTNode* root)
{
	if (root == NULL)
		return;
	printf("%d ", root->val);
	PreOrder(root->left);
	PreOrder(root->right);

}
void InOrder(BTNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}
void PostOrder(BTNode* root)
{
	if (root == NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
}
void Level_order(BTNode* root)
{
	Queue q;
	InitQueue(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEm(&q))
	{
		BTNode* head = QueueFront(&q);
		QueuePop(&q);
		printf("%d ",head->val);
		if (head->left)
		{
			QueuePush(&q, head->left);

		}
		if (head->right)
		{
			QueuePush(&q, head->right);
		}

	}
	DestroyQueue(&q);
	
}
bool Is_Complete_Tree(BTNode* root)
{
	Queue q;
	InitQueue(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEm(&q))
	{
		BTNode* head = QueueFront(&q);
		QueuePop(&q);
		if (head == NULL)
		{
			while (!QueueEm(&q))
			{
				if (QueueFront(&q) == NULL)
				{
					return false;
				}
				else
				{
					QueuePop(&q);
				}
			}
			return true;
		}
		QueuePush(&q, head->left);
		QueuePush(&q, head->right);
	}
	DestroyQueue(&q);
	return false;
}
int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return TreeSize(root->left) + TreeSize(root->right) + 1;
}
int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int hl = TreeHeight(root->left);//所有的节点都看作根（空节点除外）
	int hr = TreeHeight(root->right);//每个TreeHeight(root->right)都是根节点root->right左右子树中更高的高度
	if (hl > hr)                     //每个TreeHeight(root->left)都是根节点root->left左右子树中高的高度
		hr = hl;                     //每棵树的高度等于1（根节点）加上左右子树中更高的高度
	return hr+1;

}
int TreekSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreekSize(root->left, k - 1) +
		TreekSize(root->right, k - 1);
}
int TreeLeaves(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeaves(root->left) + TreeLeaves(root->right);

}
BTNode* TreeNodeFind(BTNode* root, int k)
{
	if (root == NULL)
		return NULL;
	if (root->val == k)
		return root;
	BTNode* ret1 = TreeNodeFind(root->left, k);
	if (ret1)
		return ret1;
	BTNode* ret2 = TreeNodeFind(root->right, k);
	if (ret2)
		return ret2;
	return NULL;
}
