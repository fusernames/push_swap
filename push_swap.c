/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:31:55 by alcaroff          #+#    #+#             */
/*   Updated: 2018/08/13 09:45:48 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;

	b = NULL;
	if (ac < 2)
		return (1);
	if ((a = parser(ac, av)) == NULL || check_exceptions(a))
		exit(error());
	if (lst_len(a) > 10)
		resolve(&a, &b);
	else
		short_resolve(&a, &b);
	if (lst_len(a))
		ps_goto(&a, ps_findmin(a), 'a');
	while (b)
		exec("pa", &a, &b, 0);
	ps_goto(&a, 0, 'a');
	lst_free(a);
	return (0);
}
