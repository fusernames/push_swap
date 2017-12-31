#include "push_swap.h"

static int	insertion_move(t_pile *b, int nb)
{
	int		max;
	int		min;

	min = -1;
	max = -1;
	while (b)
	{
		if (b->nb < min || min == -1)
			min = b->nb;
		if (b->nb > nb && (b->nb < max || max == -1))
			max = b->nb;
		b = b->next;
	}
	if (max > -1)
		return (max);
	else
		return (min);
}

int			insertion_sort(t_pile **a, t_pile **b, int start, int end)
{
	int		i;

	i = start;
	while (i <= end)
	{
		if (lst_len(*a) > 1)
			ps_goto(a, insertion_move(*a, (*b)->nb), 'a');
		pa(a, b);
		i++;
	}
	return (1);
}
