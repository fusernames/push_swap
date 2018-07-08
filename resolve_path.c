/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:11:15 by alcaroff          #+#    #+#             */
/*   Updated: 2018/02/01 20:38:38 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	get_path(t_pile *a, t_pile *b, int *p, int i)
{
	int		index_b;

	p[0] = ps_findpath(a, i, i);
	index_b = insertion_move(b, i);
	if (index_b > -1)
		p[1] = ps_findpath(b, index_b, index_b);
	else
		p[1] = 0;
}

void		resolve_path(t_pile *a, t_pile *b, int *path_a, int *path_b)
{
	int		i;
	int		max;
	int		cost;
	int		p[2];

	cost = -1;
	i = ps_findmin(a);
	max = i + (lst_len(a));
	while (i <= max)
	{
		while (i <= max && ps_findvalue(a, i, i) == -1)
			i++;
		if (i > max)
			return ;
		get_path(a, b, p, i);
		resolve_findbestway(a, b, &p[0], &p[1]);
		if (cost == -1 || cost > ps_movecost(p[0], p[1]))
		{
			cost = ps_movecost(p[0], p[1]);
			*path_a = p[0];
			*path_b = p[1];
		}
		i++;
	}
}
