#include "push_swap.h"

int			is_sorted(t_pile *a, int start, int end)
{
	int	i;

	i = end - start;
	while (a->index != start)
		a = a->next;
	while (a && a->next && i)
	{
		if ((a->index > a->next->index) ||
			(a->next->index < start || a->next->index > end))
			return (0);
		i--;
		a = a->next;
	}
	if (i)
		return (0);
	return (1);
}

void		split(t_pile **a, t_pile **b, int start, int end)
{
	int		pivot;
	pivot = (start + end) / 2;
	while (ps_findvalue(*a, start, pivot) > -1)
	{
		if ((*a)->index < pivot)
			pb(a, b);
		else if ((*a)->index > pivot)
			ra(a);
		else if ((*a)->index == pivot)
		{
			pb(a, b);
			rb(b);
		}
	}
	ps_goto(b, pivot, 'b');
	while (*a)
		pb(a, b);
}
