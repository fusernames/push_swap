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

int			quick_sort(t_pile **a, t_pile **b, int start, int end)
{
	int		pivot;
	int		nb_ra;

	nb_ra = 0;
	pivot = (start + end) / 2;
	printf("START = %d END = %d | PIVOT = %d\n", start, end, pivot);
	if (end <= start || is_sorted(*a, start, end))
		return (0);
	while ((*a)->index < start || (*a)->index > end)
		ra(a);
	if (end - start <= 25)
		return (insertion_sort(a, b, start, end));
	while (ps_findvalue(*a, start, pivot) > -1)
	{
		if ((*a)->index == pivot)
		{
			pb(a,b);
			rb(b);
		}
		if ((*a)->index < pivot)
			pb(a, b);
		else if ((*a)->index > pivot)
		{
			if (nb_ra == 0)
				nb_ra = (*a)->index;
			ra(a);
		}
	}
	if (nb_ra)
		ps_goto(a, nb_ra, 'a');
	ps_goto(b, pivot, 'b');
	while (ps_findvalue(*b, start, pivot) > -1)
		pa(a, b);
	quick_sort(a, b, start, pivot - 1);
	quick_sort(a, b, pivot + 1, end);
	return (1);
}
