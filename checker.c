/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:36:14 by alcaroff          #+#    #+#             */
/*   Updated: 2018/08/13 07:04:09 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_pile *a)
{
	while (a)
	{
		if (a->next && a->index != a->next->index - 1)
			return (0);
		a = a->next;
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;
	char	*line;

	b = NULL;
	if (ac < 2)
		return (1);
	if ((a = parser(ac, av)) == NULL || check_duplicate(a))
	{
		lst_free(a);
		exit(error());
	}
	while (get_next_line(0, &line))
	{
		if (exec(line, &a, &b, 1))
		{
			ft_putstr("KO\n");
			return (0);
		}
	}
	if (is_sorted(a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (0);
}
