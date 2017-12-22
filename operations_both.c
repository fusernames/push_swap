#include "push_swap.h"

int	ss(t_pile **a, t_pile **b)
{
	int	tmp;

	if (!(*b) || !(*b)->next)
		return (0);
	if (!(*a) || !(*a)->next)
		return (0);
	tmp = (*b)->nb;
	(*b)->nb = (*b)->next->nb;
	(*b)->next->nb = tmp;
	tmp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = tmp;
	printf("ss\n");
	return (1);
}
