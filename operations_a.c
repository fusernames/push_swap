#include "push_swap.h"

int	sa(t_pile **a)
{
	int	tmp;

	if (!(*a) || !(*a)->next)
		return (0);
	tmp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = tmp;
	printf("sa\n");
	return (1);
}

int	ra(t_pile **a)
{
	t_pile	*last;
	t_pile	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return (0);
	tmp = (*a)->next;
	last = get_last_elem(*a);
	last->next = *a;
	(*a)->previous = last;
	(*a)->next = NULL;
	tmp->previous = NULL;
	*a = tmp;
	printf("ra\n");
	return (1);
}

int	rra(t_pile **a)
{
	t_pile	*last;

	if((last = get_last_elem(*a)) == NULL)
		return (0);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *a;
	(*a)->previous = last;
	*a = last;
	printf("rra\n");
	return (1);
}

int	pa(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if (*b == NULL)
		return (0);
	tmp = (*b)->next;
	if (tmp)
		tmp->previous = NULL;
	if (*a)
		(*a)->previous = *b;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	printf("pa\n");
	return (1);
}
