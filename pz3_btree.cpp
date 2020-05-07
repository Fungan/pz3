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

void preorder(btree* tree)
{
	if (tree)
	{
		printf("%c", tree->element);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void iterativePreorder(btree* tree)
{
	queue_pointers* queue;
	initialize(&queue);
	while (tree)
	{
		printf("%c", tree->element);
		if (tree->left && tree->right)
		{
			push(queue, tree->right, 1);
			tree = tree->left;
		}
		else
		{
			if (!tree->left && !tree->right)
			{
				if (isempty(queue))
				{
					pop(queue, &tree);
				}
				else
				{
					tree = nullptr;
				}
			}
		}
	}
}

void inorder(btree* tree)
{
	if (tree)
	{
		inorder(tree->left);
		printf("%c", tree->element);
		inorder(tree->right);
	}
}

void iterativeInorder(btree* tree)
{
	queue_pointers* queue;
	initialize(&queue);
	while (tree)
	{
		if (tree->left && tree->right)
		{
			push(queue, tree, 1);
			tree = tree->left;
		}
		else
		{
			if (!tree->left && !tree->right)
			{
				printf("%c", tree->element);
				if (isempty(queue))
				{
					pop(queue, &tree);
					printf("%c", tree->element);
					tree = tree->right;
				}
				else
				{
					tree = nullptr;
				}
			}
		}
	}
}

void postorder(btree* tree)
{
	if (tree)
	{
		postorder(tree->left);
		postorder(tree->right);
		printf("%c", tree->element);
	}
}

void iterativePostorder(btree* tree)
{
	queue_pointers* queue;
	initialize(&queue);
	btree* last = nullptr;
	while (tree)
	{
		if (tree->left && tree->right)
		{
			if (tree->right == last)
			{
				last = tree;
				printf("%c", tree->element);
				if (!pop(queue, &tree)) tree = nullptr; 
			}
			else
			{
				push(queue, tree, 1);
				if (last != tree->left)
				{
					tree = tree->left;
				}
				else
				{
					tree = tree->right;
				}
			}
		}
		else
		{
			if (!tree->left && !tree->right)
			{
				printf("%c", tree->element);
				if (isempty(queue))
				{
					last = tree;
					pop(queue, &tree);
				}
				else
				{
					tree = nullptr;
				}
			}
		}
	}
}
