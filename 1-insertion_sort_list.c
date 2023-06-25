#include "sort.h"

/**
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *A = *list;
	listint_t *T, *S;

	if (list == NULL || A == NULL || A->next == NULL)
		return;

	A = A->next;
	while (A)
	{
		T = A;
		while (T->prev && (T->prev->n > T->n))
		{
			S = T->prev;
			S->next = T->next;
			if (S->next)
				S->next->prev = S;
			if (S->prev)
				S->prev->next = T;
			T->next = S;
			T->prev = S->prev;
			S->prev = T;
			if ((*list)->n > T->n)
				*list = T;
			print_list(*list);
		}
		A = A->next;
	}
}
