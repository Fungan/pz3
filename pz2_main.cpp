#include "pz2_queue.h"
#include <clocale>
#include <cstdlib>

int main()
{
	setlocale(LC_CTYPE, "rus");
	btree* tree = nullptr;
	FILE* f;
	fopen_s(&f, "input.txt","r");
	tree = create(f);
	NLR_rec(tree);
	printf("\n");
	NLR(tree);
	printf("\n");
//	LNR_rec(tree);
//	printf("\n");
//	LRN_rec(tree);
//	printf("\n");
	system("pause");
}