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

static int	check_duplicate(t_pile *a)
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

static int	check_int(t_pile *a)
{
	while (a)
	{
		if (a->nb > 2147483647 || a->nb < -2147483648)
			return (1);
		a = a->next;
	}
	return (0);
}

int			check_exceptions(t_pile *a)
{
	int	ret;

	ret = 0;
	ret += check_duplicate(a);
	ret += check_int(a);
	return (ret);
}
