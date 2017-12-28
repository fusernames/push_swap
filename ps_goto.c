#include "push_swap.h"

void		ps_goto(t_pile **b, int nb, char c)
{
	int	i;
	int	len;

	len = lst_len(*b);
	if ((i = ps_findvalue(*b, nb, nb)) > len / 2)
		i -= len;
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
