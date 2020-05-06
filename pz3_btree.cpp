#include "pz3_btree.h"
#include "pz2_queue.h"

btree* create(FILE* file)
{
	type1 element;
	btree* d = nullptr;
	fscanf(file, "%c", &element);
	if (element == '(')
	{
		d = new btree();
		fscanf(file, "%c", &element); 
		d->element = element;
		d->left = create(file);
		d->right = create(file);
		fscanf(file, "%c", &element);
	}
	if (element - '0' < 10 && element - '0' >= 0)
	{
		d = new btree();
		d->element = element;
		d->left = nullptr;
		d->right = nullptr;
		return d;
	}
	if (element == ',')
	{
		d = create(file);
	}
	return d;
}

void NLR_rec(btree* tree)
{
	if (tree)
	{
		printf("%c", tree->element);
		NLR_rec(tree->left);
		NLR_rec(tree->right);
	}
}

void NLR(btree* tree)
{
	queue_pointers* queue;
	initialize(&queue);
	char way = 1;
	char doprint = 1;
	while (tree)
	{
		if (doprint)printf("%c", tree->element);
		doprint = 1;
		if (tree->left && tree->right)
		{
			push(queue, tree, 1);
			tree = tree->left;
		}
		else
		{
			if (!tree->left && !tree->right)
			{
				if (isempty(queue))
				{
					pop(queue, &tree);
					if (tree->left)
					{
						way = 2;
					}
				}
				else
				{
					tree = nullptr;
				}
			}
			else
			{
				if (tree->left != nullptr)
				{
					tree = tree->left;
				}
				else
				{
					tree = tree->right;
				}
			}
		}
	}
}

void LNR_rec(btree* tree)
{
	if (tree)
	{
		LNR_rec(tree->left);
		printf("%c", tree->element);
		LNR_rec(tree->right);
	}
}

void LNR(btree* tree)
{

}

void LRN_rec(btree* tree)
{
	if (tree)
	{
		LRN_rec(tree->left);
		LRN_rec(tree->right);
		printf("%c", tree->element);
	}
}

void LRN(btree* tree)
{

}
