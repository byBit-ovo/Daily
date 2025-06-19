#pragma once
#include <iostream>
#include <queue>
using namespace std;
template <class T>
struct BTNode
{
	T _val;
	BTNode<T>* _left;
	BTNode<T>* _right;
	BTNode(const T& val) :_val(val), _left(nullptr), _right(nullptr) {}
};
template <class T>
class BTTree
{
	typedef BTNode<T> node;
private:
	node* _root;
public:
	~BTTree()
	{
		Destroy(_root);
	}
	void Destroy(node* root)
	{
		if (!root) return;
		Destroy(root->_left);
		Destroy(root->_right);
		delete root; root = nullptr;
	}
	BTTree(node* root):_root(root){}
	void _PreOrder(node* root)
	{
		if (!root) return;
		cout <<root->_val << " ";
		_PreOrder(root->_left);
		_PreOrder(root->_right);
	}
	void PreOrder()
	{
		cout << "PreOrder: ";
		_PreOrder(_root);
	}
	void InOrder()
	{
		cout << "InOrder: ";
		_InOrder(_root);
	}
	void _InOrder(node* root)
	{
		if (!root) return;
		_InOrder(root->_left);
		cout << root->_val << " ";
		_InOrder(root->_right);
	}
	void PostOrder()
	{
		cout << "PostOrder: "; 
		_PostOrder(_root);
	}
	void _PostOrder(node* root)
	{
		if (!root) return;
		_PostOrder(root->_left);
		_PostOrder(root->_right);
		cout << root->_val << " ";
	}
	void Level_order()
	{
		queue<BTNode<int>*> q; q.push(_root);
		cout << "Level_order: ";
		while (!q.empty())
		{
			cout << q.front()->_val << " ";
			if(q.front()->_left)
				q.push(q.front()->_left);
			if(q.front()->_right) 
				q.push(q.front()->_right);
			q.pop();
		}
	}
	bool Is_Complete_Tree()
	{
		queue<BTNode<int>*> q; q.push(_root);
		while (!q.empty())
		{
			if (!q.front())
			{
				while (!q.empty())
				{
					if (q.front()) return false;
					else q.pop();
				}
				return true;
			}
			q.push(q.front()->_left);
			q.push(q.front()->_right);
			q.pop();
		}
		return true;
	}
	int TreeSize()
	{
		return _TreeSize(_root);
	}
	int _TreeSize(node* root)
	{
		if (!root) return 0;
		return 1 + _TreeSize(root->_left) + _TreeSize(root->_right);
	}
	int _TreeHeight(node* root)
	{
		if (!root) return 0;
		int l = _TreeHeight(root->_left);
		int r = _TreeHeight(root->_right);
		if (l > r) r = l;
		return 1 + r;
	}
	int TreeHeight()
	{
		 return _TreeHeight(_root);
	}
	int TreekSize(int k)
	{
		return _TreekSize(_root, k);
	}
	int _TreekSize(node* root, int k)
	{
		if (!root) return 0;
		if (k == 1) return 1;
		return _TreekSize(root->_left, k - 1) + _TreekSize(root->_right, k - 1);
	}
	int TreeLeaves()
	{
		return _TreeLeaves(_root);
	}
	int _TreeLeaves(node* root)
	{
		if (!root) return 0;
		if (!root->_left && !root->_right) return 1;
		return _TreeLeaves(root->_left) + _TreeLeaves(root->_right);
	}
	node* TreeNodeFind(int k)
	{
		return _TreeNodeFind(_root, k);
	}
	node* _TreeNodeFind(node* root, int k)
	{
		if (!root) return root;
		if (root->_val == k) return root;
		if (_TreeNodeFind(root->_left, k)) return root->_left;
		if (_TreeNodeFind(root->_right, k)) return root->_right;
		return nullptr;
	}
	bool is_complete_tree(){
		queue<node*> q;
		node* cur = _root;
		q.push(cur);
		while(!q.empty()){
			node* head = q.front();
			q.pop();
			if(head==nullptr){
				while(!q.empty()){
					if(q.front()){
						return false;
					}
					q.pop();
				}
			}
			else{
				q.push(head->_left);
				q.push(head->_right);
			}
		}
		return true;
	}

	void test(){
	auto node1 = new BTNode<int>(1);
	BTTree<int> tree(node1);
	auto node2 = new BTNode<int>(2);
	auto node3 = new BTNode<int>(3);
	auto node4 = new BTNode<int>(4);
	auto node5 = new BTNode<int>(5);
	auto node6 = new BTNode<int>(6);
	auto node7 = new BTNode<int>(7);
	auto node8 = new BTNode<int>(8);
	auto node9 = new BTNode<int>(9);
	auto node10 = new BTNode<int>(10);
	auto node11 = new BTNode<int>(11);
	node1->_left = node2;
	node1->_right = node3;
	node3->_left = node9;
	node3->_right = node10;
	node10->_right = node11;
	node2->_left = node4;
	node4->_left = node5;
	node4->_right = node8;
	node5->_left = node6;
	node5->_right = node7;
	tree.InOrder();
	cout << endl;
	tree.PostOrder();
	cout << endl;
	tree.PreOrder();
	cout << endl;
	tree.Level_order(); cout << endl;
	cout << "tree.TreeSize: " << tree.TreeSize() << endl;
	cout << "tree.TreeHeight:" << tree.TreeHeight() << endl;
	for (int i = 1; i <= tree.TreeHeight(); ++i)
	{
		cout << "第" << i << "层节点个数: " << tree.TreekSize(i) << endl;
	}
	cout << "TreeLeaves: " << tree.TreeLeaves() << endl;
	for (int i = 0; i < 15; ++i)
	{
		cout << i << ": " << tree.TreeNodeFind(i) << endl;
	}

}
};