#include "push_swap.h"

static int	find_min(t_pile *a)
{
	int		min;

	min = -1;
	while (a)
	{
		if (a->nb < min || min == -1)
			min = a->nb;
		a = a->next;
	}
	return (min);
}

int			test(t_pile **a, t_pile **b)
{
	int		nb;
	int		path;

	if (lst_len(*a) < 1)
		return (0);
	if ((nb = find_min(*a)) == -1)
		test(a,b);
	path = ps_findpath(*a, nb, nb);
	while ((*a)->nb != nb)
	{
		if ((*a)->index < nb + 14)
			pb(a, b);
		if (path > 0)
			ra(a);
		else
			rra(a);
	}
	pb(a, b);
	test(a, b); 	
	return (0);
}
