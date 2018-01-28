/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_goto.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:31:26 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/28 16:41:39 by alcaroff         ###   ########.fr       */
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
				exec("rb", NULL, b, 0);
			else
				exec("ra", b, NULL, 0);
		}
	}
	else if (i < 0)
	{
		while (i++)
		{
			if (c == 'b')
				exec("rrb", NULL, b, 0);
			else
				exec("rra", b, NULL, 0);
		}
	}
}
