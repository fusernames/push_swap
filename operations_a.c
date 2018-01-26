/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:14:19 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/25 21:19:05 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_pile **a)
{
	int	tmp;

	if (!(*a) || !(*a)->next)
		return (0);
	tmp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = tmp;
	tmp = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = tmp;
	ft_putstr("sa\n");
	return (1);
}

int	ra(t_pile **a)
{
	t_pile	*last;
	t_pile	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return (0);
	tmp = (*a)->next;
	last = lst_getlast(*a);
	last->next = *a;
	(*a)->previous = last;
	(*a)->next = NULL;
	tmp->previous = NULL;
	*a = tmp;
	ft_putstr("ra\n");
	return (1);
}

int	rra(t_pile **a)
{
	t_pile	*last;

	if ((last = lst_getlast(*a)) == NULL)
		return (0);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *a;
	(*a)->previous = last;
	*a = last;
	ft_putstr("rra\n");
	return (1);
}

int	pa(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if (*b == NULL)
		return (0);
	tmp = (*b)->next;
	if (tmp)
		tmp->previous = NULL;
	if (*a)
		(*a)->previous = *b;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	ft_putstr("pa\n");
	return (1);
}
