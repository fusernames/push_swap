#include "push_swap.h"



static int	is_sort(t_pile *a)
{
	while (a)
	{
		if (a->next && a->nb > a->next->nb)
			return (0);
		a = a->next;
	}
	return (1);
}

int	sort_3(t_pile **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->nb;
	second = (*a)->next->nb;
	third =	(*a)->next->next->nb;
	if (first < third  && second > third)
	{
		sa(a);
		ra(a);
	}
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && first > third)
		sa(a);
	else if (first > second && third < first)
		ra(a);
	return (1);
}

static int	find_min(t_pile *a, int mode)
{
	int	min;
	int	i;
	int	ret;

	if (a)
		min = a->nb;
	i = 0;
	ret = 0;
	while (a)
	{
		if (a->nb < min)
		{
			ret = i;
			min = a->nb;
		}
		a = a->next;
		i++;
	}
	if (mode == 0)
		return (ret);
	else
		return (min);
}

int	resolve(t_pile	*a)
{
	int	min;
	int	len;
	t_pile	*b;
	int	index;
	int	swapb;

	b = NULL;
	swapb = 0;
	len = lst_len(a);
	//printf("len = %d, min = %d\n", len, find_min(a) - (len + 1));
	while (b || !is_sort(a))
	{
		if (b && is_sort(a))
			pa(&a, &b);
		else if (len == 3)
			sort_3(&a);
		else
		{
			index = find_min(a, 1);
			if ((min = find_min(a, 0)) > len / 2)
				min -= len;
			if (min > 0)
			{
				while (min-- > 0)
				{
					if (a->nb == index + 1)
					{
						pb(&a, &b);
						swapb++;
					}
					else
						ra(&a);
				}
			}
			else
			{
				while (min++ < 0)
				{
					if (a->nb == index + 1)
					{
						pb(&a, &b);
						swapb++;
					}
					rra(&a);
				}
			}
			pb(&a, &b);
			if (swapb)
			{
				sb(&b);
				swapb = 0;
				len--;
			}
			len--;
		}
	}
	print_lst(a);
	return (1);
}
