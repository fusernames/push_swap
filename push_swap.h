#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_pile{
	int		nb;
	struct s_pile		*next;
	struct s_pile		*previous;
}			t_pile;

int	resolve(t_pile *a);

int	lst_len(t_pile *a);
void	print_lst(t_pile *a);
t_pile	*get_last_elem(t_pile *a);
t_pile	*init_pile(int ac, char **av);

int	sa(t_pile **a);
int	ra(t_pile **a);
int	rra(t_pile **a);
int	pa(t_pile **a, t_pile **b);
int	sb(t_pile **b);
int	rb(t_pile **b);
int	rrb(t_pile **b);
int	pb(t_pile **a, t_pile **b);
int	ss(t_pile **a, t_pile **b);

#endif
