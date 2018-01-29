/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_findbestway.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:32:41 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/29 22:57:02 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	negative(int path, t_pile *a)
{
	int		len;

	len = lst_len(a);
	return (path - len);
}

static void	resolve_findbestway_split(t_pile *a, t_pile *b, int *path_a,
		int *path_b)
{
	int		pa;
	int		pb;
	int		len;

	pa = *path_a;
	pb = *path_b;
	if (pa == 0 || pb == 0)
		return ;
	if (pa < 0)
		pa += lst_len(a);
	if (pb < 0)
		pb += lst_len(b);
	len = ps_movecost(*path_a, *path_b);
	if (len > ps_movecost(negative(pa, a), negative(pb, b)))
	{
		*path_a = negative(pa, a);
		*path_b = negative(pb, b);
		len = ps_movecost(*path_a, *path_b);
	}
	if (len > ps_movecost(negative(pa, a), pb))
	{
		*path_a = negative(pa, a);
		*path_b = pb;
		len = ps_movecost(*path_a, *path_b);
	}
}

void		resolve_findbestway(t_pile *a, t_pile *b, int *path_a, int *path_b)
{
	int		pa;
	int		pb;
	int		len;

	pa = *path_a;
	pb = *path_b;
	if (pa == 0 || pb == 0)
		return ;
	if (pa < 0)
		pa += lst_len(a);
	if (pb < 0)
		pb += lst_len(b);
	len = ps_movecost(*path_a, *path_b);
	if (len > ps_movecost(pa, negative(pb, b)))
	{
		*path_a = pa;
		*path_b = negative(pb, b);
		len = ps_movecost(*path_a, *path_b);
	}
	if (len > ps_movecost(pa, pb))
	{
		*path_a = pa;
		*path_b = pb;
	}
	resolve_findbestway_split(a, b, path_a, path_b);
}
