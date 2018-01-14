#include "push_swap.h"

int	ss(t_pile **a, t_pile **b)
{
	int	tmp;

	if (!(*b) || !(*b)->next)
		return (0);
	if (!(*a) || !(*a)->next)
		return (0);
	tmp = (*b)->nb;
	(*b)->nb = (*b)->next->nb;
	(*b)->next->nb = tmp;
	tmp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = tmp;
	printf("ss\n");
	return (1);
}

int		rr(t_pile **a, t_pile **b)
{
	t_pile	*last;
	t_pile	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return (0);
	if (*b == NULL || (*b)->next == NULL)
		return (0);
	tmp = (*a)->next;
	last = get_last_elem(*a);
	last->next = *a;
	(*a)->previous = last;
	(*a)->next = NULL;
	tmp->previous = NULL;
	*a = tmp;
	tmp = (*b)->next;
	last = get_last_elem(*b);
	last->next = *b;
	(*b)->previous = last;
	(*b)->next = NULL;
	tmp->previous = NULL;
	*b = tmp;
	printf("rr\n");
	return (1);
}

int		rrr(t_pile **a, t_pile **b)
{
	t_pile	*last;

	if((last = get_last_elem(*a)) == NULL)
		return (0);
	if(get_last_elem(*b) == NULL)
		return (0);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *a;
	(*a)->previous = last;
	*a = last;
	last = get_last_elem(*b);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *b;
	(*b)->previous = last;
	*b = last;
	printf("rrr\n");
	return (1);
}
