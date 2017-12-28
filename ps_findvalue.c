#include "push_swap.h"

int		ps_findvalue(t_pile *a, int min, int max)
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
