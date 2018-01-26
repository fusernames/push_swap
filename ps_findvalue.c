/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_findvalue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:31:17 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/25 21:31:19 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_findvalue(t_pile *a, int min, int max)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index >= min && a->index <= max)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}
