/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_goto.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:31:26 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/25 21:31:35 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ps_goto(t_pile **b, int nb, char c)
{
	int		i;

	i = ps_findpath(*b, nb, nb);
	if (i > 0)
	{
		while (i--)
		{
			if (c == 'b')
				rb(b);
			else
				ra(b);
		}
	}
	else if (i < 0)
	{
		while (i++)
		{
			if (c == 'b')
				rrb(b);
			else
				rra(b);
		}
	}
}
