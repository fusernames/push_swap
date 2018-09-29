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

static int	is_sorted(t_pile *a)
{
	while (a)
	{
		if (a->next && a->index != a->next->index - 1)
			return (0);
		a = a->next;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;

	b = NULL;
	if (ac < 2)
		return (1);
	if ((a = parser(ac, av)) == NULL || check_exceptions(a))
		exit(error());
	if (lst_len(a) > 20 && !is_sorted(a))
		resolve(&a, &b);
	else if (lst_len(a) <= 20 && !is_sorted(a))
		short_resolve(&a, &b);
	if (lst_len(a))
		ps_goto(&a, ps_findmin(a), 'a');
	while (b)
		exec("pa", &a, &b, 0);
	ps_goto(&a, 0, 'a');
	lst_free(a);
	lst_free(b);
	return (0);
}
