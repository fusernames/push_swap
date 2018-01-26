/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exceptions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:18:34 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/25 21:18:36 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_characters(char **av, int ac)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (j < ac)
	{
		while (av[j][i])
		{
			if (!ft_isdigit(av[j][i]) && !ft_isspace(av[j][i]))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int		check_duplicate(t_pile *a)
{
	t_pile	*cpy;

	while (a)
	{
		cpy = a->next;
		while (cpy)
		{
			if (cpy->nb == a->nb)
				return (1);
			cpy = cpy->next;
		}
		a = a->next;
	}
	return (0);
}
