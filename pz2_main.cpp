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

	printf("������� ������:\n");
	printinput(f);
	printf("\n����� ����� �����������(preorder):\n");
	preorder(tree);
	printf("\n����� ����� �����������(iterativePreorder):\n");
	iterativePreorder(tree);
	printf("\n�������� ����� �����������(inorder):\n");
	inorder(tree);
	printf("\n�������� ����� �����������(iterativeInorder):\n");
	iterativeInorder(tree);
	printf("\n�������� ����� �����������(postorder):\n");
	postorder(tree);
	printf("\n�������� ����� �����������(iterativePostorder):\n");
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