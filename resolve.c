/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:32:28 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/25 21:32:29 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_pile *a)
{
	int		min;

	min = -1;
	while (a)
	{
		if (a->index < min || min == -1)
			min = a->index;
		a = a->next;
	}
	return (min);
}

static void	move(t_pile **a, t_pile **b, int path_a, int path_b)
{
	while (path_a || path_b)
	{
		if (path_a > 0 && path_b > 0)
		{
			rr(a, b);
			path_a--;
			path_b--;
		}
		else if (path_a < 0 && path_b < 0)
		{
			rrr(a, b);
			path_a++;
			path_b++;
		}
		else if (path_a > 0)
		{
			ra(a);
			path_a--;
		}
		else if (path_a < 0)
		{
			rra(a);
			path_a++;
		}
		else if (path_b > 0)
		{
			rb(b);
			path_b--;
		}
		else if (path_b < 0)
		{
			rrb(b);
			path_b++;
		}
	}
}

static int	insertion_move(t_pile *b, int index)
{
	int		max;
	int		min;

	min = -1;
	max = -1;
	if (lst_len(b) < 2)
		return (-1);
	while (b)
	{
		if (b->index < index && (b->index > min || min == -1))
			min = b->index;
		if (b->index > index && (b->index > max))
			max = b->index;
		b = b->next;
	}
	if (min > -1)
		return (min);
	else
		return (max);
}

int			resolve(t_pile **a, t_pile **b)
{
	int		index;
	int		index2;
	int		path_a;
	int		path_b;
	int		max;

	if (lst_len(*a) < 1)
		return (0);
	index = find_min(*a);
	max = index + (lst_len(*a) / 5);
	path_a = ps_findpath(*a, index, max);
	index2 = insertion_move(*b, ps_findindex(*a, path_a));
	if (index2 > -1)
		path_b = ps_findpath(*b, index2, index2);
	else
		path_b = 0;
	resolve_findbestway(*a, *b, &path_a, &path_b);
	move(a, b, path_a, path_b);
	pb(a, b);
	resolve(a, b);
	return (0);
}
