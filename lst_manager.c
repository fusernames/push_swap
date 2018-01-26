/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:18:40 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/25 21:18:47 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		lst_len(t_pile *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	lst_print(t_pile *a)
{
	while (a)
	{
		printf("%d - ", a->index);
		a = a->next;
	}
	printf("\n");
}

void	lst_free(t_pile *a)
{
	t_pile	*cpy;
	t_pile	*tmp;

	cpy = NULL;
	if (a && a->previous)
		cpy = a->previous;
	while (cpy)
	{
		tmp = cpy->previous;
		free(cpy);
		cpy = tmp;
	}
	while (a)
	{
		tmp = a->next;
		free(a);
		a = tmp;
	}
}

t_pile	*lst_getlast(t_pile *a)
{
	while (a->next)
		a = a->next;
	return (a);
}

t_pile	*lst_getmax(t_pile *a)
{
	t_pile	*max;

	max = NULL;
	while (a)
	{
		if (!max || a->index > max->index)
			max = a;
		a = a->next;
	}
	return (max);
}
