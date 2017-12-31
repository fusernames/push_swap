#include "push_swap.h"

static int	find_value(t_pile *a, int min, int max)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->nb >= min && a->nb <= max)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

int		resolve(t_pile **a, t_pile **b)
{
	find_value(*a, (*b)->index, 1);
	return (1);
}