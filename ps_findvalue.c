#include "push_swap.h"

int		ps_findvalue(t_pile *a, int min, int max)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index >= min && a->index <= max)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}
