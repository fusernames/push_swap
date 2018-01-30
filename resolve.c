/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:32:28 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/30 19:24:43 by alcaroff         ###   ########.fr       */
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

int			resolve(t_pile **a, t_pile **b)
{
	int		path_a;
	int		path_b;

	if (lst_len(*a) < 1)
		return (0);
	resolve_path(*a, *b, &path_a, &path_b);
	move(a, b, path_a, path_b);
	exec("pb", a, b, 0);
	resolve(a, b);
	return (0);
}
