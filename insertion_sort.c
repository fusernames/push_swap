#include "push_swap.h"

static int	insertion_move(t_pile *b, int nb)
{
	int		max;
	int		min;

	min = -1;
	max = -1;
	while (b)
	{
		if (b->nb > max)
			max = b->nb;
		if (b->nb < nb && b->nb > min)
			min = b->nb;
		b = b->next;
	}
	if (min > -1)
		return (min);
	else
		return (max);
}

int			insertion_sort(t_pile **a, t_pile **b, int start, int end)
{
	int		i;

	i = start;
	while (i <= end)
	{
		//print_lst(*b);
		if ((*a) && (*a)->next && i < end &&
		((*a)->index == start || (*a)->next->index == start))
		{
			if ((*a)->next->index == start)
				sa(a);
			ra(a);
			start++;
		}
		else
		{
			if (lst_len(*b) > 1)
				ps_goto(b, insertion_move(*b, (*a)->nb), 'b');
			pb(a, b);
		}
		i++;
	}
	if (*b)
		ps_goto(b, end, 'b');
	while (*b)
		pa(a,b);
	return (1);
}
