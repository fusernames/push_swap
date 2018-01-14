#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

typedef struct		s_pile{
	int		nb;
	int		index;
	struct s_pile		*next;
	struct s_pile		*previous;
}			t_pile;

int					check_characters(char **av, int ac);
int					check_duplicate(t_pile *a);
t_pile				*parser(int ac, char **av);
int					resolve(t_pile **a, t_pile **b);
void				resolve_findbestway(t_pile *a, t_pile *b, int *path_a, int *path_b);

int					is_sorted(t_pile *a, int start, int end);

int					lst_len(t_pile *a);
void				print_lst(t_pile *a);
t_pile				*get_last_elem(t_pile *a);
t_pile				*init_pile(int ac, char **av);

void				ps_goto(t_pile **a, int index, char c);
int					ps_findpath(t_pile *a, int min, int max);
int					ps_findvalue(t_pile *a, int min, int max);
int					ps_findindex(t_pile *a, int path);
int					ps_atoi(char *s, int *index);

int					sa(t_pile **a);
int					ra(t_pile **a);
int					rra(t_pile **a);
int					pa(t_pile **a, t_pile **b);
int					sb(t_pile **b);
int					rb(t_pile **b);
int					rrb(t_pile **b);
int					pb(t_pile **a, t_pile **b);
int					ss(t_pile **a, t_pile **b);
int					rr(t_pile **a, t_pile **b);
int					rrr(t_pile **a, t_pile **b);

#endif
