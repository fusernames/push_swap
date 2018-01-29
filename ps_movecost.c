/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movecost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 20:53:11 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/29 23:22:53 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ps_movecost(int path_a, int path_b)
{
	if (path_a >= 0 && path_b >= 0)
		return (path_a > path_b ? path_a : path_b);
	if (path_a < 0 && path_b < 0)
		return (path_a < path_b ? -path_a : -path_b);
	if (path_a < 0 && path_b >= 0)
		return (-path_a + path_b);
	if (path_a >= 0 && path_b < 0)
		return (path_a + -path_b);
	return (0);
}
