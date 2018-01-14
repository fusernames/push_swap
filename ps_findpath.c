#include "push_swap.h"

int		ps_findpath(t_pile *a, int min, int max)
{
	int		i;
	int		r;
	int		rr;
	t_pile 	*cpy;

	r = -1;
	rr = -1;
	i = 0;
	if (min < 0 || max < 0)
		return (-1);
	while (a)
	{
		if (a->index >= min && a->index <= max && r == -1)
			r = i;
		if (a->next == NULL)
			cpy = a;
		a = a->next;
		i++;
	}
	i = 1;
	while (cpy)
	{
		if (cpy->index >= min && cpy->index <= max && rr == -1)
			rr = i;
		cpy = cpy->previous;
		i++;
	}
	return (r <= rr ? r : -rr);
}
