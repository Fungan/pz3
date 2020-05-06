#pragma once
#include <cstdio>
#include "pz3_btree.h"

typedef btree* type;

struct queue_member
{
	type element;
	int priority;
	queue_member* next;
};

struct queue_pointers
{
	queue_member* begin;
	queue_member* end;
};

void initialize(queue_pointers** qp);
queue_member* createmember(type element, int priority, queue_member* next);
int isempty(queue_pointers* qp);
void push(queue_pointers* qp, type element, int priority);
int pop(queue_pointers* qp, type *element);
queue_pointers* print(queue_pointers* qp);