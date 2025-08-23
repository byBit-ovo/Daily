#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int BTDatatype;
typedef struct btree
{
	struct btree* left;
	struct btree* right;
	BTDatatype val;
}BTNode;

BTNode* BTCreat(BTDatatype val);
void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
void Level_order(BTNode* root);
bool Is_Complete_Tree(BTNode* root);
int TreeSize(BTNode* root);
int TreeHeight(BTNode* root);
int TreekSize(BTNode* root, int k);
int TreeLeaves(BTNode* root);
BTNode* TreeNodeFind(BTNode* root, int k);

