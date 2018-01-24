#include "push_swap.h"


int		sort3(t_pile **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->nb;
	s = (*a)->next->nb;
	t =	(*a)->next->next->nb;
	if (f > s && s > t)
	{
		sa(a);
		ra(a);
		sa(a);
		rra(a);
		sa(a);
	}
	else if (f > s && s > t)
	{
		sa(a);
		rra(a);
	}
	else if (f > s && f > t)
		sa(a);
	else if (f > s && t < f)
		ra(a);
	return (1);
}

static int		is_sorted(t_pile *a)
{
	while (a)
	{
		if (a->next && a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

int		short_resolve(t_pile **a, t_pile **b)
{
	int		index;

	index = 0;
	while (!is_sorted(*a) && lst_len(*a) > 3)
	{
		ps_goto(a, index, 'a');
		if (!is_sorted(*a))
			pb(a, b);
		index++;
	}
	if (lst_len(*a) == 3)
	{
		sort3(a);
		ps_goto(a, index, 'a');
	}
	return (0);
}
