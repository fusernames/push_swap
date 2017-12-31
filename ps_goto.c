#include "push_swap.h"

void		ps_goto(t_pile **b, int nb, char c)
{
	int		i;

	i = ps_findpath(*b, nb, nb);
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
