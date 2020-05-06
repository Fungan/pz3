#include "queue.h"

int public_queue_check(queue_pointers* qp)
{
	if (qp)
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

queue_member* private_queue_priority_member_create(type element, int priority, queue_member* next)
{
	queue_member* qm = new queue_member();
	qm->element = element;
	qm->next = next;
	qm->priority = priority;
	return qm;
}

queue_member* public_queue_priority_member_create(type element, int priority)
{
	return private_queue_priority_member_create(element, priority, nullptr);
}

void private_queue_priority_push_toempty(queue_pointers** qp, queue_member* qm)
{
	*qp = new queue_pointers();
	(*qp)->begin = qm;
	(*qp)->end = qm;
	qm->next = nullptr;
}

void private_queue_priority_push_inside(queue_member* prev, queue_member* qm, queue_member* next)
{
	prev->next = qm;
	qm->next = next;
}

void private_queue_priority_push_forward(queue_pointers** qp, queue_member* qm)
{
	qm->next = (*qp)->begin;
	(*qp)->begin = qm;
}

void private_queue_priority_push_back(queue_pointers** qp, queue_member* qm)
{
	(*qp)->end->next = qm;
	(*qp)->end = qm;
	qm->next = nullptr;
}

void public_queue_priority_push(queue_pointers** qp, queue_member* qm)
{
	if (public_queue_check(*qp))
	{
		queue_pointers* p = *qp;
		if (p->begin->priority <= qm->priority)
		{
			private_queue_priority_push_forward(qp, qm);
		}
		else
		{
			queue_member* mp = p->begin;
			while (mp->next)
			{
				if (mp->next->priority <= qm->priority)
				{
					private_queue_priority_push_inside(mp, qm, mp->next);
					return;
				}
				mp = mp->next;
			}
			private_queue_priority_push_back(qp, qm);
		}
	}
	else
	{
		private_queue_priority_push_toempty(qp, qm);
	}
}

type* public_queue_pop(queue_pointers** qp)
{
	if (!public_queue_check(*qp)) return nullptr;
	queue_pointers* p = *qp;
	type element = p->begin->element;
	if (public_queue_check(*qp) == 1)
	{
		delete p->begin;
		delete p;
		*qp = nullptr;
	}
	else
	{
		queue_member* pm = p->begin;
		(*qp)->begin = (*qp)->begin->next;
		delete pm;
	}
	return &element;
}

void public_queue_priority_output_file(queue_pointers** qp, FILE* file)
{

}

