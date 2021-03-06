/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_findindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 21:22:12 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/25 21:22:16 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_findindex(t_pile *a, int path)
{
	if (path < 0)
		path += lst_len(a);
	while (path--)
		a = a->next;
	return (a->index);
}
