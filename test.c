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

void	go_to(t_pile **b, int nb, char c)
{
	int	i;
	int	len;

	len = lst_len(*b);
	if ((i = find_value(*b, nb, nb)) > len / 2)
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

static int	is_sorted(t_pile *a, int start, int end)
{
	int	i;

	i = end - start;
	while (a->index != start)
		a = a->next;
	while (a && a->next && i)
	{
		if ((a->index > a->next->index) ||
			(a->index < start || a->index > end))
			return (0);
		i--;
		a = a->next;
	}
	if (i)
		return (0);
	return (1);
}

int	quick_sort(t_pile **a, t_pile **b, int start, int end)
{
	int	pivot;
	int	nb_ra;

	nb_ra = 0;
	pivot = ((end - start) / 2) + start;
	printf("pivot = %d\n", pivot);
	printf("start = %d end = %d\n", start, end);
	if (end <= start || is_sorted(*a, start, end))
		return (0);
	while ((*a)->index < start || (*a)->index > end)
		ra(a);
	while (find_value(*a, start, pivot) > -1)
	{
		if ((*a)->index <= pivot)
			pb(a, b);
		else if ((*a)->index > pivot)
		{
			ra(a);
			nb_ra++;
		}
	}
	while (nb_ra--)
		rra(a);
	go_to(b, pivot, 'b');
	while (*b)
		pa(a, b);
	quick_sort(a, b, start, pivot - 1);
	quick_sort(a, b, pivot + 1, end);
	return (1);
}
