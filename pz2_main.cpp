#include "pz2_queue.h"
#include <clocale>
#include <cstdlib>
void printinput(FILE* f);

int main()
{
	setlocale(LC_CTYPE, "rus");
	btree* tree = nullptr;
	FILE* f;
	fopen_s(&f, "input.txt","r");
	if (!f) return 1;
	tree = create(f);

	printf("Входные данные:\n");
	printinput(f);
	printf("\nПямой обход рекурсивный(preorder):\n");
	preorder(tree);
	printf("\nПямой обход итеративный(iterativePreorder):\n");
	iterativePreorder(tree);
	printf("\nОбратный обход рекурсивный(inorder):\n");
	inorder(tree);
	printf("\nОбратный обход итеративный(iterativeInorder):\n");
	iterativeInorder(tree);
	printf("\nКонцевой обход рекурсивный(postorder):\n");
	postorder(tree);
	printf("\nКонцевой обход итеративный(iterativePostorder):\n");
	iterativePostorder(tree);
	printf("\n");
	system("pause");
	return 0;
}

void printinput(FILE* f)
{
	fseek(f, SEEK_SET, 0);
	char c;
	c = getc(f);
	while (c != EOF)
	{
		printf("%c", c);
		c = getc(f);
	}
}