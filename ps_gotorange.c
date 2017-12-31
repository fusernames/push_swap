#include "push_swap.h"

void		ps_gotorange(t_pile **b, int start, int end, char c)
{
	int		i;

	i = ps_findpath(*b, start, end);
	if (i > 0)
	{
		while (i--)
		{
			if (c == 'b')
				rb(b);
			else
				ra(b);
		}
	}
	else if (i < 0)
	{
		while (i++)
		{
			if (c == 'b')
				rrb(b);
			else
				rra(b);
		}
	}
}
