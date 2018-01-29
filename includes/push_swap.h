/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:59:14 by alcaroff          #+#    #+#             */
/*   Updated: 2018/01/29 22:46:20 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"

typedef	struct		s_pile{
	int					nb;
	int					index;
	struct s_pile		*next;
	struct s_pile		*previous;
}					t_pile;

int					check_characters(char **av, int ac);
int					check_duplicate(t_pile *a);
t_pile				*parser(int ac, char **av);
int					resolve(t_pile **a, t_pile **b);
void				resolve_findbestway(t_pile *a, t_pile *b, int *path_a,
		int *path_b);
int					short_resolve(t_pile **a, t_pile **b);

int					lst_len(t_pile *a);
void				lst_print(t_pile *a);
t_pile				*lst_free(t_pile *a);
t_pile				*lst_getlast(t_pile *a);
t_pile				*lst_getmax(t_pile *a);

void				ps_goto(t_pile **a, int index, char c);
int					ps_findpath(t_pile *a, int min, int max);
int					ps_findvalue(t_pile *a, int min, int max);
int					ps_findindex(t_pile *a, int path);
int					ps_atoi(char *s, int *index);
int					ps_findmin(t_pile *a);
int					ps_movecost(int path_a, int path_b);

int					exec(char *s, t_pile **a, t_pile **b, int mute);
int					s(t_pile **a);
int					r(t_pile **a);
int					rr(t_pile **a);
int					p(t_pile **a, t_pile **b);

#endif
