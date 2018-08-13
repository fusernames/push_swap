/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:08:31 by alcaroff          #+#    #+#             */
/*   Updated: 2018/08/13 07:03:21 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	print(char *str, int mute)
{
	if (!mute)
	{
		ft_putstr(str);
		ft_putchar('\n');
	}
	return (1);
}

static int	exec_a(char *str, t_pile **a, t_pile **b, int mute)
{
	int		ret;

	ret = 1;
	if (!ft_strcmp(str, "ra"))
		ret = r(a);
	else if (!ft_strcmp(str, "rra"))
		ret = rr(a);
	else if (!ft_strcmp(str, "sa"))
		ret = s(a);
	else if (!ft_strcmp(str, "pa"))
		ret = p(a, b);
	if (ret == 0)
		return (print(str, mute));
	else
		return (0);
}

static int	exec_b(char *str, t_pile **a, t_pile **b, int mute)
{
	int		ret;

	ret = 1;
	if (!ft_strcmp(str, "rb"))
		ret = r(b);
	else if (!ft_strcmp(str, "rrb"))
		ret = rr(b);
	else if (!ft_strcmp(str, "sb"))
		ret = s(b);
	else if (!ft_strcmp(str, "pb"))
		ret = p(b, a);
	if (ret == 0)
		return (print(str, mute));
	else
		return (0);
}

static int	exec_both(char *str, t_pile **a, t_pile **b, int mute)
{
	int		ret_a;
	int		ret_b;

	ret_a = 1;
	ret_b = 1;
	if (!ft_strcmp(str, "rr"))
	{
		ret_a = r(a);
		ret_b = r(b);
	}
	else if (!ft_strcmp(str, "rrr"))
	{
		ret_a = rr(a);
		ret_b = rr(b);
	}
	else if (!ft_strcmp(str, "ss"))
	{
		ret_a = s(a);
		ret_b = s(b);
	}
	if (ret_a == 0 && ret_b == 0)
		return (print(str, mute));
	else
		return (0);
}

int			exec(char *str, t_pile **a, t_pile **b, int mute)
{
	if (exec_a(str, a, b, mute))
		;
	else if (exec_b(str, a, b, mute))
		;
	else if (exec_both(str, a, b, mute))
		;
	else
		return (1);
	return (0);
}
