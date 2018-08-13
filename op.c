/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:00:39 by alcaroff          #+#    #+#             */
/*   Updated: 2018/08/13 07:03:18 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	s(t_pile **a)
{
	int	tmp;

	if (!(*a) || !(*a)->next)
		return (1);
	tmp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = tmp;
	tmp = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = tmp;
	return (0);
}

int	r(t_pile **a)
{
	t_pile	*last;
	t_pile	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return (1);
	tmp = (*a)->next;
	last = lst_getlast(*a);
	last->next = *a;
	(*a)->previous = last;
	(*a)->next = NULL;
	tmp->previous = NULL;
	*a = tmp;
	return (0);
}

int	rr(t_pile **a)
{
	t_pile	*last;

	if ((last = lst_getlast(*a)) == NULL || (*a)->next == NULL)
		return (1);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *a;
	(*a)->previous = last;
	*a = last;
	return (0);
}

int	p(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if (*b == NULL)
		return (1);
	tmp = (*b)->next;
	if (tmp)
		tmp->previous = NULL;
	if (*a)
		(*a)->previous = *b;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	return (0);
}
