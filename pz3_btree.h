#pragma once
#include <cstdio>

typedef char type1;

struct btree
{
	type1 element;
	btree* left;
	btree* right;
};

btree* create(FILE* file);
void preorder(btree* tree);
void iterativePreorder(btree* tree);
void inorder(btree* tree);
void iterativeInorder(btree* tree);
void postorder(btree* tree);
void iterativePostorder(btree* tree);
