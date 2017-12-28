#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;

	b = NULL;
	if (ac < 2)
		return (0);
	a = init_pile(ac, av);
	print_lst(a);
	//resolve(&a, &b);
	quick_sort(&a, &b, 0, lst_len(a) - 1);
	while (b)
		pa(&a, &b);
	ps_goto(&a, 0, 'a');
	print_lst(a);
	return (0);
}
