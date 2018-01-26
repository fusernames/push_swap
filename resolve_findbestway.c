/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_findbestway.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:32:41 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/25 21:33:29 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	move_cost(int path_a, int path_b)
{
	if (path_a > 0 && path_b > 0)
		return (path_a > path_b ? path_a : path_b);
	if (path_a < 0 && path_b < 0)
		return (path_a < path_b ? -path_a : -path_b);
	if (path_a < 0 && path_b > 0)
		return (-path_a + path_b);
	if (path_a > 0 && path_b < 0)
		return (path_a + -path_b);
	return (0);
}

void		resolve_findbestway(t_pile *a, t_pile *b, int *path_a, int *path_b)
{
	int		len_a;
	int		len_b;
	int		pa;
	int		pb;
	int		len;

	len_a = lst_len(a);
	len_b = lst_len(b);
	pa = *path_a;
	pb = *path_b;
	if (pa == 0 || pb == 0)
		return ;
	if (pa < 0)
		pa += len_a;
	if (pb < 0)
		pb += len_b;
	len = move_cost(*path_a, *path_b);
	if (len > move_cost(pa - len_a, pb - len_b))
	{
		*path_a = pa - len_a;
		*path_b = pb - len_b;
		len = move_cost(*path_a, *path_b);
	}
	if (len > move_cost(pa - len_a, pb))
	{
		*path_a = pa - len_a;
		*path_b = pb;
		len = move_cost(*path_a, *path_b);
	}
	if (len > move_cost(pa, pb - len_b))
	{
		*path_a = pa;
		*path_b = pb - len_b;
		len = move_cost(*path_a, *path_b);
	}
	if (len > move_cost(pa, pb))
	{
		*path_a = pa;
		*path_b = pb;
	}
}
