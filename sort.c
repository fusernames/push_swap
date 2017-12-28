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

int		sort(t_pile **a, int len)
{
	if (len == 1)
		sa(a);
	else if (len == 2)
		sort3(a);
	return (1);
}
