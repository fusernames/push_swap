/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:32:28 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/29 23:22:40 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_split(t_pile **a, t_pile **b, int *path_a, int *path_b)
{
	if (*path_a > 0)
	{
		exec("ra", a, b, 0);
		(*path_a)--;
	}
	else if (*path_a < 0)
	{
		exec("rra", a, b, 0);
		(*path_a)++;
	}
	else if (*path_b > 0)
	{
		exec("rb", a, b, 0);
		(*path_b)--;
	}
	else if (*path_b < 0)
	{
		exec("rrb", a, b, 0);
		(*path_b)++;
	}
}

static void	move(t_pile **a, t_pile **b, int path_a, int path_b)
{
	while (path_a || path_b)
	{
		if (path_a > 0 && path_b > 0)
		{
			exec("rr", a, b, 0);
			path_a--;
			path_b--;
		}
		else if (path_a < 0 && path_b < 0)
		{
			exec("rrr", a, b, 0);
			path_a++;
			path_b++;
		}
		else
			move_split(a, b, &path_a, &path_b);
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

/*static void	resolve_path(t_pile *a, t_pile *b, int *path_a, int *path_b)
{
	int		i;
	int		index_b;
	int		max;
	int		cost;
	int		p[2];

	cost = -1;
	i = ps_findmin(a);
	max = i + (lst_len(a) / 5);
	while (i <= max)
	{
		while (i <= max && (p[0] = ps_findpath(a, i, i)) == -1)
			i++;
		if (i > max)
			return ;
		index_b = insertion_move(b, i);
		if (index_b > -1)
			p[1] = ps_findpath(b, index_b, index_b);
		else
			p[1] = 0;
		if (cost == -1 || cost > ps_movecost(p[0], p[1]))
		{
			cost = ps_movecost(p[0], p[1]);
			printf("a = %d | b = %d\n", p[0], p[1]);
			printf("cost = %d\n", cost);
			*path_a = p[0];
			*path_b = p[1];
		}
		i++;
	}
}*/

int			resolve(t_pile **a, t_pile **b)
{
	int		max;
	int		i;
	int		index_b;
	int		path_a;
	int		path_b;

	if (lst_len(*a) < 1)
		return (0);
	i = ps_findmin(*a);
	max = i + (lst_len(*a) / 5);
	path_a = ps_findpath(*a, i, max);
	index_b = insertion_move(*b, ps_findindex(*a, path_a));
	if (index_b > -1)
		path_b = ps_findpath(*b, index_b, index_b);
	else
		path_b = 0;
	resolve_findbestway(*a, *b, &path_a, &path_b);
	move(a, b, path_a, path_b);
	exec("pb", a, b, 0);
	resolve(a, b);
	return (0);
}
