/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:20:04 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/30 20:49:00 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pile	*new_elem(t_pile *a)
{
	t_pile	*new;

	new = NULL;
	new = malloc(sizeof(t_pile));
	new->nb = 0;
	new->index = -1;
	new->next = NULL;
	new->previous = NULL;
	if (a)
	{
		new->previous = a;
		a->next = new;
	}
	return (new);
}

static void		create_index(t_pile *a, int index)
{
	t_pile	*min;
	t_pile	*start;

	start = a;
	if (index == lst_len(a))
		return ;
	min = NULL;
	while (a)
	{
		if (a->index == -1 && (!min || a->nb < min->nb))
			min = a;
		a = a->next;
	}
	min->index = index;
	create_index(start, index + 1);
}

t_pile			*parser(int ac, char **av)
{
	t_pile	*a;
	char	**tab;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	while (i < ac)
	{
		tab = ft_splitwhitespace(av[i++]);
		j = 0;
		while (tab[j][0])
		{
			a = new_elem(a);
			if (ps_atoi(tab[j], &(a->nb)))
				exit(error());
			free(tab[j++]);
		}
		free(tab[j]);
		free(tab);
	}
	while (a && a->previous)
		a = a->previous;
	create_index(a, 0);
	return (a);
}
