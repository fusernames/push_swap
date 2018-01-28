/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_findpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:22:30 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/28 18:13:18 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse(t_pile *a, int min, int max)
{
	int		i;
	int		rr;

	i = 1;
	rr = -1;
	while (a)
	{
		if (a->index >= min && a->index <= max && rr == -1)
			rr = i;
		a = a->previous;
		i++;
	}
	return (rr);
}

int			ps_findpath(t_pile *a, int min, int max)
{
	int		i;
	int		r;
	int		rr;

	r = -1;
	rr = -1;
	i = 0;
	if (min < 0 || max < 0)
		return (-1);
	while (a)
	{
		if (a->index >= min && a->index <= max && r == -1)
			r = i;
		if (a->next == NULL)
			rr = reverse(a, min, max);
		a = a->next;
		i++;
	}
	return (r <= rr ? r : -rr);
}
