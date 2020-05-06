#include "pz2_queue.h"


void initialize(queue_pointers** queue)
{
	queue_pointers* qp;
	qp = new queue_pointers();
	qp->begin = nullptr;
	qp->end = nullptr;
	*queue = qp;
}

queue_member* createmember(type element, int priority, queue_member *next)
{
	queue_member* qm = new queue_member();
	qm->element = element;
	qm->priority = priority;
	qm->next = next;
	return qm;
}

int isempty(queue_pointers* qp) 
{
	if (qp->begin)
	{
		if (qp->begin == qp->end)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 0;
	}
}

void push(queue_pointers* qp, type element, int priority)
{
	if (!isempty(qp))
	{
		qp->begin = createmember(element, priority, nullptr);;
		qp->end = qp->begin;
	}
	else
	{	
		if (priority >= qp->begin->priority)
		{ 
			qp->begin = createmember(element, priority, qp->begin);
			return;
		}
		queue_member *qm = qp->begin;
		while (qm->next)
		{
			if (priority >= qm->next->priority)
			{
				qm->next = createmember(element, priority, qm->next);
				return;
			}
			qm = qm->next;
		}
		qm->next = createmember(element, priority, nullptr);
		qp->end = qm->next;
	}
}

int pop(queue_pointers* qp, type* element)
{
	if (!isempty(qp)) return 0;
	*element = qp->begin->element;

	if (isempty(qp) == 1)
	{
		delete qp->begin;
		qp->begin = nullptr;
		qp->end = nullptr;
	}
	else
	{
		queue_member* qm = qp->begin;
		qp->begin = qp->begin->next;
		delete qm;
	}
	return 1;
}

queue_pointers* print(queue_pointers* qp)
{
	if (!isempty(qp))
	{
		printf_s("Очередь пуста\n");
		return qp;
	}
	else
	{
		queue_pointers* new_queue;
		initialize(&new_queue);
		type element;
		while (isempty(qp))
		{
			push(new_queue, qp->begin->element, qp->begin->priority);
			pop(qp, &element);
			printf_s("%d\t", element);
		}
		return new_queue;
	}
	return nullptr;
}