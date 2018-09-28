/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:22:05 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/30 20:31:48 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ps_atoi(char *s, long *nb)
{
	int			is_negative;
	int			found;

	found = 0;
	is_negative = 0;
	while (ft_isspace(*s))
		(s)++;
	if (*s == '+')
		(s)++;
	else if (*s == '-')
	{
		is_negative = 1;
		(s)++;
	}
	while (*s >= '0' && *s <= '9')
	{
		found = 1;
		*nb = (*nb * 10) + *s - '0';
		(s)++;
	}
	if (!found)
		return (1);
	*nb = is_negative ? -(*nb) : *nb;
	return (0);
}
