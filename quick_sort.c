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

static int	quick_sort_recursive(t_pile **a, t_pile **b, int start, int end)
{
	int		pivot;
	int		nb_ra;

	nb_ra = 0;
	pivot = (start + end) / 2;
	ps_gotorange(b, start, end, 'b');
	if (end <= start || is_sorted(*b, start, end))
		return (0);
	printf("START = %d END = %d | PIVOT = %d\n", start, end, pivot);
	while (ps_findvalue(*b, pivot, end) > -1)
	{
		if ((*b)->index == pivot)
		{
			pa(a,b);
			ra(a);
		}
		else if ((*b)->index > pivot)
			pa(a, b);
		else if ((*b)->index < pivot)
		{
			if (nb_ra == 0)
				nb_ra = (*b)->index;
			rb(b);
		}
	}
	ps_goto(b, nb_ra, 'b');
	ps_goto(a, pivot, 'a');
	while (*a)
		pb(a, b);
	quick_sort_recursive(a, b, pivot + 1, end);
	quick_sort_recursive(a, b, start, pivot - 1);
	return (1);
}

int			quick_sort(t_pile **a, t_pile **b, int start, int end)
{
	int		pivot;

	pivot = (start + end) / 2;
	//printf("START = %d END = %d | PIVOT = %d\n", start, end, pivot);
	if (end <= start || is_sorted(*a, start, end))
		return (0);
	ps_gotorange(a, start, end, 'a');
	print_lst(*a);
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
			ra(a);
	}
	ps_goto(b, pivot, 'b');
	while (ps_findvalue(*a, start, end) > -1)
		pb(a, b);
	print_lst(*b);
	quick_sort_recursive(a, b, pivot + 1, end);
	quick_sort_recursive(a, b, start, pivot - 1);
	return (1);
}
