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
void NLR_rec(btree* tree);
void NLR(btree* tree);
void LNR_rec(btree* tree);
void LNR(btree* tree);
void LRN_rec(btree* tree);
void LRN(btree* tree);
