#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_pile{
	int		index;
	int		nb;
	struct s_pile		*next;
	struct s_pile		*previous;
}			t_pile;

int		resolve(t_pile **a, t_pile **b);
int		quick_sort(t_pile **a, t_pile **b, int start, int end);
int		insertion_sort(t_pile **a, t_pile **b, int start, int end);

int		is_sorted(t_pile *a, int start, int end);

int		lst_len(t_pile *a);
void	print_lst(t_pile *a);
t_pile	*get_last_elem(t_pile *a);
t_pile	*init_pile(int ac, char **av);

int		sa(t_pile **a);
int		ra(t_pile **a);
int		rra(t_pile **a);
int		pa(t_pile **a, t_pile **b);
int		sb(t_pile **b);
int		rb(t_pile **b);
int		rrb(t_pile **b);
int		pb(t_pile **a, t_pile **b);
int		ss(t_pile **a, t_pile **b);

void	ps_goto(t_pile **a, int nb, char c);
int		ps_findvalue(t_pile *a, int min, int max);

#endif
