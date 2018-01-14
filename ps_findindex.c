#include "push_swap.h"

int		ps_findindex(t_pile *a, int path)
{
	if (path < 0)
		path += lst_len(a);
	while (path--)
		a = a->next;
	return (a->index);
}
