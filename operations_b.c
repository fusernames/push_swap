#include "push_swap.h"

int	sb(t_pile **b)
{
	int	tmp;

	if (!(*b) || !(*b)->next)
		return (0);
	tmp = (*b)->nb;
	(*b)->nb = (*b)->next->nb;
	(*b)->next->nb = tmp;
	printf("sb\n");
	return (1);
}

int	rb(t_pile **b)
{
	t_pile	*last;
	t_pile	*tmp;

	if (*b == NULL || (*b)->next == NULL)
		return (0);
	tmp = (*b)->next;
	last = lst_getlast(*b);
	last->next = *b;
	(*b)->previous = last;
	(*b)->next = NULL;
	tmp->previous = NULL;
	*b = tmp;
	printf("rb\n");
	return (1);
}

int	rrb(t_pile **b)
{
	t_pile	*last;

	if((last = lst_getlast(*b)) == NULL)
		return (0);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *b;
	(*b)->previous = last;
	*b = last;
	printf("rrb\n");
	return (1);
}

int	pb(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if (*a == NULL)
		return (0);
	tmp = (*a)->next;
	if (tmp)
		tmp->previous = NULL;
	if (*b)
		(*b)->previous = *a;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	printf("pb\n");
	return (1);
}
