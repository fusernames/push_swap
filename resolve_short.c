/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 20:55:07 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/29 22:13:09 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_pile *a)
{
	t_pile	*tmp;
	int		max;

	a = lst_getmax(a);
	max = a->index;
	while (a->previous)
	{
		if (a->previous->index != a->index - 1)
			return (0);
		a = a->previous;
	}
	tmp = a;
	a = lst_getlast(a);
	if (a->index == max)
		return (1);
	if (a->index != tmp->index - 1)
		return (0);
	while (a->previous && a->previous->index != max)
	{
		if (a->previous->index != a->index - 1)
			return (0);
		a = a->previous;
	}
	return (1);
}

static void	sort_3(t_pile **a, int index)
{
	if ((*a)->index == index)
		exec("ra", a, NULL, 0);
	exec("sa", a, NULL, 0);
}

int			short_resolve(t_pile **a, t_pile **b)
{
	int		index;

	index = 0;
	while (!is_sorted(*a) && lst_len(*a) > 3)
	{
		ps_goto(a, index, 'a');
		if (!is_sorted(*a))
			exec("pb", a, b, 0);
		index++;
	}
	if (lst_len(*a) == 3)
	{
		if (!is_sorted(*a))
			sort_3(a, index);
		ps_goto(a, index, 'a');
	}
	return (0);
}
