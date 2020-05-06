#pragma once
#include <cstdio>
typedef int type;
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

int public_queue_check(queue_pointers* qp);
queue_member* private_queue_priority_member_create(type element, int priority, queue_member* next);
queue_member* public_queue_priority_member_create(type element, int priority);
void private_queue_priority_push_toempty(queue_pointers** qp, queue_member* qm);
void private_queue_priority_push_inside(queue_member* prev, queue_member* qm, queue_member* next);
void private_queue_priority_push_forward(queue_pointers** qp, queue_member* qm);
void private_queue_priority_push_back(queue_pointers** qp, queue_member* qm);
void public_queue_priority_push(queue_pointers** qp, queue_member* qm);
type* public_queue_pop(queue_pointers** qp);
void public_queue_priority_output_file(queue_pointers** qp,FILE* file);
