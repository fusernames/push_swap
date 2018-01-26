/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:14:35 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/25 21:19:52 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ss(t_pile **a, t_pile **b)
{
	int	tmp;

	if (!(*b) || !(*b)->next)
		return (0);
	if (!(*a) || !(*a)->next)
		return (0);
	tmp = (*b)->nb;
	(*b)->nb = (*b)->next->nb;
	(*b)->next->nb = tmp;
	tmp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = tmp;
	ft_putstr("ss\n");
	return (1);
}

int		rr(t_pile **a, t_pile **b)
{
	t_pile	*last;
	t_pile	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return (0);
	if (*b == NULL || (*b)->next == NULL)
		return (0);
	tmp = (*a)->next;
	last = lst_getlast(*a);
	last->next = *a;
	(*a)->previous = last;
	(*a)->next = NULL;
	tmp->previous = NULL;
	*a = tmp;
	tmp = (*b)->next;
	last = lst_getlast(*b);
	last->next = *b;
	(*b)->previous = last;
	(*b)->next = NULL;
	tmp->previous = NULL;
	*b = tmp;
	ft_putstr("rr\n");
	return (1);
}

int		rrr(t_pile **a, t_pile **b)
{
	t_pile	*last;

	if ((last = lst_getlast(*a)) == NULL)
		return (0);
	if (lst_getlast(*b) == NULL)
		return (0);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *a;
	(*a)->previous = last;
	*a = last;
	last = lst_getlast(*b);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *b;
	(*b)->previous = last;
	*b = last;
	ft_putstr("rrr\n");
	return (1);
}
